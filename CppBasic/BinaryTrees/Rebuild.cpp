#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
    Node *right;
    Node *left;
    int value;

    Node(int value, Node *left = nullptr, Node *right = nullptr)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

Node *rebuild(vector<int> &IOrder, vector<int> PreOrder)
{
    vector<int>::iterator BeginP = PreOrder.begin();
    vector<int>::iterator BeginI = IOrder.begin();

    if (IOrder.empty())
    {
        return nullptr;
    }

    int root = *BeginP;

    vector<int> left;
    vector<int> right;
    while (*BeginI != root)
    {
        left.push_back(*BeginI);
        BeginI++;
    }
    BeginI++;
    right.insert(right.end(), BeginI, IOrder.end());

    vector<int> leftP;
    vector<int> rightP;

    for (int n = 1; n <= left.size(); n++)
    {
        leftP.push_back(PreOrder[n]);
    }
    for (int n = left.size() + 1; n < PreOrder.size(); n++)
    {
        rightP.push_back(PreOrder[n]);
    }

    Node *Root = new Node(root, rebuild(left, leftP), rebuild(right, rightP));

    return Root;
}
Node *rebuildPost(vector<int> &IOrder, vector<int> PostOrder)
{
    vector<int>::iterator EndP = PostOrder.end() - 1;
    vector<int>::iterator BeginI = IOrder.begin();

    if (IOrder.empty())
    {
        return nullptr;
    }

    int root = *EndP;

    vector<int> left;
    vector<int> right;
    while (*BeginI != root)
    {
        left.push_back(*BeginI);
        BeginI++;
    }
    BeginI++;
    right.insert(right.end(), BeginI, IOrder.end());

    vector<int> leftP;
    vector<int> rightP;

    for (int n = 0; n < left.size(); n++)
    {
        leftP.push_back(PostOrder[n]);
    }
    for (int n = left.size(); n < PostOrder.size() - 1; n++)
    {
        rightP.push_back(PostOrder[n]);
    }

    Node *Root = new Node(root, rebuildPost(left, leftP), rebuildPost(right, rightP));

    return Root;
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

int main()
{
    vector<int> PreOrder = {1, 2, 4, 5, 3, 6};
    vector<int> IOrder = {4, 2, 5, 1, 3, 6};

    vector<int> PostOrder = {4, 5, 2, 6, 3, 1};
    Node *tree = rebuild(IOrder, PreOrder);
    Node *tree2 = rebuildPost(IOrder, PostOrder);
    printLOGeneration(tree);
    printLOGeneration(tree2);
    return 0;
}