#include <iostream>
#include <stack>
using namespace std;

int main() {
    // 定义一个整数类型的栈
    stack<int> s;

    // 向栈中压入元素
    s.push(10);
    s.push(20);
    s.push(30);

    // 输出栈顶元素
    cout << "Top element: " << s.top() << endl;  // 输出 30

    // 弹出栈顶元素
    s.pop();
    cout << "After pop, top element: " << s.top() << endl;  // 输出 20

    // 判断栈是否为空
    if (!s.empty()) {
        cout << "The stack is not empty." << endl;
    }

    // 输出栈的大小
    cout << "Stack size: " << s.size() << endl;  // 输出 2

    return 0;
}
