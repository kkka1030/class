#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // 定义三个 map
    map<string, string> nameToPhone;  // 名字 → 电话
    map<string, string> phoneToName; // 电话 → 名字
    map<string, string> idToPhone;   // 身份证号 → 电话

    // 插入数据
    nameToPhone["Alice"] = "12345";
    phoneToName["12345"] = "Alice";
    idToPhone["ID001"] = "12345";

    // 查找：通过名字找到身份证号
    string name = "Alice";
    if (nameToPhone.find(name) != nameToPhone.end()) {
        string phone = nameToPhone[name];
        string id = "";
        for (const auto &entry : idToPhone) {
            if (entry.second == phone) {
                id = entry.first;
                break;
            }
        }
        cout << "Name: " << name << ", Phone: " << phone << ", ID: " << id << endl;
    } else {
        cout << "名字未找到！" << endl;
    }

    // 删除数据
    string phone = nameToPhone["Alice"];
    nameToPhone.erase("Alice");
    phoneToName.erase(phone);
    for (auto it = idToPhone.begin(); it != idToPhone.end(); ++it) {
        if (it->second == phone) {
            idToPhone.erase(it);
            break;
        }
    }

    return 0;
}
