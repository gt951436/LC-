class Solution {
public:
#define p pair<int, int>
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> SPM(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            SPM[i][i] = 0;
        }
        unordered_map<int, vector<p>> adj;
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        for (int i = 0; i < n; ++i) {
            dijkstra(n, adj, SPM[i], i);
        }
        // find the city using adj
        return resultCity(n, SPM, distanceThreshold);
    }
    void dijkstra(int n, unordered_map<int, vector<p>>& adj,
                  vector<int>& result, int src) {
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, src});
        fill(result.begin(), result.end(), INT_MAX);
        result[src] = 0;
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& P : adj[node]) {
                int adjNode = P.first;
                int dist = P.second;

                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }
    }
    int resultCity(int n, vector<vector<int>>& SPM, int& distanceThreshold) {
        int res = -1;
        int leastReachableCnt = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int CntReach = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && SPM[i][j] <= distanceThreshold) {
                    CntReach += 1;
                }
            }
            if (CntReach <= leastReachableCnt) {
                leastReachableCnt = CntReach;
                res = i;
            }
        }
        return res;
    }
};