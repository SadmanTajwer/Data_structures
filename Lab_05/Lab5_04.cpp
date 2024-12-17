//Write a program to delete n-th node of a given linked list using recursion.
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
   Node* next;
};

Node* deleteNode(Node* start, int k)
{

    if (k < 1)
       return start;


    if (start == NULL)
       return NULL;


    if (k == 1)
    {
        Node *res = start->next;
        delete(start);
        return res;
    }

    start->next = deleteNode(start->next, k-1);
    return start;
}

void push( Node **head_ref, int new_data)
{
    Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}


void printList( Node *head)
{
    while (head!=NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<("\n");
}


int main()
{
  Node *head = NULL;

    push(&head,18);
    push(&head,53);
    push(&head,57);
    push(&head,2);
    push(&head,6);


    int k = 3;
    head = deleteNode(head, k);

   cout<<("\nModified Linked List: ");
    printList(head);

    return 0;
}
