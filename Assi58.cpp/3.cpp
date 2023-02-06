// Double linked list data structure 
#include<iostream>
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
    void Find_circular()
    {
        if(head->pre==NULL)
        cout<<"Not Circular list";
        else 
        cout<<"Yes it is Circular list ";
    }
    
};
int main()
{
    Double_list d;
    d.insert_Element(9);
    d.insert_Element(7);
    d.insert_Element(3);
    d.insert_Element(6);
    d.insert_Element(15);
    d.Find_circular();
    d.Print();
}