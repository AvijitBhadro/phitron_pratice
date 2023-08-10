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

       void BFS()
    {
       
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            node* a = q.front();
            q.pop();
            int l,r,p;
            l=-1 ,r =-1, p=-1;

            if(a->Left!=NULL)
            {
                l = a->Left->id;
                q.push(a->Left);
            }
         
            if(a->Right!= NULL)
            {
                r = a->Right->id;
                q.push(a->Right);
            }
        if(a->parent!=NULL)
        {
            p = a->parent->id;
        }
        cout<<"Node id: "<<a->id<<", value: "<<a->value<<", Left node: "<<l
        <<", Right node: "<<r<<", Parent node: "<<p<<"\n";
        }
    }
    void search(node* a,int value)
    {
        if(a == NULL)
        {
            return;
        }
        if(a->value==value) cout<<a->id<<" ";
        search(a->Left,value);
        search(a->Right,value);
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
bt.BFS();
cout<<"\n";
bt.search(bt.root,10);
cout<<"\n";


}