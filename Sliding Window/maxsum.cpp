#include<bits/stdc++.h>
using namespace std;
int maximum(int a,int b)
{
    return a>b?a:b;
}
int maxwindowsum(int k, vector<int> arr)
{
    int sum=0,i=0,j=0,max=INT_MIN,n=arr.size();

    while(j<n)
    {
        sum+=arr[j];
        if(j-i+1<k)
        {
            
            j++;
        }

        if(j-i+1==k)
        {
            max=maximum(sum,max);
            sum-=arr[i];
            i++;
            j++;
        }

    }

    return max;

}

int brute_force_max_sum(vector<int> arr, int k)
{
    int i,j,max=INT_MIN,sum=0,n=arr.size();

    for(i=0;i<=n-k;i++)
    {
        sum=0;

        for(j=i;j<i+k;j++)
        {
            sum+=arr[j];

        }

        if(sum>max)
        max=sum;
    }

    return max;
}