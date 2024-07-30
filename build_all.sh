#!/bin/bash

options=(
  "BUILD_X86_64_POPCNT"
  "BUILD_X86_64_MODERN"
  "BUILD_X86_64_BMI2"
  "BUILD_DEBUG"
  "BUILD_NATIVE"
)

for option in "${options[@]}"; do
  build_dir="build_${option,,}"
  mkdir -p "$build_dir"
  cd "$build_dir"
  cmake .. -D"$option"=ON
  make
  cd ..
done