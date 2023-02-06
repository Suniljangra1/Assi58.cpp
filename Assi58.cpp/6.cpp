// creating double circular linked list 
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
    node *head_2;
    public:
    Double_list()
    {
        head = NULL;
        head_2= NULL;
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
        node *s = head;
        while(s->next!=head)
        {
            cout<<s->value<<" <=> ";
            s= s->next;
        }
    }
   
   void insert_2(int v)
    {
        node *temp = new node();
        temp->value =v;
        if(head_2== NULL)
        {
            head_2= temp;
            temp->pre = temp;
            temp->next =temp;
            
        }
        else {
            node *s = head_2->pre;
            s->next = temp;
            temp->pre = s;
            head_2->pre = temp->next;
            head_2->pre = temp;

        }
    }
  
    void Print_2()
    {
        node *s = head_2;
        while(s->next!=head_2)
        {
            cout<<s->value<<" <=> ";
            s= s->next;
        }
    }
    void Equle_()
    {
        node *t = head; 
        node *r = head_2;
        
        if(r == t)
        cout<<"equle";
        else 
        cout<<"not equle ";
    }
};

int main()
{
    Double_list l;
    l.insert(7);
    l.insert(9);
    l.insert(6);
    l.insert(34);
    
    cout<<"\n----------------------------------------------------\n";
    l.insert_2(1);
    l.insert_2(2);
    l.insert_2(3);
    l.insert_2(4);
    l.Equle_();
    // l.Print_2();
}