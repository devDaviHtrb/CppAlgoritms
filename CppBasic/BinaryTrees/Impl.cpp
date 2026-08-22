#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }

    void addNode(Node *node)
    {
        if (node->value > this->value)
        {
            if (this->right != nullptr)
            {
                this->right->addNode(node);
            }
            else
            {
                this->right = node
            }
        }
        else
        {
            if (this->left != nullptr)
            {
                this->left->addNode(node);
            }
            else
            {
                this->left = node
            }
        }
    }
};
struct BinarySearchTree
{
    Node *Root;
    BinarySearchTree()
    {
        Root = nullptr;
    }
    void insert(int value)
    {
        Node *node = new Node(value);
        if (this->Root == nullptr)
        {
            this->Root = node;
        }
        else
        {
            this->Root->addNode(node);
        }
    }

    Node *deleteNode(int value, Node *root)
    {
        if (root == nullptr)
            return nullptr;
        if (root->value < value) // se o nó procurado for maior
        {
            root->right = this->deleteNode(value, root->right);
        }
        else if (root->value > value) // se o nó procurado for menor
        {
            root->left = this->deleteNode(value, root->left);
        }
        else // se achar o nó procurado
        {
            if (root->left == nullptr) // casso 1 e 2
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            // Se o nó procurado tiver 2 subárvores
            Node *current = root->right;
            // Achando o sucessor em ordem -> menor nó da direita
            while (true)
            {
                if (current->left == nullptr)
                {
                    break;
                }
                current = current->left;
            }
            // substitui o valor e apaga o nó do sucessor
            root->value = current->value;
            this->deleteNode(root->value, root > right);
        }
        // retorna a arvore
        return root;
    };

    Node *search(Node *root, int value)
    {
        if (root == nullptr)
            return nullptr;
        if (root->value > value)
        {
            return this->search(root->left, value);
        }
        else if (root->value < value)
        {
            return this->search(root->right, value);
        }
        return root;
    }

    void printPO(Node *root)
    {
        if (root == nullptr)
            return nullptr;

        printPO(root->left)
            printPO(root->right);
        cout << root->value << ", ";
    }

    void printIO(Node *root)
    {
        if (root == nullptr)
            return nullptr;

        printPO(root->left)
                cout
            << root->value << ", ";
        printPO(root->right);
    }

    void printPrO(Node *root)
    {
        if (root == nullptr)
            return nullptr;

        cout << root->value << ", ";
        printPO(root->left)
            printPO(root->right);
    }
};