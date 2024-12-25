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
Node<T> *temp = head; cout << temp->data; while (temp->next != NULL)
{
cout << temp->next->data;
temp = temp->next;
}
}
else
return NULL;
}
};
int opPres(char x)
{
if (x == '^')
{
return 3;
}
else if (x == '*' || x == '/')
{
return 2;
}
else if (x == '-' || x == '+')
{
return 1;
}
else
return 0;
}
int main()
{
Stack<char> *s = new Stack<char>;
string infix;
cin >> infix;
for (int i = 0; i < infix.size(); i++)
{
if ((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z'))
{
cout << infix[i];
}
else
{
if (s->Count() == 0)
{
s->push(infix[i]);
}
else
{
if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
{
s->push(infix[i]);
}
else if (infix[i] == ')')
{
while (s->top() != '(')
{
cout << s->pop();
}
s->pop();
}
else if (infix[i] == '}')
{
while (s->top() != '{')
{
cout << s->pop();
}
s->pop();
}
else if (infix[i] == ']')
{
while (s->top() != '[')
{
cout << s->pop();
}
s->pop();
}
else
{
if (opPres(infix[i]) > opPres(s->top()))
{
s->push(infix[i]);
}
else
{
while (opPres(infix[i]) <= opPres(s->top()) &&
s->Count() != 0 &&
opPres(infix[i]) > 0)
{
cout << s->pop();
}
s->push(infix[i]);
}
}
}
}
}
while (s->Count())
{
cout << s->pop();
}
}
