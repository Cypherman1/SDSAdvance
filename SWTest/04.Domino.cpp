#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
using namespace std;

int T, test_case, N, M, L, Answer;
int input[3001][2], Z[3001];
queue<int> tales;
set<int> fallen, visited;

void bfs(int tale)
{
    int tmptale = tale;
    visited.clear();
    tales.push(tmptale);

    while (!tales.empty())
    {
        tmptale = tales.front();
        fallen.insert(tmptale);
        visited.insert(tmptale);
        tales.pop();
        for (int i = 0; i < M; i++)
        {
            if (input[i][0] == tmptale && visited.find(input[i][1]) == visited.end())
                tales.push(input[i][1]);
        }
    }
}

int main()
{
    freopen("sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d %d", &N, &M, &L);
        memset(input, 0, sizeof(input));
        memset(Z, 0, sizeof(Z));
        for (int i = 0; i < M; i++)
        {
            scanf("%d %d", &input[i][0], &input[i][1]);
        }
        for (int i = 0; i < L; i++)
        {
            scanf("%d", &Z[i]);
        }
        fallen.clear();
        for (int i = 0; i < L; i++)
        {
            bfs(Z[i]);
        }
        cout << "#" << test_case << ":" << fallen.size() << endl;
    }
}