#include <iostream>
#include <map>
using namespace std;

struct Compare {
    bool operator()(const string &a, const string &b) const {
        return a > b; // 按降序排列键
    }
};

int main() {
    map<string, int> myMap;

    // 插入键值对
    myMap["Alice"] = 30;
    myMap["Bob"] = 25;

    // 遍历键值对
    for (auto &entry : myMap) {
        cout << entry.first << ": " << entry.second << endl;
    }

    // 查找键
    if (myMap.find("Alice") != myMap.end()) {
        cout << "Alice 存在于映射中" << endl;
    }

    // 删除键
    myMap.erase("Bob");

    // 获取元素
    cout << "Alice 的年龄: " << myMap["Alice"] << endl;

    map<string, int, Compare> myMap_;
    myMap_["Alice"] = 30;
    myMap_["Bob"] = 25;

    for (auto &entry : myMap_) {
        cout << entry.first << ": " << entry.second << endl; // 输出顺序: Bob, Alice
    }
    return 0;
}
