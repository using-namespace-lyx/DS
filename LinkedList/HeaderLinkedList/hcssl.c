#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}NODE;

NODE* insert_begin(NODE* header, int item)
{
    NODE* temp=(NODE*)malloc(sizeof(NODE));
    temp->next=item;

    if(header->next==NULL)
    {
        temp->next=header;
        return header;
    }

    NODE* start= header->next;
    header->next = temp;
    temp->next=start;

    return header;
}

NODE* insert_end(NODE* header, int item)
{
    NODE*curr= header->next;
    NODE* temp=(NODE*)malloc(sizeof(NODE));
    temp->data=item;


    while(curr->next !=header)
    {
        curr=curr->next;
    }

    curr->next=temp;
    temp->next=header;

    return header;

}

NODE* delete_begin(NODE* header)
{
    NODE* start=header->next;

    if(start->next == header )
    {
        free(start);
        header->next=header;
    }

    free(start);
    header->next=start->next;
    return header;

}

NODE * delete_end(NODE* header)
{
    NODE* curr=header,*prev=NULL;



    while(curr->next!=header)
    {
        prev=curr;
        curr=curr->next;

    }

    free(curr);
    prev->next=header;

    return header;
}