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
    double ans = 0, x = 0.01875;
    for (int i = 0; i < 5; i++)
    {
        ans = (ans + 1000) / (1 + x * 12);
    }
    double a;
    if (user_output >> a)
    {
        if (abs(a - ans) > 0.1)
        {
            return WA;
        }
        return AC;
    }
    return WA;
}
