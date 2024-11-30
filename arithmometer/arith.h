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
    
}

int applyop(double a,double b,char op)
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
        if (b == 0) throw runtime_error("Mismatched parentheses");
        return a/b;
    }
}
int evaluate(const string &expression)
{
    stack<double> values;
    stack<int> ops;
    for (int i = 0; i < expression.length();i++)
    {
        if (isspace(expression[i]))
        {
            continue;
        }
        if (isdigit(expression[i]))
        {
            int j = i;
            while (i < expression.length() && (isdigit(expression[i+1]) || expression[i+1] == '.'))
            {
                i++;
            }
            if (expression[i] == '.') 
            {
                throw runtime_error("Invalid number format"); 
            }
            int value = stod(expression.substr(j,i-j+1));
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
                if (values.empty()) throw runtime_error("erro");
                double val2 = values.top();
                values.pop();
                if (values.empty()) throw runtime_error("erro");
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
            if (precedence(expression[i])>precedence(ops.top()))
            {
                if (values.empty()) throw runtime_error("erro");
                double val2 = values.top();
                values.pop();
                if (values.empty()) throw runtime_error("erro");
                double val1 = values.top();
                values.push(applyop(val1,val2,expression[i]));
            }
            else
            {
                ops.push(expression[i]);                
            }

        }

    }
}