// 332. Reconstruct Itinerary

class Solution {
public:
    unordered_map<string, multiset<string>> m;
    vector<string> routes;

    vector<string> findItinerary(vector<vector<string>> tickets) {
       
        for (auto& ticket : tickets) {
            m[ticket[0]].insert(ticket[1]);
        }

        search("JFK");

        return {routes.rbegin(), routes.rend()};
    }

    void search(string airport) {
        
        while (m[airport].size()) {
            string nextAirport = *m[airport].begin();
            m[airport].erase(m[airport].begin());
            search(nextAirport);
        }

        routes.push_back(airport);
    }
};