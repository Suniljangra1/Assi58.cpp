// creating double circular linked list 
#include<iostream>
using namespace std;
int count=0;
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
        count++;
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
       cout<<"\nNomber of node is "<<count<<endl;
        while(s->next!=head)
        {
            cout<<s->value<<" <=> ";
            s= s->next;
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
    // l.insert_Begin(95);
    // l.insert_Begin(89);
    // l.Delete_Midle(3);
    // l.search(95);
    l.Print();
}