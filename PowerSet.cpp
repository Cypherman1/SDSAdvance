#include <iostream>
#include <vector>
using namespace std;

int icount = 0;

void PowerSet(string s, int idx, string prefix)
{
    int n = s.length();
    // if (idx == n)
    //     return;
    if (prefix.length() == 2)
    {
        cout << prefix << ":" << idx << endl;
        return;
    }

    for (int i = idx + 1; i < n; i++)
    {
        prefix += s[i];
        PowerSet(s, i, prefix);
        prefix.erase(prefix.size() - 1);
    }
}

int main()
{
    PowerSet("tung", -1, "");
    return 0;
}
