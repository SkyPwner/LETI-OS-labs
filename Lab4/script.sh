g++ lab4_1.cpp -Wall -o lab4_ex
g++ lab4_2.cpp -Wall -o lab4_2
g++ lab4_3.cpp -Wall -o lab4_3
RED='\033[0;31m'
NC='\033[0m'
echo "\033[0;31m\t Fork example \033[0m"
./lab4_ex 1 2 3
echo "\n\n\033[0;31m\t Clone example \033[0m"
./lab4_2 1 2 3 4
rm lab4_ex lab4_2 lab4_3