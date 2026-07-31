#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        priority_queue<pair<double, int>> pq;
        vector<double> max_prob(n, 0.0);

        max_prob[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [curr_prob, u] = pq.top();
            pq.pop();

            if (u == end_node) {
                return curr_prob;
            }

            if (curr_prob < max_prob[u]) {
                continue;
            }

            for (auto& edge : adj[u]) {
                int v = edge.first;
                double prob = edge.second;

                if (max_prob[u] * prob > max_prob[v]) {
                    max_prob[v] = max_prob[u] * prob;
                    pq.push({max_prob[v], v});
                }
            }
        }

        return 0.0;
    }
};