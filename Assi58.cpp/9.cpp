// Double linked list data structure 
#include<iostream>
#include<stack>
using namespace std;
class node
{
    public:
    int value;
    node *pre;
    node *next;
    node()
    {
        value = 0;
        pre = NULL;
        next = NULL;
    }

};
class Double_list
{
    node *head;
    public:
    Double_list()
    {
        head = NULL;
    }
    void insert_Element(int v)
    {
        node *temp = new node();
        temp->value =v;
        if(head == NULL)
        {
            head = temp;
        }
        else {
           node *s = head;
           while(s->next!=NULL)
           {
             s= s->next;
           }
           s->next = temp;
           temp->pre = s;
        }
    }
    void Print()
    {
        node *s = head;
        while(s!= NULL)
        {
            cout<<s->value<<" <=> ";
            s = s->next;
        }
    }
    void Reverse()
    {
        stack<int> s;
        node *r=head;
        while(r!=NULL)
        {
            s.push(r->value);
            r=r->next;
        }
        while(!s.empty())
        {
            cout<<s.top()<<" <=> ";
            s.pop();
        }
    }
    
};
int main()
{
    Double_list d;
    d.insert_Element(10);
    d.insert_Element(8);
    d.insert_Element(2);
    d.insert_Element(4);
    // d.insert_Element(15);
    d.Reverse();
    // d.Print();
}