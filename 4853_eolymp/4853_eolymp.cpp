#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
	int vertices, edges;
	cin >> vertices >> edges;
	int source, destination;
	cin >> source >> destination;
	--source, --destination;
	vector<vector<int>> graph(vertices);
	for (int j = 0; j < edges; ++j) {
		int a, b; cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}
	vector<int> dist(vertices, -1);
	queue<int> q;
	vector<int> parent(vertices, -1);
	dist[source] = 0;
	q.push(source);
	while (q.size() != 0) {
		int v = q.front();
		for (int j = 0; j < graph[v].size(); ++j) {
			int to = graph[v][j];
			if (dist[to] == -1) {
				dist[to] = dist[v] + 1;
				q.push(to);
				parent[to] = v;
			}
		}
		q.pop();
	}
	cout << dist[destination] << endl;
	if (dist[destination] != -1) {
		vector<int> path;
		path.push_back(destination);
		while (parent[destination] != -1) {
			destination = parent[destination];
			path.push_back(destination);
		}
		for (int j = path.size() - 1; j >= 0; --j) cout << path[j] + 1 << ' ';
	}
    return 0;
}

