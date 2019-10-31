#include<bits/stdc++.h>
using namespace std;

bool isbipartite(vector<int> vect[], int colorarr[], int v, int start )
{
    colorarr[start]=1;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int k=0;k<vect[u].size();k++)
        {
            if(colorarr[vect[u][k]]==-1)
            {
                colorarr[vect[u][k]]=1-colorarr[u];
                q.push(vect[u][k]);

            }
            else if(colorarr[vect[u][k]]==colorarr[u])
                return false;
        }
    }
    return true;
}
bool correct(vector<int> vect[],int v)
{
    int colorarr[v];
    for(int i=0;i<=v;i++)
    {
        colorarr[i]=-1;

    }

    for(int i=0;i<=v;i++)
    {
        if(colorarr[i]==-1)
            if(isbipartite(vect,colorarr,v,i)==false)
                {  return false;}

    }
    return true;
}


int main()
{
    int n,m;
    cin>>n>>m;
    int pseudo=n+1;
    int pseudo_count=0;
    vector <int> G[2*n];

    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        if(w%2==1)
        {
            G[a-1].push_back(b-1);
            G[b-1].push_back(a-1);
        }
        else
        {
            G[a-1].push_back(pseudo);
            G[pseudo].push_back(b-1);
            G[pseudo].push_back(a-1);
            G[b-1].push_back(pseudo);
            pseudo++;
            pseudo_count++;

        }

    }
    correct(G,n+pseudo_count) ? cout<<"NO" : cout<<"YES";
    return 0;

}
