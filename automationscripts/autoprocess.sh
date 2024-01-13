#!/bin/bash

echo "running"

compile="gcc /media/psf/Home/Desktop/OEL/sources/data.c /media/psf/Home/Desktop/OEL/sources/fetch.c /media/psf/Home/Desktop/OEL/sources/report.c ./runscript.c -o runscript -O2 -Wall -lcurl"
execute="./runscript"
$compile
if [ $? -eq 0 ]
then	
	echo "compiled succesfully"
	echo "processing started"
	$execute 2
else
	echo "compilation error"
	
fi
