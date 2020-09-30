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
    double a;
    if (user_output >> a)
    {
        if (abs(a - M_PI) > 0.01)
        {
            return WA;
        }
        return AC;
    }
    return WA;
}
