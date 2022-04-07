#!/bin/bash

#exit_status=0
#
#pathTest="./tests/cmd_test/valgrind.txt"
#errorCase=0
#retValmysh=0
#retValtcsh=0
#while IFS= read -r line; do
#    errorCase=0
#    returncmd=$(echo $line | valgrind --log-file=valg.log ./42sh)
#    valgrinfRes_1=$(cat valg.log | grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)")
#    valgrinfRes_2=$(cat valg.log | grep "LEAK SUMMARY")
#    if ([[ $valgrinfRes_1 == "" || !($valgrinfRes_2 == "" )]])
#    then
#        echo -e "\e[31mError dectected in Valgrind for $line\e[39m"
#        exit_status=1
#    else
#        echo -e "\e[32mValid Valgrind for $line\e[39m"
#    fi
#    rm valg.log
#
#done < $pathTest
#
#exit $exit_status

returncmd=$(echo 'ls' | valgrind --log-file=valg.log ./42sh)
valgrinfRes_1=$(cat valg.log | grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)")
valgrinfRes_2=$(cat valg.log | grep "LEAK SUMMARY")
if ([[ $valgrinfRes_1 == "" || !($valgrinfRes_2 == "" )]])
then
    echo -e "\e[31mError dectected in Valgrind for 'ls'\e[39m"
    exit_status=1
else
    echo -e "\e[32mValid Valgrind for echo 'ls'\e[39m"
fi
rm valg.log

returncmd=$(echo 'cd ; ls -all' | valgrind --log-file=valg.log ./42sh)
valgrinfRes_1=$(cat valg.log | grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)")
valgrinfRes_2=$(cat valg.log | grep "LEAK SUMMARY")
if ([[ $valgrinfRes_1 == "" || !($valgrinfRes_2 == "" )]])
then
    echo -e "\e[31mError dectected in Valgrind for 'cd ; ls -all'\e[39m"
    exit_status=1
else
    echo -e "\e[32mValid Valgrind for 'cd ; ls -all'\e[39m"
fi
rm valg.log

returncmd=$(echo './42sh' | valgrind --log-file=valg.log ./42sh)
valgrinfRes_1=$(cat valg.log | grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)")
valgrinfRes_2=$(cat valg.log | grep "LEAK SUMMARY")
if ([[ $valgrinfRes_1 == "" || !($valgrinfRes_2 == "" )]])
then
    echo -e "\e[31mError dectected in Valgrind for './42sh'\e[39m"
    exit_status=1
else
    echo -e "\e[32mValid Valgrind for './42sh'\e[39m"
fi
rm valg.log

returncmd=$(echo 'setenv CACA 1' | valgrind --log-file=valg.log ./42sh)
valgrinfRes_1=$(cat valg.log | grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)")
valgrinfRes_2=$(cat valg.log | grep "LEAK SUMMARY")
if ([[ $valgrinfRes_1 == "" || !($valgrinfRes_2 == "" )]])
then
    echo -e "\e[31mError dectected in Valgrind for 'setenv CACA 1'\e[39m"
    exit_status=1
else
    echo -e "\e[32mValid Valgrind for 'setenv CACA 1'\e[39m"
fi
rm valg.log

returncmd=$(echo 'unsetenv PATH' | valgrind --log-file=valg.log ./42sh)
valgrinfRes_1=$(cat valg.log | grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)")
valgrinfRes_2=$(cat valg.log | grep "LEAK SUMMARY")
if ([[ $valgrinfRes_1 == "" || !($valgrinfRes_2 == "" )]])
then
    echo -e "\e[31mError dectected in Valgrind for 'unsetenv PATH'\e[39m"
    exit_status=1
else
    echo -e "\e[32mValid Valgrind for 'unsetenv PATH'\e[39m"
fi
rm valg.log

returncmd=$(echo 'env' | valgrind --log-file=valg.log ./42sh)
valgrinfRes_1=$(cat valg.log | grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)")
valgrinfRes_2=$(cat valg.log | grep "LEAK SUMMARY")
if ([[ $valgrinfRes_1 == "" || !($valgrinfRes_2 == "" )]])
then
    echo -e "\e[31mError dectected in Valgrind for 'env'\e[39m"
    exit_status=1
else
    echo -e "\e[32mValid Valgrind for 'env'\e[39m"
fi
rm valg.log

returncmd=$(echo 'setenv CACA 1;env; unsetenv CACA' | valgrind --log-file=valg.log ./42sh)
valgrinfRes_1=$(cat valg.log | grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)")
valgrinfRes_2=$(cat valg.log | grep "LEAK SUMMARY")
if ([[ $valgrinfRes_1 == "" || !($valgrinfRes_2 == "" )]])
then
    echo -e "\e[31mError dectected in Valgrind for 'setenv CACA 1;env; unsetenv CACA'\e[39m"
    exit_status=1
else
    echo -e "\e[32mValid Valgrind for 'setenv CACA 1;env; unsetenv CACA'\e[39m"
fi
rm valg.log

returncmd=$(echo 'setenv CACA 1;setenv CACA 1' | valgrind --log-file=valg.log ./42sh)
valgrinfRes_1=$(cat valg.log | grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)")
valgrinfRes_2=$(cat valg.log | grep "LEAK SUMMARY")
if ([[ $valgrinfRes_1 == "" || !($valgrinfRes_2 == "" )]])
then
    echo -e "\e[31mError dectected in Valgrind for 'setenv CACA 1;setenv CACA 1'\e[39m"
    exit_status=1
else
    echo -e "\e[32mValid Valgrind for 'setenv CACA 1;setenv CACA 1'\e[39m"
fi
rm valg.log

returncmd=$(echo 'alias' | valgrind --log-file=valg.log ./42sh)
valgrinfRes_1=$(cat valg.log | grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)")
valgrinfRes_2=$(cat valg.log | grep "LEAK SUMMARY")
if ([[ $valgrinfRes_1 == "" || !($valgrinfRes_2 == "" )]])
then
    echo -e "\e[31mError dectected in Valgrind for 'alias'\e[39m"
    exit_status=1
else
    echo -e "\e[32mValid Valgrind for 'alias'\e[39m"
fi
rm valg.log

returncmd=$(echo "echo $PATH" | valgrind --log-file=valg.log ./42sh)
valgrinfRes_1=$(cat valg.log | grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)")
valgrinfRes_2=$(cat valg.log | grep "LEAK SUMMARY")
if ([[ $valgrinfRes_1 == "" || !($valgrinfRes_2 == "" )]])
then
    echo -e "\e[31mError dectected in Valgrind for 'echo $'PATH''\e[39m"
    exit_status=1
else
    echo -e "\e[32mValid Valgrind for 'echo $'PATH''\e[39m"
fi
rm valg.log

returncmd=$(echo "setenv CACA 1 ; echo $CACA" | valgrind --log-file=valg.log ./42sh)
valgrinfRes_1=$(cat valg.log | grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)")
valgrinfRes_2=$(cat valg.log | grep "LEAK SUMMARY")
if ([[ $valgrinfRes_1 == "" || !($valgrinfRes_2 == "" )]])
then
    echo -e "\e[31mError dectected in Valgrind for 'setenv CACA 1; echo $'CACA''\e[39m"
    exit_status=1
else
    echo -e "\e[32mValid Valgrind for 'setenv CACA 1; echo $'CACA''\e[39m"
fi
rm valg.log

exit $exit_status