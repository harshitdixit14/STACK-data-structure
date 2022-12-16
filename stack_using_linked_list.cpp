#include <bits/stdc++.h>
using namespace std;
//stack implementation by linked list uses SLL
class linked_list_stack{
    public:
        int data;
        linked_list_stack *next;
};
void push(linked_list_stack **top,int item)
{
    linked_list_stack *p=new linked_list_stack();
    p->data=item;
    if(*top==NULL)
    {
        *top=p;
        p->next=NULL;
    }
    else
    {
        p->next=*top;
        *top=p;
    }
}
void pop(linked_list_stack **top)
{
    linked_list_stack *temp;
    temp=*top;
    *top=(*top)->next;
    delete temp;
}
void traverse(linked_list_stack *top)
{
    linked_list_stack *temp;
    while(top!=NULL)
    {
        temp=top;
        cout<<top->data<<" ";
        top=top->next;
        delete temp;
    }
}
int main()
{
    linked_list_stack *top=nullptr;
    push(&top,10);
    push(&top,34);
    push(&top,4);
    push(&top,76);
    push(&top,8);
    pop(&top);
    traverse(top);
}