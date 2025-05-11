#include <stdio.h>
#include <stdlib.h>

// ノードの構造定義
typedef struct Node {
    int data;
    struct Node *next;
} Node;


Node *push(Node *head , int val) {
Node *point = malloc(sizeof(Node));
if(!point) return NULL;

point->data = val;
point->next = head;
return point;
}
  
Node *delete(Node *head , int key) {

Node dummy = {0 , head};
Node *cur = &dummy;

while(cur->next && cur->next->data !=key) {
 cur = cur->next;


if(cur->next) {
  Node *point = cur->next;
  cur->next = *point->next;
  free(point);

}
return dummy.next;

} 
}

void list(Node *head) {
for(Node *cur = head; head; cur =head->next) {
  printf("%d\n ->" cur->data);
  if(cur->next) printf(" -> ");
}
printf("-> NULL\n");
}

free_all(Node *head) {

}

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