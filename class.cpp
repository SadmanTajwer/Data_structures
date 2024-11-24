#include<iostream>
#include<conio.h>
using namespace std;
class car
{
public:
    string name;
    int year;
    double milage;

};
int main()
{
    car object1;
    object1.name = "bmw";
    object1.year = 1991;
    object1.milage = 34.6;

    cout<< "name : "<< object1.name << "  " << "year : " << object1.year<< "  "<< "Milage : "<< object1.milage<<endl;

    getch();

}

