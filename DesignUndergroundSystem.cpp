/**
 * Solution to https://leetcode.com/problems/design-underground-system/
 **/ 

class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIns.emplace(id, make_pair(stationName, t));
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [stationIn, startTime] = checkIns[id];
        checkIns.erase(id);
        
        avgTimes[stationIn + stationName].push_back(t - startTime);
    }
    
    double getAverageTime(string startStation, string endStation) {
        const auto& times = avgTimes[startStation + endStation];
        auto sum = accumulate(times.begin(), times.end(), 0.0);
                
        return sum / times.size();
    }
    
private:
    unordered_map<int, pair<string, int>>   checkIns;
    unordered_map<string, vector<double>>   avgTimes;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
