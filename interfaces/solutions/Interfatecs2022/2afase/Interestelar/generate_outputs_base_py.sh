#!/bin/zsh

for t in {1..25} 
do
  echo "Running test $t .. "
  time python interestelar.py < "inputs/${t}_in.txt" > "outputs_py/${t}_out.txt"
done
