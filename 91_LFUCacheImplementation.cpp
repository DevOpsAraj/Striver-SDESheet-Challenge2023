// Code Studio - LFU Cache Implementation

#include <bits/stdc++.h>
class LFUCache
{
public:
    int cap;
    int minFreq;
    unordered_map<int, pair<int, int>> cache;
    unordered_map<int, list<int>> freqMap;
    unordered_map<int, list<int>::iterator> pos;

    LFUCache(int capacity)
    {
        this->cap = capacity;
        minFreq = 0;
    }

    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            int freq = cache[key].second;
            freqMap[freq].erase(pos[key]);
            freq++;

            freqMap[freq].push_front(key);
            pos[key] = freqMap[freq].begin();

            if (freqMap[minFreq].empty())
                minFreq++;

            return cache[key].first;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            cache[key].first = value;
            int freq = cache[key].second;
            freqMap[freq].erase(pos[key]);
            freq++;

            freqMap[freq].push_front(key);
            pos[key] = freqMap[freq].begin();

            if (freqMap[minFreq].empty())
                minFreq++;
            return;
        }

        if (cap == cache.size())
        {
            int key = freqMap[minFreq].back();
            cache.erase(key);
            pos.erase(key);
            freqMap[minFreq].pop_front();
        }

        cache[key] = {value, 1};
        freqMap[1].push_front(key);
        pos[key] = freqMap[1].begin();
        minFreq = 1;
    }
};

int main()
{
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // returns 1
    cache.put(3, 3);              // evicts key 2
    cout << cache.get(2) << endl; // returns -1 (not found)
    cout << cache.get(3) << endl; // returns 3.
    cache.put(4, 4);              // evicts key 1.
    cout << cache.get(1) << endl; // returns -1 (not found)
    cout << cache.get(3) << endl; // returns 3
    cout << cache.get(4) << endl; // returns 4
    return 0;
}