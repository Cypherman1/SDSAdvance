#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int T, test_case, N, M, C, Answer;
int input[1001][2];
int arr[101];
set<int> result;
set<int> visited;
// vector<int> arr;

// void print_v(vector<int> v)
// {
//     for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//     {
//         cout << *it << " ";
//     }
//     cout << endl;
// }

void dfs(int start)
{
    result.insert(start);
    visited.insert(start);
    for (int i = 0; i < M; i++)
    {
        if (input[i][0] == start && visited.find(input[i][1]) == visited.end())
        {
            dfs(input[i][1]);
            break;
        }
    }
}

int main()
{
    freopen("23.sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d %d", &N, &M, &C);
        memset(input, 0, sizeof(input));
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < M; i++)
        {
            scanf("%d %d", &input[i][0], &input[i][1]);
        }
        for (int j = 0; j < C; j++)
        {
            scanf("%d", &arr[j]);
        }
        result.clear();
        for (int j = 0; j < C; j++)
        {
            visited.clear();
            dfs(arr[j]);
        }
        cout << "#" << test_case << " " << result.size() << endl;
    }
}