#include<iostream>
using namespace std;
class node
{
    public:
    int id;
    int age;
};
int main()
{
    node c;
    cout<< "Enter Customers id"<<endl;
    cin>>c.id;
    cout <<"Enter customer age"<<endl;
    cin>>c.age;
    if(c.age>60)
    {
        cout<<"They are unemployed cityzen"<<endl;
    }
}
