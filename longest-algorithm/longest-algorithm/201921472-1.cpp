#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 10001;

int n, ans = -987654321;
vector<pair<int, int>> adj[MAX];

int dfs(int curr, int parent) {
    int ret = 0;
    vector<int> path_lengths;
    for (auto next : adj[curr]) {
        int next_node = next.first, weight = next.second;
        if (next_node == parent) continue;
        int path_length = dfs(next_node, curr) + weight;
        path_lengths.push_back(path_length);
    }
    sort(path_lengths.begin(), path_lengths.end(), greater<int>());
    int path_size = path_lengths.size();
    if (path_size > 0) ret = path_lengths[0];
    if (path_size > 1) ans = max(ans, path_lengths[0] + path_lengths[1]);
    ans = max(ans, ret);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    dfs(1, 0);

    cout << ans << '\n';

    return 0;
}