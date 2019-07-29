#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int T, test_case, N, Answer;
int input[26];
// vector<int> arr;

// void print_v(vector<int> v)
// {
//     for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//     {
//         cout << *it << " ";
//     }
//     cout << endl;
// }

void dfs(int i, int sum)
{
    if (i > N)
        return;
    if (i > Answer)
        return;
    if (sum == 99)
    {
        if (i < Answer)
            Answer = i;
        return;
    }
    else
    {
        sum += input[i];
        dfs(i + 1, sum);
        sum -= input[i];

        sum -= input[i];
        dfs(i + 1, sum);
        sum += input[i];
    }
}

int main()
{
    freopen("sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        memset(input, 0, sizeof(input));
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &input[i]);
        }
        Answer = INT_MAX;
        dfs(1, input[0]);
        if (Answer == INT_MAX)
            Answer = 0;
        cout << "#" << test_case << " " << Answer << endl;
    }
}