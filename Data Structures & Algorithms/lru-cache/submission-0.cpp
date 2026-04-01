class LRUCache {
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.count(key)==0) return -1;
        order.erase(cache[key].second);
        order.push_back(key);
        cache[key].second = --order.end();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(cache.count(key)>0){
            order.erase(cache[key].second);
        }
        else if(cache.size() == capacity){
            int lru = order.front();
            order.pop_front();
            cache.erase(lru);
        }
        order.push_back(key);
        cache[key] = {value, --order.end()};
    }
};
