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
    vector<int> findMovieTime(vector<int>& input, int d)
    {
        sort(input.begin(), input.end());

        vector<int> answer;
        int timeGap = 9999;
        int givenTime = d - 30;

        for(int i = 0; i < input.size(); i++)
        {
            for(int j = i; j < input.size(); j++)
            {
                if( i == j)
                    continue;

                if( (givenTime - (input[i] + input[j]) ) < 0 )
                    break;
                else
                {
                    int totalRunTimeGap = (givenTime - (input[i] + input[j]) );
                    if(totalRunTimeGap < timeGap ) //better fit to given time
                    {
                        answer.clear();
                        answer.push_back(input[i]);
                        answer.push_back(input[j]);
                    }
                }
            }
        }
        return answer;
    }

};

int main()
{
    vector<int> input = {90, 85, 75, 60, 120, 150, 125};
    Solution obj;
    vector<int> answer = obj.findMovieTime(input, 250); //expect {90,125}

    for(int n : answer)
        cout << n << " ";
    cout << endl;

    return 0;
}
