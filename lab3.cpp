#include<bits/stdc++.h>

using namespace std;

int isbalanced( string str)
{
    stack<char> s;
    char x;
    int i;
    int y=0;
    char c;
    for(i=0;i<str.length();i++)
    {   
        
        if(str[i]=='(' || str[i]=='{' || str[i]=='[' || str[i]=='<' )
            {
                s.push(str[i]);
                continue;
            }
        if(str[i]=='|' && y==0) 
         { s.push(str[i]);
           y++;
           continue;}
        if(s.empty()) return 0;
          

           if(str[i]=='|' && y!=0)    
            { if(str[i-1]=='}' ||str[i-1] ==')' || str[i-1]=='|'|| str[i-1]=='>' || str[i-1]==']')
             {x = s.top();
              s.pop();
              y--;
             if (x =='(' || x == '{' || x=='<' || x=='[') return 0;
        
             }
              else 
              {s.push(str[i]);
               y++;
               continue;}
            }
 
        

    

    switch (str[i])
        {
        case ')':


            x = s.top();
            s.pop();
            if (x=='{' || x=='[' || x=='<' || x=='|')
                return 0 ;
            break;

        case '}':


            x = s.top();
            s.pop();
            if (x=='(' || x=='['  || x=='<' || x=='|')
                return 0;
            break;

        case ']':


            x = s.top();
            s.pop();
            if (x =='(' || x == '{' || x=='<' || x=='|')
                return 0;
            break;

         case '>':


            x = s.top();
            s.pop();
            if (x =='(' || x == '{' || x=='[' || x=='|')
                return 0;
            break;

          
        }
    }
    return (s.empty());
}

int main()
{  int n;
   cin>>n; 
   string arr[n];
   for(int j=0;j<n;j++)
    {string u;
    cin>>u;
    if(isbalanced(u)==1) arr[j]="YES";
    else arr[j]="NO";}
     
 for(int j=0;j<n;j++)   
  {cout<<arr[j]<<'\n';}
    return 0;
}
