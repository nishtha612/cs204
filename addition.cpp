#include<bits/stdc++.h>

using namespace std;

int main()
{   int n;
    cin>>n;
    string arr[n];
    for(int k=0;k<n;k++)
    {string s1;
    string s2;
    cin>>s1>>s2;
    int n1=s1.length();
    int n2=s2.length();
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());

    if(n1>=n2)
    {
        string str="";
        int carry=0;
        for(int i=0;i<n2;i++)
        {
            int sum=(s1[i]-'0')+(s2[i]-'0')+ carry;
            str.push_back(sum%10 +'0');
            carry=sum/10;
        }
        for(int i=n2;i<n1;i++)
        {
            int sum=(s1[i]-'0')+carry;
            str.push_back(sum%10 +'0');
            carry =sum/10;
        }
        if(carry)
            str.push_back(carry+'0');
        reverse(str.begin(),str.end());

        arr[k]=str;
    }

     if(n2>n1)
    {
        string str="";
        int carry=0;
        for(int i=0;i<n1;i++)
        {
            int sum=(s1[i]-'0')+(s2[i]-'0')+ carry;
            str.push_back(sum%10 +'0');
            carry=sum/10;
        }
        for(int i=n1;i<n2;i++)
        {
            int sum=(s2[i]-'0')+carry;
            str.push_back(sum%10 +'0');
            carry =sum/10;
        }
        if(carry)
            str.push_back(carry+'0');
        reverse(str.begin(),str.end());

        arr[k]=str;
    }}
    for(int k=0;k<n;k++)
    {
        cout<<arr[k]<<'\n';
    }

    return 0;
}
