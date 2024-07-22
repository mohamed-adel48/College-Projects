#include <iostream>
using namespace std;


template <class T>
struct Node
{
public:
    T data;
    Node<T> *next = NULL;
    Node<T> *prev = NULL;
};

template <class T>
class Deque
{
public:
    Node<T> *head;
    Node<T> *tail;
    int size = 0;

    Deque()
    {
        head = tail = NULL;
    }

    bool isEmpty()
    {
        return !head;
    }

    void pushFront(T item)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = item;
        size++;
        if (!head)
            head = tail = newNode;
        else
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            head->prev = NULL;
        }
    }
    void pushBack(T item)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = item;
        size++;
        if (!head)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    T Front()
    {
        return head->data;
    }
    T Back()
    {
        return tail->data;
    }
    T rFront()
    {
        return tail->data;
    }
    T rBack()
    {
        return head->data;
    }

    int popFront()
    {
        if (!head)
            return 0;
        size--;
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return 1;
        }
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }

    int popBack()
    {

        if (!head)
            return 0;
        size--;
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return 1;
        }
        Node<T> *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        return 1;
    }

    int erase(int index)
    {
        if (!head || index > size || index < 0)
            return 0;
        if (index == 0)
        {
            popFront();
            return 1;
        }
        if (index == size-1) 
        {
            popBack();
            return 1;
        }

        Node<T> *cur = head, *tmp;
        while (--index)
            cur = cur->next;
        tmp = cur->next;
        cur->next->next->prev = cur;
        cur->next = cur->next->next;
        delete tmp;
    }

    int earseByValue(T value) {
        return erase(search(value));
    }

    void display()
    {
        if (!head)
            cout << "The list is Empty" << endl;
        else
        {
            Node<T> *temp = head;
            while (temp)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    int clear()
    {
        if (!head)
            return 0;
        while (head)
            popFront();
        return 1;
    }

    int search(T value)
    {
        Node<T> *temp = head;
        int cnt = -1;
        while (temp)
        {
            cnt++;
            if (temp->data == value)
                return cnt;
            temp = temp->next;
        }
        return -1;
    }
};

int main()
{
    int item;
    Deque<int> q;
    q.pushFront(4);
    q.pushFront(3);
    q.pushFront(2);
    q.display();
    q.pushBack(5);
    q.pushBack(6);
    q.pushBack(7);
    q.display();
    cout << "POP" << endl;
    // q.display();
    // q.popFront();
    cout << " \nMsg is: " << q.erase(0) << endl;
    // q.earseByValue(3);
    q.display();
    q.clear();
    q.display();
    // cout << q.search(7);

    return 0;
}