// #include <stdio.h>
// #include <unistd.h>

// int main() {
//     pid_t pid = fork();  // forkしてプロセスを複製！

//     if (pid < 0) {
//         perror("fork failed");  // fork失敗
//         return 1;
//     }

//     if (pid == 0) {
//         // 👶 子プロセス
//         printf("👶 子プロセス: PID = %d\n", getpid());
//     } else {
//         // 👨 親プロセス
//         printf("👨 親プロセス: 子のPID = %d, 自分のPID = %d\n", pid, getpid());
//     }

//     return 0;
// }


#include <stdio.h>
#