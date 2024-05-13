#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}NODE;

NODE* delete_based_on_pos(NODE* start, int k)
{
    if(start==NULL)
    return NULL;

    NODE *prev=NULL,*curr=start;
    if(k==1)
    {
        printf("\nItem %d deleted",start->data);
        free(start);
        return NULL;
        
    }
    int pos=1;



    while(curr!=NULL && pos!=k)
    {
        prev=curr;
        curr=curr->next;
        pos+=1;
    }

    if(curr==NULL)
    {
        printf("\nPosition not found");
        return start;
    }
    else
    {
        prev->next=curr->next;
        printf("\n Item %d deleted", curr->data);
        free(curr);
        return start;
    }
}