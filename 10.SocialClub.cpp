#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int T, test_case, N, K, tA1, tA2, tmpsize, gsize, Answer;
int input[1001][1001];
int visited[1001];

void dfs(int idx)
{
    visited[idx] = 1;
    tmpsize++;
    cout << idx << " ";
    for (int j = 1; j <= N; j++)
    {
        if (input[idx][j] == 1 && visited[j] == 0)
        {
            dfs(j);
        }
    }
}

bool iszero(int i)
{
    return i == 0;
}

int main()
{
    setbuf(stdout, NULL);
    scanf("%d", &T);

    for (test_case = 1; test_case <= T; test_case++)
    {
        memset(input, 0, sizeof(input));
        memset(visited, 0, sizeof(visited));
        visited[0] = 1;
        scanf("%d %d", &N, &K);
        for (int i = 0; i < K; i++)
        {
            scanf("%d %d", &tA1, &tA2);
            input[tA1][tA2] = 1;
            input[tA2][tA1] = 1;
        }
        Answer = 0;
        gsize = 0;
        while (any_of(visited, visited + N, iszero))
        {
            tmpsize = 0;
            cout << endl;
            dfs(distance(visited, find(visited, visited + N, 0)));

            if (tmpsize > gsize)
                gsize = tmpsize;
            if (tmpsize > 1)
                Answer++;

            // cout << "Answer:" << Answer << endl;
        }
        cout << "#" << test_case << ":" << Answer << " " << gsize << endl;

        // printv(APs);
    }
    return 0;
}