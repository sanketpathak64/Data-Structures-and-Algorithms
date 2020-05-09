#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

//under contruction for insertion levelwise insertion 
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

void inorder(BT *ptr)
{
    if(ptr!=NULL)
	{
        inorder(ptr->left);
        cout<<"  "<<ptr->data<<"     ";
        inorder(ptr->right);
    }
}


void insert(BT *r,int data)
{
    BT *dnode = createNode(data); 
    BT *parent;
    parent=NULL;
    if(isempty())
        root=p;
    else{
        bintree_node *ptr;
        ptr=root;
        while(ptr!=NULL){
            parent=ptr;
            if(item>ptr->data)        
                ptr=ptr->right;
            else
                ptr=ptr->left;
        }   
        if(item<parent->data)
            parent->left=p;
        else
            parent->right=p;
    }
}

void inorder(BT *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout<<p->data<<endl;
        inorder(p->right);
    }
}
void preorder(tree *p)
{
    if (p != NULL)
    {
        cout<<p->data<<endl;
        preorder(p->l);
        preorder(p->r);
    }
}
void postorder(tree *p)
{
    if (p != NULL)
    {
        postorder(p->l);
        postorder(p->r);
        cout<<p->data<<endl;
    }
}


int main()
{
	BT *tree = createNode(1);
	tree->left = createNode(2);
	tree->right = createNode(3);
	tree->left->left = createNode(4);
	cout<<tree->data<<" "<<tree->left->data<<" "<<tree->right->data<<" "<<tree->left->left->data<<" ";
}
