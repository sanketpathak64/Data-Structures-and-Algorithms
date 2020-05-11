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

//function to find max value in BST
int max(BT *a)
{
	BT *root=a;
	while(root->right)
	{
		root = root->right;
	}
	return root->data;
}

//function to find min value in BST
int min(BT *a)
{
	BT *root=a;
	while(root->left)
	{
		root = root->left;
	}
	return root->data;
}


//function to count leaves of BST
int countLeaves(BT* root)
{
	if(root==NULL)
	    return 0;
	if(root->left == NULL && root->right==NULL)       
	    return 1; 

    return countLeaves(root->left)+countLeaves(root->right);
}

//function to find max height of BST
int height(BT* node)
{
	if(node==NULL)
		return 0;
   	return 1+max(height(node->left),height(node->right));
}

//function to find lowest common ancestor of 2 nodes in BST
int LCA(BT *root, int n1, int n2)
{
    if(root==NULL)
        return INT_MIN;
   if(n1>root->data && n2>root->data)
    return LCA(root->right,n1,n2);
    if(n1<root->data && n2<root->data)
    return LCA(root->left,n1,n2);
    
    return root->data;
}

//function to delete BST node
BT * deleteNode(BT* root, int key) 
{
    if(root == NULL)
        return root;
    BT *temp = root;
    BT *prev = NULL;
	// To find the target root
    while(temp != NULL)
	{
        if(temp->data == key)
            break;
        prev = temp;
        if(temp->data > key)
            temp = temp->left;
        else
            temp = temp->right;
    }
	//Case : Key not found
    if(temp == NULL)
        return root;
	//Case : No child
    if(temp->right == NULL && temp->left == NULL)
    {
        if(prev!=NULL)
		{
            if(prev->right == temp)
			{
               prev->right=NULL; 
            } 
            else
			{
                cout<<prev->left->data;
                prev->left = NULL; 
            }
            
        }		
        else
            return NULL;
    }
	//Case : 1 child (No right child )
    else if(temp->right == NULL)
	{
        if(prev)
		{
            if(prev->right == temp)
                prev->right=temp->left;
            else
                prev->left = temp->left;  
        }
        else
            return temp->left;
      
    } 
	//Case : 1 child (No left child)
    else if(temp->left == NULL)
	{
        if(prev)
		{
            if(prev->right == temp)
                prev->right=temp->right;
            else
                prev->left = temp->right;  
        }
        else
            return temp->right;
    }
	//Case : Both child
    else
	{
        BT *successor = createNode(max(temp->right));
        temp->data = successor->data;
        temp->right = deleteNode(temp->right,temp->data);
    }
    return root;
}
    


int main()
{
	BT *tree=NULL;
	tree=insert(tree,0);
	cout<<"hello";
	insert(tree,8);
	insert(tree,5);
	insert(tree,-8);
	insert(tree,6);
	
	insert(tree,-9);
	insert(tree,-1);
	inorder(tree);
	deleteNode(tree,-133);
//	insert(tree,10);
	inorder(tree);
	cout<<endl;
	preorder(tree);
	cout<<endl;
	postorder(tree);
	cout<<"max "<<LCA(tree,10,6);
}
