#include<iostream>
#include<map>
#include<vector>

using std::vector;
using std::map;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)
            return false;
        
        map<int,int> quantityByNumber;
        for(int i = 0; i < hand.size(); i++)
            quantityByNumber[hand[i]]++;

        map<int, int>::iterator it;
        int tempFirst, tempSecond, i, prev;

        while(!quantityByNumber.empty())
        {
            i = 0;
            it = quantityByNumber.begin();
            prev = it->first - 1;
            while(it != quantityByNumber.end() && i < groupSize)
            {
                tempFirst = it->first;
                tempSecond = it->second;

                if(tempFirst - prev > 1)
                    return false;

                i++;
                it++;

                prev = tempFirst;
                quantityByNumber[tempFirst]--;
                
                if(quantityByNumber[tempFirst] == 0)
                    quantityByNumber.erase(tempFirst);
            }
            
            if(i != groupSize)
                return false;
        }
        return true;
    }
};

int main()
{
    vector<int> hand = {1,2,3,6,2,3,4,7,8};
    Solution s;
    s.isNStraightHand(hand, 3);
}