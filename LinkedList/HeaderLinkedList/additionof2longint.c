#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE* insert_begin(NODE* header,int item)
{
    NODE* start=header->next;

    NODE* temp=(NODE*)malloc(sizeof(NODE));
    temp->data=item;
    temp->next=start;

    header->next=temp;
    return header;
}

NODE* insert_end(NODE* header, int item)
{
    NODE* curr=header->next;
    NODE* temp=(NODE*)malloc(sizeof(NODE));
    temp->data=item;
    temp->next=NULL;

    while(curr->next!=NULL)
    curr=curr->next;

    curr->next=temp;
    return header;
}

NODE* string_to_reverse_list(char str[])
{
    NODE* header1=NULL;
    for(int i=0;str[i]!='\0';i++)
    header1=insert_begin(header1,str[i]-'0');

    return header1;
}

void add(NODE*h1, NODE*h2)
{
    int count1=0,count2=0;

    NODE* curr=h1->next;
    while(curr!=NULL)
    {
        count1+=1;
        curr=curr->next;
    }

    curr=h2->next;
    while(curr!=NULL)
    {
        count2+=1;
        curr=curr->next;
    }

    if(count1>count2)
    {
        int c=count1-count2;
        while(c)
        {
            h2=insert_end(h2,0);
            c--;
        }
    }

    else
    {
        int c=count2-count1;
        while(c)
        {
            h1=insert_end(h1,0);
            c--;
        }

    }

    int count=count1>count2?count1:count2;
    int item1,item2,sum,s,c=0;
    NODE *curr1=h1,*curr2=h2,*res;

    res=(NODE*)malloc(sizeof(NODE));
    res->next=NULL;

    while(count)
    {
        curr1=curr1->next;
        item1=curr1->data;

        curr2=curr2->next;
        item2=curr2->data;

        sum=c+item1+item2;

        s=sum%10;
        c=s/10;

        res=insert_end(res,s);

        count--;



        

    }

    if(c)
    res=insert_end(res,c);

    NODE* newcurr=res->next;

    while(newcurr!=NULL)
    printf("%d",newcurr->data);



}




