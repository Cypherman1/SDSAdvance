#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <time.h>
#include <unordered_map>
#include <set>
using namespace std;

int T, N;

string input[201];
char afb[30];
int numchar;
int colored[202] = {0};
int Answer, ncount;
unordered_map<char, int> charset;
set<char> charset1;
vector<char> charset2;

void printchar()
{
    for (int i = 0; i < numchar; i++)
    {
        cout << afb[i] << " ";
    }
    cout << endl;
}
void printv(vector<char> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
bool checkcond(vector<char> c)
{
    for (int i=0; i<N; i++){
        if (find_first_of(input[i].begin(), input[i].end(), c.begin(), c.end())==input[i].end()) return false;
    }
    return true;
}

void check(int k, int l, int index, vector<char> v)
{
    if (k >= Answer)
        return;
    ncount++;
    if (l == 0)
    {
        if (checkcond(v))
            if (k < Answer)
            {
                Answer = k;
            }
    }
    else
    {
        for (int i = index; i < charset2.size(); i++)
        {
            v.push_back(charset2[i]);
            check(k, l - 1, i + 1, v);
            v.pop_back();
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
            if (!(find(begin(afb), end(afb), input[i][j]) != end(afb)) && (s.find(input[i][j]) == string::npos))
            {
                afb[numchar++] = input[i][j];
            }
        }
    }
}

void printm(unordered_map<char, int> um)
{
    for (unordered_map<char, int>::iterator it = um.begin(); it != um.end(); it++)
    {
        cout << "(" << it->first << ":" << it->second << ")";
    }
    cout << endl;
}

// bool fcsort(pair<char, int> ch1, pair<char, int> ch2)
// {
//     return ch1.second < ch2.second;
// }

void printset(set<char> s)
{
    for (set<char>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void createmap()
{
    string s = "aeiou";
    charset1.clear();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {
            if (s.find(input[i][j]) == string::npos)
            {
                charset1.insert(input[i][j]);
            }
        }
    }
    copy(charset1.begin(), charset1.end(), back_inserter(charset2));
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
        createmap();
        for (int i = 1; i <= charset2.size(); i++)
        {
            check(i, i, 0, v);
        }

        // printchar();
        // check(2, 2, 0, v);
        cout << "#" << test_case << " " << Answer << endl;
        cout << "count:" << ncount << endl;
        //printm(charset);
        printset(charset1);
        printv(charset2);
        // cout << charset3 << endl;
        printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    }
    return 0;
}
