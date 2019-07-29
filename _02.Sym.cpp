#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int T, test_case, N, tmp;
int arr1[100];
vector<int> arr;

void print_v(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void dfs(int N, int idx, vector<int> prefix)
{
    if (idx == N)
    {
        print_v(prefix);
        return;
    }
    else
    {
        for (int i = 0; i <= 1; i++)
        {
            prefix.push_back(i);
            dfs(N, idx + 1, prefix);
            prefix.pop_back();
        }
    }
}

void dfs1(int N, int idx, int l, int arr[100])
{
    if (l == 0)
    {
        for (int i = 0; i < N; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }
    else
    {
        for (int i = idx; i < N; i++)
        {
            arr[i] = 1;
            dfs1(N, i + 1, l - 1, arr);
            arr[i] = 0;
        }
    }
}

int main()
{
    vector<int> v;
    memset(arr1, 0, sizeof(arr1));
    dfs1(10, 0, 3, arr1);
    // dfs(3, 0, v);
    // freopen("sample_input.txt", "r", stdin);
    // setbuf(stdout, NULL);
    // scanf("%d", &T);
    // for (test_case = 1; test_case <= T; test_case++)
    // {
    //     scanf("%d", &N);
    //     arr.clear();
    //     for (int i = 0; i < N; i++)
    //     {
    //         scanf("%d", &tmp);
    //         arr.push_back(tmp);
    //     }

    //     cout << "#" << test_case << ":";
    //     print_v(arr);
    // }
}