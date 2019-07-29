#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int T, test_case, R, C, Answer;
int matrix[101][101];

struct min_max
{
    int min;
    int max;
};

vector<min_max> arr;

min_max find_minmax(int input[101][101], int r, int c)
{
    min_max tmp;
    tmp.min = INT_MAX;
    tmp.max = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (input[i][j] < tmp.min)
                tmp.min = input[i][j];
            if (input[i][j] > tmp.max)
                tmp.max = input[i][j];
        }
    }

    return tmp;
}

// void print_v(vector<int> v)
// {
//     for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//     {
//         cout << *it << " ";
//     }
//     cout << endl;
// }

int main()
{
    freopen("sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d", &R, &C);
        arr.clear();
        memset(matrix, 0, sizeof(matrix));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
                scanf("%d", &matrix[i][j]);
        }
        Answer = 0;
        min_max tmp = find_minmax(matrix, R, C);
        arr.push_back(tmp);

        while (R % 2 == 0 || C % 2 == 0)
        {
            if (R % 2 == 0 && C % 2 != 0)
            {
                for (int i = 0; i < R / 2; i++)
                {
                    for (int j = 0; j < C; j++)
                    {
                        matrix[i][j] += matrix[R - 1 - i][j];
                    }
                }
                R = R / 2;
            }
            else if (R % 2 != 0 && C % 2 == 0)
            {
                for (int i = 0; i < R; i++)
                {
                    for (int j = 0; j < C / 2; j++)
                    {
                        matrix[i][j] += matrix[i][C - 1 - j];
                    }
                }
                C = C / 2;
            }
            else if (R % 2 == 0 && C % 2 == 0)
            {
                if (R > C)
                {
                    for (int i = 0; i < R / 2; i++)
                    {
                        for (int j = 0; j < C; j++)
                        {
                            matrix[i][j] += matrix[R - 1 - i][j];
                        }
                    }
                    R = R / 2;
                }
                else
                {
                    for (int i = 0; i < R; i++)
                    {
                        for (int j = 0; j < C / 2; j++)
                        {
                            matrix[i][j] += matrix[i][C - 1 - j];
                        }
                    }
                    C = C / 2;
                }
            }
            Answer++;
            tmp = find_minmax(matrix, R, C);
            arr.push_back(tmp);
        }

        cout << "#" << test_case << " " << Answer << " ";
        for (vector<min_max>::iterator it = arr.begin(); it != arr.end(); it++)
        {
            cout << it->max << " " << it->min << " ";
        }
        cout << endl;
    }
}