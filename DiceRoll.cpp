#include <iostream>
#include <vector>
using namespace std;
int icount;

void printDice(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void diceRollHelper(int n, int sum, int sumSofar, vector<int> v)
{
    if ((sumSofar > sum - n * 1) || (sumSofar < sum - n * 6))
        return;
    icount++;
    if (n == 0)
    {
        printDice(v);
    }
    else
    {
        for (int i = 1; i <= 6; i++)
        {
            v.push_back(i);
            diceRollHelper(n - 1, sum, sumSofar + i, v);
            v.pop_back();
        }
    }
}
void diceRoll(int n, int sum)
{
    vector<int> v;
    icount = 0;
    diceRollHelper(n, sum, 0, v);
}
int main()
{
    diceRoll(4, 9);
    cout << icount << endl;
    return 0;
}
