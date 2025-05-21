// oshinoko_init.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void aqua() {
    printf("👦 アクア（子プロセス）[PID=%d]: 芸能界、もう俺やめるわ...\n", getpid());
    exit(42);  // 終了コード42で引退（exit）
}

void ruby() {
    printf("👧 ルビー（子プロセス）[PID=%d]: 私はアイドルとして輝くわ！\n", getpid());
    while (1) {
        sleep(1);  // 永遠に活動（orphan体験用）
    }
}

int main() {
    printf("👩 星野アイ（init）[PID=%d]: 子供たちよ、頑張っておいで〜！\n", getpid());

    pid_t aqua_pid = fork();
    if (aqua_pid == 0) {
        aqua();  // アクア誕生（子プロセス①）
    }

    pid_t ruby_pid = fork();
    if (ruby_pid == 0) {
        ruby();  // ルビー誕生（子プロセス②）
    }

    // アクアの終了を見届ける
    int status;
    waitpid(aqua_pid, &status, 0);
    printf("👩 星野アイ: アクアの芸能活動が終わったわ。終了コード: %d\n", WEXITSTATUS(status));

    printf("👩 星野アイ: 私は引退するね...（exit）\n");
    exit(0);  // アイ終了 → ルビーがorphanになる
}