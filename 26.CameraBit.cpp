#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <time.h>

using namespace std;

int n, k, test_case, T, answer, tr, tc, td, cnt, n_w;
vector<unsigned long long int> bMasks;
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
void setBit(int ir, int ic, int br, int bc)
{
    bMasks[ir * n + ic] |= ((unsigned long long int)1 << (br * n + bc));
}

void bfs(cell B, int k)
{
    memset(marked, false, sizeof(marked));
    q.push(B);
    marked[B.row][B.col] = true;
    setBit(B.row, B.col, B.row, B.col);
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        tr = tmp.row;
        tc = tmp.col;
        td = tmp.depth;
        ++td;
        if (tr - 1 >= 0 && !marked[tr - 1][tc] && input[tr - 1][tc] == '.' && td <= k)
        { // up
            setCell(tmp, tr - 1, tc, td);
            q.push(tmp);
            marked[tr - 1][tc] = true;
            setBit(B.row, B.col, tr - 1, tc);
        }
        if (tr + 1 < n && !marked[tr + 1][tc] && input[tr + 1][tc] == '.' && td <= k)
        { // down
            setCell(tmp, tr + 1, tc, td);
            q.push(tmp);
            marked[tr + 1][tc] = true;
            setBit(B.row, B.col, tr + 1, tc);
        }
        if (tc - 1 >= 0 && !marked[tr][tc - 1] && input[tr][tc - 1] == '.' && td <= k)
        { // left
            setCell(tmp, tr, tc - 1, td);
            q.push(tmp);
            marked[tr][tc - 1] = true;
            setBit(B.row, B.col, tr, tc - 1);
        }
        if (tc + 1 < n && !marked[tr][tc + 1] && input[tr][tc + 1] == '.' && td <= k)
        { // right
            setCell(tmp, tr, tc + 1, td);
            q.push(tmp);
            marked[tr][tc + 1] = true;
            setBit(B.row, B.col, tr, tc + 1);
        }
    }
}

int comb(int N, int K)
{
    vector<int> bitmask(K, 1);
    bitmask.resize(N, 0);
    unsigned long long int tmp;
    do
    {
        // tmp = 0;
        // for (int i = 0; i < N; ++i) // [0..N-1] integers
        // {
        //     if (bitmask[i] && (input[i / n][i % n] == '.'))
        //     {
        //         tmp |= bMasks[i];
        //         cout << "i = " << i << " tmp =" << tmp << " " << (((unsigned long long int)1 << N) - 1) << endl;
        //         if (tmp == (((unsigned long long int)1 << N) - 1))
        //         {
        //             return true;
        //         }
        //     }
        // }
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
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        bMasks.resize(n, 0);
        cell iC;
        // for (int i = 0; i < n; i++)
        // {
        //     setCell(iC, i / n, i % n, 0);
        //     bfs(iC, k);
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << bMasks[i] << " ";
        // }
        // cout << endl;

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
