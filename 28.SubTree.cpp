#include <iostream>
#include <vector>
using namespace std;

/*BEGIN Graph class */
int n, t1, t2;

class UGraph {
	int V;
	int E;
public:
	vector<vector<int> > adj;
	UGraph(int Vx);
	void addEdge(int v, int w);
	void printUG();
	int getV() {
		return V;
	}
};

UGraph::UGraph(int Vx) {
	V = Vx;
	E=0;
    adj.resize(V, vector<int>(0));
}

void UGraph::addEdge(int v, int w) {
	E++;
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void UGraph::printUG() {
	for (int i=0; i< V; i++) {
		for (vector<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++) {
			cout << i << " " << *it << endl;
		}
	}
}

/*END Graph class */

/*BEGIN DFS */

class DFSPaths {
	int s;
	vector<bool> marked;
	vector<int> edgeTo;
	void dfs(UGraph G, int v, vector<int> vi);
public:
	DFSPaths(UGraph G, int v);
	bool hasPathTo(int v);
	vector<int> pathTo(int v);
};

bool DFSPaths::hasPathTo(int v) {
	return marked[v];
}

vector<int> DFSPaths::pathTo(int v) {
	vector<int> path;
	if (!hasPathTo(v)) return path;
	for (int x = v; x!=s; x = edgeTo[x]) {
		path.push_back(x);
	}
	path.push_back(s);
	reverse(path.begin(), path.end());
	return path;
}

DFSPaths::DFSPaths(UGraph G, int v) {
	s = v;
    marked.resize(G.getV(), false);
    edgeTo.resize(G.getV(), -1);
    vector<int> isuf(0);
	dfs(G, s, isuf);
}

void DFSPaths::dfs(UGraph G, int v, vector<int> suf ) {
	marked[v] = true;
    for (size_t i=0; i<suf.size(); i++) cout << suf[i];
            cout << endl;

	for (vector<int>::iterator it=G.adj[v].begin(); it != G.adj[v].end(); it++) {
		if (!marked[*it]) {	
            suf.push_back(*it);	
			dfs(G, *it, suf);
			edgeTo[*it] = v;
            suf.pop_back();
		}
	}
    
}

/*END DFS*/

int main() {
    freopen("28.input.txt", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d", &n);
    UGraph G(n);
    for (int i=0; i< n-1; i++) {
        scanf("%d %d", &t1, &t2);
        G.addEdge(t1, t2);
    }

    DFSPaths dpath(G, 0);

    return 0;
}