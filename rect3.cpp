#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int heights[] = {2,1,5,6,2,3};

int GetMaxRectangle(int len)
{
    stack<int> s;
    int ans = 0;

    for (int i = 0; i <len; i++)
    {
        if (s.empty()||heights[s.top()] < heights[i])
            s.push(i);
        else
        {
            int cur = s.top();
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            ans = max(ans,width*heights[cur]);

            i--;
        }
    }
    while (!s.empty())
    {
        int cur = s.top();
        s.pop();
        int width = s.empty() ? len : len -s.top() - 1;

        ans = max(ans,width*heights[cur]);
    }

    return ans;
}
int main()
{
    int len = sizeof(heights)/sizeof(int);

    cout <<"The largest rectangle is:" <<GetMaxRectangle(len) <<endl;
    return 0;
}