
setlocal enabledelayedexpansion

set "DIRECTORY=D:\Coding\integral\src"

for /R "%DIRECTORY%" %%f in (*.cc *.h) do (
    echo Processing: %%f

    PowerShell -NoProfile -ExecutionPolicy Bypass -Command ^
        "Get-Content -Path '%%f' | ForEach-Object { ^
            if ($_ -match '^\s*// [a-z]') { ^
                if ($_ -notmatch '^\s*// clang-format') { ^
                    $_ -replace '// ([a-z])', {param($m) '// ' + $m.Groups[1].Value.ToUpper()} ^
                } else { ^
                    $_ ^
                } ^
            } else { ^
                $_ ^
            } ^
        } | Set-Content -Path '%%f'"
)

echo Done processing files.
pause
