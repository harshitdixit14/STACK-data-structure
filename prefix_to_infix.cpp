#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000
class stack_array{
public:
    //checking comment
    int top;
    int capacity;
    string *array;
};
int isEmpty(stack_array *s1)
{
    if(s1->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(stack_array *s1)
{
    if(s1->top==s1->capacity-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
stack_array* create_stack()
{
    stack_array* S=new stack_array();
    S->capacity=MAXSIZE;
    S->top=-1;
    S->array=(string*)malloc(S->capacity*sizeof(int));
    return S;
}
void push(stack_array *s1,string data)
{
    if(isFull(s1))
    {
        cout<<"STACK OVERFLOW";
    }
    else{
    s1->top++;
    s1->array[s1->top]=data;
    }
}
void pop(stack_array *s1)
{
    if(isEmpty(s1))
    {
        cout<<"STACK EMPTY";
    }
    else
    {
        --s1->top;
    }
}
void traverse(stack_array *s1)
{
    while((s1->top)!=-1)
    {
        cout<<s1->array[s1->top]<<" ";
        --(s1->top);
    }
}
void delete_stack(stack_array *s1)
{
    delete s1->array;
}
string postfix_to_infix(string s)
{
    stack_array *st=create_stack();
    string result="";
    int i=s.length()-1;
    while(i>=0)
    {
        string opr1="",opr2="";
        result="";
        string t="";
        t+=s[i];
        if(s[i]>=65 && s[i]<=90)
        {
            push(st,t);
        }
        else
        {
            opr2=(st->array[st->top]);
            pop(st);
            opr1=(st->array[st->top]);
            pop(st);
            result+=("("+opr2+t+opr1+")");
            push(st,result);
        }
        i--;
    }
    return st->array[st->top];
}
int main()
{
    string s;
    cin>>s;
    cout<<postfix_to_infix(s);
}