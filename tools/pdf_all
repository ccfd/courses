#!/bin/bash

FILES=$(ls | grep '^[^_].*\.md$')

for i in $FILES
do
	tools/pdf_full $i
done
