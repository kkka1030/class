#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <string>
using namespace std;


int precedence(char op) 
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
    
}

double applyop(double a,double b,char op)
{
    if (op == '+')
    {
        return a+b;
    }
    if (op == '-')
    {
        return a-b;
    }
    if (op == '*')
    {
        return a*b;
    }
    if (op == '/')
    {
        if (b == 0) throw runtime_error("除数不能为0");
        return a/b;
    }
    return 0;
}

bool isminus(int i,const string &expression)
{
    if (i==0)
    {
        return true;
    }
    while (i >= 1 && isspace(expression[i-1]))
        {
            --i;
        }
    if (i ==0 || expression[i-1] == '+' || expression[i-1] == '-' || expression[i-1] == '*' || expression[i-1] == '/'|| expression[i-1] == '(')
    {
        return true;
    }
    return false; 
}

double evaluate(const string &expression)
{
    stack<double> values;
    stack<char> ops;
    int count =0;
    for (int i = 0; i < expression.length();i++)
    {
        if (isspace(expression[i]))
        {
            continue;
        }
        if (isdigit(expression[i]))
        {
            int j = i;
            count = 0;
            while (i < expression.length()-1 && (isdigit(expression[i+1]) || expression[i+1] == '.'))
            {
                if (expression[i+1] == '.')
                {
                    ++count;
                }
                i++;
            }
            if (expression[i] == '.' || count >=2) 
            {
                throw runtime_error("小数格式错误"); 
            }
            double value = stod(expression.substr(j,i-j+1));
            values.push(value);
        }
        else if (expression[i] == '(')
        {
            ops.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                if (values.empty()) throw runtime_error("操作数不足");
                double val2 = values.top();
                values.pop();
                if (values.empty()) throw runtime_error("操作数不足");
                double val1 = values.top();
                values.pop();
                values.push(applyop(val1,val2,ops.top()));
                ops.pop();
            }
            if (ops.empty()) throw runtime_error("erro");
            ops.pop();
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            if (expression[i] == '-' && isminus(i,expression))
            {
                values.push(0);
            }
            while (!ops.empty() && precedence(expression[i]) <= precedence(ops.top()))
            {
                if (values.empty()) throw runtime_error("操作数不足");
                double val2 = values.top();
                values.pop();
                if (values.empty()) throw runtime_error("操作数不足");
                double val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyop(val1,val2,op));
            }
            ops.push(expression[i]);
        }
        else 
        {
            throw runtime_error("非法字符");
        }

    }
    while (!ops.empty()) {
        if (values.empty()) throw runtime_error("操作数不足");
        double val2 = values.top();
        values.pop();

        if (values.empty()) throw runtime_error("操作数不足");
        double val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyop(val1, val2, op));
    }
    if (values.size() != 1) throw runtime_error("表达式错误");
    return values.top();

}