

#include <bits/stdc++.h>
using namespace std;

struct point{
   int x;
   int y;
   struct point *next;
   };
 struct point *head;
struct point *createnode()
  {
     struct point *temp=(struct point *)(malloc(sizeof(struct point)));
     temp->next=NULL;
     return temp;
  }
 void AddFirst(int x,int y)
 {
 	struct point *newnode=createnode();
 	newnode->next=head;
 	head=newnode;
 	newnode->x=x;
 	newnode->y=y;
 }
 void DelFirst()
 {

 	if(head!=NULL)
 	{
 	 struct point*temp=head;
 	 head=temp->next;
 	 free(temp);

        }
        else cout<<-1<<endl;

 }
 void Del(int x,int y)
 {
        if(head==NULL){ cout<<-1<<endl; return;}
 	if(head->x==x && head->y==y) { DelFirst(); return;}
 	struct point *temp=head;
 	struct point *prev=NULL;
        int flag=0;
 	while(temp->next!=NULL)
 	{
 		prev=temp;
 		temp=temp->next;
 		if(temp->x==x && temp->y==y)
 		{
                   prev->next=temp->next;
                   free(temp);
                   flag=1;
                    break;
 		}
 	}
   if(flag==0) cout<<-1<<endl;

 }
void Search(int x,int y)
 {
 	struct point *temp=head; int c=0;
 	while(temp!=NULL)
 	{
 		if(temp->x==x && temp->y==y)
 		{
             cout<<"True"<<endl; return;
 		}
            temp=temp->next;
 	}
 	cout<<"False"<<endl;
 }
 int Length()
 {
 	struct point *temp=head; int i=0;
 	while(temp!=NULL)
 	{
 		temp=temp->next;
 		i++;
 	}
 	return i;
 }
 void Search(float d)
 {
 	struct point *temp=head;
 	int flag=0;
 	while(temp!=NULL)
 	{
 	   float dist= sqrt((temp->x)*(temp->x) + (temp->y)*(temp->y) );
 	   if(dist <= d) {flag++;
 	   cout<<"("<<temp->x<<","<<temp->y<<") ";}
    	   temp=temp->next;
 	}
         if(flag==0) cout<<-1<<endl;

 }


 int main()
 {
 	head=NULL;
        int t;
        cin>>t;
        for(int k=0;k<t;k++)
        {
 	int num;
 	cin>>num;
 	switch(num)
 	{

 		case 1:
 		 int x,y;
 		 cin>>x>>y;
 		 AddFirst(x,y);
 		 break;
 		case 2:
 		  DelFirst();
 		  break;
 		case 3:
 		  int x1,y2;
 		 cin>>x1>>y2;
 		 Del(x1,y2);
 		 break;
 		case 4:
 		   float d;
 		  cin>>d;
 		  Search(d);

 		  break;
 		case 5:
 		  int x2,y1;
 		 cin>>x2>>y1;
 		 Search(x2,y1);
                 break;
                case 6:
                 cout<<Length()<<endl;
                 break;

 	}
    }
return 0;
 }

