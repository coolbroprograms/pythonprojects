#!/bin/bash

touch FILE_1
touch FILE_2

for i in {1..10}
do
    echo "File_1 content..$i" >> FILE_1
    echo "FILE_2 content..$i" >> FILE_2
done

