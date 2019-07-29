#include <iostream>
#include <vector>
using namespace std;

int T, test_case, N, Answer;
int input[11][11];
struct node
{
    int x;
    int y;
};

node tmp;
vector<node> nodes;

void printv(vector<node> v)
{
    for (vector<node>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "(" << it->x << "," << it->y << ")";
    }
    cout << endl;
}

void dfs(int x, int y, int N, vector<node> nodes, int tsum)
{

    if (x == N - 1 && y == N - 1)
    {
        tmp.x = x;
        tmp.y = y;
        nodes.push_back(tmp);
        tsum += input[x][y];
        if (tsum > Answer)
            Answer = tsum;
        // printv(nodes);
        return;
    }
    else
    {
        if (x >= 0 && x <= N - 1)
        {
            tmp.x = x;
            tmp.y = y;
            nodes.push_back(tmp);
            tsum += input[x][y];
            dfs(x + 1, y, N, nodes, tsum);
            nodes.pop_back();
            tsum -= input[x][y];
        }
        if (y >= 0 && y <= N - 1)
        {
            tmp.x = x;
            tmp.y = y;
            nodes.push_back(tmp);
            tsum += input[x][y];
            dfs(x, y + 1, N, nodes, tsum);
            nodes.pop_back();
            tsum -= input[x][y];
        }
    }
}

int main()
{
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                scanf("%d", &input[i][j]);
        }
        Answer = 0;
        vector<node> v;
        v.clear();
        dfs(0, 0, N, v, 0);
        cout << "#" << test_case << ":" << Answer << endl;
    }

    return 0;
}