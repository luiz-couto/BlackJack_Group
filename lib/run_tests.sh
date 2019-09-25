#!/bin/bash

rm -rf ./testes_results
mkdir ./testes_results
cd testes_results

mkdir ./0
mkdir ./100
mkdir ./200
mkdir ./300
mkdir ./400
mkdir ./500

cd 0
../../main ../../testes/0/1.txt -d > 1.txt

cd ../100
../../main ../../testes/100/1.txt -d > 1.txt
../../main ../../testes/100/2.txt -d > 2.txt
../../main ../../testes/100/3.txt -d > 3.txt
../../main ../../testes/100/4.txt -d > 4.txt
../../main ../../testes/100/5.txt -d > 5.txt

cd ../200
../../main ../../testes/200/1.txt -d > 1.txt
../../main ../../testes/200/2.txt -d > 2.txt
../../main ../../testes/200/3.txt -d > 3.txt
../../main ../../testes/200/4.txt -d > 4.txt
../../main ../../testes/200/5.txt -d > 5.txt

cd ../300
../../main ../../testes/300/1.txt -d > 1.txt
../../main ../../testes/300/2.txt -d > 2.txt
../../main ../../testes/300/3.txt -d > 3.txt
../../main ../../testes/300/4.txt -d > 4.txt
../../main ../../testes/300/5.txt -d > 5.txt

cd ../400
../../main ../../testes/400/1.txt -d > 1.txt
../../main ../../testes/400/2.txt -d > 2.txt
../../main ../../testes/400/3.txt -d > 3.txt
../../main ../../testes/400/4.txt -d > 4.txt
../../main ../../testes/400/5.txt -d > 5.txt

cd ../500
../../main ../../testes/500/1.txt -d > 1.txt
../../main ../../testes/500/2.txt -d > 2.txt
../../main ../../testes/500/3.txt -d > 3.txt
../../main ../../testes/500/4.txt -d > 4.txt
../../main ../../testes/500/5.txt -d > 5.txt