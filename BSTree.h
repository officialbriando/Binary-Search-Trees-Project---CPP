//Author: Brian Do

#include <iostream>
#include "TreeNode.h"

using namespace std;

template <class E>				//Creating a template class of data type E.

class BSTree
{
	private:
		TreeNode root;
	public:
		BSTree();
		~BSTree();

		void insert(E data);
		bool contains(E data);
		bool deleteNode(E data);

		bool isEmpty();
		E getMin();
		E getMax();

		TreeNode getSuccessor(TreeNode n);		//Helper function for delete method.
};

template<class E>
BSTree<E>::BSTree()
{
	root = NULL;
}

template<class E>
BSTree<E>::~BSTree()
{
	//Iterate through and delete all nodes.
}

template<class E>
E BSTree<E>::getMax()
{
	TreeNode *current = root;

	if(root == NULL)
	{
		return NULL;
	}
	else
	{
		while(current->right != NULL)
		{
			current = current->right;
		}

		return &(current->element);
	}
}

template<class E>
E BSTree<E>::getMin()
{
	TreeNode *current = root;

	if(root == NULL)
	{
		return NULL;
	}
	else
	{
		while(current->left != NULL)
		{
			current = current->left;
		}

		return &(current->element);
	}
}

template<class E>
void BSTree<E>::insert(E data)
{
	TreeNode *node = new TreeNode(data);

	if(root == NULL) //If tree is empty
	{
		root = node;
	}
	else
	{
		TreeNode *current = root;	//Initialize current node to root
		TreeNode *parent = NULL;

		while(true)
		{
			parent = current;

			if(data < current->element)
			{
				current = current->left;
				if(current == NULL)	//Position to insert found
				{
					parent->left = node;
					break;
				}
			}
			else if(data > current->element)
			{
				current = current->right;
				if(current == NULL)	//Position to insert found
				{
					parent->right = node;
					break;
				}
			}
		}
	}
}

template<class E>
bool BSTree<E>::contains(E data)
{
	if(root == NULL)
	{
		cout << "The tree is empty, it does not contain your given element." << endl;
		return false;
	}
	else
	{
		TreeNode *current = root;	//Start at root

		while(current->element != data)
		{
			if(data < current->element)
			{
				current = current->left;
			}
			else if(data > current->element)
			{
				current = current->right;
			}

			if(current == NULL)
			{
				cout << "The tree does not contain your given element." << endl;
				return false;
			}
		}
	}

	cout << "The tree contains your given element." << endl;
	return true;
}

template<class E>
bool BSTree<E>::deleteNode(E data)
{
	if(root == NULL)	//Empty tree
	{
		return false;
	}

	TreeNode *current = root;	//Always start at root for current
	TreeNode *parent = NULL;	//No initial parents
	bool isLeft = true;

	while(current->element != data)
	{
		parent = current;

		if(data < current->element)
		{
			ifLeft = true;
			current = current->left;
		}
		else if(data > current->element)
		{
			isLeft = false;
			current = current->right;
		}
		if(current == NULL)
		{
			return false;	//Deletion failed, no such data in tree
		}
	}

	//Begin checks for deletion

	//NO CHILDREN
	if(current->left == NULL && current->right == NULL)
	{
		if(currrent == root)
		{
			root == NULL;
		}
		else if(isLeft)
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}
	}

	//ONE CHILD
	else if(current->right == NULL)	//No right child
	{
		if(current == root)
		{
			root = current->left;
		}
		else if(isLeft)
		{
			parent->left = current->left;
		}
		else
		{
			parent->right = current->left;
		}
	}
	else if(current->left == NULL)	//No left child
	{
		if(current == root)
		{
			root = current->right;
		}
		else if(isLeft)
		{
			parent->left = current->right;
		}
		else
		{
			parent->right = current->right;
		}
	}

	//TWO CHILDREN
	else if(current->left != NULL && current->right != NULL)
	{
		
	}
}