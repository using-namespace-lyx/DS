#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE ;

NODE * insert_ordered(NODE * start, int item)
{
    NODE* temp=(NODE*)malloc(sizeof(NODE));
    temp->data=item;
    temp->next=NULL;

    if(start==NULL)
    return temp;

    if(item<=start->data)
    {
        temp->next=start;
        return temp;
    }

    NODE *curr=start,*prev=NULL;
    while(curr!=NULL && curr->data<item)
    {
        prev=curr;
        curr=curr->next;
    }

    prev->next=temp;
    temp->next=curr;

    return start;
}
