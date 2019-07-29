#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int r;
    int c;
    int d;
};

int T, N, row, col, Answer;
char input[1000][1000];
char visited[1000][1000];

queue<Node> qNode;

void bfs(int x, int y)
{
    Node tmpNode;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = 0;
        }
    }
    Node tmp = {x, y, 0};
    qNode.push(tmp);
    visited[x][y] = 1;
    while (!qNode.empty())
    {
        tmpNode = qNode.front();
        Answer = tmpNode.d;
        qNode.pop();

        if ((tmpNode.r + 1 < N && input[tmpNode.r + 1][tmpNode.c] == 'G' && visited[tmpNode.r + 1][tmpNode.c] == 0))
        {
            tmp.r = tmpNode.r + 1;
            tmp.d = tmpNode.d + 1;
            tmp.c = tmpNode.c;

            qNode.push(tmp);
            visited[tmpNode.r + 1][tmpNode.c] = 1;
        }
        if (tmpNode.c + 1 < N && input[tmpNode.r][tmpNode.c + 1] == 'G' && visited[tmpNode.r][tmpNode.c + 1] == 0)
        {
            tmp.r = tmpNode.r;
            tmp.d = tmpNode.d + 1;
            tmp.c = tmpNode.c + 1;
            qNode.push(tmp);
            visited[tmpNode.r][tmpNode.c + 1] = 1;
        }
        if ((tmpNode.r - 1 > 0 && input[tmpNode.r - 1][tmpNode.c] == 'G' && visited[tmpNode.r - 1][tmpNode.c] == 0))
        {
            tmp.r = tmpNode.r - 1;
            tmp.d = tmpNode.d + 1;
            tmp.c = tmpNode.c;
            qNode.push(tmp);
            visited[tmpNode.r - 1][tmpNode.c] = 1;
        }
        if ((tmpNode.c - 1 > 0 && input[tmpNode.r][tmpNode.c - 1] == 'G' && visited[tmpNode.r][tmpNode.c - 1] == 0))
        {
            tmp.r = tmpNode.r;
            tmp.d = tmpNode.d + 1;
            tmp.c = tmpNode.c - 1;
            qNode.push(tmp);
            visited[tmpNode.r][tmpNode.c - 1] = 1;
        }
    }
}

int main()
{
    int test_case;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {

        scanf("%d %d %d", &N, &row, &col);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> input[i][j];
            }
        }
        Answer = 0;
        bfs(row, col);
        cout << "#" << test_case << " " << Answer << endl;
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < N; j++)
        //     {
        //         cout << input[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    return 0;
}
