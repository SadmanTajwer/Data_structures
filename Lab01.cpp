#include <iostream>

using namespace std;
int multiply(int digit)
{
    int lastFirst=digit%10;
    int lastSecond=((digit%100)-lastFirst)/10;
    return lastFirst*lastSecond;
}
int recursiveFunction(int apple)
{
    if(apple>42)
    {
        if(apple%5==0)
        {
            return recursiveFunction(apple-42);
        }
       if((apple%3==0)||(apple%4==0))
        {
            return recursiveFunction(apple-multiply(apple));
        }
        if(apple%2!=0)
        {
            return recursiveFunction(apple-(apple/2));
        }
    }
    else
        return apple;
}

int main()
{
    cout<<"Input The Apple Number: ";
    int appleNo;
    cin>>appleNo;
    int result=recursiveFunction(appleNo);
    if(result==42)cout<<"Taker WIN";else cout<<"Giver Win";
    return 0;
}
