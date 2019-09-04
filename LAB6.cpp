#include<bits/stdc++.h>
using namespace std;

class Node  
{  
    public: 
    long long int user_id;
    double amount; 
    Node *left;  
    Node *right;  
    int height;  
};  
  

int max(int a, int b);  
  

int height(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  
  

int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  

Node* newNode(long long int user_id, double amount )  
{  
    Node* node = new Node(); 
    node->user_id = user_id;
    node->amount=amount;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;
    return(node);  
}  
  

Node *rightRotate(Node *y)  
{  
    Node *x = y->left;  
    Node *T2 = x->right;  
  
    
    x->right = y;  
    y->left = T2;  
  
    
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                    height(x->right)) + 1;  
  
    
    return x;  
}  
  

Node *leftRotate(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;  
  
    y->left = x;  
    x->right = T2;  
  

    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
   
    return y;  
}  
  

int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  
  

Node* insert(Node* node, long long user_id, double amount)  
{  
    
    if (node == NULL)  
        return(newNode(user_id,amount));  
  
    if (user_id < node->user_id)  
        node->left = insert(node->left, user_id,amount);  
    else if (user_id > node->user_id)  
        node->right = insert(node->right,user_id, amount);  
    else 
        return node;  
  
    
    node->height = 1 + max(height(node->left),  
                        height(node->right));  
  
    
    int balance = getBalance(node);  
  
   
   
    if (balance > 1 && user_id < node->left->user_id)  
        return rightRotate(node);  
  
    
    if (balance < -1 && user_id > node->right->user_id)  
        return leftRotate(node);  
  
    
    if (balance > 1 && user_id > node->left->user_id)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    
    if (balance < -1 && user_id < node->right->user_id)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
   
    return node;  
}  
  
 Node* search(Node* root,long long int user_id) 
{ 
   
    if (root == NULL || root->user_id == user_id) 
       return root; 
     
    
    if (root->user_id < user_id) 
       return search(root->right, user_id); 
  
    
    return search(root->left, user_id); 
} 

int main()
{
	long long int n;
	long long  int q;
	cin>>n;
	cin>>q;
	Node *root=NULL;
	double max=0;
        long long int uid=0;
	for(long long int i=0;i<q;i++)
	{   
		int e;
                cin>>e;
		if(e==1)
		{
			int user_id;
		    double amount;
		    cin>>user_id;
		    cin>>amount;
		    if(search(root,user_id)==NULL) {
		    	root=insert(root,user_id,amount);
		    	if(amount>max)
                        {max=amount;
                         uid=user_id;}}
		    else
		    {
		    	search(root,user_id)->amount=search(root,user_id)->amount+amount;
		    	if(search(root,user_id)->amount>max) {
                         max=search(root,user_id)->amount;
                         uid=user_id;}
		    }

		}
		if(e==2)
		{
                    if(uid==0) cout<<"Data not available."<<"\n";
                    else cout<<uid<<"\n";
		}


	}
	return 0;
 }
