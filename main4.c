// Reversing a  linked list through iteration

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *head;

void Print(){
    Node *node = head;

    while(node != NULL){
        printf(" %d", node->data);
        node = node->next;
    }
    printf("\n");
}

void Insert(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }

    Node *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void Reverse(){
    Node *current, *next, *prev;
    current = head;
    prev = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

int main(void){
    head = NULL;
    Insert(2);
    // Insert(4);
    // Insert(6);
    // Insert(8);
    Print();
    Reverse();
    Print();
}
