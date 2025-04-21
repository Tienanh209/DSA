#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Default Constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
    // Parameterized Constructor
    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    // Default Constructor
    LinkedList()
    {
        head = NULL;
    }

    // Function to insert a new node at the first of the linked list
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        this->head = newNode;
    }

    // Function to insert a new node at the end of the linked list
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Fuction to insert a new node at a specific position in the linked list
    void insertAtSpecific(int pos, int value)
    {
        if (pos < 1)
        {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 1)
        {
            insertAtBeginning(value);
            return;
        }
        else
        {
            Node *newNode = new Node(value);
            Node *temp = head;
            for (int i = 1; i < pos - 1 && temp != NULL; i++)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "Out of Range" << endl;
                return;
            }

            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
    }

    void deleteAtBeginning()
    {
        if (head == NULL)
            return;
        Node *nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
    }

    void deleteAtEnd()
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *nodeToDelete = temp->next;
        temp->next = NULL;
        delete nodeToDelete;
    }

    void deteteAtSpecific(int pos)
    {
        if (head == NULL)
            return;
        if (pos == 1)
        {
            deleteAtBeginning();
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL)
        {
            cout << "Out of Range" << endl;
        }
        else
        {
            Node *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
        return;
    }

    // Function to search for a node with a given key in the linked list
    int search(int key)
    {
        if (head == NULL)
            return -1;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
                return 1;
            temp = temp->next;
        }
        return -1; // Key not found
    }

    // Function return size of linked list
    int size()
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertAtSpecific(1, 25);
    list.insertAtSpecific(4, 35);
    list.printList();
    list.deleteAtEnd();
    list.printList();

    // cout << "Length of the list: " << list.size() << endl;
    // cout << "Is 30 present in the list? " << list.search(30) << endl;
    // cout << "Is 22 present in the list? " << list.search(22) << endl;
    // list.printList();
    // list.deleteAtBeginning();
    // list.deleteAtEnd();
    // list.deteteAtSpecific(4);
    // list.printList();
    return 0;
}
