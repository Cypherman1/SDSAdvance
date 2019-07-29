#include <iostream>
using namespace std;

void TryPrintHelper(int N, string s)
{

    if (N == 0)
    {
        cout << s << endl;
    }
    else
    {
        for (char i = '0'; i <= '1'; i++)
        {
            TryPrintHelper(N - 1, s + i);
        }
    }
}

int main()
{
    TryPrintHelper(3, "");
}
