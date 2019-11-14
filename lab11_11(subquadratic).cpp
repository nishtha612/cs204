#include<bits/stdc++.h>
using namespace std;

int main()
{   int n;
    cin>>n;
    int flag=0;
    unordered_map<string, int> mmap;
    for(int i=0;i<n;i++)
    {string word;
    cin>>word;
    
    string copy=word;
    reverse(word.begin(), word.end());
    if(copy!=word)
    {
        if(mmap.find(copy)==mmap.end())
        {
            mmap.insert({word,1});
        }
        else
        {
          flag=1;
        }
    }}
    if(flag==1) cout<<"yes";
    else cout<<"no";
    return 0;
}