#include <iostream>
#include <chrono>

using namespace std;

int T, N, M;
int P[50][18], C[50][18];

bool checklinefix(int ip, int j, int ic, int l)
{
    for (int x = 0; x < l; x++)
    {
        if (P[ip][j + x] != C[ic][j + x])
            return false;
    }
    return true;
}
bool checkmovex(int col, int l)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (checklinefix(i, col, j, l))
                return true;
        }
    }
    return false;
}
bool checklinemoveall(int l)
{
    for (int j = 0; j < M - l; j++)
    {
        if (!checkmovex(j, l))
            return false;
    }
    return true;
}
bool checklinemove(int ip, int ic, int l)
{
    for (int j = 0; j < M - l; j++)
    {
        if (!checklinefix(ip, j, ic, l))
            return false;
    }
    return true;
}
bool checklineall(int l)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!checklinemove(i, j, l))
                return false;
        }
    }
    return true;
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
                scanf("%d", &P[i][j]);
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                scanf("%d", &C[i][j]);
            }
        }
        
        for (answer = 1; answer <= M; answer++)
        {
            if (!checklinemoveall(answer))
                break;
        }
        
        cout << "#" << test_case << ":" << answer << endl;
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count();
    }
    return 0;
}
