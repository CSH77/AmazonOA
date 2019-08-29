#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

struct Vertex
{
    char point;
    map<char, int> connect; //point name, distance;
    Vertex(char c) : point(c) {}
};

class Graph 
{
public:
    void addEdge(Vertex& a, Vertex& b, int distance)
    {
        a.connect.insert(pair<char,int>{b.point, distance});
        b.connect.insert(pair<char,int>{a.point, distance});
    }   

    void printGraph(vector<Vertex>& v)
    {
        for(auto n : v)
        {
            cout << n.point << " is connected: ";
            for(auto x : n.connect)
            {
                cout << x.first << "::" << x.second << "   ";
            }
            cout << endl;
        }
    }

};


int main()
{
    Graph graph;
    vector<Vertex> v('Z', 0);

    for(char i = 'A'; i <= 'Z'; i++)
    {
        v[i].point = i;
    }
 
    graph.addEdge(v['A'], v['B'], 2 );
    graph.addEdge(v['A'], v['D'], 3 );
    graph.addEdge(v['A'], v['C'], 3 );
    graph.addEdge(v['D'], v['F'], 7 );
    graph.addEdge(v['D'], v['C'], 5 );
    graph.addEdge(v['F'], v['G'], 9 );
    graph.addEdge(v['F'], v['E'], 8 );
    graph.addEdge(v['C'], v['B'], 4 );
    graph.addEdge(v['C'], v['E'], 1 );

    // graph.printGraph(v);


    return 0;
}
