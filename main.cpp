#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int getEuclideanDistance(vector<int> input)
    {
        return (input[0] * input[0]) +  (input[1] * input[1]);
    }

    vector<vector<int>> answer;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multimap<int, pair<int,int>> mmap; //key distance, value: grid number

        // cout << getEuclideanDistance(points[0]);
        for(int i = 0; i < points.size(); i++)
        {
            pair<int,int> currentPair = pair<int,int>(points[i][0],points[i][1]);
            int distance = getEuclideanDistance(points[i]);
            mmap.insert( pair<int, pair<int,int>> (distance, currentPair));
        }


        auto iter = mmap.begin();
        for(int i = 0; i < K && i < mmap.size(); i++)
        {
            answer.push_back(vector<int>{iter->second.first, iter->second.second } );
            iter++;
        }

        return answer;
    }
};

int main()
{
    Solution obj;
    // vector<vector<int>> input = {{1,3},{-2,2}}; //expect {-2,2}
    vector<vector<int>> input = {{0,1},{1,0}}; //expect 0,1 1,0
    // vector<vector<int>> input = {{3,3},{5,-1},{-2,4}};

    // vector<vector<int>> answer = obj.kClosest(input, 1); //expect {-2,2}
    // vector<vector<int>> answer = obj.kClosest(input, 2); //expect {-2,2}
    vector<vector<int>> answer = obj.kClosest(input, 2); //expect {3,3},{-2,4}

    // cout << obj.getEuclideanDistance(input[1]) << endl;
    // cout << obj.getEuclideanDistance(input[2]) << endl;


    for(vector<int> v : answer)
    {
        for(int n : v)
            cout << n << " ";
        cout << endl;
    }


    return 0;
}
