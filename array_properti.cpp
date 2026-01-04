#include "array_properti.h"

void kelolaModulArray(ArrayManager& manager) {
    int p;
    do {
        cout << "\n--- Arsip (Array) ---\n";
        cout << "1.Tampil 2.Tambah 3.Keluar: "; cin >> p;
        if (p == 1) manager.tampilkanSemua();
        else if (p == 2) {
            int id; string nm;
            cout << "ID: "; cin >> id; cin.ignore();
            cout << "Nama: "; getline(cin, nm);
            manager.tambahData(PropertiArray(id, nm, "Arsip", 0, "Gudang"));
        }
    } while (p != 3);
}