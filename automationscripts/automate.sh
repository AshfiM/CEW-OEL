#!/bin/bash

echo "running"

compile="gcc /media/psf/Home/Desktop/OEL/sources/data.c /media/psf/Home/Desktop/OEL/sources/fetch.c /media/psf/Home/Desktop/OEL/sources/report.c ./program.c -o program -O2 -Wall -lcurl" 
execute="./program"
$compile

if [ $? -eq 0 ]
then
	echo "compiled succesfully"
	$execute
else
	echo "compilation error"
fi



