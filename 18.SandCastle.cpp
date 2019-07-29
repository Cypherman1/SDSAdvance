#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int T, test_case, N, M, Answer, max_depth;
int input[100][2];

struct f_node
{
    int f;
    int depth;
};

queue<f_node> bfs_q;

f_node tmp_friend, next_friend;

// vector<int> arr;

// void print_v(vector<int> v)
// {
//     for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//     {
//         cout << *it << " ";
//     }
//     cout << endl;
// }

void dfs(int start, int depth)
{
    // cout << start;
    if (depth > max_depth)
        max_depth = depth;
    for (int i = 0; i < M; i++)
    {
        if (input[i][0] == start)
        {
            dfs(input[i][1], depth + 1);
        }
    }
}

void bfs(int start)
{
    tmp_friend.f = start;
    tmp_friend.depth = 1;
    bfs_q.push(tmp_friend);
    while (!bfs_q.empty())
    {
        tmp_friend = bfs_q.front();
        bfs_q.pop();
        for (int i = 0; i < M; i++)
        {
            if (input[i][0] == tmp_friend.f)
            {
                next_friend.f = input[i][1];
                next_friend.depth = tmp_friend.depth + 1;
                max_depth = tmp_friend.depth + 1;
                bfs_q.push(next_friend);
            }
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
        {
            scanf("%d %d", &input[i][0], &input[i][1]);
        }
        Answer = 0;
        cout << "#" << test_case << " ";
        for (int i = 1; i <= N; i++)
        {
            max_depth = 1;
            // bfs(i);
            dfs(i, 1);
            cout << max_depth << " ";
        }
        cout << endl;
    }
}