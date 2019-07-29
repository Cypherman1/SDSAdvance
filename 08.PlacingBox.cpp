#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, test_case, N, K, Answer, tmp_sum;
int scores[101], conditions[101];

struct block
{
    int scrs;
    int cods;
};

vector<block> blocks, rs;

void printv(vector<block> blocks)
{
    for (vector<block>::iterator it = blocks.begin(); it != blocks.end(); it++)
    {
        cout << "(" << it->scrs << "," << it->cods << ") ";
    }
    cout << endl;
}

int sumv(vector<block> blocks)
{
    int res = 0;
    for (vector<block>::iterator it = blocks.begin(); it != blocks.end(); it++)
    {
        res += it->scrs;
    }
    return res;
}

void dfs(vector<block> blocks, int l, vector<block> relt)
{
    if (relt.size() > 0)
    {
        if (relt[relt.size() - 1].cods < K - l)
        {
            return;
        }
    }

    if (l == 0)
    {
        tmp_sum = sumv(relt);
        if (tmp_sum > Answer)
            Answer = tmp_sum;
        return;
    }
    else
    {
        for (vector<block>::iterator it = blocks.begin(); it != blocks.end(); it++)
        {
            block tmp = *it;
            relt.push_back(tmp);
            blocks.erase(it);
            dfs(blocks, l - 1, relt);
            relt.pop_back();
            blocks.insert(it, 1, tmp);
        }
    }
}

int main()
{
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d", &N, &K);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &scores[i]);
        }
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &conditions[i]);
        }
        blocks.clear();
        rs.clear();
        for (int i = 0; i < N; i++)
        {
            block tmp = {scores[i], conditions[i]};
            blocks.push_back(tmp);
        }
        Answer = 0;
        // printv(blocks);
        dfs(blocks, K, rs);

        cout << "#" << test_case << ":" << Answer << endl;
    }
    return 0;
}