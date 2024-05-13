#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next
}NODE;

NODE* insert_begin(NODE* header,int item)
{
    NODE* start=header->next;

    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->data=item;
    temp->next=start;

    header->next=start;
    return header;

}

NODE* insert_end(NODE* header, int item)
{
    NODE * start=header->next;
    NODE * temp=(NODE*)malloc(sizeof(NODE));
    temp->data=item;
    temp->next=NULL;


    NODE* curr=start;

    while(curr->next !=NULL)
    {
        curr=curr->next;
    }

    curr->next=temp;

    header->next=start;
    return header;

}

NODE* delete_begin(NODE* header)
{
    NODE* start=header->next;

    NODE* temp=start->next;

    printf("%d deleted",start->data);

    header->next=temp;
    free(start);
    return header;
}

NODE* delete_end(NODE* header)
{
    NODE* curr=header->next,*prev=NULL;

    while(curr!=NULL)
    {
        prev=curr;
        curr=curr->next;
    }

    prev->next=NULL;
    return header;

}

NODE* display(NODE* header)
{
    NODE* curr=header->next;

    while(curr!=NULL)
    {
        printf("%d \t",curr->data);
        curr=curr->next;
    }

    return header;
}