#include<bits/stdc++.h>
using namespace std;

vector<int> first_negative_in_every_window(int k,vector<int> arr)
{
    vector<int> res;
    int i=0,j=0,n=arr.size();

    while(j<n)
    {
        

        while(j-i+1<k and arr[j]>=0)
        {
            j++;
        }

        if(arr[j]<0)
        {
            res.push_back(arr[j]);
            i++;
            j=i;
        }

        else
        {
            res.push_back(0);
            i++;
            j++;
        }
    }

    return res;
}

vector<int> brute_force_first_negative(vector<int> arr, int k)
{
    int i,j,max=INT_MIN,n=arr.size();
    vector<int> res;

    for(i=0;i<=n-k;i++)
    {
        

        for(j=i;j<i+k;j++)
        {
            if(arr[j]<0)
            {
                res.push_back(arr[j]);
                break;
            }

        }

        if(j==i+k)
        res.push_back(0);
    }

    return res;
}