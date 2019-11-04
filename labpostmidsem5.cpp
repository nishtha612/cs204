#include<bits/stdc++.h>
using namespace std;

long long int root(long long int x,long long int id[])
{
     while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void uni(long long int x,long long int y,long long int id[])
{
    long long int p=root(x,id);
    long long int q=root(y,id);
    id[p]=id[q];
}

long long kruskal( pair<long long int ,pair<long long int,long long int> > p[], long long int m,long long int id[])
{
    long long int  maxcost=1;
    for(long long int i=0;i<m;i++)
    {
        if(root(p[i].second.first,id)!=root(p[i].second.second,id))
        {
            maxcost=maxcost*p[i].first;
            uni(p[i].second.first,p[i].second.second,id);
        }
    }
        if(maxcost<0)
            return -maxcost%(1000000000+7);
        else
            return maxcost%(1000000000+7);
    
}

int main()
{
    long long int m,n;
    cin>>n>>m;
    long long int id[n];
    pair<long long int , pair<long long int,long long int> > p[m];
    
    for(long long int i=0;i<n;i++)
    {
        id[i]=i;
    }
    for(long long int i=0;i<m;i++)
    {
      long long int x,y;
      long long int weight;
      cin>>x>>y>>weight;
      long long int k=(-1)*(weight);
      p[i]=make_pair(k,make_pair(x-1,y-1));
     
      
    }
    sort(p,p+m);
    cout<<kruskal(p,m,id);
    return 0;
}
/*que
Given a weighted undirected graph. Find the sum of weights of edges of a Minimum Spanning Tree.
input
no of verices
no of edges m
m lines containing vertices joining edges and weights
ouput 
sum of edges weight in mst
sample input output
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6

output 19*/
