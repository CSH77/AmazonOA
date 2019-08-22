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


    int findDistance(vector<vector<char>>& input)
    {

        int colSize = input.size();
        int rowSize = input[0].size();
        // bool visited[colSize][rowSize];
        Point cp(0,0,0);

        //mark D as visited too
        queue<Point> que;
        que.push(cp);

        while(!que.empty())
        {
            Point current = que.front();
            que.pop();
            //mark current position as visited 'v'
            int col = current.col;
            int row = current.row;

            //found point
            if(input[col][row] == 'X' )
            {
                cout << "point found:" << endl;
                return current.distance;
            }

            //up
            if( col - 1 >= 0 && input[col - 1][row] != 'V' && input[col - 1][row] != 'D')
                que.push(Point(col - 1, row, current.distance + 1));

            //down
            if( col + 1 < colSize && input[col + 1][row] != 'V' && input[col + 1][row] != 'D')
                que.push(Point(col + 1, row, current.distance + 1));

            //left
            if( row - 1 >= 0 && input[col][row - 1] != 'V' && input[col][row - 1] != 'D')
                que.push(Point(col, row - 1, current.distance + 1));

            //right
            if( row + 1 < rowSize && input[col][row + 1] != 'V' && input[col][row + 1] != 'D')
                que.push(Point(col, row + 1, current.distance + 1));

            input[col][row] = 'V';
        }
        return -1;
    }
};


int main()
{
    vector<vector<char>> input =
        {
            {'O', 'O', 'O', 'O'},
            {'D', 'O', 'D', 'O'},
            {'O', 'O', 'O', 'O'},
            {'X', 'D', 'D', 'O'},
        };

    Solution obj;
    cout << obj.findDistance(input);

    return 0;
}
