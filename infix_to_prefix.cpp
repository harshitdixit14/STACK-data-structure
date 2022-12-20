#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000
class stack_array{
public:
    int top;
    int capacity;
    int *array;
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
    S->array=(int*)malloc(S->capacity*sizeof(int));
    return S;
}
void push(stack_array *s1,int data)
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
int prec(char a)
{
    if(a=='^')
    {
        return 3;
    }
    if(a=='/' || a=='*')
    {
        return 2;
    }
    if(a=='+' || a=='-')
    {
        return 1;
    }
    return 0;
}
string infix_to_prefix(string s)
{
    reverse(s.begin(),s.end());
    stack_array *s1=create_stack();
    int i=0;
    string result="";
    while(i<s.length())
    {
        if(s[i]==')')
        {
            push(s1,s[i]);
        }
        else if(s[i]>=65 && s[i]<=90)
        {
            result+=s[i];
        }
        else if(s[i]==')')
        {
            while(s1->array[s1->top]!='(')
            {
                result+=s1->array[s1->top];
                pop(s1);
            }
            pop(s1);
        }
        else
        {
            if(s1->top==-1 || s1->array[s1->top]==')')
            {
                push(s1,s[i]);
            }
            else if((prec(s[i])>=prec(s1->array[s1->top]) && s1->top!=-1)||(s1->array[s1->top]==')'))
            {
                push(s1,s[i]);
            }
            else
            {
                while(prec(s[i])<prec(s1->array[s1->top]))
                {
                    result+=s1->array[s1->top];
                    pop(s1);
                }
                push(s1,s[i]);
            }
        }
        i++;
    }
    while(s1->top!=-1)
    {
        result+=s1->array[s1->top];
        pop(s1);
    }
    reverse(result.begin(),result.end());
    return result;
}
int main()
{
    string s;
    cin>>s;
    cout<<infix_to_prefix(s);
    //(a+(b/c)*(d^e)-f)
}