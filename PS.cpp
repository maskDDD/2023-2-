#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_INIT 100001

int N, M;
int task_t[MAX_INIT];
vector<vector<int>> adj(MAX_INIT);
int Max = 0;
int MAX = 0;

int DFS(int sum, int n) {
	sum += task_t[n];
	Max = max(Max, sum);
	for (int i = 0; i < adj[n].size(); i++) {
		DFS(sum, adj[n][i]);
	}
	return Max;
}

int main() {
	cin >> N >> M;
	int buf;
	for (int i = 1; i < N+1; i++) {
		cin >> buf;
		task_t[i] = buf;
	}
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
	}

	int sum = 0;
	for (int i = 1; i < N; i++) {
		MAX = max(DFS(sum, i), MAX);
		Max = 0;
	}
	cout << MAX;

	return 0;
}