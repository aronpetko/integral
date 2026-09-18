#!/usr/bin/env python3
"""Bootstrap Integral datagen on Windows or Ubuntu/Debian; Python 3.8+, no pip."""

import os
from pathlib import Path
import shutil
import subprocess
import sys
import urllib.request
import zipfile


WINDOWS = sys.platform == "win32"
BOOK = "UHO_Lichess_4852_v1.epd"
REPOSITORY = "https://github.com/aronpetko/integral.git"


def run(*args, **kwargs):
    command = [str(arg) for arg in args]
    command[0] = shutil.which(command[0], path=kwargs.get("env", os.environ).get("PATH")) or command[0]
    subprocess.run(command, check=True, **kwargs)


def install_dependencies(env):
    if WINDOWS:
        msys = Path(env.get("MSYS2_ROOT", "C:/msys64"))
        bash = msys / "usr/bin/bash.exe"
        if not bash.is_file():
            run("winget", "install", "--id", "MSYS2.MSYS2", "--exact", "--silent",
                "--location", msys, "--accept-package-agreements",
                "--accept-source-agreements")
        tools = ("mingw64/bin/gcc.exe", "mingw64/bin/g++.exe",
                 "mingw64/bin/cmake.exe", "mingw64/bin/ninja.exe", "usr/bin/git.exe")
        if not all((msys / tool).is_file() for tool in tools):
            run(bash, "-lc", "pacman -Syu --noconfirm")
            run(bash, "-lc", "pacman -Su --needed --noconfirm "
                "mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake "
                "mingw-w64-x86_64-ninja git")
        env["PATH"] = os.pathsep.join(
            (str(msys / "mingw64/bin"), str(msys / "usr/bin"), env.get("PATH", "")))
    else:
        if not shutil.which("apt-get"):
            raise RuntimeError("Supported systems: Windows and Ubuntu/Debian (including WSL)")
        if not all(shutil.which(tool) for tool in ("gcc", "g++", "make", "cmake", "git")):
            sudo = [] if os.geteuid() == 0 else ["sudo"]
            run(*sudo, "apt-get", "update")
            run(*sudo, "apt-get", "install", "-y", "build-essential", "cmake",
                "git", "ca-certificates")


def download_book(directory):
    book = directory / BOOK
    if book.is_file() and book.stat().st_size:
        return
    archive = directory / (BOOK + ".zip")
    url = f"https://raw.githubusercontent.com/official-stockfish/books/master/{BOOK}.zip"
    print(f"Downloading {BOOK}", flush=True)
    with urllib.request.urlopen(url) as source, archive.open("wb") as output:
        shutil.copyfileobj(source, output)
    partial = directory / (BOOK + ".part")
    with zipfile.ZipFile(archive) as zipped:
        if not zipped.getinfo(BOOK).file_size:
            raise RuntimeError("Book archive contains no positions")
        with zipped.open(BOOK) as source, partial.open("wb") as output:
            shutil.copyfileobj(source, output)
    partial.replace(book)
    archive.unlink()


def main(args):
    if not args:
        raise RuntimeError("Usage: python datagen.py <datagen arguments, without the datagen prefix>")
    env = os.environ.copy()
    install_dependencies(env)
    source = Path(env.get("INTEGRAL_DIR", Path(__file__).resolve().parent.parent))
    if not (source / "src/data_gen/data_gen.cc").is_file():
        source = Path(env.get("INTEGRAL_DIR", Path.cwd() / "integral"))
        branch = ["--branch", env["INTEGRAL_REF"]] if env.get("INTEGRAL_REF") else []
        run("git", "clone", "--depth", "1", *branch, REPOSITORY, source, env=env)
    source = source.resolve()
    build = source / "cmake-build-datagen"
    generator = ["-G", "Ninja"] if WINDOWS else []
    run("cmake", "-S", source, "-B", build, *generator,
        "-DCMAKE_BUILD_TYPE=Release", "-DDATAGEN=ON",
        "-DCMAKE_C_COMPILER=gcc", "-DCMAKE_CXX_COMPILER=g++", env=env)
    run("cmake", "--build", build, "--parallel",
        env.get("BUILD_JOBS", str(os.cpu_count() or 1)), env=env)
    directory = build / "data"
    directory.mkdir(parents=True, exist_ok=True)
    download_book(directory)
    print(f"Running in {directory}", flush=True)
    engine = build / ("integral.exe" if WINDOWS else "integral")
    run(engine, input="datagen " + " ".join(args) + "\n", text=True,
        cwd=directory, env=env)


if __name__ == "__main__":
    try:
        main(sys.argv[1:])
    except (OSError, RuntimeError, subprocess.CalledProcessError, zipfile.BadZipFile, KeyError) as error:
        sys.exit(f"Error: {error}")
