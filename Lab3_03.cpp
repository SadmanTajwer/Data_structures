/*Write a program that reverses the contents of a stack (the top and bottom elements exchange
positions, the second and the element just before the bottom exchange positions, and so forth
until the entire stack is reversed). (Hint: Use temporary stacks.)*/

#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
T	data; Node *next; Node(T data)
{
this->data = data; next = NULL;
}
};
template <typename T>
#define MAX 1000
class Stack
{
public:
Node<T> *head = NULL;
Node<T> *newdata = NULL;
int count = 0;
void push(T item)
{
newdata = new Node<T>(item);
if (head == NULL)
{
head = newdata;
}
else
{
Node<T> *temp = head;
head = newdata;
newdata->next = temp;
}
count++;
}
T	pop()
{
if (count > 0)
{
Node<T> *temp = head->next;
T popOut = head->data;
delete head;
head = temp;
count--;
return popOut;
}
else
{
cout << "Stack is empty" << endl;
}
}
int Count()
{
return count;
}
T	top()
{
if (head != NULL)
return head->data;
else
return NULL;
}
T	allData()
{
if (head != NULL)
{
Node<T> *temp = head;
cout << temp->data;
while (temp->next != NULL)
{
cout << temp->next->data;
temp = temp->next;
}
}
else
return NULL;
}
};
int main()
{
Stack<int> *sourceStack = new Stack<int>;
Stack<int> *tempStack = new Stack<int>;
Stack<int> *copyStack = new Stack<int>;
int data;
cout << "Enter data to copy\nPress 0 for exit" << endl;
while (true)
{
cin >> data;
if (data == 0)
break;
sourceStack->push(data);
}
cout << "\nTemporary stack:";
while (sourceStack->Count())
{
data = sourceStack->pop();
tempStack->push(data);
cout << data << " ";
}
cout << "\nCopied stack:";
while (tempStack->Count())
{
data = tempStack->pop();
copyStack->push(data);
cout << data << " ";
}
}

