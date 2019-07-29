#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int T, test_case, N, tmp;
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
    freopen("sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d", &N);
        arr.clear();
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &tmp);
            arr.push_back(tmp);
        }

        cout << "#" << test_case << ":";
        print_v(arr);
    }
}