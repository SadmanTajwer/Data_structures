#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int num1, num2, sum,i;
    char name[100];
    cout << "Enter the first number :  " <<endl;
    cin >> num1;
    cout << "Enter the second number : "  << endl;
    cin >> num2;
    cout << "Enter your name: "<< endl;
    cin >> name;
    cout << "First number is:"<<  num1 << endl;
    cout << "Second NUmber is:"<< num2<< endl;
    sum = num1 + num2;
    cout << "Total number is :" << sum;
    cout << "Welcome:" << name<< endl;

    getch();
}
