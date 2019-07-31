#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
    struct Point
    {
        int col;
        int row;
        int distance;
        Point(int c, int r, int d) : col(c), row(r), distance(d){}
    };

    int minDistance(vector<vector<char>> pirateMap)
    {
        int columSize = pirateMap.size();
        int rowSize = pirateMap[0].size();
        bool visited[columSize][rowSize];
        Point startingPoint(0,0,0);

        for(int i = 0; i < columSize; i++)
        {
            for(int j = 0; j < rowSize; j++)
            {
                if(pirateMap[i][j] == 'D')
                    visited[i][j] = true;
                else
                    visited[i][j] = false;
            }
        }

        //BFS search.
        queue<Point> que;
        que.push(startingPoint);
        visited[startingPoint.col][startingPoint.row] = true;

        while(!que.empty())
        {
            Point current = que.front();
            que.pop();

            //check if destination is found
            if(pirateMap[current.col][current.row] == 'X')
                return current.distance;

            //move up
            if(current.col - 1 >= 0 && visited[current.col - 1][current.row] == false)
            {
                que.push(Point(current.col - 1, current.row, current.distance + 1 ));
                visited[current.col - 1][current.row] = true;
            }

            //move down
            if(current.col + 1 < columSize && visited[current.col + 1][current.row] == false)
            {
                que.push(Point(current.col + 1, current.row, current.distance + 1 ));
                visited[current.col + 1][current.row] = true;
            }

            //move left
            if(current.row - 1 >= 0  && visited[current.col][current.row - 1] == false)
            {
                que.push(Point(current.col, current.row - 1, current.distance + 1 ));
                visited[current.col][current.row - 1] = true;
            }

            //move right
            if(current.row + 1 < rowSize && visited[current.col][current.row + 1] == false)
            {
                que.push(Point(current.col, current.row + 1, current.distance + 1 ));
                visited[current.col][current.row + 1] = true;
            }
        }
        return -1;
    } //EOF minDistance

    // int minDistanceDFS(vector<vector<char>>& pirateMap)
    vector<pair<int,int>> minDistanceDFS(vector<vector<char>>& pirateMap)
    {
        int columSize = pirateMap.size();
        int rowSize = pirateMap[0].size();
        bool visited[columSize][rowSize];
        vector<pair<int, int>> route;

        stack<Point> stk;

        //mark visited
        for(int i = 0; i < columSize; i++)
        {
            for(int j = 0; j < rowSize; j++)
            {
                if(pirateMap[i][j] == 'D')
                    visited[i][j] = true;
                else
                    visited[i][j] = false;
            }
        }

        //staring point
        Point startingPoint(0,0,0);
        stk.push(startingPoint);
        route.push_back(pair<int,int>(startingPoint.col, startingPoint.row));

        while(!stk.empty())
        {
            Point current = stk.top();

            stk.pop();
            route.pop_back();

            //find destination?
            int currentCol = current.col;
            int currentRow = current.row;

            if(pirateMap[currentCol][currentRow] == 'X')
                // return current.distance;
                return route;

            if( currentCol - 1 >= 0 && visited[currentCol - 1][currentRow] == false  ) //up
            {
                stk.push(current);
                route.push_back( pair<int,int>(current.col, current.row) );
                stk.push( Point(currentCol - 1, currentRow, current.distance + 1) );
                route.push_back( pair<int,int>(currentCol - 1, currentRow) );
                visited[currentCol - 1][currentRow] = true;
            }
            else if ( currentCol + 1 < columSize && visited[currentCol + 1][currentRow] == false  ) //down
            {
                stk.push(current);
                route.push_back( pair<int,int>(current.col, current.row) );
                stk.push( Point(currentCol + 1, currentRow, current.distance + 1) );
                route.push_back( pair<int,int>(currentCol + 1, currentRow) );
                visited[currentCol + 1][currentRow] = true;
            }
            else if ( currentRow + 1 < rowSize && visited[currentCol][currentRow + 1] == false  ) //right
            {
                stk.push(current);
                route.push_back( pair<int,int>(current.col, current.row) );
                stk.push( Point(currentCol, currentRow + 1, current.distance + 1) );
                route.push_back( pair<int,int>(currentCol, currentRow + 1) );
                visited[currentCol][currentRow+ 1] = true;
            }
            else if ( currentRow - 1 >= 0 && visited[currentCol][currentRow - 1] == false  ) //left
            {
                stk.push(current);
                route.push_back( pair<int,int>(current.col, current.row) );
                stk.push( Point(currentCol, currentRow - 1, current.distance + 1) );
                route.push_back( pair<int,int>(currentCol, currentRow - 1) );
                visited[currentCol][currentRow - 1] = true;
            }
        }
        return vector<pair<int,int>>();



    }//EOL minDistanceDFS


};


int main()
{
    char arr[4][4] = {
        {'O', 'O', 'O', 'O'},
        {'D', 'O', 'D', 'O'},
        {'O', 'O', 'O', 'O'},
        {'X', 'D', 'D', 'O'}
    };

    int sizeColum = sizeof(arr) / sizeof(arr[0]);
    vector<vector<char>> pirateMap;
    // vector<char> temp(std::begin(arr[0]), std::end(arr[0]));


    for(int i = 0; i < sizeColum; i++)
    {
       pirateMap.push_back( vector<char>(std::begin(arr[i]), std::end(arr[i]) ) );
    }

    Solution obj;
    // cout << obj.minDistance(pirateMap);

    vector<pair<int,int>> answer = obj.minDistanceDFS(pirateMap);


    for(pair<int,int> n : answer)
    {
        cout << n.first << ":" << n.second << " => ";
    }
    cout << endl;

    // for(vector<char> v : pirateMap)
    // {
    //     for(char c : v)
    //     {
    //         cout << c << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}