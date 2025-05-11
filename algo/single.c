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

    while (prev->next && prev->next->data != key) //while (prev->next)のprev＝dummyである。
        prev = prev->next;
//while , if文のprev = ローカル変数同士であるため、prevの値はwhileとif文同士で継承しない
    if (prev->next) {                 //＝20の値の処理
        Node *to_delete = prev->next; //＝20の値の処理
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

void free_all(Node *head) {
    while(head){
      Node *cur = head;
      head = head->next;
      free(cur);
       
    }
}
// メイン処理
int main() {
    Node *head = NULL;
    head = push_front(head, 10);
    head = push_front(head, 20);
    head = push_front(head, 30);

    head = delete_node(head, 20);
    print_list(head);                  // 30 -> 20 -> 10 -> NULL
    print_list(head);                  // 30 -> 10 -> NULL

    free_list(head);
    return 0;
}