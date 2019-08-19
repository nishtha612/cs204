#include<bits/stdc++.h>

using namespace std;

int isOperator(char c)
{ 
  if(c=='+' || c=='-' || c=='/' || c=='*' || c=='^')
    return 1;
  else return 0;
 }

int prec(char c)
{
  if(c=='^')
  return 3;
  if(c=='*' || c=='/')
  return 2;
  if(c=='+' || c=='-')
  return 1;
  
  return -1;}
  
  
string intopo( string s)
{
  string str="";
  stack<char> st;
  st.push('N');
  
  
  int j=0;
  int i;
  for(i=0;i<s.length();i++)
   { 
    
    if(isOperator(s[i])==0 && s[i]!='(' && s[i]!=')') str.push_back(s[i]);
    if(isOperator(s[i])==1)
    str=str+"?";
    
    if(s[i]=='(')
      st.push('(');
      
    if(s[i]==')')
    { 
      while(st.top() != 'N' && st.top() !='(')
      {
        char c= st.top();
        st.pop();
        str.push_back(c);
       }
       
       if(st.top()=='(')
       {
         char c=st.top();
         st.pop();
        }
       }
       
      if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^')
        { 
          while(st.top() !='N' && prec(s[i]) <= prec(st.top()))
          { 
            char c = st.top();
            st.pop();
            str.push_back(c);
            }
            
            st.push(s[i]);
           }
          }
          
          while(st.top() !='N')
          {
            char c=st.top();
            st.pop();
            str.push_back(c);
           }
          
      return str;}

struct t{
 string num;
 t *left;
 t *right;};
t* newnode(string v)
{
  t *nn=new t;
  nn->left=NULL;
  nn->right=NULL;
  nn->num=v;
  return nn;
};

t* tree( string r)
{
 stack<t *> sc;
 t *t1,*t2,*t3;
 
 
 int i=0;
 while(1)
 { int w=0;
   string l="";
   for(int j=i;j<r.length();j++)
   {
    if(isOperator(r[j])==0 && r[j]!='?')
     { l.push_back(r[j]);
       i=j+1;
       w=1;}
    else break;
   }
   if((isOperator(r[i])==1 || r[i]=='?') && w==1)
    { 
      t1=newnode(l);
      sc.push(t1);
    }

   if(isOperator(r[i])==1)
   { string y="";
     y.push_back(r[i]);
     t1=newnode(y);
     t2=sc.top();
     sc.pop();
     t3=sc.top();
     sc.pop();
     
     t1->right =t2;
     t1->left=t3;
    
     sc.push(t1);
     
  }
  i++;
  if(i==r.length()) break;
}

 t1=sc.top();
 sc.pop();
 
 return t1;   
 
}

int toInt(string s)  
{  
    int nu = 0;  
      
    
  
        for (int i=0; i<s.length(); i++)  
            nu = nu*10 + (int(s[i])-48);  
   
    return nu;  
}  

int eval(t *root)  
{  
      
    if (root==NULL)  
     return 0;  
  
      
    if (root->left==NULL && root->right==NULL)  
        return toInt(root->num);  
  
    
    int l_val = eval(root->left);  
  
   
    int r_val = eval(root->right);  
  
     
    if (root->num=="+")
        
        return l_val+r_val;  
  
    if (root->num=="-")  
        return l_val-r_val;  
  
    if (root->num=="*")  
        return l_val*r_val;
    if(root->num=="^")
       return pow(l_val, r_val);  
  
    return l_val/r_val;
     
} 


      
int main()
{
  int f,g;
  cin>>f;
  
  for(int i=0;i<f;i++)
   {
     cin>>g;
     for(int j=0;j<g;j++)
      {string e;
      cin>>e;
      cout<<eval(tree(intopo(e)));}}
 
  
  return 0;}
      
    
    
      
     
     
     
         
    
      
     
     
     
         
