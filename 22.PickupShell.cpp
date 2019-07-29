#include <iostream>
#include <cstdio>
#include <vector>
#include <time.h>

using namespace std;

int T, test_case, N, Answer;
int input[11][11];
int DP[11][11];
struct cell
{
    int row;
    int col;
};

cell tmp_cell;

void print_path(vector<cell> p)
{
    for (vector<cell>::iterator it = p.begin(); it != p.end(); it++)
    {
        cout << "(" << it->row << "," << it->col << ")";
    }
    cout << endl;
}

void dfs(int row, int col, int sum, vector<cell> path)
{
    if (sum > DP[row][col])
    {
        DP[row][col] = sum;
    }
    else
    {
        return;
    }
    if (row == N - 1 && col == N - 1)
    {
        sum += input[row][col];
        if (sum > Answer)
        {
            Answer = sum;
        }
        return;
    }
    else
    {
        if (row + 1 < N)
        {
            sum += input[row][col];
            tmp_cell.row = row;
            tmp_cell.col = col;
            path.push_back(tmp_cell);
            dfs(row + 1, col, sum, path);
            sum -= input[row][col];
            path.pop_back();
        }
        if (col + 1 < N)
        {
            sum += input[row][col];
            tmp_cell.row = row;
            tmp_cell.col = col;
            path.push_back(tmp_cell);
            dfs(row, col + 1, sum, path);
            sum -= input[row][col];
            path.pop_back();
        }
    }
}

int main()
{
    clock_t tStart = clock();
    freopen("22.sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d", &N);
        memset(input, 0, sizeof(input));
        memset(DP, -1, sizeof(DP));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &input[i][j]);
            }
        }
        Answer = 0;
        vector<cell> tmp;
        dfs(0, 0, 0, tmp);
        cout << "#" << test_case << " " << Answer << endl;
    }
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
}