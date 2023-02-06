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
    void Convert()
    {
        node *s = head;
        while(s->next!=NULL)
        {
            s= s->next;
        }
        s->next = head->pre;
        head->pre = s;
    }
    void Print_1()
    {
        node *s = head;
        while(s->next!=head)
        {
            cout<<s->value<<" <=> ";
            s = s->next;
        }
    }
};
int main()
{
    Double_list d;
    d.insert_Element(1);
    d.insert_Element(2);
    d.insert_Element(3);
    d.insert_Element(4);
    d.insert_Element(5);
    d.insert_Element(6);
    d.insert_Element(7);
    d.insert_Element(8);
    d.insert_Element(9);
    d.Convert();
    d.Print_1();
}
    
    

