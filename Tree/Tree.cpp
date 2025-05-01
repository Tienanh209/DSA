#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;

    Node(int val)
    {
        this->data = val;
    }
};

class Tree
{
    Node *root;

public:
    Tree()
    {
        root = nullptr;
    }

    void insertNode(int val)
    {
        if (root == nullptr)
        {
            root = new Node(val);
            return;
        }
        root->children.push_back(new Node(val));
    }

    void removeNode()
    {
        if (root == nullptr)
        {
            cout << "Tree null" << endl;
            return;
        }
        root->children.pop_back();
    }

    void printTree()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        printTreeRecursive(root);
    }

private:
    void printTreeRecursive(Node *node)
    {
        if (!node)
            return;                        // Điều kiện dừng
        cout << node->data << " ";         // In dữ liệu của node hiện tại
        for (Node *child : node->children) // Duyệt qua tất cả các con
        {
            printTreeRecursive(child); // Gọi đệ quy cho từng con
        }
    }
};

int main()
{
    Tree t;
    t.insertNode(20);
    t.insertNode(30);
    t.removeNode();
    t.printTree();
};