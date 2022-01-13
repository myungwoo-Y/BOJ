// title : 1326. Minimum Number of Taps to Open to Water a Garden
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> tabsInGarden(n+1);
        
        vector<int> distanceToRight(n+1);
        
        const int maxRange = 100;
        
        for (int i = 0; i <= n; i++) {
            distanceToRight[i] = i + ranges[i];
        }
        
        for (int tab = 0; tab <= n; tab++) {
            int distance = distanceToRight[tab];
            for (int garden = tab - ranges[tab]; garden <= distance; garden++) {
                if (garden > n) break;
                if (garden < 0) garden = 0;
                int prevTab = tabsInGarden[garden];
                tabsInGarden[garden] = distance > distanceToRight[prevTab] ? tab : prevTab;
            }
        }
        
        int tabCnt = 0;
        int tab = 0;
        while (tab < n) {
            int preTab = tab;
            tab = distanceToRight[tabsInGarden[tab]];
            if (preTab == tab) {
                tabCnt = -1;
                break;
            }
            tabCnt++;
        }
        
        return tabCnt;
    }
};