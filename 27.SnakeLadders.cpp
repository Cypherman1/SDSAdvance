
/* eslint-disable */
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int T, test_case, answer, n, m;

class DGraph
{
    int V;

public:
    vector<vector<int> > adj;
    DGraph(int n)
    {
        V = n;
        adj.resize(V, vector<int>(0));
    }
    void addEdge(int i, int j)
    {
        adj[i].push_back(j);
    }
    int getV()
    {
        return V;
    }
    void printG() {
        for (int i=0; i<V; i++) {
            cout << i << "->";
            for (size_t j=0; j < adj[i].size(); j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

struct cell
{
    int id;
    int depth;
};

class BFSPath
{
    int s;
    vector<bool> marked;

public:
    BFSPath(DGraph g, int is)
    {
        marked.resize(g.getV(), false);
        s = is;
    }
    int bfs(DGraph g, int is)
    {
        queue<cell> bfsq;
        marked[is] = true;
        cell ctmp, itmp;
        ctmp.id = is;
        ctmp.depth = 0;
        bfsq.push(ctmp);
        int d;
        while (!bfsq.empty())
        {
            ctmp = bfsq.front();
            d = ctmp.depth;
            d++;
            bfsq.pop();
            
            for (size_t i = 0; i < g.adj[ctmp.id].size(); i++)
            {
                if (!marked[g.adj[ctmp.id][i]])
                {
                    itmp.id = g.adj[ctmp.id][i];
                    itmp.depth = d;
                    bfsq.push(itmp);
                    marked[g.adj[ctmp.id][i]] = true;
                    if (itmp.id == 99)
                        return itmp.depth;
                }
            }
        }
        return -1;
    }
};

// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int> > ladders, vector<vector<int> > snakes)
{
    map<int, int> m_ladders, m_snakes;
    m_ladders.clear();
    m_snakes.clear();
    vector<vector<int> >::iterator it;
    for (it = ladders.begin(); it != ladders.end(); it++)
        m_ladders[--it->at(0)] = --it->at(1);
    for (it = snakes.begin(); it != snakes.end(); it++)
        m_snakes[--it->at(0)] = --it->at(1);
    DGraph G(100);

    for (int i = 0; i < 100; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (m_ladders.find(i + j) != m_ladders.end())
            {
                G.addEdge(i, m_ladders[i + j]);
            }
            else if (m_snakes.find(i + j) != m_snakes.end())
            {
                G.addEdge(i, m_snakes[i + j]);
            }
            else
            {
                G.addEdge(i, i + j);
            }
        }
    }
    // G.printG();
    BFSPath bPath(G, 0);
    return bPath.bfs(G, 0);
}

int main()
{
    // eslint-disable-next-line
    vector<vector<int> > vLadders, vSnacks;
    int v1, v2;
    freopen("27.sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d", &n);
        vLadders.resize(n, vector<int>(0));
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &v1, &v2);
            vLadders[i].push_back(v1);
            vLadders[i].push_back(v2);
        }
        scanf("%d", &m);
        vSnacks.resize(m, vector<int>(0));
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &v1, &v2);
            vSnacks[i].push_back(v1);
            vSnacks[i].push_back(v2);
        }
        cout << "#" << test_case << " " << quickestWayUp(vLadders, vSnacks) << endl;
    }
    return 0;
}