#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *next;

    Node(int v, Node *n = nullptr)
    {
        value = v;
        next = n;
    };
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);

    Node *first_element = new Node(12);

    Node *second_element = new Node(13);

    first_element->next = second_element;

    for (Node *node = first_element; node != nullptr; node = node->next)
    {
        cout << node->value;
    }
}