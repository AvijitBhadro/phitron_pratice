//height of binary tree

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int id;
    int value;
    node *Left;
    node *Right;
    node *parent;
};

class BinaryTree
{
public:
    node *root;

    BinaryTree()
    {
        root = NULL;
    }
   node* CreateNewNode(int id,int val)
    {
        node* newnode = new node;
        newnode->id = id;
        newnode->value = val;
        newnode->Left = NULL;
        newnode->Right = NULL;
        newnode->parent = NULL;
        return newnode;
    }
    void Insertion(int id,int val)
    {
        node* newnode = CreateNewNode(id,val);
        if(root==NULL)
        {
            root = newnode;
            return;
        }
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            node* a = q.front();
            q.pop();
            if(a->Left!=NULL)
            {
                q.push(a->Left);
            }
            else{
                a->Left = newnode;
                newnode->parent = a;
                return;
            }
            if(a->Right!= NULL)
            {
                q.push(a->Right);
            }
            else{
                a->Right = newnode;
                newnode->parent = a;
                return;
            }
        }
    }
//  int height(node* a)
//  {
//    if(a == NULL)
//    return 0;
//    int lh = height(a->Left);
//    int rh = height(a->Right);

//    if(lh>rh) return lh+1;
//    else return rh+1;
 
//  }
int height(node* root)
{
 
    
    int height = 0;
 
    queue<node*> q;
 
   
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        node* a = q.front();
        q.pop();
 
        // When NULL encountered, increment the value
        if (a == NULL) {
            height++;
        }
 
     
        if (a != NULL) {
            if (a->Left!=NULL) {
                q.push(a->Left);
            }
            if (a->Right!=NULL) {
                q.push(a->right);
            }
        }
 
 
        else if (!q.empty()) {
            q.push(NULL);
        }
    }
    return height;
}
    

};

int main()
{
BinaryTree bt;
bt.Insertion(0,5);
bt.Insertion(1,10);
bt.Insertion(2,5);
bt.Insertion(3,7);
bt.Insertion(4,10);
cout<<bt.height(bt.root)<<"\n";



}