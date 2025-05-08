#include <stdio.h>
#include <stdlib.h>

// ノードの構造定義
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// ノードを先頭に追加する関数
Node *push(Node *head, int val) {
  Node *tmp = malloc(sizeof(Node));
  if (!tmp) {
    perror("malloc failed");
    exit(1);
  }
  tmp->data = val;
  tmp->next = head;
  return tmp;
}

// リストから指定値を削除する関数（最初に見つかった1つだけ）
Node *delete(Node *head, int key) {
  if (!head)
    return NULL;

  Node dummy = {0, head}; // ダミーヘッドを使う
  Node *cur = &dummy;

  while (cur->next && cur->next->data != key) {
    cur = cur->next;
  }

  if (cur->next) {
    Node *tmp = cur->next;
    cur->next = tmp->next;
    free(tmp);
  }

  return dummy.next;
}

// リストを表示する関数
void list(Node *head) {
  for (; head; head = head->next) {
    printf("%d -> ", head->data);
  }
  printf("NULL\n");
}

// リストをすべて解放する関数
void free_list(Node *head) {
  while (head) {
    Node *tmp = head;
    head = head->next;
    free(tmp);
  }
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
  head = delete (head, 20);
  printf("After deleting 20:\n");
  list(head);

  // メモリ解放
  free_list(head);

  return 0;
}
  