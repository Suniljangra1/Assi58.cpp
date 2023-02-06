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
        node *s = head;
        while(s->next!=head)
        {
            cout<<s->value<<" <=> ";
            s= s->next;
        }
    }
    void insert_Begin(int v)
    {
        node *temp = new node();
        temp->value = v;
        if(head == NULL)
        {
            head= temp;
            temp->pre = temp;
            temp->next =temp;
            
        }
        else {
            node *s = head->pre;
            temp->next= head;
            head->pre = temp;
            s->next=temp->pre;
            temp->pre=s;
            head = temp;
        }
    }
    // void insert_middle(int v,int n)
    // {
    //     node *temp = new node();
    //     temp->value = v;
    //     if(n==1)
    //     insert_Begin(v);
    //     else {
    //         node *s = head;
    //         while(n>2)
    //         {
    //             n--;
    //             if(s->next!=head)
    //             s = s->next;
    //             else 
    //             {
    //                 cout << "position not found ";
    //                 return;
    //             }
    //             if(s == head)
    //             {
    //                 insert(v);
    //             }
    //         }
    //         temp->next = s->next;
    //         s->next = temp;
    //         temp->pre = s;
    //         s = temp;
    //     }
    // }
    void Delete_Midle(int n)
    {
        node *temp = head;
        if (n==1)
        {
          head = head->next;
          head->pre = temp->pre;
          temp->pre->next= head;   
          delete temp;
        }
        else {
            while(n>2)
            {
                n--; 
                if(temp->next!=head)
                temp=temp->next;
                else {
                    cout<<"position not found ";
                }
            }
            temp = temp->next;
             temp->pre->next=temp->next;
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
    
    l.Delete_Midle(3);
    l.Print();
   
    
}