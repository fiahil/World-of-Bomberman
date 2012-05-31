#!/bin/sh

i=10

while [ ! $i -eq 2000 ]
do
    rm -rf "maps/"$i
    rm -rf "profiles/"$i
    rm -rf "saves/"$i
    let "i+=1"
done
    rm -rf maps/*~ profiles/*~ saves/*~