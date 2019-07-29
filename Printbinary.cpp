#include <iostream>
using namespace std;

string s = "";

void TryPrintHelper(int idx, int N)
{

    if (idx == N)
    {
        cout << s << endl;
    }
    else
    {
        for (char i = '0'; i <= '1'; i++)
        {
            s.push_back(i);
            TryPrintHelper(idx + 1, N);
            s.pop_back();
        }
    }
}

int main()
{
    TryPrintHelper(1, 3);
}
