#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // Default constructor
    Node()
    {
        this->data = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }
    // Parameterized constructor
    Node(int value)
    {
        this->data = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList
{
public:
    Node *head;

    // Default constructor
    DoublyLinkedList()
    {
        head = nullptr;
    };

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *lastNode = head;
        while (lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->prev = lastNode;
    }

    void insertAtSpecific(int pos, int value)
    {
        Node *newNode = new Node(value);
        if (pos == 1)
        {
            insertAtBeginning(value);
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    int search(int key)
    {
        int pos = 1;
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                return pos;
            }
            pos++;
            temp = temp->next;
        }
        return -1;
    }

    void deleteAtBeginning()
    {
        if (head == nullptr)
            return;

        Node *deleteNode = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        delete deleteNode;
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        Node *deleteNode = temp->next;
        temp->next = nullptr;
        delete deleteNode;
    }

    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~DoublyLinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
};

int main()
{
    DoublyLinkedList dll;
    dll.insertAtBeginning(10);
    dll.insertAtBeginning(20);
    dll.insertAtBeginning(30);
    dll.insertAtEnd(40);
    dll.insertAtSpecific(1, 25);
    dll.printList();

    dll.deleteAtBeginning();
    dll.printList();
    dll.deleteAtEnd();
    dll.printList();

    // cout << "Search for 25: " << dll.search(25) << endl;
}