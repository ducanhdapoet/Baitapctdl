#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = right = nullptr;
        height = 1;
    }
};

int height(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int balanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

void updateHeight(Node* node) {
    node->height = (height(node->left) > height(node->right) ? height(node->left) : height(node->right)) + 1;
}

Node* rotateLeft(Node* z) {
    Node* y = z->right;
    z->right = y->left;
    y->left = z;
    updateHeight(z);
    updateHeight(y);
    return y;
}

Node* rotateRight(Node* z) {
    Node* y = z->left;
    z->left = y->right;
    y->right = z;
    updateHeight(z);
    updateHeight(y);
    return y;
}

Node* rotateLeftRight(Node* z) {
    z->left = rotateLeft(z->left);
    return rotateRight(z);
}

Node* rotateRightLeft(Node* z) {
    z->right = rotateRight(z->right);
    return rotateLeft(z);
}

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    } else {
        return root;
    }
    updateHeight(root);
    int balance = balanceFactor(root);
    if (balance > 1 && key < root->left->data) {
        return rotateRight(root);
    }
    if (balance < -1 && key > root->right->data) {
        return rotateLeft(root);
    }
    if (balance > 1 && key > root->left->data) {
        return rotateLeftRight(root);
    }
    if (balance < -1 && key < root->right->data) {
        return rotateRightLeft(root);
    }
    return root;
}

void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int getHeight(Node* root) {
    return height(root);
}

int main() {
    Node* root = nullptr;
    int n;
    cout << "So phan tu cua cay AVL: ";
    cin >> n;
    cout << "Nhap data cho node: ";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        root = insert(root, num);
    }
    cout << "Cay AVL la: ";
    inOrder(root);
    cout << endl;
    cout << "Chieu cao cua cay AVL la: " << getHeight(root) << endl;
    return 0;
}
