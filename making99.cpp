#include <iostream>
using namespace std;

#define INF 987654321;

int T, N, Answer, Sum;
int Input[25];

void backtract(int idx, int sumSofar)
{
    // cout << "*" << idx << ":" << sumSofar << endl;
    if (sumSofar == 99)
    {
        if (idx + 1 < Answer)
        {
            Answer = idx + 1;
        }
    }
    if (idx >= N - 1)
    {
        return;
    }
    else if (idx + 1 > Answer)
    {
        return;
    }
    else
    {
        backtract(idx + 1, sumSofar + Input[idx + 1]);
        backtract(idx + 1, sumSofar - Input[idx + 1]);
    }
}

int main()
{
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%d", &Input[i]);
        Answer = 987654321;

        backtract(0, Input[0]);

        if (Answer == 987654321)
            Answer = 0;

        cout << "#" << test_case << " " << Answer << endl;
    }
}