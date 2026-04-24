/* Leetcode 155: Min stack. */
// Difficulty: Medium.

#include <iostream>
#include <vector>
using namespace std;

class MinStack
{
public:
    vector<int> st, minSt;
    MinStack()
    {
    }

    void push(int value)
    {
        st.push_back(value);
        if (minSt.empty() || value <= minSt.back())
            minSt.push_back(value);
    }

    void pop()
    {
        if (st.back() == minSt.back())
            minSt.pop_back();
        st.pop_back();
    }

    int top()
    {
        return st.back();
    }

    int getMin()
    {
        return minSt.back();
    }
};