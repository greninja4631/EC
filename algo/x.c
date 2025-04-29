#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node*  push_front(Node *head , int val) {
    Node *new = malloc(sizeof(Node));
    if(new == NULL) {
        printf("returnで値を返せえないので、if文の処理終了です");
    }
    new->data = val;
    new->next = head;
    return new;
} 

void print_list(Node *head) {
for(; head; head = head->next)
   printf("%d ->", head->data);
puts(NULL);
}

Node* print_delete(Node *head , int key) {
    if(head == NULL) {
        printf("値が入っていないため、処理終了です。");
    }

if (head->data == key) {
    Node *tmp = head->next;
    free(head);        // ← 本当に削除したいのは head
    return tmp;        // ← 次のノードを新しい head にする
}

for(Node *cur = head; cur != NULL &&  cur->next != NULL; cur = cur->next){
     if(cur->next->data == key) {
        Node *tmp = cur->next;
        cur->next = tmp->next;
        free(tmp);
        break;
     }
}

    return head;
}
    
void free_all(Node *head) {
    while(head){
      Node *tmp = head;
       head = head->next;
       free (tmp);
       break;
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












    