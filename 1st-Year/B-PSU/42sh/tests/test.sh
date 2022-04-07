#!/bin/bash
cd ../
make re
echo "**********Success ls**********"
echo "ls" | ./mysh
echo $?
echo "**********Failure ls**********"
echo "ls nofile" | ./mysh
echo $?
echo "**********Success cd**********"
echo "cd include" | ./mysh
echo $?
echo "**********Failure cd**********"
echo "cd oui" | ./mysh
echo $?
echo "**********Failure cd**********"
echo "cd include oui" | ./mysh
echo $?
echo "**********Success env**********"
echo "env" | ./mysh
echo $?
echo "**********Failure env**********"
echo "env oui" | ./mysh
echo $?
echo "**********Failure setenv**********"
echo "setenv" | ./mysh
echo $?
echo "**********Failure setenv**********"
echo "setenv 48" | ./mysh
echo $?
echo "**********Success setenv**********"
echo "setenv oui" | ./mysh
echo $?
echo "**********Success setenv**********"
echo "setenv non 45" | ./mysh
echo $?
echo "**********Failure unsetenv**********"
echo "unsetenv" | ./mysh
echo $?
echo "**********Success unsetenv**********"
echo "unsetenv oui" | ./mysh
echo $?
echo "**********Success exit**********"
echo "exit" | ./mysh
echo $?
echo "**********Success exit 54**********"
echo "exit 54" | ./mysh
echo $?
make fclean
cd tests