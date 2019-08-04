
#include<bits/stdc++.h>
using namespace std;


string findDiff(string str1, string str2)
{



	string str = "";

	int n1 = str1.length(), n2 = str2.length();


	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;
	if(n1>=n2)
{

	for (int i=0; i<n2; i++)
	{


		int sub = ((str1[i]-'0')-(str2[i]-'0')-carry);


		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}


	for (int i=n2; i<n1; i++)
	{
		int sub = ((str1[i]-'0') - carry);


		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}


	reverse(str.begin(), str.end());

	return str;}
	if(n2>n1)
    {for (int i=0; i<n1; i++)
	{


		int sub = ((str2[i]-'0')-(str1[i]-'0')-carry);


		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}


	for (int i=n1; i<n2; i++)
	{
		int sub = ((str2[i]-'0') - carry);


		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

    str.push_back('-');
	reverse(str.begin(), str.end());

	return str;}

}


int compare(string st1, string st2)
{
    int n1=st1.length();
    int n2=st2.length();
    int x;


    if(n1>n2)
    {
        reverse(st2.begin(),st2.end());
        for(int i=0;i<n1-n2;i++)
        {
            st2.push_back('0');
        }
        reverse(st2.begin(),st2.end());
    }
    n2=st2.length();

    if(n2>n1)
    {
        reverse(st1.begin(),st1.end());
        for(int i=0;i<n2-n1;i++)
        {
            st1.push_back('0');
        }
        reverse(st1.begin(),st1.end());
    }
    n1=st1.length();


    for(int i=0;i<n1;i++)
    {
        if(st1[i]>st2[i])
            {
                x=1;
                break;

        }
        else if(st2[i]>st1[i]){
            x=2;
            break;
        }
        else if(st1[i]==st2[i] && i==n1-1)
            return 1;

        else
            continue;

    }
    return x;

}
int main()
{   int n;

    cin>>n;
    string arr1[n];
    string arr2[n];
    for(int h=0;h<n;h++)
    {string s1;
    string s2;
    cin>>s1>>s2;
    string s="";
    string quo="";
    int n1=s1.length();
    int n2=s2.length();
    if(n2>n1)
       {
        arr1[h]='0';
        arr2[h]=s1;}

    else{

    for(int i=0;i<n2;i++)
    {
        s.push_back(s1[i]);
    }
    int j=0;

    if(s<s2) {
        s.push_back(s1[n2]);
        j=1;
    }

    while(n2+j<=n1){
    int q=0;

    while(compare(s,s2)==1)
    {
        s= findDiff(s,s2);
        q++;

    }

    quo.push_back(q+'0');

    if(n2==n1)
        break;

    s.push_back(s1[n2+j]);


    j++;

    } }
    arr1[h]=quo;
    arr2[h]=s;}

    for(int i=0;i<n;i++)
        cout<<arr1[i]<<'\n'<<arr2[i]<<'\n';

    return 0;}

