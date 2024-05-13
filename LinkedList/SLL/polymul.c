#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int coeff;
    int degree;
    struct node *next;

}NODE ;

NODE* insert_end(NODE* start, int c, int d)
{
    NODE* temp=(NODE*)malloc(sizeof(NODE));
    temp->coeff=c;
    temp->degree=d;
    temp->next=NULL;

    if(start==NULL)
    return temp;

    NODE* curr=start;

    while(curr->next!=NULL)
    curr=curr->next;

    curr->next=temp;

    return start;
}

NODE* make_nodes(NODE*start,int c , int d)
{
    NODE * curr=start;

    while(curr!=NULL)
    {
        if(curr->degree==d)
        {
            curr->coeff+=c;
            return start;
        }
        
        curr=curr->next;
    }

    
    start=insert_end(start,c,d);
    return start;
    

}

NODE* multiply(NODE* poly1, NODE*poly2)
{
    NODE* res= NULL,*i,*j;

    for(i=poly1;i!=NULL;i=i->next)
    for(j=poly2;j!=NULL;j=j->next)
    res=make_nodes(res,(i->coeff)*(j->coeff),(i->degree)+(j->degree));

    return res;

}

int main()
{
    NODE *poly1=NULL, *poly2=NULL,*res;

    printf("\nEnter n1,n2:");
    int n1,n2,i,j,c,d;
    scanf("%d%d",&n1,&n2);

    printf("\nPoly1\n");
    for(i=0;i<n1;i++)
    {
        printf("\nEnter c and d:");
        scanf("%d%d",&c,&d);
        poly1=insert_end(poly1,c,d);
    }

    printf("\nPoly2\n");
    for(i=0;i<n2;i++)
    {
        printf("\nEnter c and d:");
        scanf("%d%d",&c,&d);
        poly2=insert_end(poly2,c,d);
    }

    NODE* curr1=poly1,*curr2=poly2;

    while(poly1->next!=NULL)
    {
        printf("%d * (x) ^ %d + ",poly1->coeff,poly1->degree);

        poly1=poly1->next;
    }


     printf("%d * (x) ^ %d \n ",poly1->coeff,poly1->degree);

    while(poly2->next!=NULL)
    {
        printf("%d * (x) ^ %d + ",poly2->coeff,poly2->degree);

        poly2=poly2->next;
    }


     printf("%d * (x) ^ %d \n ",poly2->coeff,poly2->degree);

    res=multiply(curr1,curr2);

    while(res->next!=NULL)
    {
        printf("%d * (x) ^ %d + ",res->coeff,res->degree);

        res=res->next;
    }

     printf("%d * (x) ^ %d  ",res->coeff,res->degree);
}