#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;

int T, test_case, N, M, C, Answer;
int DD[10001][2];
int Z[101];
map<int, int> DDmap;
set<int> emp, visited;

void printset(set<int> s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void findRoot(int st)
{
    int root = st;
    visited.clear();
    emp.insert(root);
    visited.insert(root);
    while (DDmap.find(root) != DDmap.end())
    {
        root = DDmap.find(root)->second;
        if (visited.find(root) != visited.end())
            break;
        emp.insert(root);
        visited.insert(root);
    }
}

int main()
{
    freopen("sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d %d", &N, &M, &C);
        memset(DD, 0, sizeof(DD));
        memset(Z, 0, sizeof(Z));
        for (int i = 0; i < M; i++)
        {
            scanf("%d %d", &DD[i][0], &DD[i][1]);
        }
        for (int i = 0; i < C; i++)
        {
            scanf("%d", &Z[i]);
        }
        DDmap.clear();
        for (int i = 0; i < M; i++)
        {
            DDmap[DD[i][0]] = DD[i][1];
        }
        emp.clear();
        // cout << "emp:" << emp.size();
        // printset(emp);
        visited.clear();
        for (int i = 0; i < C; i++)
        {
            findRoot(Z[i]);
            // cout << Z[i] << " ";
        }
        // cout << endl;
        cout << "#" << test_case << ":" << emp.size() << endl;
        printset(emp);
    }
    return 0;
}
