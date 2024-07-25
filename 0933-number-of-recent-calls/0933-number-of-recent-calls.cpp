class RecentCounter {
public:

    queue<int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int thresh = t - 3000;
        while(!q.empty() && thresh > q.front()) {
            q.pop();
        }

        q.push(t);

        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */