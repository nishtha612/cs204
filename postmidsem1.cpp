#include<bits/stdc++.h>

using namespace std;
 
long long int finddist(long long int x, long long int y)
{
	return (x*x+y*y);
}

void insertionSort(long long int arr[], long long int n)  
{  
    long long int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  

long long int findmedian(long long int arr[], int n)
{
	insertionSort(arr, n);
	return(arr[n/2]);
}

void swap(long long int *a, long long int *b)
{
	long long int t;
	t=*a;
	*a=*b;
	*b=t;
}

long long int partition(long long int arr[],long long int l,long long int r,long long int x)
{
	long long int i;
	for(i=l;i<r;i++)
	{
		if(arr[i]==x)
			break;
	}
	swap(&arr[i],&arr[r]);
    i=l;
	for(long long int j=l;j<=r-1;j++)
	{
       if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i;
	

}

long long int radius(long long int arr[], long long int l,long long int r,long long int k)
{
	long long int n=r-l+1;
	
	long long int i,median[(n+4)/5];
	for(i=0;i<n/5;i++)
	{
		median[i]=findmedian(arr+l+i*5,5);
	}
	if(i*5<n)
	{
		median[i]=findmedian(arr+l+i*5,n%5);
		i++;
	}

	long long int medOfmed= (i == 1)? median[i-1]: 
                                 radius(median, 0, i-1, i/2); 
  
        
        long long int position = partition(arr, l, r, medOfmed); 
  
      
        if (position-l == k-1) 
            return arr[position]; 
        if (position-l > k-1)  
            return radius(arr, l, position-1, k); 
  
        
        return radius(arr, position+1, r, k-position+l-1);
}



int main()
{
  long long int n;
  long long int p;

  cin>>n;
  
  for(int j=0;j<n;j++)
  {
  	cin>>p;
  	long long int ar[p];
  	{
  		for(int m=0;m<p;m++)
  		{
  			long long int x,y;
  			cin>>x>>y;
  			ar[m]=finddist(x,y);
  		}
  	}
  	if(p%2==0)
  	cout<<sqrt(radius(ar,0,p-1,(p/2)))<<endl;
    else cout<<sqrt(radius(ar,0,p-1,(p/2)+1))<<endl;
  }
  return 0;
}