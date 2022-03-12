// 679. 24 Game

class Solution {
public:
    bool isFind = false;
    const double eps = 0.001;
    
    void findTargetValue(vector<double>& cards) {
        if (isFind) return;

        if (cards.size() == 1) {
            isFind |= (24.0 - eps <= cards.front() && cards.front() <= 24.0 + eps);
            return;
        }

        for (int i = 0; i < cards.size(); i++) {
            for (int j = 0; j < cards.size(); j++) {
                if (i == j) continue;

                double a = cards[i];
                double b = cards[j];

                vector<double> results = {a*b, a+b, a-b, b-a};

                if (b > eps) results.push_back(a/b);
                if (a > eps) results.push_back(b/a);

                if (i < j) {
                    cards.erase(cards.begin()+j);
                    cards.erase(cards.begin()+i);
                } else {
                    cards.erase(cards.begin()+i);
                    cards.erase(cards.begin()+j);
                }

                for (double result : results) {
                    cards.push_back(result);
                    findTargetValue(cards);
                    cards.pop_back();
                }

                if (i < j) {
                    cards.insert(cards.begin()+i, a);
                    cards.insert(cards.begin()+j, b);
                } else {
                    cards.insert(cards.begin()+j, b);
                    cards.insert(cards.begin()+i, a);
                }
            }
        }
    }


    bool judgePoint24(vector<int>& cards) {
        vector<double> newCards;

        for (int card : cards) {
            newCards.push_back((double)card);
        }

        findTargetValue(newCards);

        return isFind;
    }
};