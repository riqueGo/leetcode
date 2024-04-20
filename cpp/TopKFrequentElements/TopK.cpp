#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;
using std::unordered_map;
using std::string;
using std::pair;

class Solution {
    public:
        // Time: O(n log n)
        // Space: O(n + k)
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int,int> umap = getNumsByQuantity(nums);

            vector<pair<int,int>> vec(umap.begin(), umap.end());
            std::sort(vec.begin(), vec.end(), [](const auto& lhs, const auto& rhs){
                return lhs.second > rhs.second;
            });

            vector<int> result;

            for(int i = 0; i < k; i++){
                result.push_back(vec[i].first);
            }

            return result;
        }

        // Time: O(n log k)
        // Space: O(n + k)
        vector<int> topKFrequentMap(vector<int>& nums, int k) {
            unordered_map<int,int> umap = getNumsByQuantity(nums);

            std::priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
            for(auto it = umap.begin(); it != umap.end(); ++it) {
                pq.push({it->second, it->first});
                if(pq.size() > k) {
                    pq.pop();
                }
            }

            vector<int> result;
            while(!pq.empty()) {
                result.push_back(pq.top().second);
                pq.pop();
            }
            return result;
        }

        // Time: O(n)
        // Space: O(n)
        vector<int> topKFrequentBucketSort(vector<int>& nums, int k){
            int n = nums.size();

            unordered_map<int,int> umap = getNumsByQuantity(nums);

            vector<vector<int>> buckets(n+1);
            for(auto it = umap.begin(); it != umap.end(); ++it){
                buckets[it->second].push_back(it->first);
            }

            vector<int> result;

            for(int i = n; i >= 0; i--){
                if(result.size() >= k){
                    break;
                }
                if(!buckets[i].empty()){
                    result.insert(result.end(), buckets[i].begin(), buckets[i].end());
                }
            }
            return result;
        }


    
    private:
        unordered_map<int,int> getNumsByQuantity(vector<int>& nums) {
            unordered_map<int,int> umap;
            for(int i = 0; i < nums.size(); i++) {
                umap[nums[i]]++;
            }
            return umap;
        }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    Solution solution;
    vector<int> result = solution.topKFrequentBucketSort(nums, k);

    for(int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}