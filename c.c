#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // 👶 子プロセス
        printf("👶 子プロセス: PID = %d\n", getpid());
        return 0;  // 任意の終了コード
    } else {
        // 👨 親プロセス
        int status;
        wait(&status);  // 子の終了を待つ

        if (WIFEXITED(status)) {
            printf("👨 親プロセス: 子は %d で終了\n", WEXITSTATUS(status));
        }
    }

    return 0;
}