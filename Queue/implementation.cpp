#include<bits/stdc++.h>
using namespace std;
#define SIZE 5

class queue
{
    int data[SIZE];
    int f;
    int r;

    void enqueue(int item)
    {
        if(r==SIZE-1)
        {
            cout<<"Overflow";
            return;
        }

        r=r+1;
        data[r]=item;

        if(f==-1)
        f=0;

        return;
    }


    int dequeue()
    {
        if(f==-1)
        return INT_MIN;

        int item=data[f];

        if(f==r)
        f=r=0;

        else
        f=f+1;

        return item;
    }

    void display()
    {
        for(int i=r;i<=f;i++)
        cout<<data[i]<<"\t";
    }
};