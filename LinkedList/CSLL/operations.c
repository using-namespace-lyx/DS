#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}NODE;

NODE * insert_begin(NODE *last, int item)
{
    NODE * temp=(NODE*)malloc(sizeof(NODE));
    temp->data =item;

    if(last==NULL)
    {
        temp->next=temp;
        return temp;
    }
    temp->next=last->next;
    last->next=temp;
    return last;
}

NODE * insert_end(NODE *last , int item)
{
    NODE * temp=(NODE*)malloc(sizeof(NODE));
    temp->data=item;

    if(last==NULL)
    {
        temp->next=temp;
        return temp;
    }

    temp->next=last->next;
    last->next=temp;

    return temp;
}

NODE* delete_begin(NODE* last)
{
    if(last==NULL)
    return NULL;

    if(last->next==last)
    {
        printf("%d deleted",last->data);
        free(last);
        return NULL;

    }

    NODE* temp=last->next;
    last->next = temp->next;
    printf("%d deleted",temp->data);
    free(temp);
    return last;
}

NODE* delete_end(NODE* last)
{
    if(last==NULL)
    return NULL;

    if(last->next==last)
    {
        printf("%D deleted",last->data);
        return NULL;
    }

    NODE* curr=last->next;
    while(curr->next !=last)
    curr=curr->next;

    curr->next=last->next;
    printf("%d deleted", last->data);
    free(last);
    return(curr);

}

NODE* display(NODE* last)
{
    if(last==NULL)
    printf("\nNothing to display");

    else
    {
        NODE* curr=last->next;
        while(curr!=last)
        {
            printf("%d\t",curr->data);
            curr=curr->next;
        }

        printf("%d\n",curr->data);

    }
    
}
