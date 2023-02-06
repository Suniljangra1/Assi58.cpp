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
    void insert_Begin(int v)
    {
        node *temp = new node();
        temp->value =v;
        if(head == NULL)
        head = temp;
        else {
            node *s= head;
            temp->next = s;
            s->pre =temp->next;
            head = temp;
        }
    }
    void insert_Middle(int v,int n)
    {
        node *temp = new node();
        temp->value = v;
        if(n==1)
        insert_Begin(v);
        else {
            node *s = head;
            while(n>1)
            {
                n--; 
                if(s->next!=NULL)
                s= s->next;
                else 
                {
                    cout<<"position not found \n";
                    return ;
                }
            }
            if(s->next!=NULL)
            s->next->pre = temp;
            temp->next = s->next;
            temp->pre = s;
            s->next =temp;
        }
    }

    void Delete_middle(int n)
    {
        node *temp = head;
        if(n == 1)
        {
            temp= temp->next;
            temp->pre = NULL;
            head = temp;
        }
        else {
            while(n>1)
            {
                n--;
                if(temp->next!=NULL)
                temp = temp->next;
                else
                {
                    cout<<"position not found ";
                    return;
                }
            }
            
            temp->pre->next= temp->next;
            temp->next = temp->pre;
            cout<<"deleted "<<temp->value<<endl;
        }
    }
    void search(int v)
    {
        node *r = head;
        while(r->next!=NULL)
        {
            if(r->value== v)
            {
                cout<<"value founded ";
                return;
            }
            r= r->next;
        }
        cout<<"value not found ";
    }
    void large()
    {
        node *s= head;
        int lr=0;
        while(s->next!=NULL)
        {
            if(s->value > s->next->value)
            lr = s->value;
            else 
            lr = s->next->value;
            s=s->next;
        }   
        cout<<"\nlarge element is -> "<<lr;
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
    d.large();
    // d.insert_Middle(50,3);
    // d.Delete_middle(6);
    // d.search(90);
    // d.Print();
}