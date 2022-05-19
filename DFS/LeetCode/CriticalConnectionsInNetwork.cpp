// 1192. Critical Connections in a Network

struct pairHash {
    size_t operator()(const pair<int, int>& p) const {
        size_t firstHash = hash<int>{}(p.first);
        size_t secondHash = hash<int>{}(p.second);
 
        return firstHash ^ secondHash;
    }
};

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_map<pair<int, int>, bool, pairHash> visitConnections;
    unordered_map<int ,int> levels;
    unordered_set<pair<int, int>, pairHash> connectionSet;
    int graphs = 0;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ret;
        int root = connections.front()[0];
        
        // build graph
        for (vector<int>& connection : connections) {
            int a = connection[0];
            int b = connection[1];
            
            if (graph.find(a) == graph.end()) {
                graph[a] = vector<int>();
            }
            
            if (graph.find(b) == graph.end()) {
                graph[b] = vector<int>();
            }
            
            graph[a].push_back(b);
            graph[b].push_back(a);
            visitConnections[{a, b}] = false;
            connectionSet.insert({a, b});
        }

        searchGraph(0, root, graph[root]);

        for (auto& el : connectionSet) {
            ret.push_back({el.first, el.second});
        }
        
        return ret;
    }
    
    
    int searchGraph(int level, int cur, vector<int>& neighber) {
        int minLevel = level;
        levels[cur] = level;

        for (int v : neighber) {
            if (levels.find(v) == levels.end()) {
                
                if (visitConnections.find({cur, v}) != visitConnections.end()) {
                        visitConnections[{cur, v}] = true;
                } else {
                        visitConnections[{v, cur}] = true;
                }
                
                int nextMinLevel = searchGraph(level+1, v, graph[v]);

                if (nextMinLevel <= level) {
                    if (connectionSet.find({cur, v}) != connectionSet.end()) {
                        connectionSet.erase({cur, v});
                    } else {
                        connectionSet.erase({v, cur});
                    }
                }

                minLevel = min(minLevel, nextMinLevel);
            } else {
                bool isVisit = visitConnections.find({cur, v}) != visitConnections.end() ? visitConnections[{cur, v}] : visitConnections[{v, cur}];
                if (!isVisit) {
                    if (level > levels[v]) {
                        if (connectionSet.find({cur, v}) != connectionSet.end()) {
                            connectionSet.erase({cur, v});
                        } else {
                            connectionSet.erase({v, cur});
                        }
                    }
                    minLevel = min(minLevel, levels[v]);
                }
            }
        }
        
        return minLevel;
    }
};