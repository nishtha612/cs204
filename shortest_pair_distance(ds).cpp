#include<bits/stdc++.h>
using namespace std;
#define INF 99999

int main()
{
   /* long long int m;long long int n;
    cin>>n>>m;*/
    int n=4;
    
    long long int arr[n][n]={ {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
  ;
    /*for(long long int i=0;i<n;i++)
    {
        for(long long int j=0;j<n;j++)
        {
            arr[i][j]=999999;
        }
    }*/
    /*for(long long int i=0;i<m;i++)
    {
        long long int a,b;
        cin>>a>>b;
        long long int weight;
        cin>>weight;
        arr[a-1][b-1]=weight;
        
    }*/
    
    
    long long int dist[n][n];
    for(long long int i=0;i<n;i++)
    {
        for(long long int j=0;j<n;j++)
        {
            dist[i][j]=arr[i][j];
            
        }
    }
    
    for(long long int k=0;k<n;k++)
    {
        for(long long int i=0;i<n;i++)
        {
            for(long long int j=0;j<n;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }


    for(long long int j=0;j<n;j++)
    {for(long long int i=0;i<n;i++)
    {
      cout<<dist[j][i]<<" ";
    }cout<<"\n";}
    return 0;
}

