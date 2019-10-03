#include<bits/stdc++.h>

using namespace std;

struct coor
{
    int x;
    int y;
};
coor p0;

coor second(stack<coor> s)
{
    coor t=s.top();
    s.pop();
    coor r=s.top();
    s.push(t);
    return r;
}

int dist(coor p1,coor p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
int swap1(coor &p1, coor &p2)
{
    coor temp = p1;
    p1 = p2;
    p2 = temp;
}
int orientation(coor p, coor q, coor r)
{
    int ori= (r.y-q.y)*(q.x-p.x)-(q.y-p.y)*(r.x-q.x);

    if(ori==0) return 0;

   return (ori>0)?1:2;
}

int compare(coor p1,coor p2)
{
    int o = orientation(p0, p1, p2);
   if (o == 0)
     return (dist(p0, p2) >= dist(p0, p1))? -1 : 1;

   return (o == 1)? -1: 1;

}
void merge1(coor arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    coor L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (compare(L[i],R[j])==-1)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(coor arr[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;


        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge1(arr, l, m, r);
    }
}

void convexHull(coor points[], int n)
{
   int ymin = points[0].y, min1 = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min1].x))
        ymin = points[i].y, min1 = i;
   }
    swap1(points[0], points[min1]);


    p0=points[0];
    mergeSort(points,1,n-1);

    int k = 1;
   for (int i=1; i<n; i++)
   {

       while (i < n-1 && orientation(p0, points[i],points[i+1]) == 0)
          i++;
          points[k] = points[i];
          k++;
   }


   if (k < 3) return;


   stack<coor> st;
   st.push(points[0]);
   st.push(points[1]);
   st.push(points[2]);


   for (int i = 3; i < k; i++)
   {

      while (orientation(second(st), st.top(), points[i]) != 1)
         st.pop();
      st.push(points[i]);
   }
   cout<<st.size()<<endl;
   coor ar[st.size()];
   int z=0;
   while (!st.empty())
   {
       ar[z] = st.top();

       st.pop();
       z++;

   }
   int e=ar[0].x;
   int g=0;

   for(int i=0;i<z;i++)
   {
       int h=ar[i].x;
       if(h<ar[i].x)
       {
           e=ar[i].x;
           g=i;
       }
   }
   for(int i=g;i<z;i++)
   {
       cout<<"("<<ar[i].x<<","<<ar[i].y<<")";
   }
   for(int i=0;i<g;i++)
   {
        cout<<"("<<ar[i].x<<","<<ar[i].y<<")";
   }

}
int main()
{
   int t;
   cin>>t;
   coor arr[t];
   for(int j=0;j<t;j++)
   {
       cin>>arr[j].x>>arr[j].y;
   }
   convexHull(arr,t);
}
