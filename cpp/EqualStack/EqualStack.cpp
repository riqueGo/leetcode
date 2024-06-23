#include<iostream>
#include<vector>
#include<stack>

using std::vector;
using std::stack;

struct StackHeight {
    stack<int> s;
    int totalHeight = 0;
    
    StackHeight(vector<int> h) {
        for(int i = h.size()-1; i >= 0; i--) {
            totalHeight+=h[i];
            s.push(h[i]);
        }
    }
    
    void pop() {
        totalHeight-=s.top();
        s.pop();
    }
};

int lowerStackHeight(StackHeight& s1, StackHeight& s2, StackHeight& s3) {
    if(s1.totalHeight <= s2.totalHeight && s1.totalHeight <= s3.totalHeight) {
        return s1.totalHeight;
    } else if (s2.totalHeight <= s1.totalHeight && s2.totalHeight <= s3.totalHeight) {
        return s2.totalHeight;
    }
    return s3.totalHeight;
}

void removeUntilSpecificHeight(StackHeight& s, int height) {
    while(s.totalHeight > height) {
        s.pop();
    }
}

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    StackHeight s1(h1);
    StackHeight s2(h2);
    StackHeight s3(h3);
    int lowestHeigh;
    
    while(s1.totalHeight != s2.totalHeight || s2.totalHeight != s3.totalHeight) {
        lowestHeigh = lowerStackHeight(s1,s2,s3);
        removeUntilSpecificHeight(s1, lowestHeigh);
        removeUntilSpecificHeight(s2, lowestHeigh);
        removeUntilSpecificHeight(s3, lowestHeigh);
    }
    
    return s1.totalHeight;
}

int main() {
    equalStacks({3,2,1,1,1}, {4,3,2}, {1,1,4,1});
}