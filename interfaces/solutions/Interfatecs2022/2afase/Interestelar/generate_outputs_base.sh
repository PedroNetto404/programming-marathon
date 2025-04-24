#!/bin/zsh

for t in {1..25} 
do
  echo "Running test $t .. "
  time ./base < "inputs/${t}_in.txt" > "outputs/${t}_out.txt"
done
