#include<bits/stdc++.h>
using namespace std;
struct NODE
{
    int value;
    NODE* next;
    NODE*prev;

};

NODE* reverse(NODE* head)
{
    NODE* last=NULL,*curr=head;
    while(curr!=NULL)
    {
        last=curr->prev;
        curr->prev=curr->next;
        curr->next=last;

        curr=curr->prev;
    }

    return last!=NULL?last->prev:head;
    
    
}