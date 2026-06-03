#include <map>
#include <string>

using namespace std;

struct Node
{
    string name;
    map<string, int> neighbors;

    Node(string name)
    {
        this->name = name;
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

    void add_vertex(string name)
    {
        if (this->vertex.find(name) == this->vertex.end())
        {
            this->vertex[name] = new Node(name);
        }
    }

    void add_edge(string vertex1, string vertex2, int pound)
    {
        this->add_vertex(vertex1);
        this->add_vertex(vertex2);

        this->vertex[vertex1]->add_neighbor(vertex2, pound);
    }
};