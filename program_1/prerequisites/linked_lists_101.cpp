#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void printList(struct Node *n){
    while (n != NULL){
    printf("%d\n",n->data);
    n = n->next;
    }
}

//Program to create a simple linked list with three elements
int main(){
    //std::string base = "n";
    //std::string node_name = base + std::to_string(1);

    struct Node* i = NULL;
    struct Node* n2 = NULL;
    struct Node* n3 = NULL;

    // allocate n3 nodes in the heap
    i = (struct Node*)malloc(sizeof(struct Node));
    n2 = (struct Node*)malloc(sizeof(struct Node));
    n3 = (struct Node*)malloc(sizeof(struct Node));

    i->data = 1;
    i->next = n2;
    n2->data = 2;
    n2->next = n3;
    n3->data = 3;
    n3->next = NULL;

    printList(i);

    return 0;
}


