#include <iostream>
#include <set>
using namespace std;



struct Compare {
    bool operator()(int a, int b) const {
        return a > b; // 降序
    }
};

int main() {
    set<int> mySet;

    // 插入元素
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(10); // 重复元素将被忽略

    // 遍历元素
    for (int val : mySet) {
        cout << val << " "; // 输出: 10 20
    }
    cout << endl;

    // 查找元素
    if (mySet.find(20) != mySet.end()) {
        cout << "20 存在于集合中" << endl;
    }

    // 删除元素
    mySet.erase(10);

    // 检查集合大小
    cout << "集合大小: " << mySet.size() << endl;
    
    set<int, Compare> mySet_ = {10, 20, 5};

    for (int val : mySet_) {
        cout << val << " "; // 输出: 20 10 5
    }
    
    return 0;
}



