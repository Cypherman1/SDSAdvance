#include <iostream>
using namespace std;

int icount = 0;

void FLS(string input, int idx, int l, string prefix, bool done)
{
    icount++;
    if (done)
        return;
    int n = input.length();
    if (l == 0)
    {
        cout << prefix << endl;
        if (prefix.compare("AC") == 0)
            done = true;
    }
    else
    {
        for (int i = idx; i < n; i++)
        {
            prefix.push_back(input[i]);
            FLS(input, i + 1, l - 1, prefix, done);
            prefix.pop_back();
        }
    }
}

int main()
{
    icount = 0;
    FLS("ABCD", 0, 2, "", false);
    cout << icount << endl;
    return 0;
}
