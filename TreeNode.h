//Author: Brian Do

using namespace std;

template<class E>				//Creating a template class of data type E.

class TreeNode
{
	TreeNode();
	TreeNode(E data);
	~TreeNode();

	E element;

	TreeNode* left;				//Pointers to left and right child nodes.
	TreeNode* right;
};

template<class E>
TreeNode<E>::TreeNode()			//Default constructor initializes both pointers to NULL.
{
	left = NULL;
	right = NULL;
}

template<class E>
TreeNode<E>::TreeNode(E data)	//Constructor initializes both pointers to NULL.
{								//Sets data argument to the element of the node.
	left = NULL;	
	right = NULL;

	element = data;
}

template<class E>
TreeNode<E>::~TreeNode()
{

}