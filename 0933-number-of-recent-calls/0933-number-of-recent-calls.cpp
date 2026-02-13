class RecentCounter {
public:
    queue<int>timestamps;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        timestamps.push(t);
        while(!timestamps.empty() && timestamps.front() < t-3000){
            timestamps.pop();
        }
        return timestamps.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */