#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}NODE;

NODE* reverse(NODE*start)
{
    NODE *prev,*curr,*temp;

    temp=prev=NULL;
    curr=start;

    while(curr!=NULL)
    {
        temp=prev;
        prev=curr;
        curr=curr->next;
        prev->next=temp;

    }

    return prev;
}