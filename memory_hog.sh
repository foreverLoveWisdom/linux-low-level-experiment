#!/bin/bash

allocate_memory() {
  echo "Allocating memory..."
  arr=()
  for ((i = 0; i < 500000000; i++)); do
    arr[i]=0
  done
  echo "Memory allocation complete."
}

allocate_memory
