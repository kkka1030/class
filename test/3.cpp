#include <iostream>
#include <stdexcept>  // 引入标准异常类

void divide(int a, int b)
{
    if (b == 0)  // 检查是否除以零
    {
        throw std::runtime_error("Division by zero!");  // 抛出异常
    }
    std::cout << "Result: " << a / b << std::endl;
}

int main()
{
    try
    {
        divide(10, 0);  // 调用 divide 函数，b 为 0 会引发异常
    }
    catch (const std::exception &e)  // 捕获异常
    {
        std::cout << "Caught an exception: " << e.what() << std::endl;  // 输出异常信息
    }
    return 0;
}
