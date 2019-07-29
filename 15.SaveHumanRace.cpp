#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

int T, test_case, N, M, Answer;
int input[151][3];

struct cell
{
    int row;
    int col;
    int time;
};

cell root_cell, tmp_cell, left_cell, right_cell;

queue<cell> bfs_quece;

bool isBom(cell icell)
{
    for (int i = 0; i < M; i++)
    {
        if (input[i][0] == icell.row && input[i][1] == icell.col && icell.time % input[i][2] == 0)
            return false;
    }
    return true;
}

void bfs()
{
    root_cell.row = 1;
    root_cell.col = 1;
    root_cell.time = 1;
    bfs_quece.push(root_cell);
    while (!bfs_quece.empty())
    {
        tmp_cell = bfs_quece.front();
        bfs_quece.pop();
        if (tmp_cell.row == N)
        {
            Answer++;
            // cout << tmp_cell.row << tmp_cell.col << tmp_cell.time << endl;
        }
        left_cell.row = tmp_cell.row + 1;
        left_cell.col = tmp_cell.col;
        left_cell.time = tmp_cell.time + 1;

        right_cell.row = tmp_cell.row + 1;
        right_cell.col = tmp_cell.col + 1;
        right_cell.time = tmp_cell.time + 1;

        if (left_cell.row <= N && left_cell.col <= N && isBom(left_cell))
        {
            bfs_quece.push(left_cell);
        }

        if (right_cell.row <= N && right_cell.col <= N && isBom(right_cell))
        {
            bfs_quece.push(right_cell);
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
        scanf("%d %d", &N, &M);
        memset(input, 0, sizeof(input));
        for (int i = 0; i < M; i++)
            scanf("%d %d %d", &input[i][0], &input[i][1], &input[i][2]);

        Answer = 0;
        bfs();
        if (Answer == 0)
            Answer = -1;
        cout << "#" << test_case << ":" << Answer << endl;
    }
}