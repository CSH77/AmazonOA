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

    vector<pair<char,char>> findMinDistanceToConnectAll(vector<Vertex>& v)
    {
        set<char> visited;

        //start from A, find shortest edge from visited list to unvisited
        visited.insert('A');

        vector<pair<char,char>> answer;
        int total = 0;
        while(true)
        {
            //find shortest edge from visited list.
            // int min = 9999;
            char minChar = 0;
            char origin = 0;
            int min = 9999;
            for(char c : visited)
            {
                for(auto m : v[c].connect)
                {
                    auto search = visited.find(m.first); //if visited skip
                    if(search != visited.end())
                        continue;
                    
                    if(m.second <= min)
                    {
                        min = m.second;
                        origin = c;
                        minChar = m.first;
                    }
                    
                }
            }

            if(minChar == 0) //can't find any point. done
                break;
            
            //add point to connect
            answer.push_back(make_pair(origin, minChar));
            visited.insert(minChar);
            visited.insert(origin);
            int distance = v[origin].connect.find(minChar)->second;
            total += distance;
            
        }
        cout << "total: " << total << endl;
        return answer;
    }//EOF

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
    graph.addEdge(v['C'], v['F'], 6 );

    // graph.printGraph(v);

    vector<pair<char,char>> answer = graph.findMinDistanceToConnectAll(v);


    for(auto n : answer)
        cout << n.first << "::" << n.second << endl;

    

    return 0;
}
