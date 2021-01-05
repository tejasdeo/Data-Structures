#include<stdio.h>
#include<stdlib.h>
#define MAXOF(x,y) ((x)>=(y)?(x):(y))


struct treenode{
	int data;
	struct treenode *lchild;
	struct treenode *rchild;
	};
typedef struct treenode tnode;
typedef tnode *tree;

 void inorder(tree root)
{
	if(root!=NULL){
	inorder(root->lchild);
	printf(" %d ",root->data);
	inorder(root->rchild);
	}
}

void preorder(tree root)
{
	if(root!=NULL){
	printf("%d ",root->data);
	preorder(root->lchild);
	preorder(root->rchild);
	}
}

void postorder(tree root)
{
	if(root!=NULL){
	postorder(root->lchild);
	postorder(root->rchild);
	printf(" %d",root->data);
	}
}

int height(tree root)
{
	if(root==NULL)
	return -1;
	
	if((root->lchild)==NULL && (root->rchild)==NULL)
	return 0;

	return	MAXOF( height(root->lchild),height(root->rchild))+1;
}

	
