#include <stdio.h>
#include <iostream>
#include <chrono>
using namespace std;

int color[204][30];
int T, N, Answer;
int visited[30];
void dfs(int idx, int cnt)
{
    if (idx > N)
    {
        if (Answer > cnt)
            Answer = cnt;
        return;
    }
    int p = 0;
    for (int i = 'a' - 'a'; i <= 'z' - 'a'; i++)
    {
        if (color[idx][i] == 1 && visited[i] == 1)
        {
            p = 1;
        }
    }
    if (p == 1)
    {
        dfs(idx + 1, cnt);
    }
    else
    {
        for (int i = 'a' - 'a'; i <= 'z' - 'a'; i++)
        {
            if (color[idx][i] == 1 && i != 'a' - 'a' && i != 'e' - 'a' && i != 'i' - 'a' && i != 'o' - 'a' && i != 'u' - 'a')
            {
                if (cnt + 1 >= Answer)
                    return;
                visited[i] = 1;
                dfs(idx + 1, cnt + 1);
                visited[i] = 0;
            }
        }
    }
}
int main()
{
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d", &N);
        Answer = 300;
        for (int i = 'a' - 'a'; i <= 'z' - 'a'; i++)
            visited[i] = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 'a' - 'a'; j <= 'z' - 'a'; j++)
            {
                color[i][j] = 0;
            }
        }
        for (int i = 1; i <= N; i++)
        {
            char str[20];
            scanf("%s", str);
            for (int j = 0; str[j] != NULL; j++)
            {
                color[i][str[j] - 'a'] = 1;
            }
        }
        auto started = std::chrono::high_resolution_clock::now();

        dfs(1, 0);
        auto done = std::chrono::high_resolution_clock::now();

        printf("#%d %d\n", test_case, Answer);
        cout << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count();
    }
}