//Author: Ridwan Rafi
//github: https://github.com/Ridwan-Rafi
#include<iostream>
using namespace std;

int ar[10000000];
void prm()
{
    for(int i=0;i<=10000000;i++)
    {
        ar[i]=0;
    }
    ar[1]=ar[0]=1;
    for(int i=2;i<=10000;i++)
    {
        if(ar[i]==0)
        {
            for(int j=i+i;j<=10000000;j+=i)ar[j]=1;
        }
    }
}

int main()
{
int n,f;
long long int arr[4],c;
prm();
    while(cin>>n)
    {
    arr[1]=arr[2]=1;
    f=0;
        for(int i=1;i<=n;i++)
        {

        if(i>2)
        {
            if(f==0)
            {
                    c=arr[1]+arr[2];

                if(ar[c]==0 || c%5==0)
                cout<<0<<' ';
                else
                cout<<c<<' ';
                arr[1]=c;
               // printf("c %d %d\n",arr[1],arr[2]);
                f=1;
            }
            else{
            c=arr[1]+arr[2];

                if(ar[c]==0 || c%5==0)
                cout<<0<<' ';
                else
                cout<<c<<' ';

                arr[2]=c;
                 //printf("d %d %d\n",arr[1],arr[2]);
                f=0;
            }

        }
        else
            cout<<arr[i]<<' ';
        }
    }
}
