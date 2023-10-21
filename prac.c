// Inserting a node at the beginning
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *head = NULL;

void Insert(int a){
    Node *temp =(Node *) malloc(sizeof(Node));
    temp->data = a;
    temp->next = head;
    head = temp;
}

void PrintList(void){
    Node *temp = head;
    printf("List is : ");
    while(temp !=NULL){
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(void){
    int len, a;
    printf("Enter the number of nodes : ");
    scanf("%d", &len);

    for(int i = 0; i < len; i++){
        printf("Enter a number : ");
        scanf("%d", &a);
        Insert(a);
    }
    
    PrintList();
}