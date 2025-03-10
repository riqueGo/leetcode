#include <iostream>
#include <vector>

using std::string;
using std::vector;

void expandAroundCenter(const string& word, int left, int right, vector<string>& palindromes) {
    int n = word.length();
    while (left >= 0 && right < n && word[left] == word[right]) {
        palindromes.push_back(word.substr(left, right - left + 1));
        left--;
        right++;
    }
}

vector<string> getAllSubPalindromes(const string& word) {
    vector<string> palindromes;
    int n = word.length();
    
    for (int i = 0; i < n; i++) {
        expandAroundCenter(word, i, i, palindromes); 
        expandAroundCenter(word, i, i + 1, palindromes);
    }
    
    return palindromes;
}

int main() {
    string word;
    std::cout << "Enter a word: ";
    std::cin >> word;
    
    vector<string> palindromes = getAllSubPalindromes(word);
    
    std::cout << "Sub-palindromes: " << std::endl;
    for (const string& palindrome : palindromes) {
        std::cout << palindrome << std::endl;
    }
}