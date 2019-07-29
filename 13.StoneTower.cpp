#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int T, test_case, N, height_sofar, answer;
int HF[1001][2];

struct stone
{
    int H;
    int F;
};

stone tmp_stone;

vector<stone> stones;

void print_stones(vector<stone> s)
{
    for (vector<stone>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "(" << it->H << "," << it->F << ")";
    }
    cout << endl;
}

bool cp_func(stone s1, stone s2)
{
    return (s1.F / (double)s1.H > s2.F / (double)s2.H);
}

int main()
{
    freopen("sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d", &N);
        stones.clear();
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &tmp_stone.H, &tmp_stone.F);
            stones.push_back(tmp_stone);
        }

        sort(stones.begin(), stones.end(), cp_func);
        answer = 0;
        height_sofar = 0;

        for (int i = 1; i < stones.size(); i++)
        {
            height_sofar += stones[i - 1].H;
            answer += stones[i].F * height_sofar / 10;
        }
        cout << "#" << test_case << ":" << answer << endl;
    }
}