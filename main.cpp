#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <functional>
#include <cctype>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> getMostCommonWord(string input, vector<string>& excludeWord)
    {
        unordered_set<string> uset;
        map<string,int> mmap;
        vector<string> answer;

        for(string str : excludeWord)
        {
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            uset.insert(str);
        }

        //split word
        string word = "";
        for(int i = 0; i < input.size(); i++)
        {
            // string str = input.substr(i,1);
            string str = input.substr(i,1);
            // transform(str.begin(), str.end(), str.begin(), ::tolower);

            if( str == "." || str == "'" || str == " ")
            {
                if(i == input.size() - 1)
                    break;

                if(!word.empty())
                {
                    transform(word.begin(), word.end(), word.begin(), ::tolower);
                    auto result = mmap.find(word);
                    if(result != mmap.end()) //found it, count up
                    {
                        result->second += 1;
                    }
                    else //first time, insert with count 1
                    {
                        //insert if word is not exclusive word
                        auto search = uset.find(word);
                        if( search == uset.end())
                            mmap.insert(pair<string,int>{word, 1});
                    }
                }
                word = "";
            }
            else
                word = word + input.substr(i,1);
        }

        auto result = mmap.find(word);
        if(result != mmap.end()) //found it, count up
        {
            result->second += 1;
        }
        else //first time, insert with count 1
        {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            auto search = uset.find(word);
            if( search == uset.end())
                mmap.insert(pair<string,int>{word, 1});
        }

        // for(auto p : mmap)
        //     cout << p.first << " : " << p.second << endl;

        //sort map by value
        typedef function<bool(pair<string, int>, pair<string, int>)> Comperator;
        Comperator comp = [](pair<string, int> a, pair<string, int> b)
        {
            return a.second >= b.second;

        };
        set< pair<string,int>, Comperator > sset(mmap.begin(), mmap.end(), comp );


        int maxCount = sset.begin()->second;
        for(pair<string,int> p : sset)
        {
            if(maxCount == p.second)
                answer.push_back(p.first);
            else
                break;
        }
        return answer;
    }

};

int main()
{
    string input = "Jack and Jill went to the market to buy bread and cheese. Cheese is Jack's and Jill's favorite food.";
    vector<string> excludeWord = {"and", "he", "the", "to", "is", "Jack", "Jill"};
    Solution obj;
    vector<string> answer = obj.getMostCommonWord(input, excludeWord);

    for(string s : answer)
        cout << s << " ";
    cout << endl;

    return 0;
}
