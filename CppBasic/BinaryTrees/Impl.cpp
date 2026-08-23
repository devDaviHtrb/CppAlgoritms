#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
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
                this->right = node;
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
                this->left = node;
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
            root->right = this->deleteNode(root->value, root->right);
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

    // dfs
    void printPO(Node *root)
    {
        if (root == nullptr)
            return;

        printPO(root->left);
        printPO(root->right);
        cout << root->value << ", ";
    }

    void printIO(Node *root)
    {
        if (root == nullptr)
            return;

        printIO(root->left);
        cout << root->value << ", ";
        printIO(root->right);
    }

    void printPrO(Node *root)
    {
        if (root == nullptr)
            return;

        cout << root->value << ", ";
        printPrO(root->left);
        printPrO(root->right);
    }

    void printLo(Node *root)
    {
        int cont = 0;
        if (root == nullptr)
            return;

        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            cont++;
            Node *current = q.front();
            q.pop();
            cout << current->value << " ";
            if (current->left != nullptr)
            {
                q.push(current->left);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
    }

    void printLOGeneration(Node *root)
    {
        if (root == nullptr)
            return;
        queue<Node *> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            int q_size = nodes.size();
            vector<Node *> generation = {};
            for (int n = 0; n < q_size; n++)
            {
                Node *curr = nodes.front();

                generation.push_back(curr);
                nodes.pop();

                if (generation[n]->left != nullptr)
                {
                    nodes.push(generation[n]->left);
                }
                if (generation[n]->right != nullptr)
                {
                    nodes.push(generation[n]->right);
                }

                cout << curr->value << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    BinarySearchTree *tree = new BinarySearchTree();

    vector<int> valores = {15, 8, 22, 4, 11, 18, 24, 2, 6, 9, 13, 16, 20, 23, 25};

    for (int v : valores)
    {
        tree->insert(v);
    }

    cout << "Impressao por Geracoes (Linhas separadas):\n";
    tree->printLOGeneration(tree->Root);

    return 0;
}