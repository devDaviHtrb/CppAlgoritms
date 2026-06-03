#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    map<string, int> NodeDigraph1;
    map<string, int> NodeDigraph2;
    map<string, int> NodeDigraph3;

    NodeDigraph1["B"] = 1;
    NodeDigraph1["C"] = 2;

    NodeDigraph2["A"] = 1;
    NodeDigraph2["C"] = 2;

    NodeDigraph3["B"] = 1;
    NodeDigraph3["A"] = 2;

    map<string, map<string, int>> digraph;
    digraph["A"] = NodeDigraph1;
    digraph["B"] = NodeDigraph2;
    digraph["C"] = NodeDigraph3;

    vector<string> NodeGraph1 = {"B", "C"};
    vector<string> NodeGraph2 = {"A", "C"};
    vector<string> NodeGraph3 = {"A", "B"};

    map<string, vector<string>> graph;
    graph["A"] = NodeGraph1;
    graph["B"] = NodeGraph2;
    graph["C"] = NodeGraph3;

    return 0;
}