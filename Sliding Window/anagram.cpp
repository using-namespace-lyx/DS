#include<bits/stdc++.h>
using namespace std;

int anagram(string text, string pattern)
{
    int i=0,j=0,n=text.size(),k=pattern.size(),count,ans=0;
    unordered_map<char,int> map;

    for (auto chr:pattern)
    map[chr]++;

    count=map.size();

    while(j<n)
    {
        if(map.find(text[j])!=map.end())
        {
            map[text[j]]--;

            if(map[text[j]]==0)
            count--;
        }

        if(j-i+1<k)
        j++;

        else if(j-i+1==k)
        {
            if(count==0)
            {
                ans++;

            }

            if(map.find(text[i])!=map.end())
            {
                map[text[i]]++;

                if(map[text[i]]==1)
                count++;
            }

            i++;
            j++;
        }


    }

    return ans;
}