# SCNUSE 2020 C 语言入门题集 Special Judge


| 题号　|　名称 | Special Judge |
|:---:|:---:|:---:|
|A| 5.7 字符转换||
|B| 3.2 反转三位数整数||
|C| 3.5 球的体积和表面积|[YES](./C.cpp)|
|D| 3.4 一元二次方程求解|[YES](./D.cpp)|
|E| 5.12 体型判断||
|F| 6.4 平方与立方||
|G| 3.3 计算本金与利润之和|[YES](./G.cpp)|
|H| 6.5 华氏温度与摄氏温度转换|[YES](./H.cpp)|
|I| 6.7 计算翻一番的年份||
|J| 6.20 找出车牌号||
|K| 6.8 π 值计算|[YES](./K.cpp)|
|L| 5.8 判断字符类型||
|M| 5.9 分数转换||
|N| 6.6 计算本金|[YES](./N.cpp)|
|O| 5.11 预测身高|[YES](./O.cpp)|
|P| 5.10 计算月份的天数||
|Q| 6.13 计算数的和||
|R| 6.14 计算人数||
|S| 6.21 听礼炮||
|T| 6.10 水仙花数||
|U| 6.17 兑换纸币||

## 什么是 Special Judge

Special Judge 是指 OJ 将使用一个特定的程序来判断提交的程序的输出是不是正确的，而不是单纯地看提交的程序的输出是否和标准输出一模一样。

## 使用场景

一般使用 Special Judge 都是因为题目的答案不唯一，更具体一点说的话一般是两种情况：

* 题目最终要求输出一个解决方案，而且这个解决方案可能不唯一。

* 题目最终要求输出一个浮点数，而且会告诉只要答案和标准答案相差不超过某个较小的数就可以，比如 0.01。这种情况保留 3 位小数、4 位小数等等都是可以的，而且多保留几位小数也没什么坏处。


## 判题机制

OJ 会事先将写你好的 SPJ 编译成可执行文件（不妨命名为 `spj`），在学生提交代码之后，OJ 会将学生提交的代码也给编译成可执行文件（不妨命名为 `stu`），然后逐个测试点进行测试，对于每个测试点，OJ 会运行 `stu`，给定一组输入数据（也就是你们上传的 `1.in`、`2.in`...），然后将 `stu` 的输出的答案保存到文件。我们假设我们在对第 5 个测试点进行测试：

```sh
(./stu < 5.in) > user_out_file
```

如果是传统的文件比对，就是由 OJ 直接比对这个文件和你们上传的 `1.out`、`2.out`...，只要有一丁点不一样，多了一个空格少一个空格都不行，就是 Wrong Answer（所以说造数据要好好造，输入输出格式要求也要约定清楚）。我们假设还是第 5 个测试点：

```sh
diff user_out_file 5.out
```


但是 SPJ 不一样，OJ 会将输入数据和 `user_out_file.out` 同时作为 `spj` 的参数，运行 `spj`，由它来判定答案对不对，假设还是第 5 个测试点：

```sh
./spj 5.in user_out_file
```

判题结果取决于 `spj` 返回值，如果程序运行结束返回 0，那么学生就会收到 Accepted 的反馈，否则就会收到 Wrong Answer 的反馈。

## 基本框架

> SCNUOJ 不支持 `testlib.h`。

每个 SPJ 基本都会包含下面的基本框架，我们要写的主要就是下面的 `do something` 部分。

```cpp
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
    // do something
    return isCorrect ? AC : WA;
}
```

## 判题逻辑

在上面的基本框架中，`input` 和 `user_output` 就是两个文件流，我们可以分别从中读取输入数据和学生程序给出的答案。通常来说，我们会跟学生一样先把输入数据读入，自己计算一遍答案。假设有下面的题目：

给定两个正整数 a 和 b（都小于 100），计算并输出 a/b，保留至少两位小数。答案正确当且仅当学生的输出和标准答案的差的绝对值小于等于 0.1。

输入格式：输入只有一行，依次是 a 和 b，数与数之间用空格隔开。

输出格式：输出一个小数，表示答案。

样例：输入 `1 3`，输出 `0.333333`。

学生写出来的程序应该是这样的：

```c
#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%lf\n", 1.0 * a / b);
    return 0;
}
```

那么我们也先把输入数据从 `input` 文件流读进来，自己算一遍答案：

```cpp
int a, b;
input >> a >> b;
double ans = 1.0 * a / b;
```

接下来我们就来从 `user_output` 文件流读取学生的答案。由于学生给出的答案可能会五花八门，虽然我们给了输入输出格式要求和数据规模约束，学生可以不用判断输入数据是否合法，但是我们是一定要判断学生输出的答案是否合法，举例：

```cpp
double user_ans;
if (user_output >> user_ans)
{
    // 合法，那么接下来判断答案是否正确
    if (abs(ans - user_ans) > 0.1)
    {
        isCorrect = 0;
    }
}
else
{
    // 不合法
    isCorrect = 0;
}
```

这个 SPJ 写出来应该是这样的：

```cpp
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
    int a, b;
    input >> a >> b;
    double ans = 1.0 * a / b;

    // 从 user_output 文件读入学生答案
    double user_ans;
    if (user_output >> user_ans)
    {
        if (abs(ans - user_ans) > 0.1)
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
```

当然上面的 SPJ 没有考虑到学生把 a/b 的结果打印出来之后还打印了什么，当然这个检查就是可选的了。但是如果学生在打印 a/b 的结果之前打印了其它的东西，或者是打印了完全错误的答案，这个程序的 main 函数会返回 `1`，那么学生就会收到 Wrong Answer 反馈。

对于某些答案不唯一的构造题，我们也不一定需要自己先算一遍答案，直接检查学生输入结果是否符合题目要求即可，但强烈建议统一先从 `input` 将自己需要到的输入数据全部读进来，然后再从 `user_output` 读取学生答案。尽量避免交替读取，以避免当学生没有按照格式输出答案时 SPJ 出错，导致 System Error。 
