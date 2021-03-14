#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>

using namespace std;

void* proc1(void * argFlag1){
    int *fl1 = (int*)argFlag1;

    while( *fl1 != 1 ){
        cout << "1" << flush;
        sleep (2);
    }

    int* proc1_return = new int(98); 
    pthread_exit(proc1_return); 
}

void* proc2(void * argFlag2){
    int *fl2 = (int*)argFlag2;

    while( *fl2 != 1 ){
        cout << "2" << flush;
        sleep (2);
    }

    int* proc2_return = new int (94); 
    pthread_exit(proc2_return); 
}

int main(){
    pthread_t id1; // Объявление идентификатора потоков
    pthread_t id2;  

    int flag1 = 0; // объявление флагов потоков
    int flag2 = 0; 

    pthread_create (&id1 , NULL , proc1 , (void*)&flag1); // Создание потока (Идентификатор, структура данных, имя функции, указатель)
    sleep(1);
    pthread_create (&id2 , NULL , proc2 , (void*)&flag2); // Null - атрибуты по умолчанию)

    getchar(); //Ожидание нажатия клавиши

    flag1 = 1; // Установка флага завершения потоков
    flag2 = 1; 

    int* proc1_return; // Объявление переменной для данных потоков
    int* proc2_return; 

    pthread_join(id1, (void**)&proc1_return); // Ожидание завершения потока
    pthread_join(id2, (void**)&proc2_return); 

    cout << *proc1_return << endl; // Вывод кодов завершения потоков
    cout << *proc2_return << endl; 

    delete(proc1_return);
    delete(proc2_return);
}
