#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::string;
using std::vector;
using std::unordered_map;

class Solution {
    public:
        vector<vector<string>> groupAnagramsBySort(vector<string> strs) {
            unordered_map<string,vector<string>> umap;
            vector<vector<string>> result;
            string sortedString;

            for(string str : strs) {
                sortedString = str;
                std::sort(sortedString.begin(), sortedString.end());
                umap[sortedString].push_back(str);
            }
            
            for(auto it = umap.begin(); it != umap.end(); ++it){
                result.push_back(it->second);
            }

            return result;
        }

        vector<vector<string>> groupAnagrams(vector<string> strs) {
            unordered_map<string, vector<string>> umap;

            for(int i = 0; i < strs.size(); i++) {
                string key = getKey(strs[i]);
                umap[key].push_back(strs[i]);
            }

            vector<vector<string>> result;
            for(auto it = umap.begin(); it != umap.end(); ++it){
                result.push_back(it->second);
            }

            return result;
        }
    
    private:
        string getKey(string str) {
            int count[26] = {};

            for(int i = 0; i < str.size(); i++){
                count[str[i] - 'a']++;
            }

            string key = "";
            for (int num : count) {
                key.append(std::to_string(num) + "#");
            }

            return key;
        }
};

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    // vector<string> strs = {"bdddddddddd", "bbbbbbbbbbc"};

    Solution solution;
    vector<vector<string>> result = solution.groupAnagramsBySort(strs);
    
    for(const vector<string>& innerVector : result) {
        for(const string& str : innerVector) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
}