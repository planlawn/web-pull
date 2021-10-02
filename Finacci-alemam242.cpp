#include<iostream>
using namespace std;
int main()
{
    int first=0,second=1,count=0,fibo,n;
    cout<< "Enter Your Limit: ";
    cin>>n;
    while(count<n)
    {
        if(count<=1)
        {
            fibo=count;
        }
        else
        {
            fibo=first+second;
            first=second;
            second=fibo;
        }
        cout<<fibo<<" ";
    count++;
    }
return 0;
}
