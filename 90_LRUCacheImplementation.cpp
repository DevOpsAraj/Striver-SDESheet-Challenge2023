// Code Studio - LRU Cache Implementation

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    unordered_map<int, int> mp;
    unordered_map<int, list<int>::iterator> address;
    list<int> l;
    int cap;
    int siz;

    LRUCache(int capacity)
    {
        cap = capacity;
        siz = 0;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;

        list<int>::iterator it = address[key];
        l.erase(it);
        address.erase(key);
        l.push_front(key);
        address[key] = l.begin();
        return mp[key];
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            l.erase(address[key]);
            address.erase(key);
            mp.erase(key);
            siz--;
        }

        if (siz == cap)
        {
            int k = l.back();
            l.pop_back();
            address.erase(k);
            mp.erase(k);
            siz--;
        }

        siz++;
        l.push_front(key);
        address[key] = l.begin();
        mp[key] = value;
    }
};

int main()
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // returns 1
    cache.put(3, 3);              // evicts key 2
    cout << cache.get(2) << endl; // returns -1 (not found)
    cache.put(4, 4);              // evicts key 1
    cout << cache.get(1) << endl; // returns -1 (not found)
    cout << cache.get(3) << endl; // returns 3
    cout << cache.get(4) << endl; // returns 4
    return 0;
}