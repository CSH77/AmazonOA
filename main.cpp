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

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(NULL), right(NULL){}
};

class Solution
{
public:
    Node* answer;

    int getMaxAverageNodeHelper(Node* node)
    {
        if(node == NULL)
            return -1;

        int val = 0;
        int count = 0;
        int average = 0;

        //iterator node

        stack<Node*> stk;
        stk.push(node);

        while(!stk.empty())
        {
            Node* cur = stk.top();
            stk.pop();

            val += cur->val;
            count++;

            if(cur->left)
                stk.push(cur->left);

            if(cur->right)
                stk.push(cur->right);

        }

        average = val / count;
        return average;
    }

    Node* getMaxAverageNode(Node* root)
    {
        int maxAverage = 0;
        // pair<int, Node*> answer;
        Node* answer = NULL;
        stack<Node*> stk;

        stk.push(root);
        while(!stk.empty())
        {
            Node* cur = stk.top();
            stk.pop();

            int curAverage = getMaxAverageNodeHelper(cur);

            if(curAverage > maxAverage)
            {
                maxAverage = curAverage;
                answer = cur;
            }

            if(cur->left)
                stk.push(cur->left);

            if(cur->right)
                stk.push(cur->right);

        }

        return answer;
    }


};

int main()
{
    Node* root = new Node(1);
    root->left = new Node(-5);
    root->left->left = new Node(1);
    root->left->right = new Node(2);

    root->right = new Node(11);
    root->right->left = new Node(4);
    root->right->right = new Node(-2);

    Solution obj;
    Node* answer = obj.getMaxAverageNode(root);
    cout << answer->val << endl;

    return 0;
}
