#include<iostream>
#include<vector>
#include<unordered_map>

using std::vector;
using std::unordered_map;
using std::string;
using std::pair;


class TimeMap {
private:
    unordered_map<string,vector<pair<string, int>>> timeMapDataStructure;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMapDataStructure[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(timeMapDataStructure.count(key) == 0)
            return "";

        if(timestamp < timeMapDataStructure[key][0].second)
            return "";

        int l = 0, r = timeMapDataStructure[key].size()-1, m;

        while(l<=r)
        {
            m = l+((r-l)/2);

            if(timestamp < timeMapDataStructure[key][m].second)
                r = m-1;
            else if (timestamp > timeMapDataStructure[key][m].second)
                l = m+1;
            else
                break;
        }
        return timestamp >= timeMapDataStructure[key][m].second ?
            timeMapDataStructure[key][m].first :
            timeMapDataStructure[key][m-1].first;
    }
};

int main()
{
    TimeMap* t = new TimeMap();
    t->set("love", "high", 10);
    t->set("love", "low", 20);
    t->get("love", 5);
    t->get("love", 10);
    t->get("love", 15);
    t->get("love", 20);
    t->get("love", 25);
}