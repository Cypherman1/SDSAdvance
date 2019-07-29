#include <stdio.h>
#include <time.h>
int Answer;
int T, M, N;
int Input1[51][20];
int Input2[51][20];
int visited[20];
int v[51];
void dfs(int idx, int cnt, int tot)
{
    if (cnt == 0)
    {
        int idx = 0;
        for (int i = 0; i < N; i++)
        {
            int digit = 1;
            int val = 0;
            for (int j = 0; j < M; j++)
            {
                if (visited[j] == 0)
                    continue;
                val += digit * Input1[i][j];
                digit *= 2;
            }
            v[idx++] = val;
        }
        for (int i = 0; i < N; i++)
        {
            int digit = 1;
            int val = 0;
            for (int j = 0; j < M; j++)
            {
                if (visited[j] == 0)
                    continue;
                val += digit * Input2[i][j];
                digit *= 2;
            }
            for (int j = 0; j < idx; j++)
            {
                if (v[j] == val)
                {
                    return;
                }
            }
        }
        Answer = tot;
        return;
    }
    for (int i = idx; i < M; i++)
    {
        visited[i] = 1;
        dfs(i + 1, cnt - 1, tot);
        visited[i] = 0;
        if (Answer == tot)
            return;
    }
}
int main()
{
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d", &N, &M);
        Answer = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                scanf("%d", &Input1[i][j]);
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                scanf("%d", &Input2[i][j]);
            }
        }
        clock_t tStart = clock();
        
            for (int i = M; i >= 1; i--)
            {
                dfs(-1, i, i);
            }
        printf("#%d %d\n", test_case, Answer);
        printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    }
}