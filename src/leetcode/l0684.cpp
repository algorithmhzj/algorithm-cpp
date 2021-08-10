//
// Created by 张俭 on 2021/8/10.
//
#include <vector>

using namespace std;

class L10684 {
public:
    vector<int> parent;

    int findParent(int u) {
        return parent[u] == u ? u : (parent[u] = findParent(parent[u]));
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size() + 1;

        for (int i = 0; i < n; i++) {
            //Initially every vertx is its own parent. For eg: parent of '1' is '1', parent of '2' is '2'
            parent.push_back(i);
        }

        for (vector<int> &e:edges) {
            int u = e[0];
            int v = e[1];
            int p1 = findParent(u);
            int p2 = findParent(v);

            if (p1 != p2) {
                parent[p1] = min(p1, p2);
                parent[p2] = min(p1, p2);
            } else {
                return e;
            }
        }

        return {};
    }
};