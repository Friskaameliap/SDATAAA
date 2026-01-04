#ifndef ARRAY_PROPERTI_H
#define ARRAY_PROPERTI_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MAX_PROPERTI 100

class PropertiArray {
    int id; string nama, tipe, lokasi, status; double harga;
public:
    PropertiArray() {}
    PropertiArray(int i, string n, string t, double h, string l) 
        : id(i), nama(n), tipe(t), harga(h), lokasi(l), status("Tersedia") {}
    int getId() { return id; }
    void tampilkan() { cout << id << " | " << nama << " | " << status << endl; }
};

class ArrayManager {
    PropertiArray data[MAX_PROPERTI];
    int jumlah;
public:
    ArrayManager() : jumlah(0) {}
    void tambahData(PropertiArray p) { if(jumlah < MAX_PROPERTI) data[jumlah++] = p; }
    void tampilkanSemua() { for(int i=0; i<jumlah; i++) data[i].tampilkan(); }
    int getJumlahData() { return jumlah; }
    int getKapasitasMaksimum() { return MAX_PROPERTI; }
};

void kelolaModulArray(ArrayManager& manager);

#endif