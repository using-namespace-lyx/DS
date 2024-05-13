#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE* insert_begin(NODE* start, int item)
{
    
        NODE* temp=(NODE*)malloc(sizeof(NODE));
        temp->data=item;
        
        
        if(start==NULL)
        {
            temp->next=NULL;
            return temp;
        }

        else
        {
            temp->next=start;
            return temp;

        }
    
}

NODE* insert_end( NODE* start,int item)
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->data = item;
    temp->next=NULL;

    if(start==NULL)
    return temp;

    NODE*curr=start;

    while(curr->next != NULL)
    curr=curr->next;

    curr->next =temp;

    return start;
}

NODE* delete_begin(NODE*start)
{
    if(start==NULL)
    {
        printf("\nList empty.Nothing to delete");
        return NULL;
    }

    printf("\nItem deleted is %d",start->data);

    NODE* temp=start->next;
    free(start);
    return temp;


}

NODE* delete_end(NODE* start)
{
    if(start==NULL)
    {
        printf("\nList empty.Nothing to delete");
        return NULL;
    }

    NODE* curr=start,*prev=NULL;

    while(curr->next!=NULL)
    {
        prev=curr;
        curr=curr->next;
    }

    printf("\n %d deleted", curr->data);
    if(start->next==NULL)
    return NULL;

    
    prev->next=NULL;

    free(curr);

    return start;


}