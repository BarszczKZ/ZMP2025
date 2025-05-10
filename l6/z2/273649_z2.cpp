#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Tree {
public:
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

    
    Node* ArrayToBalancedTree(int arr[], int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        Node* node = GetNewNode(arr[mid]);
        node->left = ArrayToBalancedTree(arr, start, mid - 1);
        node->right = ArrayToBalancedTree(arr, mid + 1, end);
        return node;
    }

    void BuildFromArray(int arr[], int size) {
        rootPTR = ArrayToBalancedTree(arr, 0, size - 1);
    }

    //  Sklejanie dwóch drzew z nowym korzeniem
    static Tree MergeTrees(Tree& t1, Tree& t2, int rootValue) {
        Tree merged;
        merged.rootPTR = merged.GetNewNode(rootValue);
        merged.rootPTR->left = t1.rootPTR; 
        merged.rootPTR->right = t2.rootPTR;
        return merged;
    }

    //  Wyszukiwanie
    bool Search(Node* node, int value) {
        if (!node) return false;
        if (node->data == value) return true;
        return Search(node->left, value) || Search(node->right, value);
    }

    bool Search(int value) {
        return Search(rootPTR, value);
    }

    //  Wysokość drzewa
    int Height(Node* node) {
        if (!node) return 0;
        return 1 + max(Height(node->left), Height(node->right));
    }

    int Height() {
        return Height(rootPTR);
    }

    // Liczba węzłów: rekurencyjnie przechodzi przez wszystkie węzły i je zlicza
    int CountNodes(Node* node) {
        if (!node) return 0;
        return 1 + CountNodes(node->left) + CountNodes(node->right);
    }

    int CountNodes() {
        return CountNodes(rootPTR);
    }

    // Liczba liści
    int CountLeaves(Node* node) {
        if (!node) return 0;
        if (!node->left && !node->right) return 1;
        return CountLeaves(node->left) + CountLeaves(node->right);
    }

    int CountLeaves() {
        return CountLeaves(rootPTR);
    }

    // Ładne wyświetlanie drzewa bokiem
    void PrettyPrint(Node* node, int indent = 0) {
        if (!node) return;

        PrettyPrint(node->right, indent + 4);
        for (int i = 0; i < indent; ++i) cout << ' ';
        cout << node->data << endl;
        PrettyPrint(node->left, indent + 4);
    }
	// funkcja zewnetrzna 
    void PrettyPrintTree() {
        PrettyPrint(rootPTR);
    }
};

int main() {
    int n1, n2, r, s;
    cin >> n1 >> n2 >> r >> s;

    int* arr1 = new int[n1];
    int* arr2 = new int[n2];

    for (int i = 0; i < n1; ++i) cin >> arr1[i];
    for (int i = 0; i < n2; ++i) cin >> arr2[i];

    Tree t1, t2;
    t1.BuildFromArray(arr1, n1);
    t2.BuildFromArray(arr2, n2);

    Tree merged = Tree::MergeTrees(t1, t2, r);

    cout << "\n--- Ladny wydruk drzewa ---\n";
    merged.PrettyPrintTree();

    cout << "\n--- Statystyki drzewa ---\n";
    cout << "Liczba wezlow: " << merged.CountNodes() << endl;
    cout << "Liczba lisci:  " << merged.CountLeaves() << endl;
    cout << "Wysokosc:     " << merged.Height() << endl;
    cout << "Czy zawiera " << s << "? " << (merged.Search(s) ? "TAK" : "NIE") << endl;

    delete[] arr1;
    delete[] arr2;

    return 0;
}
