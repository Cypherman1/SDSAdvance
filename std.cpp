#include <iostream>
#include <vector>

using namespace std;

void printv(vector<int> v)
{
    for (vector<int>::iterator i1 = v.begin(); i1 != v.end(); i1++)
    {
        cout << *i1 << " ";
    }
    cout << endl;
}

bool isOdd(int i)
{
    return i % 2 != 0;
}
bool nCheck(int i)
{
    return i > 5;
}

int main()
{

    vector<int> v;
    vector<int> v1;
    for (int i = 10; i > 0; i--)
    {
        v.push_back(i);
        v1.push_back(0);
    }
    printv(v);

    string s = "tungnt";

    sort(v.begin() + 2, v.end());

    sort(s.begin(), s.end());

    cout << s << endl;

    printv(v);

    vector<int>::iterator it1 = find_if(v.begin(), v.end(), isOdd);

    // int n = count_if(v.begin(), v.end(), [](int x) { return x < 5; });

    vector<int> items;

    items.push_back(30);
    items.push_back(40);

    vector<int>::iterator it2 = find_first_of(v.begin(), v.end(), items.begin(), items.end());

    if (it2 != v.end())
    {
        cout << "Found: " << *it2 << endl;
    }
    else
    {
        cout << "Not Found!" << endl;
    }

    printv(v1);
    copy_if(v.begin(), v.end(), v1.begin(), nCheck);
    printv(v1);

    cout << *it1 << endl;

    std::cout << "Hello, World!\n";
    return 0;
}
