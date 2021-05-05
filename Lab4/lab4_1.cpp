#include <sys/types.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    pid_t ppid = getppid();
    pid_t pid = getpid();
    for(int i = 1; i < argc; i++)
    {
        cout << argv[i] << flush;
        sleep(1);
    }
    cout << endl;
    cout << "PROGRAM 1 ID процесса - " << pid << endl;
    cout << "PROGRAM 1 PARENT ID процесса - " << ppid << endl;
    return 0;
}
