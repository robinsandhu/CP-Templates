#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PB push_back
#define MP make_pair
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define PI 3.141592653589793238

using namespace std;

struct Node{
    ll key;
    Node* left; Node* right;
    ll ht;
    Node(ll k): key{k}, left{NULL}, right{NULL}, ht{0} {}
};

ll height(Node *root){
	if(root==NULL){
		return -1;
	}
	return max(height(root->left), height(root->right))+1;
}

Node* genNode(ll key){
    return new Node(key);
}

Node* insert(Node *root, ll k){
    if(root==NULL){
        return genNode(k);
    }else if(k<root->key){
        root->left = insert(root->left, k);
    }else if(k>root->key){
        root->right = insert(root->right, k);
    }
    return root;
}

bool search(Node* root, ll k){
    if(root==NULL){
        return false;
    }else if(k==root->key){
        return true;
    }else if(k>root->key){
        return search(root->right, k);
    }else if(k<root->key){
        return search(root->left, k);
    }
}

//utility function 
ll findMin(Node *root){
    if(root->left!=NULL){
        findMin(root->left);
    }
    return root->key;
}

Node* del(Node* root, ll k){
    if(root==NULL){
        cout<<"Invalid OP\n";
    }else{
        if(k<root->key){
            root->left = del(root->left, k);
        }else if(k>root->key){
            root->right = del(root->right, k);
        }else{ //found the culprit
            if(root->left==NULL&&root->right==NULL){
                delete root;
                root=NULL;
                return root;
            }else if(root->left==NULL){
                Node *tmp=root;
                root=root->right;
                delete tmp;
                return root;
            }else if(root->right==NULL){
                Node *tmp=root;
                root=root->left;
                delete tmp;
                return root;
            }else{
                root->key = findMin(root->right);
                root->right = del(root->right, root->key);
                return root;
            }
        }
    }
}

int main(){
    fast;
    Node *root;
    root = insert(root, 20);
	root = insert(root, 15);
	root = insert(root, 22);
	cout << search(root, 22) << "\n";
	root = del(root, 22);
	cout << search(root, 22) << "\n";
    return 0;
}