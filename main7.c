// Doubly linked lists

// Implement InsertAtTail()

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *head;

Node *GetNewNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int data){
    Node *newNode = GetNewNode(data);
    
    if(head == NULL){
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void Print(void){
    struct Node *node = head;
    printf("Forward :");

    while(node != NULL){
        printf(" %d", node->data);
        node = node->next;
    }

    printf("\n");
}

void PrintReverse(){
    // We go to the end of the list and traverse backward

    Node *node = head;

    if(head == NULL) return;

    while(node->next != NULL){
        node = node->next;
    }

    // Traverse back using prev pointer
    printf("Reverse :");

    while(node != NULL){
        printf(" %d", node->data);
        node = node->prev;
    }

    printf("\n");
}

int main(void){
    head = NULL;
    InsertAtHead(2); Print() ; PrintReverse();
    InsertAtHead(4); Print() ; PrintReverse();
    InsertAtHead(6); Print() ; PrintReverse();
    InsertAtHead(8); Print() ; PrintReverse();
}