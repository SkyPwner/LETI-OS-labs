g++ lab4_1.cpp -Wall -o lab4_ex
g++ lab4_2.cpp -Wall -o lab4_2
g++ lab4_3.cpp -Wall -o lab4_3
echo "Fork example"
./lab4_ex 1 2 3
echo "Fork example"
./lab4_2 1 2 3 4
echo "Clone example"
./lab4_3 9 8 9 4 
rm lab4_ex lab4_2 lab4_3
