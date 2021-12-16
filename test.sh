#!/bin/sh

for i in {0..500}; do
	./client $1 "This is mesage n[$i]: 😂";
done
