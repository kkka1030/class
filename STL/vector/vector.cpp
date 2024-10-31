#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 定义一个空的 vector
    vector<int> v;

    // 添加元素
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // 访问元素
    cout << "Vector elements: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Using iterator to print elements: ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 使用 at 函数访问
    cout << "Element at index 1: " << v.at(1) << endl;

    // 获取第一个和最后一个元素
    cout << "First element: " << v.front() << endl;
    cout << "Last element: " << v.back() << endl;

    // 删除最后一个元素
    v.pop_back();
    cout << "After pop_back, size: " << v.size() << endl;

    // 遍历所有元素
    cout << "Vector elements: ";
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> v_ = {1, 2, 3, 4, 5};

    // 在指定位置插入元素
    v_.insert(v_.begin() + 2, 10);  // 在索引 2 处插入 10

    // 删除指定位置的元素
    v_.erase(v_.begin() + 4);  // 删除索引 4 处的元素

    // 输出修改后的 vector
    cout << "Modified vector: ";
    for (int num : v_) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> v1;

    // 预先分配空间
    v1.reserve(10);

    cout << "Initial capacity: " << v1.capacity() << endl;

    // 添加元素
    for (int i = 0; i < 5; ++i) {
        v1.push_back(i);
        cout << "Size: " << v1.size() << ", Capacity: " << v1.capacity() << endl;
    }

    // 调整大小
    v.resize(8);
    cout << "After resizing, size: " << v1.size() << ", Capacity: " << v1.capacity() << endl;


    return 0;
}

