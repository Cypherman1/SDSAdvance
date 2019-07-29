#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int T, test_case, N, K, Answer;
int input[1001];

set<int> visited;

int findidx(int start)
{
    visited.clear();
    for (int i = start; i < K; i++)
    {
        visited.insert(input[i]);
        if (visited.size() == N)
            return i - 1;
    }
    return -1;
}

int main()
{
    freopen("sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d", &N);
        scanf("%d", &K);
        for (int i = 0; i < K; i++)
            scanf("%d", &input[i]);
        Answer = 0;
        int start = 0;
        while (findidx(start) != -1)
        {
            start = findidx(start) + 1;
            Answer++;
            /* code */
        }

        cout << "#" << test_case << ":" << Answer << endl;
    }
}