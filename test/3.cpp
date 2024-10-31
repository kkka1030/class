#include <iostream>
#include <stdexcept>  // 引入标准异常类

void divide(int & a)
{
    a-=1;
    int b = a;
    std::cout << "b: " << b << std::endl;
}

int main()
{
    int a = 1;
    divide(a);
    std::cout << "a: " << a << std::endl;
    return 0;
}
