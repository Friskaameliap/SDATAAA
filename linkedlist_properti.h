#ifndef LINKEDLIST_PROPERTI_H
#define LINKEDLIST_PROPERTI_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PropertiLinkedList {
private:
    int id;
    string nama, tipe, lokasi, status;
    double harga;
public:
    PropertiLinkedList(int id, string nama, string tipe, double harga, string lokasi);
    void tampilkan() const;
    int getId() const { return id; }
    string getNama() const { return nama; }
    string getStatus() const { return status; }
    void setStatus(string s) { status = s; }
};

struct DoublyNode {
    PropertiLinkedList data;
    DoublyNode *next, *prev;
    DoublyNode(PropertiLinkedList d) : data(d), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedListManager {
private:
    DoublyNode *head, *tail;
    vector<string> historyStack;
    const int MAX_HISTORY = 10;
public:
    DoublyLinkedListManager();
    ~DoublyLinkedListManager();
    void tambahData(PropertiLinkedList data);
    void tampilkanSemuaMaju();
    void tampilkanNavigasi();
    void hapusData(int id);
    void tampilkanHistory();
    PropertiLinkedList* cariById(int id);
};

#endif