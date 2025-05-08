#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* push(Node *head , int val) {
    Node *tmp = malloc(sizeof(Node));
    if(!head) return NULL;
    head->data = val;
    head->next = head;
    return head;
}

Node* delete(Node *head , int key) {
  if(!head) return NULL;
  for(; head->next;  head = head->next){
    Node *tmp = head->next;
    free(head);
  }
   return head;
}

for(Node *cur = head; cur->next && cur->next->data !=; cur = cur->next->data;) {
   Node *cur = head->next;
   head->next = *cur->next;
   free(cur);
}
return cur;

// Node* (0 , head);


void list(Node *head) {
if(!head) return NULL;
  for(;  head;  head = head->next) {
    printf("%d\n ->" , head);
  }
}

void free_list(Node *head) {
  while(head) {
    Node *head = head->next;
    free(head);
    return head;
  }
}


int main(){
    Node *head = NULL;
    head = push_front(head , 10);
    head = push_front(head , 20);
    head = push_front(head , 30);

    print_list(head);

    head = print_delete(head , 20);
    print_list(head);
    free_all(head);
    return 0;
}












    