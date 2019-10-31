#include<bits/stdc++.h>
using namespace std;

bool isbipartite(vector<vector<int> > vect, int colorarr[], int v, int start )
{
    colorarr[start]=1;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(vect[u][u]==1)
            return false;
        for(int k=0;k<v;k++)
        {
            if(vect[u][k] && colorarr[k]==-1)
            {
                colorarr[k]=1-colorarr[u];
                q.push(k);

            }
            else if(vect[u][k] && colorarr[k]==colorarr[u])
                return false;
        }
    }
    return true;
}
bool correct(vector<vector<int> > vect,int v)
{
    int colorarr[v];
    for(int i=0;i<v;i++)
    {
        colorarr[i]=-1;
    }
    for(int i=0;i<v;i++)
    {
        if(colorarr[i]==-1)
            if(isbipartite(vect,colorarr,v,i)==false)
            return false;
    }
    return true;
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > vect(n, vector<int>(n,0));
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        vect[a-1][b-1]=1;
    }
    correct(vect,n) ? cout<<"Yes" : cout<<"No";
    return 0;
}
