#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int N;
int M;
int G;
int D;
int Destroyed[100];
int Edge[300][2];
set<int> visited;

void dfs(int start)
{
    if (visited.find(start) == visited.end())
    {
        visited.insert(start);
        for (int i = 0; i < M; i++)
        {
            if (Edge[i][0] == start && visited.find(Edge[i][1]) == visited.end())
            {
                dfs(Edge[i][1]);
            }
            else if (Edge[i][1] == start && visited.find(Edge[i][0]) == visited.end())
            {
                dfs(Edge[i][0]);
            }
        }
    }
}

int main()
{

    int T;
    /*
	freopen function below opens input file in read only mode, and afterward,
	the program will read from input file instead of standard(keyboard) input.
	To test your program, you may save input data in input file,
	and use freopen function to read from the file when using scanf function.
	You may remove the comment symbols(//) in the below statement and use it.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/
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
        cin >> N >> M >> G >> D;

        for (int i = 0; i < D; i++)
        {
            cin >> Destroyed[i];
        }
        for (int i = 0; i < M; i++)
        {
            cin >> Edge[i][0] >> Edge[i][1];
        }
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			Implement your algorithm from this section.
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////
        visited.clear();
        for (int i = 0; i < D; i++)
            visited.insert(Destroyed[i]);
        dfs(G);

        cout << "#" << test_case << ":" << N - (visited.size() - D) << endl;
        // for (set<int>::iterator it = visited.begin(); it != visited.end(); it++)
        // {
        //     cout << *it << " ";
        // }
        // cout << endl;
    }
    return 0;
}
