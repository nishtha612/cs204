#include<bits/stdc++.h>
using namespace std;

int root(int x, int id[])
{
     while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void uni(int x,int y,int id[])
{
    int p=root(x,id);
    int q=root(y,id);
    id[p]=id[q];
}

long long kruskal( pair<long long, pair<int,int> > p[], int m,int id[])
{
    long long int mincost=0;
    for(int i=0;i<m;i++)
    {
        if(root(p[i].second.first,id)!=root(p[i].second.second,id))
        {
            mincost=mincost+p[i].first;
            uni(p[i].second.first,p[i].second.second,id);
        }
    }
    return mincost;
}

int main()
{
    int m,n;
    cin>>n>>m;
    int id[n];
    pair<long long, pair<int,int> > p[m];
    for(int i=0;i<n;i++)
    {
        id[i]=i;
    }
    for(int i=0;i<m;i++)
    {
      int x,y;
      long long int weight;
      cin>>x>>y>>weight;
      p[i]=make_pair(weight,make_pair(x-1,y-1));
      
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

