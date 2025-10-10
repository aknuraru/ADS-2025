#include <iostream>

using namespace std;

struct Node{
    int key;
    int cnt;
    Node* left;
    Node* right;
    Node(int k) : key(k), cnt(1), left(nullptr), right(nullptr){};
};

Node* add(Node* root, int x){
    if(root == nullptr)
        return new Node(x);
    if(x < root->key)
        root->left = add(root->left, x);
    else if(x > root->key)
        root->right = add(root->right, x);
    else
        root->cnt++;
    return root;
}

int get_counter(Node* root, int x){
    if(root == nullptr)
        return 0;
    if(x < root->key)
        return get_counter(root->left, x);
    else if(x > root->key)
        return get_counter(root->right, x);
    else
        return root->cnt;
}

Node* getMin(Node* root) {
	while (root->left) {
		root = root->left;
	}
	return root;
}

Node* delete_node(Node* root, int x){
    if(root == nullptr)
        return nullptr;
    if(x < root->key)
        root->left = delete_node(root->left, x);
    else if(x > root->key)
        root->right = delete_node(root->right, x);
    else{
        if(root->cnt > 1){
            root->cnt--;
            return root;
        }else if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }else if(root->left == nullptr){
            Node* templ = root->right;
            delete root;
            return templ;
        }else if(root->right == nullptr){
            Node* templ = root->left;
            delete root;
            return templ;
        }else{
            Node* temp = getMin(root->right);
			root->key = temp->key;
            root->cnt = temp->cnt;
            temp->cnt = 1;
            root->right = delete_node(root->right, temp->key);
        }
    }
    return root;
}

int main(){
    int n;
    Node* root = nullptr;
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        int x;
        cin >> str >> x;
        if(str == "insert")
            root = add(root, x);
        else if(str == "cnt")
            cout << get_counter(root, x) << endl;
        else if(str == "delete")
            root = delete_node(root, x);
    }
    return 0;
}