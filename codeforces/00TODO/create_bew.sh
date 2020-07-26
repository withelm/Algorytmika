#!/usr/bin/bash

echo 'Check is exist folder '$1
DIR="../Solve/"$1


if [ -d $DIR ]; then
  echo "File is exist!!!"
else 
  mkdir $1
  cp main.cpp $1\
  
  echo "Enjoy new task!"
fi
