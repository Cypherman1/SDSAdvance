#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void reverseLine(ifstream &inputfile)
{
    string line;
    if (getline(inputfile, line))
    {
        reverseLine(inputfile);
        cout << line << endl;
    }
    else
    {
    }
}

void test_reverseLine(string filename)
{
    ifstream myfile;
    myfile.open(filename.c_str());
    if (myfile.fail())
    {
        cerr << "file not found!" << endl;
        return;
    }
    reverseLine(myfile);
    myfile.close();
}

int main()
{
    test_reverseLine("lines.txt");
    return 0;
}