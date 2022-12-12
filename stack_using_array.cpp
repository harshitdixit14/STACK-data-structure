#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 10
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
int main()
{
    stack_array *s1=create_stack();
    push(s1,23);
    push(s1,45);
    push(s1,54);
    push(s1,67);
    push(s1,56);
    push(s1,33);
    push(s1,98);
    push(s1,76);
    push(s1,99);
    push(s1,11);
    pop(s1);
    traverse(s1);
}