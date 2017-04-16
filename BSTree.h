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

		void insert(E data, int k);
		bool contains(int k);
		bool deleteNode(int k);

		bool isEmpty();
		E getMin();
		E getMax();

		void printInOrder();
		void printPostOrder();
		void printPreOrder();

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
void BSTree<E>::insert(E data, int k)
{
	TreeNode *node = new TreeNode(data, k);

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

			if(k < current->key)
			{
				current = current->left;
				if(current == NULL)	//Position to insert found
				{
					parent->left = node;
					break;
				}
			}
			else if(k > current->key)
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
bool BSTree<E>::contains(int k)
{
	if(root == NULL)
	{
		cout << "The tree is empty, it does not contain your given element." << endl;
		return false;
	}
	else
	{
		TreeNode *current = root;	//Start at root

		while(current->key != k)
		{
			if(k < current->key)
			{
				current = current->left;
			}
			else if(k > current->key)
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
bool BSTree<E>::deleteNode(int k)
{
	if(root == NULL)	//Empty tree
	{
		return false;
	}

	TreeNode *current = root;	//Always start at root for current
	TreeNode *parent = NULL;	//No initial parents
	bool isLeft = true;

	while(current->key != k)
	{
		parent = current;

		if(k < current->key)
		{
			ifLeft = true;
			current = current->left;
		}
		else if(k > current->key)
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
		TreeNode *successor = getSuccessor(current);

		if(current == root)
		{
			root = successor;
		}
		else if(isLeft)
		{
			parent->left = successor;
		}
		else
		{
			parent->right = successor;
		}

		successor->left = current->left;
	}

	return true;
}


template<class E>
TreeNode BSTree<E>::getSuccessor(TreeNode *n)
{
	TreeNode *successor_parent = n;
	TreeNode *successor = n; //Will be one right, all the way left.
	TreeNode *current = n->right;

	while(current != NULL)
	{
		successor_parent = successor;
		successor = current;
		current = current->left;
	}

	if(successor != n->right)
	{
		successor_parent->left = successor->right;
		successor->right = n->right;
	}

		return successor;
}

template<class E>
void BSTree<E>::printInOrder(TreeNode n)	//Should use root as argument.
{
	if(n != NULL)
	{
		printInOrder(n -> left);
		cout << n->element;
		printInOrder(n -> right);
	}
}

template<class E>
void BSTree<E>::printPostOrder(TreeNode n)	//Should use root as argument.
{
	if(n != NULL)
	{
		printPostOrder(n -> left);
		printInOrder(n -> right);

		cout << n->element;
	}
}

template<class E>
void BSTree<E>::printPreOrder(TreeNode n)	//Should use root as argument.
{
	if(n != NULL)
	{
		cout << n->element;

		printPostOrder(n -> left);
		printInOrder(n -> right);
	}
}
