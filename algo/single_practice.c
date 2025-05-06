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

// void list(Node *head) {
// if(!head) return NULL;
//   for(;  head;  head = head->next) {
//     printf()
//   }
// }



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












    