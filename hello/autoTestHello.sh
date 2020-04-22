#!/bin/bash

for i in 1 2 3 4
do
    insmod "hello-$i.ko"
    rmmod "hello-$i.ko"
done
