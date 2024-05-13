#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next,*prev;

}NODE;

NODE* insert_begin(NODE*start,int item)
{
    NODE* temp=(NODE*) malloc(sizeof(NODE));
    temp->data=item;
    temp->prev=NULL;

    if(start==NULL)
    {
        temp->next=NULL;
        return temp;
    }

    temp->next=start;
    start->prev=temp;

    return temp;

}

NODE* insert_end(NODE* start,int item)
{
    NODE* temp=(NODE*) malloc(sizeof(NODE));
    temp->data=item;
    temp->next=NULL;

    NODE* curr=start;
    
    if(start==NULL)
    {
        temp->prev=NULL;
        return temp;
    }

    while(curr->next!=NULL)
    curr=curr->next;

    curr->next=temp;
    temp->prev=curr;

    return start;


}

void display_forward(NODE* start)
{
    NODE* curr=start;

    while(curr!=NULL)
    {
        printf("%d",curr->data);
        curr=curr->next;
    }
}

void display_backward(NODE* start)
{
    NODE* curr=start;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }

    while(curr!=NULL)
    {
        printf("%d",curr->data);
        curr=curr->prev;
    }

}

void delete_begin(NODE* start)
{
    if(start==NULL)
    {
        printf("\nEmpty");
        return NULL;
    }

    NODE* temp=start->next;

    temp->prev=NULL;

    printf("%d",start->data);
    free(start);
    return temp;

}

void delete_end(NODE* start)
{
    NODE *curr=start,*previ=NULL;
    while(curr->next!=NULL)
    {
        previ=curr;
        curr=curr->next;
    }

    printf("%d",curr->data);
    previ->next=NULL;

    curr->prev=NULL;
    printf("%d",curr->data);
    free(curr);
    return start;

}