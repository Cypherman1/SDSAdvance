#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <time.h>
#include <queue>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

int T, N;

string input[201];
string charset;
int numchar;
int colored[202] = {0};
int Answer, ncount;
set<char> charset1;
unordered_map<char, int> charset4;

string charset2;

struct cs
{
    char ckey;
    int cc;
};

struct letters
{
    int level;
    int pos;
    string st;
};

queue<letters> visited;

vector<cs> charset3;

void printv(vector<char> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
bool checkcond(string c)
{
    for (int i = 0; i < N; i++)
    {
        if (find_first_of(input[i].begin(), input[i].end(), c.begin(), c.end()) == input[i].end())
            return false;
    }
    return true;
}

bool check(string s)
{
    // string tmp;
    for (int i = 0; i < N; i++)
    {
        colored[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        string tmp;
        for (int j = 0; j < s.length(); j++)
            if (!tmp.empty())
                colored[i] = 1;
    }
    int tmp1 = 0;
    for (int i = 0; i < N; i++)
    {
        tmp1 += colored[i];
    }
    if (tmp1 == N)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void dfs(int idx, string prefix)
{

    ncount++;
    int n = charset.length();
    if (idx == n)
        return;
    // cout << prefix << endl;
    if (prefix.length() > Answer)
        return;
    if (checkcond(prefix))
    {
        if (prefix.length() < Answer)
        {
            Answer = prefix.length();
        }
    }
    for (int i = idx + 1; i < n; i++)
    {
        prefix.push_back(charset[i]);
        dfs(i, prefix);
        prefix.pop_back();
    }
    return;
}

void bfs()
{
    letters node0 = {0, -1, ""};
    letters tmpnode;
    ncount = 0;

    visited.push(node0);
    while (!visited.empty())
    {
        ncount++;
        tmpnode = visited.front();
        visited.pop();
        if (checkcond(tmpnode.st))
        {
            Answer = tmpnode.level;
            return;
        }
        for (int i = tmpnode.pos + 1; i < charset3.size(); i++)
        {
            letters newnode = {tmpnode.level + 1, i, tmpnode.st + charset3[i].ckey};
            visited.push(newnode);
        }
    }
}

void createcharset()
{
    numchar = 0;
    string s = "aeiou";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {
            if (!(find(begin(charset), end(charset), input[i][j]) != end(charset)) && (s.find(input[i][j]) == string::npos))
            {
                charset.push_back(input[i][j]);
            }
        }
    }
}
bool cbfun(cs cs1, cs cs2)
{
    return cs1.cc > cs2.cc;
}
void createcharset1()
{
    string s = "aeiou";
    charset4.clear();
    charset3.clear();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {
            if (s.find(input[i][j]) == string::npos)
            {
                // charset1.insert(input[i][j]);
                charset4[input[i][j]]++;
            }
        }
    }
    for (unordered_map<char, int>::iterator it = charset4.begin(); it != charset4.end(); it++)
    {
        cs tmpnode = {it->first, it->second};
        charset3.push_back(tmpnode);
    }
    sort(charset3.begin(), charset3.end(), cbfun);
    // for (vector<cs>::iterator it = charset3.begin(); it != charset3.end(); it++)
    // {
    //     cout << "(" << it->ckey << "," << it->cc << ")" << endl;
    // }
    // copy(charset1.begin(), charset1.end(), back_inserter(charset2));
}

void createcharset2()
{
    string s = "aeiou";
    charset2.clear();

    for (char i = 'a'; i <= 'z'; i++)
        if (s.find(i) == string::npos)
        {
            charset2.push_back(i);
        }
}

int main()
{
    int test_case;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            cin >> input[i];
        }
        Answer = 300;
        ncount = 0;
        vector<char> v;
        clock_t tStart = clock();
        // createcharset();
        // dfs(-1, "");
        createcharset1();
        bfs();

        // cout << charset << endl;
        // check(2, 2, 0, v);
        cout << "#" << test_case << " " << Answer << endl;
        cout << "count:" << ncount << endl;
        printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    }
    return 0;
}
