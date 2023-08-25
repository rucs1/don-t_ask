#include<bits/stdc++.h>
using namespace std;
bool isoperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
    return true;
    else 
    return false;
}
int precedence(char c)
{
    if(c=='^') return 3;
    else if(c=='+'||c=='-')
    return 1;
    else if(c=='*'||c=='/')
    return 2;
    else return -1;
}
string intopost(stack<char>stack,string in)

{
    string postfix;
    for(int i=0;i<in.size();i++)
    {
        if(in[i]>='a'&& in[i]<='z'||in[i]>='A'&&in[i]<='Z')
        {
            postfix+=in[i];
        }
        else if(in[i]=='(' )
        {
            stack.push(in[i]); 
        }
        else if(in[i]==')' )
        {
            while((!stack.empty())&&(stack.top()!='(')) 
            {
                char temp=stack.top();
                postfix+=temp;
                stack.pop();
            }
        }
        else if(isoperator(in[i]))
        {
            if(stack.empty())
            {
                stack.push(in[i]);
            }
            else
            {
                if(precedence(in[i])>precedence(stack.top()))
                {
                    stack.push(in[i]);
                }
                else if((precedence(in[i])==precedence(stack.top()))&& in[i]=='^')
                {
                    stack.push(in[i]);
                }
                else
                {
                    while((!stack.empty())&&precedence(in[i])<=precedence(stack.top()))
                    {
                        char temp = stack.top();
                        postfix+=temp;
                        stack.pop();
                    }
                }
            }
        }
    }
    return postfix;
}

int main()
{
    string in,post ;
    cin>>in;
    stack<char>s;
    post=intopost(s,in);
    cout<<endl<<"postfix expression:"<<post;
}