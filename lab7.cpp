#include<bits/stdc++.h>
using namespace std;


int Compare(string q, string r) 
{ 
   
   return (q+r).compare(r+q) > 0 ? 1: 0; 
} 
  


void swap(string* a, string* b)  
{  
    string t = *a;  
    *a = *b;  
    *b = t;  
}  
  

long long int partition (string arr[], long long int b, long long int e)  
{  
    string pivot = arr[e]; 
    long long int i = (b - 1);
    for (long long int j = b; j <= e - 1; j++)  
    {  
        
        if (Compare(arr[j],pivot))  
        {  
            i++;  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[e]);  
    return (i + 1);  
}  
  

void quickSort(string arr[], long long int b, long long int e)  
{  
    if (b < e)  
    {  
        
        long long int p = partition(arr, b, e);  
  
        
        quickSort(arr, b, p - 1);  
        quickSort(arr, p + 1, e);  
    }  
}  
void printL(string arr[], long long int m) 
{ 
    quickSort(arr, 0,m-1) ;
  
    for ( long long int k=0; k <m ; k++ ) 
        cout << arr[k]; 
} 
int main()
{   
	long long int o;
	cin>>o;
	for(long long int j=0;j<o;j++)
	{long long int n;
	cin>>n;
	string ar[n];
	for(long long int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	printL(ar,n);
    cout<<"\n";}
	return 0;

}