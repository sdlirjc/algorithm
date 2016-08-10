class LRUCache{
public:
    struct CacheEntry{
    public:
        int key;
        int val;
        CacheEntry(int k,int v):key(k),val(v){}
    };
    LRUCache(int capacity) {
        m_capacity=capacity;
        
    }
    
    int get(int key) {
        if(m_map.find(key)==m_map.end()){
            return -1;
        }
        move(key);
        return m_map[key]->val;
    }
    
    void set(int key, int value) {
        if(m_map.find(key)==m_map.end()){
            CacheEntry newItem(key,value);
            if(m_map.size()>=m_capacity){
                m_map.erase(m_list.back().key);
                m_list.pop_back();
            }
            m_list.push_front(newItem);
            m_map[key]=m_list.begin();
        }
        m_map[key]->val=value;
        move(key);
    }
private:
    int m_capacity;
    unordered_map<int, list<CacheEntry>::iterator >m_map;
    list<CacheEntry> m_list;
    void move(int key){
        auto entry=*m_map[key];
        m_list.erase(m_map[key]);
        m_list.push_front(entry);
        m_map[key]=m_list.begin();
    }
};
