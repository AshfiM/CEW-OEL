#!/bin/bash

echo "running"

compile="clang ./sources/fetch.c ./sources/data.c ./sources/report.c program.c -o program -O2 -Wall -lcurl" 
execute="./program"
$compile

if [ $? -eq 0 ]
then
	echo "compiled succesfully"
	$execute
else
	echo "compilation error"
fi



