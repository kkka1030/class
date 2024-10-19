#include "List.h"
#include <iostream>
#include <utility>  // for std::move

void testList() {
    // 测试默认构造函数和析构函数
    List<int> lst;
    std::cout << "测试: 默认构造函数成功" << std::endl;

    // 测试 push_back, push_front, pop_back, pop_front
    lst.push_back(10);
    lst.push_back(15);
    lst.push_back(20);
    lst.push_back(25);
    lst.push_front(5);
    std::cout << "测试push_back和push_front: 插入 5, 10, 15，20，25 到链表" << std::endl;

    // 输出链表的元素
    for (const auto& it : lst) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    
    // 测试 front() 和 back() 函数
    std::cout << "测试: front() 返回 " << lst.front() << std::endl;
    std::cout << "测试: back() 返回 " << lst.back() << std::endl;
    
    lst.pop_back();  // 删除最后一个元素
    lst.pop_front();  // 删除第一个元素
    std::cout << "测试pop_back()和pop_front()：删除头尾元素，此时链表应剩余 10 15 20" << std::endl;

    // 输出链表的元素
    for (const auto& it : lst) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    
    // 测试前置递增 (++iterator)
    std::cout << "测试前置递增 ++iterator" << std::endl;
    auto it = lst.begin();
    std::cout << "当前元素为: " << *(++it) << std::endl;  // 输出 15

    // 5. 测试后置递增 (iterator++)
    std::cout << "测试后置递增 iterator++" << std::endl;
    auto it_ = lst.begin();
    std::cout << "当前元素为: " << *(it_++) << std::endl;  // 输出 10

    //  测试带初始化列表的构造函数
    List<int> lstInit = {1, 2, 3, 4, 5};  // 使用初始化列表
    std::cout << "测试初始化列表构造函数" << std::endl;
    for (const auto& it : lstInit) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    //  测试拷贝构造函数
    List<int> lstCopy = lst;  // 调用拷贝构造函数
    std::cout << "测试拷贝构造函数" << std::endl;

    // 输出拷贝后的链表
    for (const auto& it : lstCopy) {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    //  测试移动构造函数
    List<int> lstMove = std::move(lstCopy);  // 调用移动构造函数
    std::cout << "测试移动构造函数" << std::endl;

    // 输出移动后的链表
    for (const auto& it : lstMove) {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    //  测试插入与删除
    lstMove.insert(lstMove.begin(), 100);  // 在头部插入元素
    lstMove.insert(lstMove.end(), 200);    // 在尾部插入元素
    std::cout << "测试insert: 在链表头部插入 100, 尾部插入 200" << std::endl;

    for (const auto& it : lstMove) {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    // 测试erase
    lstMove.erase(lstMove.begin());  // 删除第一个元素
    std::cout << "测试erase: 删除头部元素" << std::endl;

    for (const auto& it : lstMove) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    
    //  测试 erase(from, to) 
    std::cout << "测试erase(from, to)" << std::endl;
    lstMove.erase(++lstMove.begin(), --lstMove.end());  // 删除第二个到倒数第二个元素
    for (const auto& it : lstMove) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    
    
    //  测试赋值运算符
    List<int> lstAssign;
    lstAssign = lstMove;  // 调用赋值运算符
    std::cout << "测试赋值运算符" << std::endl;

    for (const auto& it : lstAssign) {
        std::cout << it << " ";
    }
    std::cout  << std::endl;

    //  测试移动赋值运算符
    List<int> lstMoveAssign;
    lstMoveAssign = std::move(lstAssign);  // 调用移动赋值运算符
    std::cout << "测试移动赋值运算符" << std::endl;

    for (const auto& it : lstMoveAssign) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    
    lstMoveAssign.clear();
    std::cout << "测试clear() 函数清空链表" << std::endl;

    // 测试链表是否为空
    if (lstMoveAssign.empty()) {
        std::cout << "测试empty()和size()成功" << std::endl;
    }
    //  测试空链表处理
    List<int> emptyList;
    if (emptyList.begin() == emptyList.end()) {
        std::cout << "测试空链表中begin()和end()成功" << std::endl;
    }
    
}

int main() {
    testList();  // 调用测试函数
    return 0;
}
