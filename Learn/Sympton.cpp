#include <iostream>
#include <chrono>
#include <vector>
#include <set>
#include <time.h>

using namespace std;

int T, N, M;
char P[60][20], C[60][20];
int visited[51];
int Col[60], Col1[60];
int val, digit;
bool isCol, isDone;
int Answer;
set<bool> iset;

vector<bool> isMatch;

void dfs(int idx, int l, int total)
{
    if (iset.find(false) != iset.end())
        return;
    if (l == 0)
    {
        isCol = false;
        for (int i = 0; i < N; i++)
        {
            val = 0;
            digit = 1;
            for (int j = 0; j < M; j++)
            {
                digit = digit * 2;
                val += digit * visited[j] * P[i][j];
            }
            Col[i] = val;
        }
        for (int i = 0; i < N; i++)
        {
            val = 0;
            digit = 1;
            for (int j = 0; j < M; j++)
            {
                digit = digit * 2;
                val += digit * visited[j] * C[i][j];
            }
            for (int idx = 0; idx < N; idx++)
            {
                if (Col[idx] == val)
                {
                    isCol = true;
                    break;
                }
            }
        }
        iset.insert(isCol);
    }
    else
    {
        for (int i = idx; i < M; i++)
        {
            visited[i] = 1;
            dfs(i + 1, l - 1, total);
            visited[i] = 0;
        }
    }
}

int main()
{
    int test_case, answer;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                scanf("%s", &P[i][j]);
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                scanf("%s", &C[i][j]);
            }
        }
        // dfs(0, 2, 0);
        clock_t tStart = clock();
        for (int i = 0; i < M; i++)
        {
            visited[i] = 0;
        }
        for (answer = M; answer > 0; answer--)
        {
            iset.clear();
            dfs(0, answer, answer);
            if (iset.find(false) == iset.end())
                break;
        }
        cout << "#" << test_case << ":" << answer + 1 << endl;
        printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    }
    return 0;
}