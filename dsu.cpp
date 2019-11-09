#include<bits/stdc++.h>
using namespace std;

int root (int Arr[ ] ,int i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ;
        i = Arr[ i ];
    }
return i;
}
void weighted_union(int Arr[ ],int size[ ],int A,int B)
{
    int root_A = root(Arr,A);
    int root_B = root(Arr,B);
    if(size[root_A] < size[root_B])
    {
      Arr[ root_A ] = Arr[root_B];
      size[root_B] += size[root_A];
    }
    else
    {
      Arr[ root_B ] = Arr[root_A];
      size[root_A] += size[root_B];
    }

}

bool find(int arr[],int A,int B)
{
    if( root(arr,A)==root(arr,B) )
    return true;
    else
    return false;
}

int main()
{
   int arr[10];
   for(int i=0;i<10;i++)
   {
       arr[i]=i;
   }
   int size[10];
   for(int i=0;i<10;i++)
   {
       size[i]=1;
   }
   weighted_union(arr,size,8,9);
   weighted_union(arr,size,7,4);
   weighted_union(arr,size,4,5);
   weighted_union(arr,size,8,1);
   weighted_union(arr,size,4,8);
   cout<<find(arr,8,9)<<endl;
   cout<<find(arr,7,5)<<endl;
   cout<<find(arr,1,2)<<endl;
   cout<<find(arr,9,4)<<endl;
   return 0;

}

