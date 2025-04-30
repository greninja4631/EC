#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;











int main() {
    Node *head = NULL;
    head = push(head, 10);
    head = push(head, 20);
    head = push(head, 30);

    print_list(head);

    head = delete_node(head, 20);
    print_list(head);
    
    free_all(head);
    return 0;
}
