#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <time.h>
#include <queue>

using namespace std;

int T, N, M, answer, next_row, next_col, next_sum;
int MAP[51][51], DP[51][51], DP_TMP[51][51];

struct b_cell
{
    int row;
    int col;
    int sum;
};

queue<b_cell> q;
b_cell tmp_c, next_c;

struct cell
{
    int row;
    int col;
};

cell t_cell;

vector<cell> r_path;

void print_v(vector<cell> v)
{
    for (vector<cell>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "(" << it->row << "," << it->col << ")";
    }
    cout << endl;
}

void print_dp(int DP[51][51])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs(b_cell start, int _3mrow)
{
    q.push(start);
    while (!q.empty())
    {
        tmp_c = q.front();
        q.pop();
        if (tmp_c.row - 1 == _3mrow)
        {
            for (int i = tmp_c.col - 3; i <= tmp_c.col + 3; i++)
            {
                next_row = tmp_c.row - 1;
                next_col = i;
                if (next_row >= 0 && next_col >= 0 && next_col < N)
                {
                    next_c.row = next_row;
                    next_c.col = next_col;
                    next_c.sum = tmp_c.sum + MAP[next_row][next_col];
                    if (next_c.sum > DP[next_row][next_col])
                    {
                        DP[next_row][next_col] = next_c.sum;
                        q.push(next_c);
                        // print_dp();
                    }
                }
            }
        }
        else
        {
            for (int i = tmp_c.col - 2; i <= tmp_c.col + 2; i++)
            {
                next_row = tmp_c.row - 1;
                next_col = i;
                if (next_row >= 0 && next_col >= 0 && next_col < N)
                {
                    next_c.row = next_row;
                    next_c.col = next_col;
                    next_c.sum = tmp_c.sum + MAP[next_row][next_col];
                    if (next_c.sum > DP[next_row][next_col])
                    {
                        DP[next_row][next_col] = next_c.sum;
                        q.push(next_c);
                    }
                }
            }
        }
        /* code */
    }
}

void dfs(int _3step, int s_col, int row, int t_sum, vector<cell> path)
{
    if (t_sum > DP[row + 1][s_col])
    {
        DP[row + 1][s_col] = t_sum;
    }
    else
    {
        return;
    }
    if (row == -1)
    {
        return;
    }
    else
    {
        if (_3step == row)
        {
            for (int j = s_col - 3; j <= s_col + 3; j++)
            {
                if (j >= 0 && j < N)
                {
                    t_sum += MAP[row][j];
                    dfs(_3step, j, row - 1, t_sum, path);
                    t_sum -= MAP[row][j];
                }
            }
        }
        else
        {
            for (int j = s_col - 2; j <= s_col + 2; j++)
            {
                if (j >= 0 && j < N)
                {
                    t_sum += MAP[row][j];
                    dfs(_3step, j, row - 1, t_sum, path);
                    t_sum -= MAP[row][j];
                }
            }
        }
    }
}

int main(int argc, const char *argv[])
{

    int test_case, i, j;

    freopen("sample_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);
    clock_t tStart = clock();

    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d", &N, &M);
        memset(MAP, 0, sizeof(MAP));

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                scanf("%d", &MAP[i][j]);
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
         Implement your algorithm from this section.
         */
        memset(DP, -1, sizeof(DP));

        answer = 0;
        int max_row = 0;
        b_cell start = {N - 1, M - 1, 0};
        bfs(start, -10);
        memcpy(DP_TMP, DP, sizeof(DP_TMP));
        for (int i = N - 2; i >= 0; i--)
        {
            memcpy(DP, DP_TMP, sizeof(DP));
            if (i < N - 2)
            {
                for (int j = 0; j < N; j++)
                {
                    start.row = i + 1;
                    start.col = j;
                    start.sum = DP[i + 1][j];
                    bfs(start, i);
                }
            }
            else
            {
                start.row = N - 1;
                start.col = M - 1;
                start.sum = 0;
                bfs(start, i);
            }

            max_row = *max_element(DP[0], DP[0] + N);
            if (max_row > answer)
            {
                answer = max_row;
            }
            // print_dp(DP);
        }
        printf("#%d %d\n", test_case, answer);
    }
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}