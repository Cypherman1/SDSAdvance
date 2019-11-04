#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <time.h>

using namespace std;

int n, k, test_case, T, answer, tr, tc, td, cnt, n_w;
string input[6];
bool marked[6][6];
int cmr[6][6];
bool isblock;

struct cell
{
    int row;
    int col;
    int depth;
};

queue<cell> q;
vector<cell> tb;
cell tmp_c, tmp;
void setCell(cell &ctmp, int ir, int ic, int id)
{
    ctmp.row = ir;
    ctmp.col = ic;
    ctmp.depth = id;
}



bool bfs(vector<cell> B, int k)
{
    for (size_t i = 0; i < B.size(); i++)
    {
        q.push(B[i]);
        marked[B[i].row][B[i].col] = true;
    }
    cnt = 0;
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        tr = tmp.row;
        tc = tmp.col;
        td = tmp.depth;
        ++td;
        cnt++;
        if (tr - 1 >= 0 && !marked[tr - 1][tc] && input[tr - 1][tc] == '.' && td <= k)
        { // up
            setCell(tmp, tr - 1, tc, td);
            q.push(tmp);
            marked[tr - 1][tc] = true;
        }
        if (tr + 1 < n && !marked[tr + 1][tc] && input[tr + 1][tc] == '.' && td <= k)
        { // down
            setCell(tmp, tr + 1, tc, td);
            q.push(tmp);
            marked[tr + 1][tc] = true;
        }
        if (tc - 1 >= 0 && !marked[tr][tc - 1] && input[tr][tc - 1] == '.' && td <= k)
        { // left
            setCell(tmp, tr, tc - 1, td);
            q.push(tmp);
            marked[tr][tc - 1] = true;
        }
        if (tc + 1 < n && !marked[tr][tc + 1] && input[tr][tc + 1] == '.' && td <= k)
        { // right
            setCell(tmp, tr, tc + 1, td);
            q.push(tmp);
            marked[tr][tc + 1] = true;
        }
    }
    if (cnt < n * n - n_w)
    {
        return false;
    }
    // cout << "$ cnt =" << cnt << " n= " << n << " n_w =" << n_w << endl;
    // for (int i = 0; i < B.size(); i++)
    // {
    //     cout << "(" << B[i].row << "," << B[i].col << ") ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << marked[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (!marked[i][j] && input[i][j] == '.')
    //             return false;
    //     }
    // }
    return true;
}

int comb(int N, int K)
{
    int cnt = 0;
    vector<int> bitmask(K, 1);
    bitmask.resize(N, 0);
    do
    {
        memset(marked, false, sizeof(marked));
        tb.clear();
        isblock = false;
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i])
            {
                setCell(tmp_c, i / n, i % n, 0);
                if (input[tmp_c.row][tmp_c.col] == '#')
                {
                    isblock = true;
                    break;
                }
                tb.push_back(tmp_c);
            }
        }
        if (!isblock)
        {
            if (bfs(tb, k))
                return true;
        }
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
    return false;
}

int main()
{
    clock_t tStart = clock();
    freopen("24.sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d", &n, &k);
        n_w = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
            for (int j = 0; j < n; j++)
            {
                if (input[i][j] == '#')
                    n_w++;
            }
        }

        for (answer = 1; answer <= 5; answer++)
        {
            if (comb(n * n, answer))
                break;
        }
        if (answer == 6)
        {
            cout << "#" << test_case << " " << -1 << endl;
        }
        else
        {
            cout << "#" << test_case << " " << answer << endl;
        }
    }

    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

    return 0;
}
