#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    this->data = val;
    left = NULL;
    right = NULL;
  }
};

//O(logn) -> insert 
Node* buildBST(int val, Node *root) {
  if (root == NULL) {
    root = new Node(val);
	return root;
  } else {
    if (val < root->data) {
      // val -> left subtree
      root->left = buildBST(val, root->left);
    } else {
      // val ->right subtree
      root->right = buildBST(val, root->right);
    }
  }
	return root;
}

void preorderTraversal(Node* root) {
	if(root == NULL)
		return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void inorderTraversal(Node* root) {
	if(root == NULL)
		return;
	inorderTraversal(root->left);
	cout << root->data << " ";
	inorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
	if(root == NULL)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout << root->data << " ";
}


void createTree(Node* &root) {
  cout << "Enter the value for Node: " << endl;
  int val;
  cin >> val;

  while (val != -1) {
    root = buildBST(val, root);
    cout << "Enter the value for Node: " << endl;
    cin >> val;
  }
}

void levelOrderTraversal(Node *root) {
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    Node *front = q.front();
    q.pop();
	
    if (front == NULL) {
      cout << endl;
      if (!q.empty()) {
        q.push(NULL);
      }
    } 
	else {
	  cout << front->data << " ";
      if (front->left) {
        q.push(front->left);
      }
      if (front->right) {
        q.push(front->right);
      }
    }
  }
}

int getMin(Node* root) {
	if(root == NULL) {
		return -1;
	}
	while(root->left != NULL) {
		root = root->left;
	}
	//iska mtlb, jab main yaha pohochunga
	//tab root extreme left pr hoga
	return root->data;
}

int getMax(Node* root) {
	if(root == NULL) {
		return -1;
	}
	while(root->right != NULL) {
		root = root->right;
	}
	//iska mtlb, jab main yaha pohochunga
	//tab root extreme left pr hoga
	return root->data;
}

bool searchBST(Node* root, int target) {
	if(root == NULL) {
		return false;
	}
	if(root->data == target) {
		return true;
	}
	else {
		//data != target
		//decide -> left jau ya right jau
		if(target < root->data) {
			//left jao
			bool leftAns = searchBST(root->left, target);
			if(leftAns == true)
				return true;
		}
		else {
			//right jao
			bool rightAns = searchBST(root->right,  target);
			if(rightAns == true)
				return true;
		}
	}
	//agar leftAns / rightAns is false;
	return false;
}

Node* deleteFromBST(Node* root, int target) {
	
}

int main() {
	Node *root = NULL;
	createTree(root);
	cout << "Printing Level Order:" << endl;
	levelOrderTraversal(root);
	cout << endl << "inorder: ";
	inorderTraversal(root);
	cout << endl << "preorder: ";
	preorderTraversal(root);
	cout << endl << "postorder: ";
	postorderTraversal(root);
	cout << endl;
	//NOTE: inorder of BST is always sorted
	cout << "Min Element: "<< getMin(root) << endl;
	cout << "Max Element: "<< getMax(root) << endl;
	bool searchAns = searchBST(root, 251);
	if(searchAns) 
		cout << "Node Found" << endl;
	else
		cout << "Node not found" << endl;
	
  return 0;
}