#include<bits/stdc++.h>
using namespace std;

struct node
{
    int k;
    int priority;
    node* left;
    node* right;
};

node* nnode(int key)
{
    node* temp= new node;
    temp->k=key;
    temp->priority=rand()%100;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

node* rightrotate(node* n)
{
    node* temp=n->left;
    node* temp2=temp->right;

    temp->right=n;
    n->left=temp2;
    return temp;

}
node* leftrotate(node* n)
{
    node* temp=n->right;
    node* temp2=temp->left;

    temp->left=n;
    n->right=temp2;
    return temp;

}

node* search(int key, node*root)
{
  if(root->k==key|| root==NULL)
  return root;

  else
  {
      if(key<root->k)
      return search(key,root->left);

      else
      return search(key,root->right);
  }
}

node* insert(int key,node* root)
{
    if(!root)
    return nnode(key);

    if(key<root->k)
    {
        root->left= insert(key,root->left);

        if(root->left->priority>root->priority)
        root= rightrotate(root);


    }
    if(key>root->k)
    {
        root->right=insert(key,root->right);

        if(root->right->priority>root->priority)
        root= leftrotate(root);
    }
    return root;

}

node* deletenode(int key, node* root)
{
    if(root==NULL)
    return root;

    if(key<root->k)
    {
        root->left=deletenode(key,root->left);
    }
    else if(key>root->k)
    {
        root->right=deletenode(key,root->right);
    }
    else if(root->left==NULL)
    {
        node* temp=root->right;
        delete(root);
        root=temp;
    }
    else if(root->right==NULL)
    {
        node* temp=root->left;
        delete(root);
        root=temp;
    }

    else if(root->left->priority<root->right->priority)
    {
        root=leftrotate(root);
        root->left=deletenode(key,root->left);
    }
    else
    {
        root=rightrotate(root);
        root->right=deletenode(key,root->left);
    }

     return root;
}

void inorder(node* root)
{
    if (root)
    {
        inorder(root->left);
        cout << "key: "<< root->k << " | priority: %d "
            << root->priority;
        if (root->left)
            cout << " | left child: " << root->left->k;
        if (root->right)
            cout << " | right child: " << root->right->k;
        cout << endl;
        inorder(root->right);
    }
}

int main()
{
    srand(time(NULL));

    struct node *root = NULL;
    root = insert(50,root);
    root = insert(30,root);
    root = insert(20,root);
    root = insert(40,root);
    root = insert(70,root);
    root = insert(60,root);
    root = insert(80,root);

    cout << "Inorder traversal of the given tree \n";
    inorder(root);

    cout << "\nDelete 20\n";
    root = deletenode(20,root);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 30\n";
    root = deletenode(30,root);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 50\n";
    root = deletenode(50,root);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    node *res = search(50,root);
    (res == NULL)? cout << "\n50 Not Found ":
                   cout << "\n50 found";

    return 0;
}
