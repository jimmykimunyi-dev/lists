// Inserting node at the nth position

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *head;

void Insert(int data, int n){
    Node *newNode =(Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty :
    if(n==1){
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;

    // Go to (n-1)th position, We use (n-2) in the loop because indexing starts at 0
    for(int i = 0; i < n-2 ;i++){
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
    Insert(2,1);
    Insert(3,2);
    Insert(4,1);
    Insert(5,2);
    Print();
}