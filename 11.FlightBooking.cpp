#include <iostream>
#include <vector>

using namespace std;

int T, test_case, N, M, A, B, Answer1, Answer2;
int input[101][101];
vector<int> prefix, checkv;

void printv(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

bool check(vector<int> v)
{
    v.insert(v.begin(), A);
    v.push_back(B);
    checkv.clear();
    printv(v);
    for (int i = 0; i < v.size() - 1; i++)
    {
        checkv.push_back(input[v[i] - 1][v[i + 1] - 1]);
    }
    if (*min_element(checkv.begin(), checkv.end()) >= M)
        return true;
    return false;
}

bool check_rv(vector<int> v)
{
    v.insert(v.begin(), A);
    v.push_back(B);
    checkv.clear();

    reverse(v.begin(), v.end());
    printv(v);
    for (int i = 0; i < v.size() - 1; i++)
    {
        checkv.push_back(input[v[i] - 1][v[i + 1] - 1]);
    }
    if (*min_element(checkv.begin(), checkv.end()) >= M)
        return true;
    return false;
}

void dfs(int idx, int l, vector<int> prefix)
{
    if (l >= 0)
    {
        if (check(prefix))
        {
            Answer1++;
        }
        if (check_rv(prefix))
        {
            Answer2++;
        }
    }
    else
        return;
    for (int i = idx; i < B; i++)
    {
        prefix.push_back(i);
        dfs(i + 1, l - 1, prefix);
        prefix.pop_back();
    }
}

void dfs_rv(int idx, int l, vector<int> prefix)
{
    if (l > 0)
    {
        for (vector<int>::iterator it = prefix.begin(); it != prefix.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
        if (check_rv(prefix))
        {
            Answer2++;
        }
    }
    else
        return;
    for (int i = idx; i > A; i--)
    {
        prefix.push_back(i);
        dfs(i - 1, l - 1, prefix);
        prefix.pop_back();
    }
}
int main()
{
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d %d %d", &N, &M, &A, &B);
        memset(input, 0, sizeof(input));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &input[i][j]);
            }
        }
        Answer1 = 0;
        Answer2 = 0;
        vector<int> t1, t2;
        dfs(A + 1, 3, t1);
        // dfs_rv(B - 1, 3, t2);
        cout
            << "#" << test_case << ":" << Answer1 << " " << Answer2 << endl;
    }
}