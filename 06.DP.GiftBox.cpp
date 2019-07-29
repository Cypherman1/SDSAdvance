#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, Answer, N, test_case;
int price_limit, pieces;
int input[101];
int *min_price;



int main()
{
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d", &price_limit, &pieces);
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &input[i]);
        }
        min_price = min_element(input, input + N);
        Answer = 0;
        vector<int> st;
        st.clear();

        for (int i = pieces; i > 0; i--)
        {
            dfs(0, i, i, 0, st);
            if (Answer > 0)
            {
                break;
            }
        }
        cout << "#" << test_case << ":" << Answer << endl;
        // cout << "#" << test_case << ":" << *min_price << endl;
    }
    return 0;
}