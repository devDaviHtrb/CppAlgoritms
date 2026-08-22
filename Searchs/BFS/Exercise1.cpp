#include <bits/stdc++.h>
#include <map>
#include <string>

using namespace std;

struct Node
{
    string name;
    map<string, int> neighbors;
    string value;

    Node(string name, string value)
    {
        this->name = name;
        this->value = value;
    };

    void add_neighbor(string name, int pound)
    {
        if (neighbors.find(name) == neighbors.end())
        {
            neighbors[name] = pound;
        }
    };
};

struct Digraph
{
    map<string, Node *> vertex;

    Digraph() {}

    Node *getNode(string name)
    {
        auto node = this->vertex.find(name);
        if (node != this->vertex.end())
        {
            return node->second;
        }
        return nullptr;
    };

    void add_vertex(string name, string value)
    {
        if (this->vertex.find(name) == this->vertex.end())
        {
            this->vertex[name] = new Node(name, value);
        }
    }

    void add_edge(string vertex1, string vertex2, int pound)
    {
        this->add_vertex(vertex1, "");
        this->add_vertex(vertex2, "");

        this->getNode(vertex1)->add_neighbor(vertex2, pound);
        this->getNode(vertex2)->add_neighbor(vertex1, pound);
    }
};

Node *bfs(Digraph *graph, string initial_node, string wanted_value)
{
    queue<string> queue = {initial_node};
    set<string> veryfied = {initial_node};

    while (queue.size() != 0)
    {
        Node *node = graph->getNode(queue.front());
        queue.pop();

        if (node == nullptr)
        {
            continue;
        }

        cout << node->value << endl
             << endl;

        if (node->value == wanted_value)
        {
            return node;
        }

        for (auto [vertex, __] : node->neighbors)
        {
            if (!veryfied.count(vertex))
            {
                veryfied.insert(vertex);
                queue.push(vertex);
            }
        }
    }

    return nullptr;
}

int main()
{
}