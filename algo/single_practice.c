#include <stdio.h>
#include <stdlib.h>

// ノードの構造定義
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// ノードを先頭に追加する関数
Node* push(Node *head , int val) {
Node *tmp = malloc(sizeof(Node));
if(!tmp) return NULL;

head->data = val;
head->next = head;
return tmp;
}

// リストから指定値を削除する関数（最初に見つかった1つだけ）
Node* delete(Node *head , int key) {
Node dummy = {0 , head};
Node *cur = &dummy;

if(*cur->next && *cur->next->data !=key) {

}



}
// リストを表示する関数


// リストをすべて解放する関数


int main() {
    Node *head = NULL;

    // 要素追加
    head = push(head, 10);
    head = push(head, 20);
    head = push(head, 30);

    // 表示
    printf("Initial list:\n");
    list(head);

    // 要素削除
    head = delete(head, 20);
    printf("After deleting 20:\n");
    list(head);

    // メモリ解放
    free_list(head);

    return 0;
}