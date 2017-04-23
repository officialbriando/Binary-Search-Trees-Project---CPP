//Author: Brian Do & Miguel Gotao

#include <iostream>
#include "TreeNode.h"

using namespace std;

template <class E>				//Creating a template class of data type E.

class BSTree
{
	private:
		TreeNode<E> *root;
	public:
		BSTree();
		~BSTree();

		int size;

		void insert(E data, int k);
		TreeNode<E>* getNode(int k);
		bool deleteNode(int k);

		bool isEmpty();
		E getMin();
		E getMax();

		void printInOrder(TreeNode<E> *n);
		void printPostOrder(TreeNode<E> *n);
		void printPreOrder(TreeNode<E> *n);

		TreeNode<E>* getSuccessor(TreeNode<E> *n);	//Helper function for delete method.
		TreeNode<E>* getRoot();
		int getSize();
};

template<class E>
BSTree<E>::BSTree()
{
	root = NULL;
	size = 0;
}

template<class E>
BSTree<E>::~BSTree()
{
	//Iterate through and delete all nodes.
}

template<class E>
E BSTree<E>::getMax()
{
	TreeNode<E> *current = root;

	if(root == NULL)
	{
		cout << "The tree is empty." << endl;
		return 0;
	}
	else
	{
		while(current->right != NULL)
		{
			current = current->right;
		}

		return current->element;
	}
}

template<class E>
E BSTree<E>::getMin()
{
	TreeNode<E> *current = root;

	if(root == NULL)
	{
		cout << "The tree is empty." << endl;
		return 0;
	}
	else
	{
		while(current->left != NULL)
		{
			current = current->left;
		}

		return current->element;
	}
}

template<class E>
void BSTree<E>::insert(E data, int k)
{
	TreeNode<E> *node = new TreeNode<E>(data, k);

	if(root == NULL) //If tree is empty
	{
		root = node;
	}
	else
	{
		TreeNode<E> *current = root;	//Initialize current node to root
		TreeNode<E> *parent = NULL;

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

	size++;
}

template<class E>
TreeNode<E>* BSTree<E>::getNode(int k)
{
	if(root == NULL)
	{
		cout << "The tree is empty, it does not contain your given element." << endl;
		return NULL;
	}
	else
	{
		TreeNode<E> *current = root;	//Start at root

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
				return NULL;
			}
		}
		return current;
	}
}

template<class E>
bool BSTree<E>::deleteNode(int k)
{
	if(root == NULL)	//Empty tree
	{
		return false;
	}

	TreeNode<E> *current = root;	//Always start at root for current
	TreeNode<E> *parent = NULL;	//No initial parents
	bool isLeft = true;

	while(current->key != k)
	{
		parent = current;

		if(k < current->key)
		{
			isLeft = true;
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
		if(current == root)
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
		TreeNode<E> *successor = getSuccessor(current);

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

	size--;
	return true;
}


template<class E>
TreeNode<E>* BSTree<E>::getSuccessor(TreeNode<E> *n)
{
	TreeNode<E> *successor_parent = n;
	TreeNode<E> *successor = n; //Will be one right, all the way left.
	TreeNode<E> *current = n->right;

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
void BSTree<E>::printInOrder(TreeNode<E> *n)	//Should use getRoot as argument.
{
	if(n != NULL)
	{
		printInOrder(n -> left);
		cout << n->element << endl;
		printInOrder(n -> right);
	}
}

template<class E>
void BSTree<E>::printPostOrder(TreeNode<E> *n)	//Should use getRoot as argument.
{
	if(n != NULL)
	{
		printPostOrder(n -> left);
		printPostOrder(n -> right);

		cout << n->element << endl;
	}
}

template<class E>
void BSTree<E>::printPreOrder(TreeNode<E> *n)	//Should use getRoot as argument.
{
	if(n != NULL)
	{
		cout << n->element << endl;

		printPreOrder(n -> left);
		printPreOrder(n -> right);
	}
}

template<class E>
TreeNode<E>* BSTree<E>::getRoot()
{
	if(root != NULL)
	{
		return root;
	}
	else
	{
		return 0;
	}
}

template<class E>
int BSTree<E>::getSize()		//To be used with getRoot() method.
{
	return size;
}
