#include <iostream>
using namespace std;

struct Tree {
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* rootPTR;

    Tree() {
        rootPTR = nullptr;
    }

    Node* GetNewNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    Node* Insert(Node* root, int data) {
        if (root == nullptr) {
            root = GetNewNode(data);
        } else if (data <= root->data) {
            root->left = Insert(root->left, data);
        } else {
            root->right = Insert(root->right, data);
        }
        return root;
    }

    void Insert(int data) {
        rootPTR = Insert(rootPTR, data);
    }

    void InOrder(Node* root) {
        if (root == nullptr) return;
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }

    void PrintTree() {
        InOrder(rootPTR);
        cout << endl;
    }

    void CopyToBST(Node* sourceNode, Tree& targetTree) {
        if (!sourceNode) return;
        CopyToBST(sourceNode->left, targetTree);
        targetTree.Insert(sourceNode->data);
        CopyToBST(sourceNode->right, targetTree);
    }

    Tree SortTree() {
        Tree sortedTree;
        CopyToBST(rootPTR, sortedTree);
        return sortedTree;
    }

    static bool AreIsomorphic(Node* a, Node* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        return AreIsomorphic(a->left, b->left) && AreIsomorphic(a->right, b->right);
    }

    static Node* AddTrees(Node* a, Node* b) {
        if (!a && !b) return nullptr;
        if (!a) return new Node{b->data, AddTrees(nullptr, b->left), AddTrees(nullptr, b->right)};
        if (!b) return new Node{a->data, AddTrees(a->left, nullptr), AddTrees(a->right, nullptr)};
        return new Node{a->data + b->data, AddTrees(a->left, b->left), AddTrees(a->right, b->right)};
    }

    static Node* SubtractTrees(Node* a, Node* b) {
        if (!a && !b) return nullptr;
        if (!a) return new Node{-b->data, SubtractTrees(nullptr, b->left), SubtractTrees(nullptr, b->right)};
        if (!b) return new Node{a->data, SubtractTrees(a->left, nullptr), SubtractTrees(a->right, nullptr)};
        return new Node{a->data - b->data, SubtractTrees(a->left, b->left), SubtractTrees(a->right, b->right)};
    }

    bool operator==(const Tree& other) const {
        return AreIsomorphic(this->rootPTR, other.rootPTR);
    }

    Tree operator+(const Tree& other) const {
        Tree result;
        if (!(*this == other)) {
            cout << "Drzewa nie są izomorficzne – nie można dodać.\n";
            return result;
        }
        result.rootPTR = AddTrees(this->rootPTR, other.rootPTR);
        return result;
    }

    Tree operator-(const Tree& other) const {
        Tree result;
        if (!(*this == other)) {
            cout << "Drzewa nie są izomorficzne – nie można odjąć.\n";
            return result;
        }
        result.rootPTR = SubtractTrees(this->rootPTR, other.rootPTR);
        return result;
    }
};


int main() {
    int n;
    cin >> n;

    Tree t1, t2;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        t1.Insert(val);
    }

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        t2.Insert(val);
    }

    cout << "T1: "; t1.PrintTree();
    cout << "T2: "; t2.PrintTree();

    if (t1 == t2) {
        cout << "Drzewa są izomorficzne.\n";

        Tree sum = t1 + t2;
        cout << "Suma:\n"; sum.PrintTree();

        Tree diff = t1 - t2;
        cout << "Różnica:\n"; diff.PrintTree();
    } else {
        cout << "Drzewa nie są izomorficzne.\n";
    }

    return 0;
}

