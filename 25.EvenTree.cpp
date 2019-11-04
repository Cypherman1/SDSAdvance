#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

class UF
{
    int id[201];
    int N;
    int sz[201];

public:
    UF(int n);
    void uF_union(int p, int q);
    int uF_find(int p, int q);
    int uF_root(int p);
    void clear()
    {
        memset(id, 0, sizeof(id));
        memset(sz, 0, sizeof(id));
        for (int i = 0; i < N; i++)
        {
            id[i] = i;
        }
    }
};

UF::UF(int n)
{
    memset(id, 0, sizeof(id));
    memset(sz, 0, sizeof(id));
    N = n;
    for (int i = 0; i < N; i++)
    {
        id[i] = i;
    }
};

int UF::uF_root(int x)
{
    while (x != id[x])
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
};

int UF::uF_find(int p, int q)
{
    return uF_root(p) == uF_root(q) ? 1 : 0;
};

void UF::uF_union(int p, int q)
{
    int qr = uF_root(q);
    int pr = uF_root(p);
    if (qr == pr)
        return;
    if (sz[qr] < sz[pr])
    {
        id[qr] = pr;
        sz[pr] += sz[qr];
    }
    else
    {
        id[pr] = qr;
        sz[qr] += sz[pr];
    }
    //id[pr] = qr;
}

bool checkOK(UF tuf, set<int> s, int tnodes)
{
    map<int, int> rs;
    for (int i = 0; i < tnodes; i++)
    {
        rs[tuf.uF_root(i)]++;
    }
    for (map<int, int>::iterator it = rs.begin(); it != rs.end(); it++)
    {

        if (it->second % 2 != 0)
            return false;
    }
    return true;
}
// Complete the evenForest function below.
int main()
{
    int t_nodes = 10;
    int t_edges = 9;
    int t_from[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    int t_to[] = {1, 1, 3, 2, 1, 2, 6, 8, 8};
    for (int i = 0; i < t_edges; i++)
    {
        t_from[i]--;
        t_to[i]--;
    }
    UF uf(t_nodes);
    set<int> s;
    bool cont = true;
    while (cont)
    {
        cont = false;
        for (int i = 0; i < t_edges; i++)
        {
            if (s.find(i) == s.end())
            {
                uf.clear();
                for (int j = 0; j < t_edges; j++)
                {
                    if (j != i && s.find(j) == s.end())
                        uf.uF_union(t_from[j], t_to[j]);
                }
                if (checkOK(uf, s, t_nodes))
                {
                    s.insert(i);
                    cont = true;
                    break;
                }
            }
        }
    }
    cout << s.size() << endl;

    return 0;
}
