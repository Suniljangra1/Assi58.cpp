#include<iostream>
using namespace std;
class node
{
    public:
    int value;
    node *next;
    node()
    {
        value = 0;
        next = NULL;
    }

};
class Circular_list
{
    node *head;
    public:
    Circular_list()
    {
        head = NULL;
    }
    void insert(int v)
    {
        node *temp = new node();
        temp->value = v;
        if( head== NULL)
        {
            head = temp;
            temp->next = head;
        }
        else {
            node *s= head;
             while(s->next!=head)
             {
                s= s->next;
             }
             s->next = temp;
             temp->next = head;
        }
    }
    int  Search(int v)
    {
        int c= 0;
        node *s= head;
        while(s->next!=head)
        {
            c++;
            if(s->value == v)
            break;
            s=s->next;
        }
        return c;
    }
    void Delete_node(int v)
    {
        node *s = head;
        int n= Search(v);
        if(n == 1)
        {
           
            while(s->next!=head)
            {
                s=s->next;
            }
             head= head->next;
            s->next =head;
        }
        else {
            while(n>1)
            {
               n--;
               if(s->next!=head)
                s=s->next;
            }
           s->next=s->next->next;

        }
    }
    void Print()
    {
        node *s = head;
        while(s->next!=head)
        {
            cout<<s->value<<" <-> ";
            s=s->next;
        }
        if (s->next==head)
        cout<<s->value;
    }
    void Delete_ODD()
    {
        node *s= head;
        while(s->next != head)
        {
            if(s->value % 2 !=0 )
            Delete_node(s->value);
            s=s->next;
        }
    }
};
int main()
{
    Circular_list c;
    c.insert(5);
    c.insert(9);
    c.insert(7);
    c.insert(4);
    c.insert(2);
    c.Delete_ODD();
    c.Print();
}