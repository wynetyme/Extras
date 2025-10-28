#include <iostream>
#include <vector>
using namespace std;
class MyHashMap {
private:
    vector<vector<pair<int,int>>> buckets;
    int size;
    int hash(int key) {
        return key % size;
    }
public:
    MyHashMap() {
        size = 1009;
        buckets.resize(size);
    }
    void put(int key, int value) {
        int idx = hash(key);
        for(auto& p : buckets[idx]) {
            if(p.first == key) {
                p.second = value;
                return;
            }
        }
        buckets[idx].push_back({key, value});
    }
    int get(int key) {
        int idx = hash(key);
        for(auto& p : buckets[idx]) {
            if(p.first == key) {
                return p.second;
            }
        }
        return -1;
    }
    void remove(int key) {
        int idx = hash(key);
        for(int i = 0; i < buckets[idx].size(); i++) {
            if(buckets[idx][i].first == key) {
                buckets[idx].erase(buckets[idx].begin() + i);
                return;
            }
        }
    }
};
int main(){
    MyHashMap* myHashMap = new MyHashMap();
    myHashMap->put(1, 1);
    myHashMap->put(2, 2);
    cout << myHashMap->get(1) << '\n';
    cout << myHashMap->get(3) << '\n';
    myHashMap->put(2, 1);
    cout << myHashMap->get(2) << '\n';
    myHashMap->remove(2);
    cout << myHashMap->get(2) << '\n';
    delete myHashMap;
    return 0;
}
