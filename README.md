# pidigits

compute the nth digit of pi in base 16

performance seems reasonable - 10^7th digit calculated in 3.6s on my i7-6770HQ CPU @ 2.60GHz

## Usage

make clean build test bench

$  time pidigits 10000000
pi16(10000000): 7af5863e

## Paper
"ON THE RAPID COMPUTATION OF VARIOUS POLYLOGARITHMIC CONSTANTS" David Bailey, Peter Borwein and Simon Plouffe
