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
   void Triplets(int x)
    {
        node *t = head;
        node *i,*j,*k;
        for(i=head; i->next!=NULL; i=i->next)
        {
            for(j=i->next; j!=NULL; j= j->next)
            {
                for(k= j->next->next; k!=NULL; k=k->next)
                {
                    if(i->value + j->value + k->value == x)
                    {
                        cout<<i->value<<" <=> "<<j->value<<" <=> "<<k->value<<" <=> ";
                        continue;
                    }
                }
            }
        }
        cout<<"😢 Not Found ";
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
    // d.Print();
    d.Triplets(17);
}
    
    

