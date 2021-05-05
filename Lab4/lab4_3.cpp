#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <sched.h>
#define _GNU_SOURCE
#define STACK_SIZE 16553

using namespace std;

static int child(void* args)
{
    char** arg = (char** ) args;
    cout << "ENTERED CHILD PROCESS\n\n";
    execvpe(arg[0], arg, NULL);
    return 5;
	
}
int main(int argc, char* argv[])
{
    char* stack;
    stack = (char*)malloc(STACK_SIZE);
    pid_t parent_pid = getppid();
    pid_t pid = getpid();
    char* arg[] = {(char*)"./lab4_ex",(char*)"p",(char*)"r",(char*)"o",(char*)"g",(char*)"r",(char*)"a",(char*)"m",(char*)"3", nullptr};
    pid_t child_pid = clone(child,stack, SIGCHLD, arg);
    int status;
    while (waitpid(-1, &status, WNOHANG) == 0){
            printf("Подождите...\n");
            usleep(500 * 1000);
        }
    if (WIFEXITED(status))
        printf("Процесс завершился удачно со статусом: %d\n", WEXITSTATUS(status));
    else{
        printf("Процесс завершился неудачно!\n");
		}
	cout << endl;
    cout << "PROGRAM 3 PROCESS ID - " << pid << flush;
    cout << "\nPROGRAM 3 PARENT ID процесса - " << parent_pid << flush;
    cout << "\nPROGRAM 3 CHILD ID процесса - " << child_pid << flush;
    cout << endl;
    return 10;
}