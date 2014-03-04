#include"iostream"
#include"malloc.h"
#include"vector"
using namespace std;

typedef struct node
{
	int data;
	struct node *left, *right;
}Btree;

int sum;
vector<Btree*> *BNode;

void pathSum( Btree *T, int s )
{
	if( T != NULL )
	{
		if( T->left == NULL && T->right == NULL )
		{
			BNode->push_back(T);
			if( s + T->data == sum )
			{
				int i;
				for( i = 0; i < BNode->size(); i ++ )
				{
	        		cout<<BNode->at(i)->data<<" ";
				}
				cout<<"\n";
			}		
		}
		else
		{
			if( s + T->data > sum )
			{
				return;
			}
			else
			{
				s = s + T->data;				
				BNode->push_back(T);			
				pathSum( T->left, s );
				pathSum( T->right, s );		
			}
		}
		BNode->pop_back();	
	}
}

Btree *newNode( int data)
{
	Btree *tNode = (Btree*)malloc(sizeof(Btree));
	tNode->data = data;
	tNode->left = NULL;
	tNode->right = NULL;
	return tNode;
}

void Btraverse( Btree *T )
{
	if( T != NULL )
	{
		cout<<T->data<<" ";
		Btraverse(T->left);
		Btraverse(T->right);
	}	
}

int main(void)
{
	BNode = new vector<Btree*>();
	sum = 12;
	Btree *root = newNode(5);
	root->left = newNode(8);
	root->right = newNode(4);
	root->left->left = newNode(20);
	root->left->left->left = newNode(7);
	root->left->left->right = newNode(2);
	root->right->left = newNode(13);
	root->right->right = newNode(2);
	root->right->right->left = newNode(5);
	root->right->right->right = newNode(1);
	Btraverse(root);
	cout<<endl;	
	pathSum( root, 0 );
	return 0;
}
