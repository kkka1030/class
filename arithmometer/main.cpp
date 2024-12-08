#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <string>
#include "arith.h"
using namespace std;

int main()
{
    // 测试用例数组
    std::string testCases[] = {
        //基本测试
        "1 + 2 * 3",        
        "(1 + 2) * 3",      
        "3 + (4 * 5)",      
        "(10 - 3) / (2 + 1)", 

        // 测试负数和小数
        "1 + -2.1",         
        "3.5 + 2.1",        
        "4 * -1.5",         
        "10 / 2.5",         
        "1 + -2.1 * 2",     

        // 测试非法表达式
        "1 ++ 2",           
        "1 + 2 *",          
        "+ 1 + 2",          
        "(1 + 2",           
        "10 / 0",           
        "1.2 + 3.4.5",      
        "10 / 0.0",         
        "2 * (3 / 0)"       
    };
    
    for (const auto& expr : testCases) 
    {
        try {
            std::cout << "Expression: " << expr << std::endl;
            double result = evaluate(expr);  
            std::cout << "Result: " << result << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "ILLEGAL:" << e.what() << std::endl;  
        }
        std::cout << std::endl;
    }
    
    
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);
    try 
    {
        double result = evaluate(expression);
        cout << result << endl;
    } 
    catch (const exception &e) 
    {
        cout << "ILLEGAL: " << e.what() << endl;
    }
    return 0;
}
