#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int T, test_case, N, K, L;
long long int Answer, total_quality, remaining_quality;

struct apple_tree
{
    int A;
    int B;
};

apple_tree tmp_tree;

vector<apple_tree> trees;

void print_v(vector<apple_tree> v)
{
    for (vector<apple_tree>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "(" << it->A << "," << it->B << ")";
    }
    cout << endl;
}
bool comp_func(apple_tree t1, apple_tree t2)
{
    return t1.B < t2.B;
}

int main()
{
    freopen("sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d %d", &N, &K, &L);
        trees.clear();
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &tmp_tree.A, &tmp_tree.B);
            trees.push_back(tmp_tree);
        }

        Answer = 0;
        total_quality = 0;

        for (vector<apple_tree>::iterator it = trees.begin(); it != trees.end(); it++)
        {
            total_quality += it->A;
        }
        if (total_quality >= K * N)
        {
            Answer = 0;
        }
        else
        {
            remaining_quality = K * N - total_quality;
            sort(trees.begin(), trees.end(), comp_func);

            for (vector<apple_tree>::iterator it = trees.begin(); it != trees.end(); it++)
            {
                int i = 1;
                while (i <= L - it->A)
                {
                    remaining_quality -= 1;
                    Answer += it->B;
                    i++;
                    if (remaining_quality == 0)
                        goto finish;
                }
            }
        }
    finish:
        cout << "#" << test_case << " " << Answer << endl;
    }
}