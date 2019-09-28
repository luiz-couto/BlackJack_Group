#!/bin/bash
rm -rf ./testes

mkdir ./testes
cd testes

mkdir ./0
mkdir ./100
mkdir ./200
mkdir ./300
mkdir ./400
mkdir ./500

cd 0
../../main ./1.txt 0 0 0 0

cd ..
cd 100
../../main ./1.txt 100 10 10 10
../../main ./2.txt 100 30 30 30
../../main ./3.txt 100 50 50 50
../../main ./4.txt 100 70 70 70
../../main ./5.txt 100 90 90 90

cd ..
cd 200
../../main ./1.txt 200 10 10 10
../../main ./2.txt 200 30 30 30
../../main ./3.txt 200 50 50 50
../../main ./4.txt 200 70 70 70
../../main ./5.txt 200 90 90 90

cd ..
cd 300
../../main ./1.txt 300 10 10 10
../../main ./2.txt 300 30 30 30
../../main ./3.txt 300 50 50 50
../../main ./4.txt 300 70 70 70
../../main ./5.txt 300 90 90 90

cd ..
cd 400
../../main ./1.txt 400 10 10 10
../../main ./2.txt 400 30 30 30
../../main ./3.txt 400 50 50 50
../../main ./4.txt 400 70 70 70
../../main ./5.txt 400 90 90 90

cd ..
cd 500
../../main ./1.txt 500 10 10 10
../../main ./2.txt 500 30 30 30
../../main ./3.txt 500 50 50 50
../../main ./4.txt 500 70 70 70
../../main ./5.txt 500 90 90 90