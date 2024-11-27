#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node*next;
    node(int d){
    data=d;
    next=NULL;
    }
};
void insertatbegining(node*&head, int data){
    node*n= new node(data);
    n->next=head;
    head=n;
}
void display(node*head)
{
    while(head!=NULL){
        cout<<head->next<<"->";
        head=head->next;
    }
}
int main()
{
    node*head=NULL;
        insertatbegining(head, 4);
         insertatbegining(head, 5);
        display(head);
}
