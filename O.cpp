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
    int faHeight, moHeight;
    double x;
    string sex, sports, diet;
    input >> sex >> faHeight >> moHeight >> sports >> diet;
    if (sex == "M")
        x = 1.0 * (faHeight + moHeight) * 0.54;
    else if (sex == "F")
        x = 1.0 * (faHeight * 0.923 + moHeight) / 2;
    if (sports == "Y")
        x = 1.0 * x * (1 + 0.02);
    if (diet == "Y")
        x = 1.0 * x * (1 + 0.015);
    double aaaaa;
    if (user_output >> aaaaa)
    {
        if (abs(aaaaa - x) > 0.1)
        {
            return WA;
        }
        return AC;
    }
    return WA;
}
