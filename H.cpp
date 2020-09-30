#include <bits/stdc++.h>
using namespace std;

#define AC 0
#define WA 1
#define ERROR -1

int main(int argc, char *args[])
{
    ifstream input, user_output;
    input.open(args[1]);
    user_output.open(args[2]);
    vector<pair<int, double>> ans;
    int a;
    double b;
    while (user_output >> a >> b)
    {
        ans.push_back(make_pair(a, b));
    }
    if (ans.size() != 31)
    {
        return WA;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].first != i * 10)
        {
            return WA;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        a = ans[i].first;
        b = ans[i].second;
        double t = 5.0 / 9.0 * (a - 32);
        if (abs(b - t) > 0.1)
        {
            return WA;
        }
    }
    return AC;
}
