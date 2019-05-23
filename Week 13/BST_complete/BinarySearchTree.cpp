/**
Terminologies used in Trees:
Root - The top node in a tree.
Parent - The converse notion of a child.
Siblings - Nodes with the same parent.
Descendant - A node reachable by repeated proceeding from parent to child.
Ancestor - A node reachable by repeated proceeding from child to parent.
Leaf - A node with no children.
Internal node - A node with at least one child.
External node - A node with no children.
Degree - Number of sub trees of a node.
Edge - Connection between one node to another.
Path - A sequence of nodes and edges connecting a node with a descendant.
Level - The level of a node is defined by 1 + (the number of connections between the node and the root).
Height of node - The height of a node is the number of edges on the longest downward path between that node and a leaf.
Height of tree - The height of a tree is the height of its root node.
Depth - The depth of a node is the number of edges from the node to the tree's root node.
Forest - A forest is a set of n >= 0 disjoint trees.
**/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d = 0, Node* l = nullptr, Node* r = nullptr) {
        data = d;
        left = l;
        right = r;
    }
};

class BST {
    Node* root;
    int size;

public:
    BST();
    ~BST();
    BST(const BST& other);
    BST& operator=(const BST& other);

    int getMin() const;
    int getMax() const;
    int getSize() const;
    bool isEmpty() const;

    void push(int x);
    void pop(int x);
    void popMin();
    void popMax();

    int getLevel(int x);
    int getHeightOfNode(int x);
    int getHeightOfTree();
    int getDepth(int x);

    bool contains(int x);
    Node* search(int x);

    void clear();
    void getElementsAtLevel(vector<int>& v, int k);

    void preorder();
    void inorder();

private:
    void copyTree(const BST& other);
    Node* copySubtreeFromNode(Node* node);
    Node* pop(Node* node, int x);
    void destroySubtree(Node*& node);
    int calcHeightOfNode(Node* node);
    void print_preorder(Node* node);
    void print_inorder(Node* node);
    void getElementsAtLevel(vector<int>& v, Node* node, int k);
};

BST::BST() {
    root = nullptr;
    size = 0;
}

BST::~BST() {
    destroySubtree(root);
}

BST::BST(const BST& other) {
    copySubtreeFromNode(other.root);
}

BST& BST::operator=(const BST& other) {
    if (this != &other) {
        destroySubtree(root);
        copySubtreeFromNode(other.root);
    }
    return *this;
}

Node* BST::copySubtreeFromNode(Node* otherNode) {
    if (otherNode == nullptr) {
        return nullptr;
    }
    Node* node = new Node(otherNode->data);
    node->left = copySubtreeFromNode(otherNode->left);
    node->right = copySubtreeFromNode(otherNode->right);
    size++;
    return node;
}

void BST::copyTree(const BST& other) {
    root = copySubtreeFromNode(other.root);
}

void BST::clear() {
    destroySubtree(root);
}

void BST::destroySubtree(Node*& node) {
    if (node == nullptr) {
        return;
    }
    destroySubtree(node->left);
    destroySubtree(node->right);

    delete node;
    node = nullptr;
    size--;
}

int BST::getSize() const {
    return size;
}

bool BST::isEmpty() const {
    return size == 0;
}

int BST::getMin() const {
    assert(!isEmpty());
    Node* tmp = root;
    while (tmp->left != nullptr) {
        tmp = tmp->left;
    }
    return tmp->data;
}

int BST::getMax() const {
    assert(!isEmpty());
    Node* tmp = root;
    while (tmp->right != nullptr) {
        tmp = tmp->right;
    }
    return tmp->data;
}

void BST::push(int x) {
    if (contains(x)) {
       return;
    }

    Node* tmp = root;
    Node* parent = nullptr;
    while (tmp != nullptr) {
        parent = tmp;
        if (x <= tmp->data) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }

    tmp = new Node(x);
    if (size == 0) {
        root = tmp;
    } else {
        if (x <= parent->data) {
            parent->left = tmp;
        } else {
            parent->right = tmp;
        }
    }
    size++;
}

bool BST::contains(int x) {
    Node* node = search(x);
    return node != nullptr;
}

Node* BST::search(int x) {
    Node* tmp = root;
    while (tmp != nullptr && tmp->data != x) {
        if (x <= tmp->data) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }
    return tmp;
}

void BST::pop(int x) {
    root = pop(root, x);
}

Node* BST::pop(Node* node, int x) {
    if (node == nullptr) {
        return nullptr;
    } else if (x < node->data) {
        node->left = pop(node->left, x);
        return node;
    } else if (x > node->data) {
        node->right = pop(node->right, x);
        return node;
    } else { /// we have found the node to delete
        if (node->left == nullptr && node->right == nullptr) { /// 'node' is leaf
            delete node;
            size--;
            return nullptr;
        } else if (node->left != nullptr && node->right == nullptr) { /// 'node' has only one child - the left one
            Node* nodeToReturn = node->left;
            delete node;
            size--;
            return nodeToReturn;
        } else if (node->left == nullptr && node->right != nullptr) { /// 'node' has only one child - the right one
            Node* nodeToReturn = node->right;
            delete node;
            size--;
            return nodeToReturn;
        } else { /// 'node' has 2 childs
            Node* nodeToDelete = node;
            node = node->left;
            if (node->right == nullptr) {
                node->right = nodeToDelete->right;
                delete nodeToDelete;
                size--;
                return node;
            } else {
                Node* parentOfNode = nodeToDelete;
                while (node->right != nullptr) {
                    parentOfNode = node;
                    node = node->right;
                }
                swap(node->data, nodeToDelete->data); /// now we should delete 'node' instead of 'nodeToDelete'
                parentOfNode->right = node->left;
                delete node;
                size--;
                return nodeToDelete;
            }
        }
    }
}

void BST::popMin() {
    if (root == nullptr) {
        return;
    }

    Node* parent = nullptr;
    Node* tmp = root;
    while (tmp->left != nullptr) {
        parent = tmp;
        tmp = tmp->left;
    }

    if (parent != nullptr) {
        parent->left = tmp->right;
    } else { /// in case when root has no left subtree, i.e. root is the minimum element in the tree, or
             /// when we have only one node - the root
        root = tmp->right;
    }

    delete tmp;
    size--;
}

void BST::popMax() {
    if (root == nullptr)
        return;

    Node* parent = nullptr;
    Node* tmp = root;
    while (tmp->right != nullptr) {
        parent = tmp;
        tmp = tmp->right;
    }

    if (parent != nullptr) {
        parent->right = tmp->left;
    } else { /// in case when root has no right subtree, i.e. root is the maximum element in the tree, or
             /// when we have only one node - the root
        root = tmp->left;
    }

    delete tmp;
    size--;
}

int BST::calcHeightOfNode(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    return 1 + max(calcHeightOfNode(node->left),
                   calcHeightOfNode(node->right));
}

int BST::getHeightOfNode(int x) {
    Node* tmp = search(x);
    return calcHeightOfNode(tmp) - 1;
}

int BST::getHeightOfTree() {
    if (root == nullptr) {
        return -1;
    }
    return calcHeightOfNode(root) - 1;
}

int BST::getLevel(int x) {
    Node* tmp = root;
    int level = 1;
    while (tmp != nullptr) {
        if (x < tmp->data) {
            tmp = tmp->left;
        } else if (x > tmp->data) {
            tmp = tmp->right;
        } else {
            return level;
        }
        level++;
    }

    return 0;
}

int BST::getDepth(int x) {
    return getLevel(x) - 1;
}

void BST::preorder() {
    print_preorder(root);
    cout << endl;
}

void BST::print_preorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->data << " ";
    print_preorder(node->left);
    print_preorder(node->right);
}

void BST::inorder() {
    print_inorder(root);
    cout << endl;
}

void BST::print_inorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    print_inorder(node->left);
    cout << node->data << " ";
    print_inorder(node->right);
}

void BST::getElementsAtLevel(vector<int>& v, int k) {
    assert(k >= 1);
    getElementsAtLevel(v, root, k);
}

void BST::getElementsAtLevel(vector<int>& v, Node* node, int k) {
    if (node == nullptr) {
        return;
    }
    if (k == 1) {
        v.push_back(node->data);
        return;
    }
    getElementsAtLevel(v, node->left, k - 1);
    getElementsAtLevel(v, node->right, k - 1);
}


int main()
{
    BST T;
    T.push(7);
    T.push(4);
    T.push(1);
    T.push(2);
    T.push(3);
    T.push(5);
    T.push(9);
    T.push(8);
    T.push(13);
    T.push(10);
    T.push(14);
    cout << "Size of tree: " << T.getSize() << endl;

    for( int i = 1; i <= 6; i++ )
    {
        cout << "For node: " << i << endl;
        cout << "Level:  " << T.getLevel(i) << endl;
        cout << "Depth:  " << T.getDepth(i) << endl;
        cout << "Height: " << T.getHeightOfNode(i) << endl << endl;;
    }

    T.preorder();

    T.clear();
    /*T.push(5);
    T.push(1);
    T.push(10);
    T.push(2);
    T.push(11);
    T.push(0);
    T.push(7);*/
    T.push(10);
    T.push(5);
    T.push(20);
    T.push(1);
    T.push(7);
    T.push(11);
    T.push(25);
    T.push(0);
    T.push(6);
    T.push(17);

    vector <int> v;
    int k = 3;
    T.getElementsAtLevel(v, k);
    for( int i = 0; i < v.size(); i++ )
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
