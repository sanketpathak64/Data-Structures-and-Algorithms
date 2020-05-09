#include<cstdio>
#include<bits/stdc++.h>
using namespace std;


typedef struct bt
{
	struct bt* left;
	int data;
	struct bt* right; 
}BT;

BT *createNode(int data)
{
	BT *a = (BT *)malloc(sizeof(struct bt));
	a->left = NULL;
	a->data = data;
	a->right = NULL;
	
	return a;
}


void inorder(BT *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
    
}
void preorder(BT *p)
{
    if (p != NULL)
    {
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
    }
    
    
}
void postorder(BT *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->data<<" ";
    }

}

BT *insert(BT *a,int val)
{
	BT *newnode = createNode(val);
	BT *root=a,*b=NULL;
	while(root)
	{
		b=root;
		if(val>root->data)
			root=root->right;
		else if(val<root->data)
			root=root->left;
	}
	if (b == NULL) 
        b = newnode; 
    else if (val < b->data) 
        b->left = newnode;  
    else
        b->right = newnode; 
    
    return b;
}

int max(BT *a)
{
	BT *root=a;
	while(root->right)
	{
		root = root->right;
	}
	return root->data;
}

int main()
{
	BT *tree=NULL;
	tree=insert(tree,5);

insert(tree,2);
insert(tree,7);
insert(tree,4);
inorder(tree);
cout<<endl;
preorder(tree);
cout<<endl;
postorder(tree);
cout<<"max "<<max(tree);
}
