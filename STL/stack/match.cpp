#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 函数用于检查括号是否匹配
bool isValidParentheses(const string &str) {
    stack<char> s;
    for (char c : str) {
        // 如果是左括号，则压入栈
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        // 如果是右括号，检查栈顶元素是否匹配
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) {
                return false;  // 栈为空，说明没有匹配的左括号
            }
            char top = s.top();
            s.pop();
            // 检查是否是对应的括号
            if ((c == ')' && top != '(') || 
                (c == '}' && top != '{') || 
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    // 检查栈是否为空，栈为空表示括号匹配
    return s.empty();
}

int main() {
    string expr = "{[()]}";  // 测试字符串
    if (isValidParentheses(expr)) {
        cout << "Parentheses are balanced." << endl;
    } else {
        cout << "Parentheses are not balanced." << endl;
    }
    return 0;
}
