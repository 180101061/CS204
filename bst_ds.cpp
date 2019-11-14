#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

Node *newNode(int key){
        Node *a = ( Node*)malloc(sizeof( Node));
        a->key=key;
        a->left=NULL;
        a->right=NULL;
        return a;
    }

Node *InsertR( Node *root, int key){
    	if(root == NULL) return newNode(key);
    	root->right =  InsertR(root->right, key);
    	return root;
    }

Node *InsertL( Node *root, int key){
    	if(root == NULL) return newNode(key);
    	root->left =  InsertL(root->left, key);
    	return root;
    }

void inorder( Node* root)
    {
        if (!root) return;
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
    
void preorder( Node* root) {
        if(root == NULL) return;
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }

void postorder( Node* root) {
        if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }

bool Search( Node* root, int key)
    {
        if (root == NULL)
            return false;

        if (root->key == key)
            return true;

        bool l = Search(root->left, key);

        bool r = Search(root->right, key);

        return l || r;
    }


int main(){
  Node *root = NULL;
	root = InsertL(root, 80);
	root = InsertR(root, 54);
	root = InsertL(root, 23);
	root = InsertL(root, 43);
	root = InsertR(root, 5);
	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
    postorder(root);
	cout<<endl;
	cout<<Search(root, 80)<<"\n";
	cout<<Search(root,70)<<"\n";
}
