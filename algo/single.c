#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 要素をリストの先頭に追加
Node* push_front(Node *head, int value) {
    Node *new_node = malloc(sizeof(Node));
    if (!new_node) return head;
    new_node->data = value;
    new_node->next = head;
    return new_node;
}

// 指定された値を持つノードを削除
Node* delete_node(Node *head, int key) {
    Node dummy = {0, head};
    Node *prev = &dummy;

    while (prev->next && prev->next->data != key) 
        prev = prev->next;

    if (prev->next) { 
        Node *to_delete = prev->next;
        prev->next = to_delete->next;
        free(to_delete);
    } else {
        printf("Key %d not found in list\n", key);
    }

    return dummy.next; 
}

// リストの内容を表示
void print_list(Node *head) {
    for (Node *cur = head; cur; cur = cur->next) {
        printf("%d", cur->data);
        if (cur->next) printf(" -> ");
    }
    printf(" -> NULL\n");
}

// 全ノードのメモリを解放
void free_list(Node *head) {
    while (head) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

// メイン処理
int main() {
    Node *head = NULL;
    head = push_front(head, 10);
    head = push_front(head, 20);
    head = push_front(head, 30);

    print_list(head);                  // 30 -> 20 -> 10 -> NULL
    head = delete_node(head, 20);     // 中間ノードを削除
    print_list(head);                  // 30 -> 10 -> NULL

    free_list(head);
    return 0;
}