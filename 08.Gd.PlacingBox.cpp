#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int T, test_case, N, K, Answer, tmp_sum, c;
int scores[101], conditions[101];
map<int, int, greater<int> > blocks;
int pos[101];

void greedy()
{
    for (map<int, int>::iterator it = blocks.begin(); it != blocks.end(); it++)
    {
        for (int i = it->second; i > 0; i--)
        {
            if (pos[i] == 0 && c < K)
            {
                pos[i] = 1;
                Answer += it->first;
                c++;
                break;
            }
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
        for (int i = 0; i < N; i++)
        {
            blocks[scores[i]] = conditions[i];
            pos[i] = 0;
        }
        pos[0] = 1;
        pos[N] = 0;
        Answer = 0;
        c = 0;
        greedy();
        // for (map<int, int>::iterator it = blocks.begin(); it != blocks.end(); it++)
        // {
        //     cout << "(" << it->first << "," << it->second << ") ";
        // }
        // cout << endl;
        cout << "#" << test_case << ":" << Answer << endl;
    }
    return 0;
}