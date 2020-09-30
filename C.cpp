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
    bool isCorrect = 1;
    // 从 input 文件流读取输入数据
    double r;
    input >> r;
    double ans1 = 4.0 * M_PI * r * r;
    double ans2 = (4.0 / 3.0) * M_PI * r * r * r;
    double user_ans1, user_ans2;

    // 从 user_output 文件读入学生答案
    if (user_output >> user_ans1 >> user_ans2)
    {
        if (abs(ans2 - user_ans1) > 0.1 || abs(ans1 - user_ans2) > 0.1)
        {
            isCorrect = 0;
        }
    }
    else
    {
        isCorrect = 0;
    }
    return isCorrect ? AC : WA;
}
