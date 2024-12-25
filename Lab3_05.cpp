#include <iostream>
#include <conio.h>
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
int isParenthesis(char x)
{
if (x == '[' || x == ']')
{
return 3;
}
else if (x == '{' || x == '}')
{
return 2;
}
else if (x == '(' || x == ')')
{
return 1;
}
else
return 0;
}
int isOpen(char x)
{
return (x == '[' || x == '{' || x == '(');
}
int main()
{
Stack<char> *s = new Stack<char>;
bool flag = true;
int count1 = 0, count2 = 0, count3 = 0;
string infix;
cin >> infix;
for (int i = 0; i < infix.size(); i++)
{
if (isParenthesis(infix[i]) > 0)
{
if (isOpen(infix[i]))
{
s->push(infix[i]);
if (infix[i] == '(')
count1++;
else if (infix[i] == '{')
count2++;
else if (infix[i] == '[')
count3++;
}
else
{
if (s->Count() == 0)
{
cout << "Closing Parenthesis used without open" <<"Parenthesis\n";
flag = false;
break;
}
else if (isParenthesis(infix[i]) != isParenthesis(s->top()))
{
cout << "Wrong placement of Parenthesis\n";
flag = false;
break;
}
else
{
s->pop();
if (infix[i] == ')')
count1--;
else if (infix[i] == '}')
count2--;
else if (infix[i] == ']')
count3--;
}
}
}
}
if (count1 + count2 + count3 != 0)
{
flag = false;
cout << "Equation ends without closing Parenthesis\n";
}
if (flag == true)
{
cout << "Parenthesis used correctly\n";
}
getch();
}
