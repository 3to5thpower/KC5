#!/bin/bash

bin="$1"

assert() {
  expected="$1"
  input="$2"

  ./$bin "$input" > tmp.s
  cc -o tmp tmp.s
  ./tmp
  actual="$?"

  if [ "$actual" = "$expected"  ]; then
    echo "$input => $actual"
  else
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

# Add your test expression -----
assert 0 0
assert 42 42
assert 21 '5 20 + 4 -'
assert 47 '6 7 * 5 +'
assert 15 '9 6 - 5 *'
assert 4 '3 5 + 2 /'

# ------------------------------
echo OK

