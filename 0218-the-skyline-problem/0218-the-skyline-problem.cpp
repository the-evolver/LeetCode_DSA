class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> edges;
        for (int i = 0; i < buildings.size(); i++) {
            edges.push_back({buildings[i][0], i});
            edges.push_back({buildings[i][1], i});
        }
        sort(edges.begin(), edges.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;
        vector<vector<int>> res;
        int y = 0;
        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i].first;
            while (i < edges.size() && edges[i].first == x) {
                int ind = edges[i].second;
                if (buildings[ind][0] == x) {
                    q.push({buildings[ind][2], buildings[ind][1]});
                }
                i += 1;
            }
            i -= 1;
            while (!q.empty() && q.top().second <= x) {
                q.pop();
            }
            int h = q.empty() ? 0 : q.top().first;
            if (y != h) {
                res.push_back({x, h});
                y = h;
            }
        }
        return res;
    }
};