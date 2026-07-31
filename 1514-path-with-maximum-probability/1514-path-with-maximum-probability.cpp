#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        vector<double> max_prob(n, 0.0);
        vector<bool> in_queue(n, false);
        queue<int> q;

        max_prob[start_node] = 1.0;
        q.push(start_node);
        in_queue[start_node] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue[u] = false;

            for (const auto& [v, prob] : adj[u]) {
                if (max_prob[u] * prob > max_prob[v]) {
                    max_prob[v] = max_prob[u] * prob;
                    if (!in_queue[v]) {
                        q.push(v);
                        in_queue[v] = true;
                    }
                }
            }
        }

        return max_prob[end_node];
    }
};