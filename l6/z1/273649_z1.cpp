// Wybrałem Drzewo binarne poniewaz z założenia jest ono dobrze uporządkowane, oraz dodałem algorytm sortujacy w przypadku gdy nasze drzewo powstało np z połączenia dwóch drzew ze sobą 

#include <iostream>
using namespace std;

struct Tree
{
    struct Node
    {
        int data;
        Node* left;
        Node* right;
    };

    Node* rootPTR;

    Tree() // Konstruktor
    {
        rootPTR = nullptr;
    }

    Node* GetNewNode(int data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    Node* Insert(Node* root, int data)
    {
        if (root == nullptr)
        {
            root = GetNewNode(data);
        }
        else if (data <= root->data)
        {
            root->left = Insert(root->left, data);
        }
        else
        {
            root->right = Insert(root->right, data);
        }
        return root;
    }

    void Insert(int data)
    {
        rootPTR = Insert(rootPTR, data);
    }

    void InOrder(Node* root)
    {
        if (root == nullptr) return;
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }

    void PrintTree()
    {
        InOrder(rootPTR);
        cout << endl;
    }

    void CopyToBST(Node* sourceNode, Tree& targetTree)
    {
        if (!sourceNode) return;
        CopyToBST(sourceNode->left, targetTree);
        targetTree.Insert(sourceNode->data);
        CopyToBST(sourceNode->right, targetTree);
    }

    Tree SortTree()
    {
        Tree sortedTree;
        CopyToBST(rootPTR, sortedTree);
        return sortedTree;
    }
};

int main()  
{
    int n;
    cin >> n;

    Tree tree;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        tree.Insert(val);
    }

    cout << "Drzewo przed sortowaniem (in-order): ";
    tree.PrintTree();

    Tree sorted = tree.SortTree();
    cout << "Drzewo posortowane (kopiowane do BST): ";
    sorted.PrintTree();

    return 0;
}

