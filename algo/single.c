/**
 * @file linked_list.c
 * @brief API駆動型マイクロサービス基盤に適合した、学習・クラウド実装向けリンクリスト構造
 * @details 本コードはFlutter × FastAPI構成やDockerベースCI、マルチクラウド環境との統合を前提にした実務品質実装であり、
 * Doxygen対応・静的解析・抽象データ型・ログ・テスト容易性に重点を置いています。
 

 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>
 #include <errno.h>
 #include <string.h>
 
 // ---------------- ログ分類と標準化 ---------------- //
 #define LOG_INFO(...)   fprintf(stdout,  "[INFO]  " __VA_ARGS__)
 #define LOG_ERROR(...)  fprintf(stderr, "[ERROR] " __VA_ARGS__)
 
 // ---------------- データ構造定義 ---------------- //
 
 /**
  * @struct Node
  * @brief 単方向リンクリストのノード（内部専用）
  */
 typedef struct Node {
     int data;
     struct Node *next;
 } Node;
 
 /**
  * @struct LinkedList
  * @brief ADTとしてのリンクリスト構造体。外部公開インターフェース
  */
 typedef struct {
     Node *head;
     size_t size;
 } LinkedList;
 
 // ---------------- 関数インターフェース群 ---------------- //
 
 /**
  * @brief リストの初期化
  */
 void list_init(LinkedList *list) {
     list->head = NULL;
     list->size = 0;
 }
 
 /**
  * @brief 要素を先頭に追加
  */
 void list_push_front(LinkedList *list, int value) {
     Node *new_node = (Node *)malloc(sizeof(Node));
     if (!new_node) {
         LOG_ERROR("malloc failed: %s\n", strerror(errno));
         return;
     }
     new_node->data = value;
     new_node->next = list->head;
     list->head = new_node;
     list->size++;
     LOG_INFO("Pushed: %d (size: %zu)\n", value, list->size);
 }
 
 /**
  * @brief 指定した値のノードを削除
  */
 void list_delete(LinkedList *list, int key) {
     Node dummy = {0, list->head};
     Node *prev = &dummy;
 
     while (prev->next && prev->next->data != key) {
         prev = prev->next;
     }
 
     if (prev->next) {
         Node *target = prev->next;
         prev->next = target->next;
         free(target);
         list->head = dummy.next;
         list->size--;
         LOG_INFO("Deleted: %d (size: %zu)\n", key, list->size);
     } else {
         LOG_INFO("Key not found: %d\n", key);
     }
 }
 
 /**
  * @brief リスト内容の表示
  */
 void list_print(const LinkedList *list) {
     const Node *cur = list->head;
     printf("[LIST] ");
     while (cur) {
         printf("%d", cur->data);
         if (cur->next) printf(" -> ");
         cur = cur->next;
     }
     printf(" -> NULL\n");
 }
 
 /**
  * @brief 全ノードのメモリ解放
  */
 void list_free_all(LinkedList *list) {
     Node *cur = list->head;
     while (cur) {
         Node *tmp = cur;
         cur = cur->next;
         free(tmp);
     }
     list->head = NULL;
     list->size = 0;
     LOG_INFO("All nodes freed\n");
 }
 
 // ---------------- ユニットテスト ---------------- //
 
 /**
  * @brief CI/CDやDocker環境での自動テスト実行
  */
 void run_tests(void) {
     LinkedList list;
     list_init(&list);
 
     list_push_front(&list, 10);
     list_push_front(&list, 20);
     list_push_front(&list, 30);
     assert(list.size == 3);
     list_print(&list);
 
     list_delete(&list, 20);
     assert(list.size == 2);
 
     list_delete(&list, 99);
     assert(list.size == 2);
 
     list_free_all(&list);
     assert(list.size == 0);
 }
 
 // ---------------- エントリーポイント ---------------- //
 
 int main(int argc, char **argv) {
     LOG_INFO("Starting linked list test...\n");
     run_tests();
     LOG_INFO("All tests passed.\n");
     return EXIT_SUCCESS;
 }
 