#include <iostream>
#include <string>
#include<vector>
#include <sstream>

using std::string;
using std::vector;

class Solution {
    public:
        string encode(vector<string>& strs){
            std::ostringstream stream;

            for(string str : strs){
                int size = str.size();
                stream << size << "#" << str;
            }

            return stream.str();
        }

        vector<string> decode(string &str){
            vector<string> result;
            int i = 0;

            while (i < str.size()) {
                // Find the position of the "#" character
                int atPos = str.find('#', i);
                if (atPos == std::string::npos) {
                    // If "#" is not found, there's an error in the encoded string
                    return {};
                }
                
                // Get the length of the next string
                int len = std::stoi(str.substr(i, atPos - i));
                
                // Move the index to the start of the string
                i = atPos + 1;
                
                // Extract the string
                std::string subStr = str.substr(i, len);
                
                // Add the string to the decoded vector
                result.push_back(subStr);
                
                // Move the index to the start of the next string
                i += len;
            }
            return result;
        }
};

int main(){
    vector<string> strs = {"neet", "co#de"};
    Solution solution;

    string resultEncode = solution.encode(strs);
    std::cout << resultEncode << std::endl;

    vector<string> result = solution.decode(resultEncode);
    for(string str : result) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
}