#include <iostream>
#include "BinarySearchTree.h"
#include "dsexceptions.h"

using namespace std;

int main() {
    // 创建一个整数类型的二叉搜索树并插入一些元素
    BinarySearchTree<int> tree;
    cout << "插入元素: 10, 5, 15, 3, 7, 12, 18" << endl;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);
    cout << "当前树的内容:" << endl;
    tree.printTree();

    // 测试删除叶子节点
    cout << "\n测试删除叶子节点" << endl;
    cout << "删除元素 3" << endl;
    tree.remove(3);
    cout << "删除后树的内容:" << endl;
    tree.printTree();
    cout << "检查删除后查找元素 3: " << (tree.contains(3) ? "找到" : "未找到") << endl;

    // 测试删除只有一个子节点的节点
    cout << "\n测试删除只有一个子节点的节点" << endl;
    cout << "删除元素 5" << endl;
    tree.remove(5);
    cout << "删除后树的内容:" << endl;
    tree.printTree();
    cout << "检查删除后查找元素 5: " << (tree.contains(5) ? "找到" : "未找到") << endl;

    // 测试删除有两个子节点的节点
    cout << "\n测试删除有两个子节点的节点" << endl;
    cout << "删除元素 10" << endl;
    tree.remove(10);
    cout << "删除后树的内容:" << endl;
    tree.printTree();
    cout << "检查删除后查找元素 10: " << (tree.contains(10) ? "找到" : "未找到") << endl;

    // 测试删除不存在的元素
    cout << "\n测试删除不存在的元素" << endl;
    cout << "删除元素 100" << endl;
    tree.remove(100);
    cout << "删除后树的内容:" << endl;
    tree.printTree();
    cout << "检查删除后查找元素 100: " << (tree.contains(100) ? "找到" : "未找到") << endl;

    // 最终验证树的完整性
    cout << "\n最终树的内容:" << endl;
    tree.printTree();
    
    return 0;
}

