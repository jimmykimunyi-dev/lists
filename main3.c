// Deleting a node at nth position

// On your own time implement a delete for value n
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *head ;

void Print(){
    Node *temp = head;
    while(temp != NULL){
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");

}

void Delete(int n){
    Node *node = head;

    // if(n==1){
    //     head = node->next;
    //     free(node);
    //     return;
    // }
    
    for(int i = 0;i < n - 2; i++){ // go to the n-1 element, which is at index n-2
        node = node->next;
    }

    Node *temp = node;   
    node = node->next;
    temp->next = node->next;
    node->next = NULL;
    free(node);
}

void Insert(int data){
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

int main(void){
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(8);
    Print();

    int n;
    printf("Enter a position n : ");
    scanf("%d", &n);
    Delete(n);
    Print();
}