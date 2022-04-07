#!/usr/bin/env bash
##
## EPITECH PROJECT, 2021
## exit_statusTest
## File description:
## bash_tests
##

exit_status=0

tcshRes="cmd_test/tcsh.txt"
myshRes="cmd_test/42sh.txt"
pathTest="cmd_test/exit_status.txt"
errorCase=0
retValmysh=0
retValtcsh=0
while IFS= read -r line; do
    errorCase=0
    eval "echo $line | tcsh" > $tcshRes
    retValtcsh=$(echo $?)
    eval "echo $line | ../42sh" > $myshRes
    retValmysh=$(echo $?)
    if !(cmp -s $tcshRes $myshRes)
    then
        displayRes="Display is WRONG!"
        errorCase=1
    else
        displayRes="Display is GOOD!"
    fi
    if (($retValmysh != $retValtcsh))
    then
        retRes="Return is WRONG! tcsh=\"$retValtcsh\" 42sh=\"$retValmysh\""
        errorCase=1
    else
        retRes="Return is GOOD!"
    fi
    if (($errorCase == 1))
    then
        echo -e "\e[31m$line: $displayRes $retRes\e[39m"
        exit_status=1
    else
        echo -e "\e[32m$line: Display is GOOD! Return is GOOD!\e[39m"
    fi
    rm $tcshRes
    rm $myshRes

done < $pathTest

exit $exit_status