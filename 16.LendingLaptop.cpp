#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int T, test_case, N, tmp;
int input[1001][2];
int lend[1500001];

vector<int> arr;

void print_v(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    freopen("16.sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d", &N);
        memset(input, 0, sizeof(input));
        memset(lend, 0, sizeof(lend));
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &input[i][0], &input[i][1]);
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = input[i][0]; j < input[i][0] + input[i][1]; j++)
            {
                lend[j]++;
            }
        }
        cout << "#" << test_case << ":" << *max_element(lend, lend + 1500001) << endl;
    }
}