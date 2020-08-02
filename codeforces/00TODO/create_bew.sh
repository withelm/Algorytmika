#!/usr/bin/bash


NEW_TASK=$(dotnet.exe run --project solver/)
echo $NEW_TASK

mkdir $NEW_TASK
cp main.cpp $NEW_TASK\


  
 