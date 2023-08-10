#include <bits/stdc++.h>
using namespace std;


class node{
public:
    int value;
    node* Left;
    node* Right;
};

class BST{
public:
    node *root;

    BST()
    {
        root = NULL;
    }

    node* CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode->value = value;
        newnode->Left = NULL;
        newnode->Right = NULL;
        return newnode;
    }


    void BFS()
    {
        if(root == NULL)
            return;
        queue<node*>q;
        q.push(root);

        while(!q.empty())
        {
            node* a = q.front();
            q.pop();
            int p = -1, l = -1 , r= - 1;
            if(a->Left != NULL){
                l = a->Left->value;
                q.push(a->Left);
            }
            if(a->Right != NULL){
                r = a->Right->value;
                q.push(a->Right);
            }
            cout<<"Node value = "<<a->value<<" Left Child = "<<l;
            cout<<" Right Child = "<<r<<"\n";
        }
    }


    void Insert(int value)
    {
        node* newnode = CreateNewNode(value);

        if(root == NULL)
        {
            root = newnode;
            return;
        }

        node* cur= root;
        node* prv= NULL;
        while(cur != NULL)
        {
            if(newnode->value > cur->value)
            {
                prv = cur;
                cur = cur->Right;
            }
            else{
                prv = cur;
                cur = cur->Left;
            }
        }
        if(newnode->value > prv->value)
        {
            prv->Right = newnode;
        }
        else{
            prv->Left = newnode;
        }

    }

    int minvalue()
    {
         if (root == NULL)
        {
            return -1;
        }

     node* a = root;
     while(a->Left!=NULL)
     {
        a = a->Left;
     }

        return a->value;
    }

      int maxvalue()
    {
         if (root == NULL)
        {
            return -1;
        }
     node* a = root;
     while(a->Right!=NULL)
     {
        a = a->Right;
     }

        return a->value;
    }

   
};


int main()
{
    BST bst;
    bst.Insert(6);
    bst.Insert(4);
    bst.Insert(3);
    bst.Insert(5);
    bst.Insert(7);
    bst.Insert(8);

    bst.BFS();
    
    cout<<"Min value of binary search tree: "<<bst.minvalue()<<"\n";
    cout<<"Max value of binary search tree: "<<bst.maxvalue()<<"\n";

    return 0;
}