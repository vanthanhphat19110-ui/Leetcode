/* Leetcode 394: Decode string. */
// Difficulty: Medium.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    struct Node
    {
        string str;
        int num;
    };

    string decodeString(string s)
    {
        vector<Node> stack;
        string currStr = "";
        int currNum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
                currNum = currNum * 10 + (s[i] - '0');
            else if (isalpha(s[i]))
                currStr += s[i];
            else if (s[i] == '[')
            {
                Node pair;
                pair.num = currNum;
                pair.str = currStr;
                stack.push_back(pair);
                currNum = 0;
                currStr = "";
            }
            else // s[i] == ']'
            {
                string temp = currStr;
                currStr = stack.back().str;
                int times = stack.back().num;
                for (int j = 0; j < times; j++)
                    currStr += temp;
                stack.pop_back();
            }
        }
        return currStr;
    }
};