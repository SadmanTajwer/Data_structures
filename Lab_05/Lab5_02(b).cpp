#include <iostream>
using namespace std;

void PrintReverseOrder(int n)
{
cout << "Output is ";
{

    for (int i = 1; i <= n; i++)
        cout  << i << " ";

}
}
int main()
{
    int n;
    cout<<"Enter a Number: "<< endl ;
    cin>> n;

    PrintReverseOrder(n);

    return 0;
}
