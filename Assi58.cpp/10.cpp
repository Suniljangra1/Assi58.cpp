// creating double circular linked list 
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
    void insert(int v)
    {
        node *temp = new node();
        temp->value =v;
        if(head == NULL)
        {
            head= temp;
            temp->pre = temp;
            temp->next =temp;
            
        }
        else {
            node *s = head->pre;
            s->next = temp;
            temp->pre = s;
            head->pre = temp->next;
            head ->pre = temp;

        }
    }

    void Print ()
    {
        node *s = head->pre;
        while(s!=head)
        {
            cout<<s->value<<" <=> ";
            s= s->pre;
        }
        if(s==head)
        {
            cout<<s->value;
        }
    }
   
};

int main()
{
    Double_list l;
    l.insert(7);
    l.insert(9);
    l.insert(6);
    l.insert(34);
    l.Print();
    
}