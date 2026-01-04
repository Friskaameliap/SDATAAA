#ifndef STACK_HISTORY_H
#define STACK_HISTORY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ActivityStack {
private:
    vector<string> stack;
public:
    void push(string log) {
        stack.push_back(log);
    }
    void pop() {
        if (!stack.empty()) stack.pop_back();
    }
    void tampilkanRiwayat() {
        cout << "\n=== RIWAYAT AKTIVITAS (STACK) ===\n";
        if (stack.empty()) cout << "Belum ada riwayat.\n";
        for (int i = stack.size() - 1; i >= 0; i--) {
            cout << "[" << stack.size() - i << "] " << stack[i] << endl;
        }
    }
};

#endif