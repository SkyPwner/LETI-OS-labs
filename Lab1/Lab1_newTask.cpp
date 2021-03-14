#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>

using namespace std;

void* proc1(void*Param){
int *p = (int*)Param;
int* proc1_return = new int (*p * *p);
pthread_exit(proc1_return);

}

int main(){
pthread_t id1;
int param;
cin >> param;

pthread_create (&id1 , NULL , proc1 , (void*)&param);

int* proc1_return;

pthread_join(id1, (void**)&proc1_return);

cout << *proc1_return << endl;

delete(proc1_return);
}
