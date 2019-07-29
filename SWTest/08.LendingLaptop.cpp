#include <iostream>
#include <cstdio>

using namespace std;

int T, test_case, N, Answer;
int input[1001][2];

int main()
{
    freopen("sample_input.txt", "r", stdin);

    /*
	If you remove the statement below, your program's output may not be recorded
	when your program is aborted due to the time limit.
	For safety, please use setbuf(stdout, NULL); statement.
	*/
    setbuf(stdout, NULL);

    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case)
    {
        //	Read each test case from standard input.

        cout << "#" << test_case << ":" << N << endl;
        for (int i=0; i<N; i++) {
            scanf("%d %d", &input[i][0], &input[i][0]);
        }
        // for (set<int>::iterator it = visited.begin(); it != visited.end(); it++)
        // {
        //     cout << *it << " ";
        // }
        // cout << endl;
    }
    return 0;
}