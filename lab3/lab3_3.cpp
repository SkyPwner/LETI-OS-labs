#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>

using namespace std;

constexpr size_t BUFF_SIZE = 32;

int flag1 = 0; // объявление флагов завершения потоков
int flag2 = 0; 
int field[2];

void* proc1(void* nothing) {
    string buffer;
    int divisionNum = 1;
    
    while (flag1 != 1){
        buffer.clear();
        buffer += "98 " + to_string(divisionNum) + " 94";
        write(field[1], buffer.c_str(), strlen(buffer.c_str())+1);
        if (strlen(buffer.c_str()) >= BUFF_SIZE)
            cerr << "Сообщение больше буфера! Память может быть повреждена!\n";
        divisionNum++;
        sleep(2);
    }

    return NULL;
}

void* proc2(void* nothing) {
    char buffer[BUFF_SIZE] = {'\0'};

    while (flag2 != 1){
        memset(buffer, '\0', BUFF_SIZE);
        int value = read(field[0], buffer, BUFF_SIZE);
        if (value == -1)
            cout << "Нет сообщения!" << endl;
        else
            cout << buffer << endl;
        sleep(2);
    }
    return NULL;
}

int main(){
    pthread_t id1; // Объявление идентификатора для потоков
    pthread_t id2; 

    pipe(field); // Создание канала
    fcntl(field[0], F_SETFL, O_NONBLOCK);
    fcntl(field[1], F_SETFL, O_NONBLOCK);

    pthread_create (&id1 , NULL , proc1 , NULL); // Создание потоков
    pthread_create (&id2 , NULL , proc2 , NULL); 

    getchar();
    
    flag1 = 1; // Установка флага завершения для потоков
    flag2 = 1; 

    pthread_join(id1, NULL); // Ожидание завершения потоков
    pthread_join(id2, NULL); 

    close(field[0]);
    close(field[1]);
}
