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
int postfix_eval(string postfix_string)
{
    stack<float> s;
    char sym;
    float l,r,res;
    for(int i=0;i<postfix_string.size();i++)
    {
        sym=postfix_string[i];

        if(isdigit(sym))
        s.push(sym-'0');

        else{

            r=s.top();
            s.pop();
            l=s.top();
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
    cout<<"Enter postfix:";
    cin>>a;
    cout<<postfix_eval(a);
}
