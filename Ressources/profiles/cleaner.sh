#!/bin/sh

i=5

while [ ! $i -eq 100 ]
do
    rm -rf $i
    let "i+=1"
done
    rm -rf *~