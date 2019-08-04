#include<bits/stdc++.h>
using namespace std;


int main()
{   int n;
    cin>>n;
    string arr[n];
    for(int q=0;q<n;q++)
    {string s1;
    string s2;
    cin>>s1>>s2;
    int n1=s1.length();
    int n2=s2.length();
    int x,y;

     if(n1==n2)
    {
        for(int i=0;i<n1;i++)
        {
            if(s1[i]>s2[i])
            { x=1;
            break;}
            else if(s1[i]<s2[i])
            {x=0;
            break;}
            else continue;


        }
    }

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    if(n1>=n2 && x )
    {
        int carry=0;
        string diff="";
        for(int i=0;i<n2;i++)
        {
            int total=(s1[i]-'0')-(s2[i]-'0')-carry;
            if(total<0) {total=total+10;
            carry=1;}
            else carry=0;
            diff.push_back(total+'0');

        }


        for(int i=n2;i<n1;i++)
        {   int total= (s1[i]-'0')-carry;
            carry=0;
            if(total<0) total=total+10;
            diff.push_back(total+'0');
        }
        reverse(diff.begin(), diff.end());
           arr[q]=diff;
    }
    else if(n2>=n1 )
    {

        int carry=0;
        string diff="";
        for(int i=0;i<n1;i++)
        {
            int total=(s2[i]-'0')-(s1[i]-'0')-carry;
            if(total<0) {total=total+10;
            carry=1;}
            else carry=0;
            diff.push_back(total+'0');

        }

        for(int i=n1;i<n2;i++)
        {   int total= (s2[i]-'0')-carry;
            carry=0;
            if(total<0) total=total+10;
            diff.push_back(total+'0');

        }
        diff.push_back('-');

        reverse(diff.begin(), diff.end());

           arr[q]=diff;
    }}
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<'\n';
    }

    return 0;
}
