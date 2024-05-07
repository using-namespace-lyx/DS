#include <bits/stdc++.h>
using namespace std;
float evaluate(float l,float r, char sym)
{
    switch(sym)
    {
        case '+':
        return l+r;

        case '-':
        return l-r;

        case '*':
        return l*r;

        case '/':
        return l/r;

        case '^':
        return pow(l,r);

        


    }
}
string reverse(string s)
{
    for(int i=0,j=s.size()-1;i<j;i++,j--)
    swap(s[i],s[j]);

    return s;
}
int prefix_eval(string prefix_string)
{
    stack<float> s;
    char sym;
    float l,r,res;
    prefix_string=reverse(prefix_string);
    for(int i=0;i<prefix_string.size();i++)
    {
        sym=prefix_string[i];

        if(isdigit(sym))
        s.push(sym-'0');

        else{

            l=s.top();
            s.pop();
            r=s.top();
            s.pop();

            res=evaluate(l,r,sym);
            s.push(res);




        }
    }

    return s.top();
}

int main()
{
    string a;
    cout<<"Enter prefix:";
    cin>>a;
    cout<<prefix_eval(a);
}
