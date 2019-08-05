#include<bits/stdc++.h>

using namespace std;

struct point
{
 long long int x;
 long  long int y;
};

struct node
{
    struct point p;
    struct node*next;
};
void addFirst( struct node**head, long long int x1,long long int y1)
{
    struct node*newnode= (struct node*) malloc(sizeof(struct node));
    newnode->p.x=x1;
    newnode->p.y=y1;
    newnode->next=*head;
    *head=newnode;
}

int delFirst(struct node**head)
{
    struct node*temp=*head;
    if(*head==NULL) return -1;
    *head=temp->next;
    free(temp);
    return 0;
}

int del(struct node**head, long long int x1,long long int y1)
{
    struct node*temp=*head;
    struct node*prev;
    if( temp!= NULL && temp->p.x==x1 && temp->p.y==y1)
    {
        *head=temp->next;
        free(temp);
        return 0;
    }
    while(temp!=NULL &&(temp->p.x!=x1 && temp->p.y!=y1))
          {
            prev=temp;
            temp=temp->next;
          }
    if(temp==NULL) return -1;

    prev=temp->next;
    free(temp);
    return 0;



}

void search2(struct node**head,long double d)
{
    struct node*temp=*head;
    while(temp!=NULL)
    {
         if(sqrt((temp->p.x)*(temp->p.x)+(temp->p.y)*(temp->p.y))<=d)
        cout<<'('<<temp->p.x<<','<<temp->p.y<<')';
        temp=temp->next;
    }


}
bool search1(struct node**head,long long int x1,long long int y1)
{
    struct node*temp=*head;
    while(temp!=NULL)
    {
        if(temp->p.x==x1 && temp->p.y==y1)
        {
            return true;
            break;
        }
        else temp=temp->next;
    }
    return false;
}

void length(struct node**head)
{   int n=0;
    struct node*temp=*head;
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    cout<<n;
}

int main()
{
    struct node*Head=NULL;
     long long int n;
    cin>>n;
    int i=0;
    while(i<n)
    {
    int k;
    cin>>k;

    switch (k)
    {
    case 1:
        {
           long long  int a,b;
            cin>>a>>b;
            addFirst(&Head,a,b);
        }
        break;
    case 2:
        {
            cout<<delFirst(&Head);
        }
        break;
    case 3:
        {
            long long int c,d;
            cin>>c>>d;
            cout<<del(&Head,c,d);
        }
        break;
    case 4:
        {
            long double d;
            cin>>d;
            search2(&Head,d);
        }
        break;
    case 5:
        {
           long long  int e,f;
            cin>>e>>f;
            if(search1(&Head,e,f)) cout<<"true";
            else cout<<"false";
        }
        break;
    case 6:
        {
            length(&Head);
        }
        break;

    
        }
     i++;}
    return 0;
}
