#include <iostream>
#include <map>
#include <set>

using namespace std;

int T, test_case, N, Answer, O, D;
int dcnt;
map<int, int> rk;
set<int> cs;

void printm(map<int, int> m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ")";
    }
    cout << endl;
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
            scanf("%d %d", &O, &D);
            rk[O] = D;
        }
        Answer = 1;
        for (map<int, int>::iterator it = next(rk.begin(), 1); it != rk.end(); it++)
        {
            dcnt = 0;
            for (map<int, int>::iterator it1 = rk.begin(); it1 != it; it1++)
            {
                if (it1->second > it->second)
                    dcnt++;
            }
            if (N - distance(rk.begin(), it) - 1 + dcnt == N - 1)
            {
                Answer++;
                cout << "(" << it->first << "," << it->second << ")" << endl;
            }
        }
        printm(rk);
        cout << "#" << test_case << ":" << Answer << endl;
    }
}