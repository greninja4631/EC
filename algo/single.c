#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// ノードをリストの先頭に追加
Node* push_front(Node *head, int val) {
    Node *new_node = malloc(sizeof(Node));
    if (!new_node) return head;
    new_node->data = val;
    new_node->next = head;
    return new_node;
}

// 値が key のノードを削除（ダミーノード方式ですべて cur->next で統一）
Node* delete_node(Node *head, int key) {
    if (!head) return NULL;

    Node dummy = {0, head};    // data は 0（使わない）、next に本当の先頭をつなぐ
    Node *cur = &dummy;      // これで cur->next が常に本物の head になる

    while (cur->next && cur->next->data != key)
        cur = cur->next;

    if (cur->next) {
        Node *to_delete = cur->next;
        cur->next = to_delete->next;
        free(to_delete);
    }

    return dummy.next;
}

// リスト全体を出力
void print_list(Node *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    puts("NULL");
}

// 全ノードを解放
void free_all(Node *head) {
    while (head) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

int main() {
    Node *head = NULL;
    head = push_front(head, 10);
    head = push_front(head, 20);
    head = push_front(head, 30);  // 30 -> 20 -> 10

    print_list(head);             // 出力：30 -> 20 -> 10 -> NULL

    head = delete_node(head, 20); // 中間ノード削除（ダミーノード方式）
    print_list(head);             // 出力：30 -> 10 -> NULL

    free_all(head);
    return 0;
}