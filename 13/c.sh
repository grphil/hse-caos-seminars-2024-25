#!/bin/bash

# Хотите найти инфу про что-то - пишите это cheat sheet

echo $1
x=1
echo $x

y=$(cat a.cpp)
echo $y

if [[ $x == $1 ]]; then 
	echo yes
else
	echo no
fi

for i in "q" "w" "e" "r" qwe 332323 $1 $x
do
	echo $i
done

for i in $(cat a.cpp)
do
	echo $i
done

for (( i = 0; i <= 10; i++ ))
do
	echo $i
done

