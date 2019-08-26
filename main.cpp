#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> getTwoPackageForSpace(vector<int>& packages, int space)
    {
        int availableSpace = space - 30;
        sort(packages.begin(), packages.end());

        int maxspaceGap = 9999;
        vector< pair<int,int> > answerPair; //package index, package weight
        for(int i = 0; i < packages.size(); i++)
        {
            for(int j = i; j < packages.size(); j++)
            {
                if(j == i)
                    continue;

                int gap = availableSpace - (packages[i] + packages[j]);

                if(gap >= 0)
                {
                    if(gap < maxspaceGap)
                    {
                        answerPair.clear();
                        maxspaceGap = gap;
                        answerPair.push_back(pair<int,int>{i, packages[i]});
                        answerPair.push_back(pair<int,int>{j, packages[j]});
                    }
                }
                else
                    break;
            }
        }
        return vector<int> { answerPair[0].first, answerPair[1].first };
    }
};

int main()
{
    vector<int> input = {1, 10, 25, 35, 60}; //exepct [2, 3]
    int trucSpace = 90; //reserved space 30

    Solution obj;
    vector<int> answer = obj.getTwoPackageForSpace(input, trucSpace);

    for(int n : answer)
        cout << n << " ";
    cout << endl;



    return 0;
}
