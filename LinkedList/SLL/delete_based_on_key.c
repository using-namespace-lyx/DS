#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}NODE;

NODE* delete_based_on_key(NODE* start, int key)
{
    if(start==NULL)
    return NULL;

    NODE*temp; 

    if(start->data==key)
    {
        temp=start->next;
        free(start);
        return temp;
    }

    NODE*curr=start,*prev=NULL;

    while(curr!=NULL && curr->data !=key)
    {
        prev=curr;
        curr=curr->next;
    }

    if(curr==NULL)
    printf("\n Key not found ");

    else
    {
        prev->next =curr->next;
        free(curr);


    }

    return start;

    
}

