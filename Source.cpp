#include"iostream"
#include"string"
#include"Windows.h"
using namespace std;

template<typename Data>
class Node
{
public:
	Node();
	~Node();

	int D;

	Node * Left;

	Node * Right;
private:

};

template<typename Data>
Node::Node()
{
}

template<typename Data>
Node::~Node()
{
}



template<typename Data, class Node>
Node * Insert(Node * Root, int data) {    // Inser Into The BST.

	if (Root == NULL) {   // If The Root is EMPTY
		Root = new Node();
		Root->D = data;
		Root->Left = Root->Right = NULL;
	}
	else if (data == Root->D) {
		Root->D++;
		return false;
	}

	else if (data < Root->D) {    // If The Value is Less Than The Root go LEFT.
		Root->Left = Insert(Root->Left, data);
	}
	else {                       // If The Value is Bigger Than The Root go Right.
		Root->Right = Inser(Root->Right, data);
	}
	return Root;
}


template<typename Data, class Node>
Node * Delete(Node * Root, int data) {   // Delete a Node.

	if (Root == NULL) {   // No Children.
		return Root;
	}
	else if (data < Root->D) {
		Root->Left = Delete(Root->Left, data);
	}
	else if (data > Root->D) {
		Root->Right = Delete(Root->Right, data);
	}

	else {
		if (Root->Left == NULL && Root->Right->Right == NULL) {   // Two Children.
			Root = NULL;
			delete Root;
		}

		else if (Root->Left == NULL) {
			Node * Temp = Root;
			Root = Root->Right;
			delete Temp;
		}
		
		else if (Root->Right == NULL) {
			Node * Temp = Root;
			Root = Root->Left;
			delete Temp;
		}

		else {  // One Child
			Node * Temp = FindMinimum(Root->Right);
			Root->Data = Temp->D;
	        Root->Right = Delete(Root->Right, Temp->D);
		}
	}
	return Root;
}


template<typename Data, class Node>
bool Search(Node * Root, int data) {

	if (Root == NULL) {   // If Equals NULL or Nothing.
		return false;
	}

	else if (data == Root->D) {   // If Element is Found.
		return true;
	}

	else if (data < Root->D) {    // If Element is Less Than The Data go LEFT.
		return Search(Root->Left, data);
	}

	else {                        // If Element is Bigger Than The Data go RIGHT.
		return Search(Root->Right, data);
	}
}


template<typename Data, class Node>
void TraverseInOrder(Node * Root) {   // Go Through or Across One By One.   TRAVERSE is The Same as INORDER
	if (Root == NULL) {
		return;
	}

	TraverseInOrder(Root->Left);

	cout << "Value is : " << Root->D;

	TraverseInOrder(Root->Right);
}


template<typename Data, class Node>
Node * FindMinimum(Node * Root) {

	while (Root->Left != NULL) {
		Root = Root->Left;
	}
	return Root;
}

template<typename Data, class Node>
Node * FindMaximum(Node * Root) {
	
	while (Root->Right != NULL) {
		Root = Root->Right;
	}
	return Root;
}

template<typename Data, class Node>
int LeafCount(Node * Root) {  // Count Number of Leafs in a Tree.    Leaf--> No Childern.
	
	if (Root == NULL) {
		return 0;
	}

	else if (Root->Left == NULL && Root->Right == NULL) {
		return 1;
	}

	else {
		return LeafCount(Root->Left) + LeafCount(Root->Right);
	}
}


























int main() {
	system("pause");
	return 0;
}