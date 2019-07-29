#include <iostream>

using namespace std;

int T, test_case, N, f_row, f_col, l_row, l_col;
char grid[16][16];
char word[21];
bool found, isFounded;

void dfs(int row, int col, int idx)
{
    if (idx == N - 1)
    {
        l_row = row;
        l_col = col;
        isFounded = true;
        // cout << "(" << l_row << "," << l_col << ")";
        return;
    }
    else
    {
        found = false;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (row + i >= 0 && row + i < 15 && col + j >= 0 && col + j < 15)
                {
                    if (grid[row + i][col + j] == word[idx + 1])
                    {
                        found = true;
                        dfs(row + i, col + j, idx + 1);
                    }
                }
            }
        }
    }
}

int main()
{
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (int i = 0; i < 15; i++)
    {

        scanf("%s", &grid[i]);
    }
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d", &N);
        scanf("%s", &word);
        cout << "#" << test_case << ":";
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                if (grid[i][j] == word[0])
                {
                    isFounded = false;
                    f_row = i;
                    f_col = j;
                    l_row = -1;
                    l_col = -1;
                    dfs(i, j, 0);
                    if (isFounded)
                        goto finish;
                    // if (l_row != -1 && l_col != -1)
                    //     goto Done;
                }
            }
        }
        f_col = -1;
        f_row = -1;
    finish:
        cout << f_row << " " << f_col << " " << l_row << " " << l_col << endl;
        // f_row = -1;
        // f_col = -1;
        // Done:
        //     cout << "#" << test_case << ":" << f_row << " " << f_col << " " << l_row << " " << l_col << endl;
    }
    return 0;
}
