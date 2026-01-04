#include "queue_antrian.h"

void kelolaAntrianPemesanan(DoublyLinkedListManager& manager) {
    static queue<string> antrian;
    int p;
    do {
        cout << "\n--- Antrian (Queue) ---\n";
        cout << "1.Tambah Antri 2.Proses 3.Keluar: "; cin >> p;
        if (p == 1) {
            int id; cout << "ID Properti: "; cin >> id;
            PropertiLinkedList* prop = manager.cariById(id);
            if (prop) {
                antrian.push(prop->getNama());
                cout << prop->getNama() << " masuk antrian.\n";
            } else cout << "ID tidak ditemukan.\n";
        } else if (p == 2 && !antrian.empty()) {
            cout << "Memproses: " << antrian.front() << endl;
            antrian.pop();
        } else if (p == 2) cout << "Antrian kosong.\n";
    } while (p != 3);
}