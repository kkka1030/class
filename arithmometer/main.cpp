#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <string>
#include "arith.h"
using namespace std;

int main()
{
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);
    try 
    {
        int result = evaluate(expression);
        cout << result << endl;
    } 
    catch (const exception &e) 
    {
        cout << "ILLEGAL" << endl;
    }
    return 0;
}
