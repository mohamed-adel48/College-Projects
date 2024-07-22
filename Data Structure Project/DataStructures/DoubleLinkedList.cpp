#include <iostream>

using namespace std;

class DoubleLinkedList
{

public:
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
    };

    Node *first, *last;
    int length;

    void insertFirst(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;

        if (first == NULL || last == NULL)
        {

            first = last = newNode;
            newNode->next = newNode->prev = NULL;
        }
        else
        {

            newNode->next = first;
            newNode->prev = NULL;
            first->prev = newNode;
            first = newNode;
        }
    }

    void insertLast(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;

        if (first == NULL || last == NULL)
        {
            first = last = newNode;
            newNode->next = newNode->prev = NULL;
        }
        else
        {

            newNode->next = NULL;
            newNode->prev = last;
            last->next = newNode;
            last = newNode;
        }
    }

    void displayFirst()
    {
        Node *curr = first;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void displayLast()
    {
        Node *curr = last;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->prev;
        }
        cout << endl;
    }

    void removeFirst()
    {

        if (first == NULL || last == NULL)
        {

            cout << "emptylist";
        }

        else if (first == last)
        {
            delete first;
            last = first = NULL;
        }
        else
        {
            Node *curr = first;
            first = first->next;
            first->prev = NULL;
            delete curr;
        }
    }

    void removeLast()
    {

        if (first == NULL || last == NULL)
        {

            cout << "emptylist";
        }

        else if (first == last)
        {
            delete last;
            last = first = NULL;
        }
        else
        {
            Node *curr = last;
            last = last->prev;
            last->next = NULL;
            delete curr;
        }
    }

    void removeItem(int value)
    {

        Node *curr;
        if (first == NULL || last == NULL)
        {
            cout << "emptylist";
        }
        else if (first->data == value)
        {
            removeFirst();
        }
        else
        {
            curr = first->next; // 3shan ybd2 yshof b3d el first
            while (curr != NULL)
            {
                if (curr->data == value)
                    break;
                curr = curr->next;
            }
        }

        if (curr == NULL)
        {
            cout << "item not found" << endl;
        }
        else if (curr->next == NULL)
        {
            removeLast();
        }
        else
        {

            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
    }
};
