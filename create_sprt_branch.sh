#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

BENCH_EXE="cmake-build-release/integral.exe"

if [[ ! -f "$BENCH_EXE" ]]; then
  echo "Error: $BENCH_EXE not found. Build the project first." >&2
  exit 1
fi

echo "Running bench..."
BENCH_OUTPUT="$("$BENCH_EXE" bench)"
echo "$BENCH_OUTPUT"

NODES="$(echo "$BENCH_OUTPUT" | grep -oE '[0-9]+ nodes' | grep -oE '^[0-9]+' | tail -1)"

if [[ -z "$NODES" ]]; then
  echo "Error: could not parse node count from bench output." >&2
  exit 1
fi

echo "Node count: $NODES"

BRANCH_NAME="${1:-}"

if [[ -z "$BRANCH_NAME" ]]; then
  read -rp "Branch name: " BRANCH_NAME
fi

if [[ -z "$BRANCH_NAME" ]]; then
  echo "Error: branch name cannot be empty." >&2
  exit 1
fi

if git rev-parse --verify --quiet "$BRANCH_NAME" >/dev/null; then
  git checkout "$BRANCH_NAME"
else
  echo "Branch '$BRANCH_NAME' does not exist locally, creating it."
  git checkout -b "$BRANCH_NAME"
fi

git add .
git commit -m "Bench: $NODES"
git push -u origin "$BRANCH_NAME"
