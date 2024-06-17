#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using std::vector;
using std::set;
using std::greater;

class Solution {
    public:
    vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
        set<int, greater<int>> nonRepeatedRanked;
        
        for(int i = 0; i < ranked.size(); i++) {
            nonRepeatedRanked.insert(ranked[i]);
        }
        
        vector<int> nonRepeatedRankedVec(nonRepeatedRanked.begin(), nonRepeatedRanked.end());
        
        vector<int> result;
        for(int i = 0; i < player.size(); i++) {
            int l = 0, r = nonRepeatedRankedVec.size()-1, m;
            
            while(l<=r) {
                m = r - ((r-l)/2);
                
                if(player[i] > nonRepeatedRankedVec[m]) {
                    r = m - 1;
                } else if (player[i] < nonRepeatedRankedVec[m]) {
                    l = m + 1;
                } else {
                    break;
                }
            }
            
            if(player[i] > nonRepeatedRankedVec[m]) {
                result.push_back(m+1);
            } else if (player[i] < nonRepeatedRankedVec[m]) {
                result.push_back(m+2);
            } else {
                result.push_back(m+1);
            }
            
        }
        return result;
    }
};

int main() {
    Solution s;
    s.climbingLeaderboard({100, 90, 90, 80, 75, 60}, {50, 65, 77, 90, 102});
}