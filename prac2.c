// Inserting a node ant nth position
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *head;

void InsertAtHead(int data){
    // Insert at head
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void InsertAtEnd(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty
    if(head == NULL){
        head = newNode;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    // At this point temp->next == NULL
    temp->next = newNode;
}

void InsertAt(int data, int n){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(n==1){
        // We set the next to point to where head is pointing at
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    // Since indexing starts at 0, (n-1)th element is located at index (n-1)
    for(int i = 0; i < n-2; i++){
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

void Print(){
    Node *temp = head;
    while(temp != NULL){
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(void){
    head = NULL;
    InsertAt(34,1); //2
    InsertAt(78,2); //4
    InsertAt(22,2); //3
    InsertAt(99,1); //1
    Print();
    InsertAtHead(676);
    InsertAtHead(567);
    InsertAtHead(789);
    InsertAtHead(334);
    Print();
    InsertAtEnd(1234);
    InsertAtEnd(2345);
    InsertAtEnd(7987);
    InsertAtEnd(7786);
    Print();
}
