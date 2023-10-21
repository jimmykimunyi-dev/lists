// Reversal of linked lists via recursion

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *head;

Node * Insert(Node * head, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }else{

        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newNode;
    }

    return head;
}

void Delete(Node *head,int n){
    Node *node = head;

    for(int i = 0; i < n - 2; i++){
        node = node->next;
    }

    Node *temp = node;
    node = node->next;
    temp->next = node->next;
    free(node);
}

void Print(Node *node){
    // Using recursion

    if(node == NULL) {
        printf("\n");
        return;
        }

    printf(" %d", node->data);
    Print(node->next);
}

void Reverse(Node *node){
    if (node->next == NULL){
        head = node;
        return;
    }

    Reverse(node->next);
    Node *temp = node->next;
    temp->next = node;
    node->next = NULL;
}

void PrintReverse(Node *node){
    if(node == NULL){
        printf("\n");
        return;
    }
    PrintReverse(node->next);
    printf(" %d", node->data);
}

int main(void){
    head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 8);
    Print(head);
    Reverse(head);
    Print(head);
    // PrintReverse(head);
    //     printf("\n");

    // Delete(i);
}