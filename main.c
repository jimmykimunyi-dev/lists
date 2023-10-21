// Inserting a node at the beginning of the list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head = NULL;

void Insert(int x){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    // temp->next = NULL; // This is used when the head is null

    // Inserting at the beginning
    // Check if the head is null then perform the insert

    // if(head != NULL) temp->next = head; // points to where head is pointing

    // Use : 
    temp->next = head;
    head = temp; // Now head points to the node inserted at the beginning
}
void Print(){
    Node *temp = head; // set it as the addresss of the head node
    printf("List is : ");

    while(temp != NULL){
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");

}
int main(void){
    head = NULL;
    int n, i, x;
    printf("How many numbers : \n");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        printf("Enter a number : \n");
        scanf("%d", &x);
        Insert(x);
        Print();    
    }
}