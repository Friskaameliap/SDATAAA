#include "linkedlist_properti.h"
#include <iomanip>

PropertiLinkedList::PropertiLinkedList(int id, string nama, string tipe, double harga, string lokasi) 
    : id(id), nama(nama), tipe(tipe), harga(harga), lokasi(lokasi), status("Tersedia") {}

void PropertiLinkedList::tampilkan() const {
    cout << "ID: " << id << " | " << setw(15) << left << nama << " | " << status << endl;
}

DoublyLinkedListManager::DoublyLinkedListManager() : head(nullptr), tail(nullptr) {}

DoublyLinkedListManager::~DoublyLinkedListManager() {
    DoublyNode* curr = head;
    while (curr) {
        DoublyNode* next = curr->next;
        delete curr;
        curr = next;
    }
}

void DoublyLinkedListManager::tambahData(PropertiLinkedList data) {
    DoublyNode* newNode = new DoublyNode(data);
    if (!head) head = tail = newNode;
    else { tail->next = newNode; newNode->prev = tail; tail = newNode; }
    historyStack.push_back("Tambah: " + data.getNama());
}

void DoublyLinkedListManager::tampilkanSemuaMaju() {
    DoublyNode* curr = head;
    if(!curr) { cout << "Data kosong!\n"; return; }
    while (curr) { curr->data.tampilkan(); curr = curr->next; }
}

void DoublyLinkedListManager::tampilkanNavigasi() {
    if (!head) return;
    DoublyNode* curr = head;
    int p;
    do {
        cout << "\n--- Navigasi ---\n";
        curr->data.tampilkan();
        cout << "1.Next 2.Prev 3.Keluar: "; cin >> p;
        if (p == 1 && curr->next) curr = curr->next;
        else if (p == 2 && curr->prev) curr = curr->prev;
    } while (p != 3);
}

void DoublyLinkedListManager::hapusData(int id) {
    DoublyNode* curr = head;
    while (curr && curr->data.getId() != id) curr = curr->next;
    if (!curr) return;
    if (curr == head) head = head->next;
    if (curr == tail) tail = tail->prev;
    if (curr->next) curr->next->prev = curr->prev;
    if (curr->prev) curr->prev->next = curr->next;
    historyStack.push_back("Hapus ID: " + to_string(id));
    delete curr;
    cout << "Data berhasil dihapus.\n";
}

void DoublyLinkedListManager::tampilkanHistory() {
    cout << "\n--- Riwayat (Stack) ---\n";
    if(historyStack.empty()) cout << "Belum ada riwayat.\n";
    for (int i = historyStack.size() - 1; i >= 0; i--) cout << historyStack[i] << endl;
}

PropertiLinkedList* DoublyLinkedListManager::cariById(int id) {
    DoublyNode* curr = head;
    while (curr) {
        if (curr->data.getId() == id) return &curr->data;
        curr = curr->next;
    }
    return nullptr;
}