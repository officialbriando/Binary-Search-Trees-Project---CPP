//Author: Brian Do

using namespace std;

template<class E>				//Creating a template class of data type E.

class TreeNode
{
	public:
		TreeNode();
		TreeNode(E data, int k);
		~TreeNode();

		int key;
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
TreeNode<E>::TreeNode(E data, int k)	//Constructor initializes both pointers to NULL.
{								//Sets data argument to the element of the node.
	left = NULL;	
	right = NULL;

	element = data;
	key = k;

}

template<class E>
TreeNode<E>::~TreeNode()
{

}
