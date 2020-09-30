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
    int a, b, c;
    input >> a >> b >> c;
    bool ok = 1;
    if (b * b < 4 * a * c)
    {
        ok = 0;
    }
    double ans1 = (-b + sqrt(b * b - 4.0 * a * c)) / (1.0 * a * 2);
    double ans2 = (-b - sqrt(b * b - 4.0 * a * c)) / (1.0 * a * 2);
    double x, y;
    string aa;
    if (user_output >> aa)
    {
        if (ok == 0)
        {
            return aa == "NO" ? AC : WA;
        }
        if (aa != "YES")
        {
            return WA;
        }
    }
    else
    {
        return WA;
    }
    if (user_output >> x >> y)
    {
        if (abs(x - ans1) <= 0.1 && abs(y - ans2) <= 0.1)
        {
            return AC;
        }
        if (abs(x - ans2) <= 0.1 && abs(y - ans1) <= 0.1)
        {
            return AC;
        }
        return WA;
    }
    return WA;
}
