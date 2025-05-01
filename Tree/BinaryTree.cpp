#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree
{
    Node *root;

public:
    BinaryTree()
    {
        root = nullptr;
    }

    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left == nullptr)
            {
                temp->left = newNode; // Fixed: Assign newNode instead of temp
                break;
            }
            else
            {
                q.push(temp->left);
            }
            if (temp->right == nullptr)
            {
                temp->right = newNode; // Fixed: Assign newNode instead of temp
                break;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }

    void inOrder()
    {
        inOrderHelper(root);
    }

private:
    void inOrderHelper(Node *node)
    {
        if (node == nullptr)
        { // Added base case to prevent null pointer dereference
            return;
        }
        inOrderHelper(node->left);  // Traverse left subtree
        cout << node->data << " ";  // Visit root
        inOrderHelper(node->right); // Traverse right subtree
    }
};

int main()
{
    BinaryTree bt;
    bt.insert(5);
    bt.insert(10);
    bt.inOrder(); // Expected output: 5 10
    cout << endl;
    return 0;
}