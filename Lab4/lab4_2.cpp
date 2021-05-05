#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[],char** envp)
{
    pid_t parent_pid = getppid();
    pid_t pid = getpid();
    pid_t child_pid = fork();
    int status;
   
    char* arg[] = {(char*)"./lab4_ex",(char*)"p",(char*)"r",(char*)"o",(char*)"g",(char*)"r",(char*)"a",(char*)"m",(char*)"2", nullptr};
    if(child_pid == 0)
    {
        cout << "ENTERED CHILD PROCESS\n";

        execvpe(arg[0], arg, envp);
    }
	else{
		while (waitpid(-1, &status, WNOHANG) == 0){
            printf("Подождите...\n");
            usleep(500 * 1000);
        }
        if (WIFEXITED(status))
            printf("Процесс завершился удачно со статусом: %d\n", WEXITSTATUS(status));
        else{
            printf("Процесс завершился неудачно!\n");
		}
	}
    cout << endl;
    cout << "Program 2 ID процесса - " << pid << endl;
    cout << "Program 2 PARENT ID процесса - " << parent_pid << endl;
    cout << "Program 2 CHILD ID процесса - " << child_pid << endl;
    return 10;
}