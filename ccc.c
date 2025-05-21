#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

// 割り込み用フラグ
volatile bool interrupt_flag = false;

// デバイスの入力をエミュレート（割り込み処理用）
void* emulate_device_input(void* arg) {
    int sleep_time = rand() % 5 + 1;
    sleep(sleep_time);
    interrupt_flag = true;
    printf("[デバイス割り込み] ボタンが押されました！\n");
    return NULL;
}

// ポーリング方式の例
void polling_example() {
    interrupt_flag = false;
    printf("\n=== ポーリング方式 ===\n");
    for (int i = 0; i < 10; i++) {
        printf("CPU：デバイス準備できた？\n");
        usleep(500000);
        if (interrupt_flag) {
            printf("CPU：お、準備できてるな。処理するで！\n");
            return;
        }
    }
    printf("CPU：時間切れ、準備できてないようやな。\n");
}

// 割り込み方式の例
void interrupt_example() {
    interrupt_flag = false;
    pthread_t thread;

    printf("\n=== 割り込み方式 ===\n");
    printf("CPU：ほな他の仕事しとくわ。準備できたら呼んでや！\n");

    pthread_create(&thread, NULL, emulate_device_input, NULL);

    while (!interrupt_flag) {
        printf("CPU：仕事中...(他の処理)\n");
        sleep(1);
    }

    printf("CPU：おっ、通知きた！処理開始や！\n");
    pthread_join(thread, NULL);
}

// DMA風の例
void dma_example() {
    printf("\n=== DMA（風）処理 ===\n");
    printf("CPU：ポケモンにボール出してもらって、バッグにしまう命令出すで！\n");
    printf("DMA：OK！データを直接バッグに転送するわ（CPUはヒマ）\n");
    sleep(1);
    printf("バッグ：アイテムを受け取ったで！\n");
}

// 仮想メモリ風の例
char* memory_pages[3];

void access_virtual_memory(int page) {
    printf("\n=== 仮想メモリアクセス: ページ %d ===\n", page);
    if (memory_pages[page] == NULL) {
        printf("ページフォールト発生！ディスクから読み込み中...\n");
        sleep(1);
        memory_pages[page] = malloc(64);
        snprintf(memory_pages[page], 64, "ディスクから読み込んだデータ (page %d)", page);
    }
    printf("アクセス成功: %s\n", memory_pages[page]);
}

int main() {
    srand((unsigned int)time(NULL));

    // 基本I/Oの例
    printf("Hello, world!\n");
    int r = rand() % 10;
    printf("ポケモンの出現番号: %d\n", r);

    // ポーリング方式
    polling_example();

    // 割り込み方式
    interrupt_example();

    // DMA風の処理
    dma_example();

    // 仮想メモリアクセス
    memory_pages[0] = "ピカチュウのステータス";
    memory_pages[1] = "ヒトカゲの技リスト";
    memory_pages[2] = NULL;  // 初期状態はスワップアウト風

    access_virtual_memory(1);
    access_virtual_memory(2);  // 存在しなかったページ → スワップIN風

    // メモリ解放
    free(memory_pages[2]);

    return 0;
}
