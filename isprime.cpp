#include<bits/stdc++.h>

using namespace std;

int main()
{   int z;
    cin>>z;
    string arr[z];
    for(int j=0;j<z;j++)
    {int x=0;
    long long int n;
    cin>>n;
    int k=sqrt(n);
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) {
        arr[j]="not a prime";
        x=1;
        break;

    }
    else continue;
    }
    if(x==0) arr[j]="prime";}
    for(int i=0;i<z;i++)
    {
        cout<<arr[i]<<'\n';
    }
        return 0;


}
