#include<bits/stdc++.h>
using namespace std;

vector<int> max_of_every_window(vector<int> arr,int k)
{
    vector<int> res;
    int i=0,j=0,n=arr.size();
    multiset<int> q;

    while(j<n)
    {
        q.insert(arr[j]);

        if(j-i+1<k)
        j++;

        if(j-i+1==k)
        {
            res.push_back(*(--q.end()));

            q.erase(q.find(arr[i]));

            i++;
            j++;
            
        }


    }

    return res;
}

//Alternate

vector<int> func (vector<int> arr,int k)
{
    int i=0,j=0,n=arr.size();
    vector<int> res;
    list<int> l;

    while(j<n)
    {
        while(l.size()>0 and l.back()<arr[j])
        l.pop_back();

        l.push_back(arr[j]);

        if(j-i+1<k)
        j++;

        else if(j-i+1==k)
        {
            res.push_back(l.front());

            if(arr[i]==l.front())
            l.pop_front();

            i++;
            j++;
        }
    }

    return res;



}