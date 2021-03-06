#include "libc/sys/syscalls.h"
#include "libc/stdio.h"
#include "libc/string.h"
#include "signals.h"

#define ESC 27
#define TERMINATE 3

#define COL0 0
#define COL1 35

#define WIDTH 33
#define HEIGHT 30

void start_shell(const char** envp)
{
    const char* name = "/bin/shell";
    const char* argv[2];

    argv[0] = name;
    argv[1] = 0;


    sys_execve("/bin/shell", argv, envp);
}
int main(int argc, char** argv, const char** envp)
{
    int fd = sys_open("/dev/tty0", O_RDONLY);
    sys_dup2(fd, 0);
    fd = sys_open("/dev/tty0", O_RDONLY);
    sys_dup2(fd, 1);
    fd = sys_open("/dev/tty0", O_RDONLY);
    sys_dup2(fd, 2);

    /*
    if (argc < 2)
    {
        start_shell();
    }
*/
    sys_execve(argv[1], (const char**)(argv + 1), envp);
}
