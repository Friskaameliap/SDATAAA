#ifndef QUEUE_BATAL_H
#define QUEUE_BATAL_H

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class QueuePembatalan {
private:
    queue<string> qBatal;
public:
    void tambahPermintaan(string namaProp) {
        qBatal.push(namaProp);
        cout << "Permintaan pembatalan " << namaProp << " dikirim ke Admin.\n";
    }
    void approveAdmin() {
        if (qBatal.empty()) {
            cout << "Tidak ada antrian pembatalan.\n";
            return;
        }
        cout << "Admin menyetujui pembatalan properti: " << qBatal.front() << endl;
        qBatal.pop();
    }
};

#endif