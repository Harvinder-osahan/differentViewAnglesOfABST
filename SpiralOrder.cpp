#include<bits/stdc++.h>
using namespace std;

struct Node{
int data;
Node* left, *right;
} *root=NULL;

Node* N(int val){

Node* h= new Node;
h->data=val;
h->left=h->right=NULL;
return h;
}
Node* Ins(Node* root, int val){
if(root==NULL) return N(val);

if(val>root->data)
    root->left= Ins(root->left, val);
else
    root->right=Ins(root->right, val);
return root;
}

bool printLevelLeftToRight(Node* root, int level)
{
    if (root == nullptr)
        return false;

    if (level == 1)
    {
        cout << root->data << " ";
        return true;
    }

    bool left = printLevelLeftToRight(root->left, level - 1);
    bool right = printLevelLeftToRight(root->right, level - 1);

    return left || right;
}


bool printLevelRightToLeft(Node* root, int level)
{
    if (root == nullptr)
        return false;

    if (level == 1)
    {
        cout << root->data << " ";
        return true;
    }

    // process right child before left child
    bool right = printLevelRightToLeft(root->right, level - 1);
    bool left = printLevelRightToLeft(root->left, level - 1);

    return right || left;
}

// Function to print level order traversal of given binary tree
void spiralOrderTraversal(Node* root)
{
    if (root == nullptr)
        return;

    // start from level 1 -- till height of the tree
    int level = 1;

    // run till either function returns false
    while (printLevelLeftToRight(root, level++) &&
          printLevelRightToLeft(root, level++));
}


/*
void preorder(Node *root, int level, unordered_map<int, list<int>> &map)
{

	if (root == NULL)
		return;
	if (level & 0)
		map[level].push_back(root->data);
	else
		map[level].push_front(root->data);


	preorder(root->left, level + 1, map);
	preorder(root->right, level + 1, map);
}


void levelOrderTraversal(Node *root)
{

	unordered_map<int, list<int>> map;


	preorder(root, 0, map);


	for (int i = 0; map[i].size() > 0; i++)
	{
		cout << "Level " << i << ": ";
		for (int i: map[i])
		   {cout << i << " ";}

		cout << endl;
	}
}
*/
int main()
{
    Node* root=NULL;
    int n,c;
    cin>>n;
    while(n--){
        cin>>c;
        root=Ins(root,c);
    }
	spiralOrderTraversal(root);
return 0;
}
