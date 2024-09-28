#include <iostream>
#include <cstring>

class Chicken
{
    private:
        int age = 24;
        char* name = nullptr;
    public:
        Chicken(){};
        Chicken(int _age) : age(_age) {};
        Chicken(int _age, const char *_name) : age(_age) 
        {
            int len = strlen(_name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = _name[i];
        };
        
        // 复制构造函数（深拷贝）
        Chicken(const Chicken &other) 
        {
            age = other.age;
            if (other.name != nullptr)
            {
                int len = strlen(other.name) + 1;
                name = new char[len];
                for (int i = 0; i < len; i++)
                    name[i] = other.name[i];
            } else 
            {
                name = nullptr;
            }
        }
        
        // 赋值操作符（深拷贝）
        Chicken& operator=(const Chicken &other)
        {
            if (this == &other)
                return *this;

            if (name != nullptr)
                delete[] name;
                name = nullptr;

            // 进行深拷贝
            age = other.age;
            if (other.name != nullptr) 
            {
                int len = strlen(other.name) + 1;
                name = new char[len];
                for (int i = 0; i < len; i++)
                    name[i] = other.name[i];
            } 
            else 
            {
                name = nullptr;
            }

            return *this;  
        }

        ~Chicken()
        {
            if (name != nullptr)
                delete[] name;
                name = nullptr; // 防止悬空指针
        }
        
        void setAge(int _age)
        {
            age = _age;
        }
        
        void setName(const char *_name)
        {
            if(name != nullptr)
                delete[] name;
                name = nullptr;
            int len = strlen(_name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = _name[i];
        }

        const char* getName() const
        {
            if (name == nullptr) 
            {
                return "";  // 返回""以防止返回nullptr
            }
            return name;
        }

        const int &getAge() const
        {
            return age;
        }
};


int main()
{
    Chicken c(24,"KunKun");
    Chicken c2 = c;
    std::cout << "Hi, everyone! My name is " << c.getName() << ", I am " << c.getAge() << " years old." << std::endl;
    std::cout << "Hi, everyone! My name is " << c2.getName() << ", I am " << c2.getAge() << " years old." << std::endl;
    
    Chicken c3(30);//试一下不给名字的输出
    std::cout << "Hi, everyone! My name is " << c3.getName() << ", I am " << c3.getAge() << " years old." << std::endl;
    
    c3.setName(c.getName());//试一下这样给名字
    std::cout << "Hi, everyone! My name is " << c3.getName() << ", I am " << c3.getAge() << " years old." << std::endl;
    Chicken c4;
    c4 = c3 = c;  //测试连续赋值
    std::cout << "Hi, everyone! My name is " << c4.getName() << ", I am " << c4.getAge() << " years old." << std::endl;

    return 0;
}


/*
int main(){
auto print = [](const Chicken &c){
std::cout << "Hi, everyone! My name is " << c.getName()
<< ", I am " << c.getAge() << " years old." << std::endl;
};
Chicken c(24, "Kunkun");
print(c);
Chicken d;
d = c;
print(d); // 测试【赋值运算符】是否正确，能正确输出给 20 分
Chicken a = c;
print(a); // 测试【赋值构造函数】是否正确，能正确输出给 20 分
c.setName("Xukun Cai");
print(c);
print(a);
print(d); // 测试是否为【深度复制】，本行与上两行能正确输出给 20 分
Chicken b;
b = d = c;
print(b);
print(d); // 测试【连续赋值】功能，本行与上一行能正确输出给 20 分
return 0;
}
*/