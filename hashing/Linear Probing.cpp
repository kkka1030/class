#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HashTable {
private:
    vector<string> table;
    int size;
    string DELETED = "__DELETED__";

public:
    HashTable(int size) : size(size) {
        table.resize(size, "");
    }

    int hashFunction(string key) {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % size;
        }
        return hash;
    }

    void insert(string key) {
        int index = hashFunction(key);
        while (table[index] != "" && table[index] != DELETED) {
            index = (index + 1) % size; // 线性探测
        }
        table[index] = key;
    }

    bool search(string key) {
        int index = hashFunction(key);
        int start = index;
        while (table[index] != "") {
            if (table[index] == key) return true;
            index = (index + 1) % size;
            if (index == start) break; // 避免无限循环
        }
        return false;
    }

    void remove(string key) {
        int index = hashFunction(key);
        int start = index;
        while (table[index] != "") {
            if (table[index] == key) {
                table[index] = DELETED;
                return;
            }
            index = (index + 1) % size;
            if (index == start) break;
        }
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    HashTable hashTable(7);

    hashTable.insert("Alice");
    hashTable.insert("Bob");
    hashTable.insert("Charlie");

    hashTable.display();

    cout << "Search Bob: " << hashTable.search("Bob") << endl;

    hashTable.remove("Bob");
    cout << "After removing Bob:" << endl;
    hashTable.display();

    return 0;
}
