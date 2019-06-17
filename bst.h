#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode( int x ): val(x), left(NULL), right(NULL) { }
};

/* Class to hold a Binary Search Tree (BST)
 */
class BST {

private:
	TreeNode *root = NULL;
		
public:
	
/* A recursive function that is used to build a BST from a 
 * given set of values in vector v
 */
	TreeNode * buildBST( vector<int>& v, int low, int high )
	{
		int mid;
		TreeNode *newNode = NULL;
		if ( low <= high )
		{
			mid = (low + high)/2;
			
			newNode = new TreeNode( v[ mid ] );
			newNode->left = buildBST( v, low, mid-1 );
			newNode->right = buildBST( v, mid+1, high );
		}
		return newNode;
	}

	void buildTree( vector<int> v ) {
		// Sort the given array
		sort( v.begin(), v.end() );
		root = buildBST( v, 0, v.size()-1 );
	}
	
	vector<int> inorder( ) {
		vector<int> res;
		if ( root != NULL )
			inorderRec( root, res );
		return res;
	}

/* The inorder traversal of a tree
 */
	void inorderRec( TreeNode *node, vector<int>& res ) {
		if ( node->left != NULL ) {
			inorderRec( node->left, res );
		}
		res.push_back( node->val );
		if ( node->right != NULL ) {
			inorderRec( node->right, res );
		}
	}

	TreeNode* getNode( int data ) {
		vector<TreeNode*> res;
		if ( root != NULL )
			preorderRec( root, data, res );
		
		return (!res.empty())?res[0]:NULL;
	}
	
	void preorderRec( TreeNode *node, int currData, vector<TreeNode*>& res ) {
		if ( node->val == currData )
			res.push_back( node );
		
		if ( node->left != NULL ) {
                preorderRec( node->left, currData, res );
           }
		if ( node->right != NULL ) {
			preorderRec( node->right, currData, res );
           }
     }
	
	TreeNode* inOrderSuccessor( TreeNode* node ) {
		
		TreeNode* curr;
		TreeNode* succ;
		
		if ( node->right != NULL ) {
			curr = node->right;
			while ( curr->left != NULL ) {
				curr = curr->left;
			}
			return curr;
		}
		
		curr = this->root;
		succ = NULL;
		while( curr != node ) {
			if ( node->val < curr->val ) {
				succ = curr;
				curr = curr->left;
			} else {
				curr = curr->right;
			}
		}
		
		return succ;
	}

/* A function that checks if the tree rooted at "root"
 * is indeed a Binary Search Tree.
 */
	bool isBST( TreeNode *root ) {
		bool b = true;
		static TreeNode* last = NULL;
		if ( b && ( root->left != NULL ) ) {
			b = isBST( root->left );
		}
		if ( last != NULL && ( last->val > root->val ) ) {
			b = false;
		}
		last = root;
		if ( b && ( root->right != NULL ) ) {
			b = isBST( root->right );
		}
		return b;
	}

	bool isBSTUtil() {
		if ( root != NULL )
			return isBST( root );
	}

/* Function to check if the trees rooted at root1 and
 * and root2 are indeed the same tree. That is, they have
 * the same structure and same data for all the nodes.
 */
	bool isSameTree( TreeNode *root1, TreeNode *root2 ) {
		if ( root1 == NULL || root2 == NULL )
			if ( root1 == NULL && root2 == NULL )
				return true;
			else
				return false;
		if ( root1->val != root2->val ) {
			return false;
		}
		bool b1 = true;
		if ( root1->left != NULL ) {
			if ( root2->left == NULL )
				return false;
			b1 = isSameTree( root1->left, root2->left  );
		}
		if ( !b1 )
			return false;
		if ( root1->right != NULL ) {
			if ( root2->right == NULL )
				return false;
			b1 = isSameTree( root1->left, root2->left );
		}
		return b1;
	}

	bool isSameBSTUtil(TreeNode *outroot) {
		return isSameTree( this->root, outroot );
	}
	
};
