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
    double a, c;
    int b;
    input >> a >> b >> c;
    for (int i = 0; i < b; i++)
    {
        c += c * a;
    }
    double ans;
    if (user_output >> ans)
    {
        if (abs(ans - c) > 0.1)
        {
            return WA;
        }
        return AC;
    }
    return WA;
}
