#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next = NULL;
    Node<T> *prev = NULL;
};

template <class T>
class LinkedList
{
public:
    Node<T> *head;
    Node<T> *tail;

    LinkedList<T>()
    {
        head = NULL;
        tail = NULL;
    }
    void pushBack(T value)
    {
        Node<T> *newnode = new Node<T>;
        newnode->data = value;
        
        if (!head)
            head = tail = newnode;
        else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    void push(T value)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = value;

        if (head != NULL)
        {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
    }

    int insertAtPositoin(T val, int index) 
    {
        if(index < 0 || index > size())
            return 0;
        Node<T> *itt = head;
        Node<T> *newNode = new Node<T>;
            newNode->data = val;

        if (index == 0) {push(val); return 1;}

        while(--index)
            itt = itt->next;

        newNode->next = itt->next;
        itt->next = newNode;
        newNode->prev = itt;
        newNode->next->prev = newNode;
        return 1;
    }

    void display()
    {
        if (!head)
            cout << "Is empty\n";
        else
        {
            Node<T> *cur = head;
            while(cur != NULL)
            {
                cout << cur->data << " ";
                cur = cur->next;
            }
        }
    }

    void rDisplay()
    {
        if (!tail)
            cout << "Is empty\n";
        else
        {
            Node<T> *cur = tail;
            while (cur != NULL)
            {
                cout << cur->data << " ";
                cur = cur->prev;
            }
        }
    }

    bool isFound(T value)
    {
        Node<T> *cur = head;
        while (cur)
        {
            if (cur->data == value)
                return 1;
            cur = cur->next;
        }
        return 0;
    }

    T atPosition(int index) 
    {
        if (index < 0) {
            Node<T> *cur = tail;
            while(++index)
                cur = cur->prev;
            return cur->data;
        }
        else {
            if(!head)
                return -1;
            Node<T> *cur = head;
            while(index--)
                cur = cur->next;
            return cur->data;
        }
    }

    bool isEmpty()
    {
        return !head;
    }

    int size()
    {
        if (!head)
            return 0;
            
        Node<T> *temp = head;
        int cnt = 0;
        while (temp)
        {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

    int search(T value)
    {
        Node<T> *cur = head;
        int cnt = -1;
        while(cur)
        {
            cnt++;
            if(cur->data == value)
                return cnt;
            cur = cur->next;
        }
        return -1;
    }

    int pop() {
        if(!head)
            return -1;
        Node<T> *tmp = head;
        head = head->next;
        head->prev = NULL;
        delete tmp;
        return 1;
    }

    int popBack() {
        if (!head)
            return -1;
        Node<T> *tmp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete tmp;
        return 1;
    }

    int deleteByIndex(int index)
    {
        if (!head || index > size() || index < 0) return -1;
        if (index == 0){pop(); return 1;}
        if (index == size()-1) {popBack(); return 1;}

        Node<T> *tpr = head, *tmp;
        while (--index)
            tpr = tpr->next;
        tmp = tpr->next;
        tpr->next->next->prev = tpr;
        tpr->next = tpr->next->next;
        delete tmp;
    }

    int deleteByValue(T value)
    {   
        return deleteByIndex(search(value));
    }
};
