///
///  Not Completed
///

#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T key;
    Node<T> *left = NULL;
    Node<T> *right = NULL;
};

template <class T>
class Tree
{

public:

    Node<T> *root;

    Tree<T>()
    {
        root = NULL;
    }

    Tree<T>(T key)
    {
        root->key = key;
    }

    void insert(T key) 
    {
        Node<T> *newLeaf = new Node<T>, *tmp;
        newLeaf->key = key;

        if (!root){
            root = newLeaf;
            return;
        }
        else
            insert(key, root);
    }  

void insert(T key, Node<T>* node)
    {

        if (key < node->key)
        {
            if (node->left)
                insert(key, node->left);
            else {
                node->left = new Node<T>;
                node->left->key = key;
            }
        }
        else if (key > node->key)
        {
            if (node->right)
                insert(key, node->right);
            else
            {
                node->right = new Node<T>;
                node->right->key = key;
            }
        }
    }

    preOrder(Node<T>* node)
    {
        if(!root)
            return -1;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->rigth);
    }
};

int main()
{
    Tree<int> *tree = new Tree<int>(2);
    tree->insert(4);
    tree->preOrder(tree);
    ///
    /// Not Completed
    ///

}