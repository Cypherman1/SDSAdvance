#include <iostream>

using namespace std;

#define INF 987654321;

int T, N, Answer, Sum;
int Input[25];

void Try(int i)
{
    if (Sum == 99)
    {
        if (i < Answer)
        {
            Answer = i;
            return;
        }
    }
    if (i == N)
    {
        return;
    }
    for (int j = 0; j < 2; j++)
    {
        if (j == 0)
        {
            Sum += Input[i];
        }
        else
        {
            Sum -= Input[i];
        }

        Try(i + 1);

        if (j == 1)
        {
            Sum += Input[i];
        }
        else
        {
            Sum -= Input[i];
        }
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
        Sum = Input[0];

        Try(1);

        if (Answer == 987654321)
        {
            Answer = 0;
        }
        cout << "#" << test_case << " " << Answer << endl;
    }

    return 0;
}
