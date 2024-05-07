#include<bits/stdc++.h>
using namespace std;

int preced(char c)
{
    switch(c)
    {
        case '+':
        case '-':
        return 1;

        case '*':
        case '/':
        return 2;

        case '^':
        return 3;
    }
}

string reverse(string a)
{
    for(int i=0,j=a.size()-1;i<j;i++,j--)
    swap(a[i],a[j]);

    return a;
}
string infix_to_postfix(string a)
{
    a=reverse(a);

    for(int i=0;i<a.size();i++)
    {if(a[i]=='(')
    a[i]=')';

    else if (a[i]==')')
    a[i]='(';
}

    string b{};
    char sym,temp;
    stack<char> s;

    for(int i=0;i<a.size();i++)
    {
        sym=a[i];

        
            if(sym=='(')
            s.push(sym);
            

            else if (sym ==')')
            {
            temp=s.top();
            s.pop();
            while(temp!='(')
            {
                b+=temp;
                temp=s.top();
                s.pop();
                
            }
            }
            

    
        

            else if(isalnum(sym))
            {
                b+=sym;
            }

            else
            {
                if( s.empty() or s.top()=='(' )
                    s.push(sym);

                else
                {
                    while (!s.empty() and preced(s.top()) >= preced(sym))
                    {
                        b+=s.top();
                        s.pop();
                    }
                    s.push(sym);
                }

               
            }
     }

      while(!s.empty())
                {
                    b+=s.top();
                    s.pop();
                }


     return reverse(b);

}

int main()
{
    string a;
    cout<<"Enter string:";
    cin>>a;
    cout<<"\n"<<infix_to_postfix(a);
}