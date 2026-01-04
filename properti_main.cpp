#include <iostream>
#include "linkedlist_properti.h"
#include "stack_history.h"
#include "queue_batal.h"
#include "huffman_coding.h"
#include "avl_tree.h"

using namespace std;

int main() {
    DoublyLinkedListManager dll;
    ActivityStack stackHistory;
    QueuePembatalan qBatal;
    HuffmanTree huffman;
    AVLTree avl;
    AVLNode* avlRoot = nullptr;

    int pilihan;
    do {
        cout << "\n===== SISTEM PROPERTI ADVANCED =====\n";
        cout << "1. Kelola Properti (DLL)\n";
        cout << "2. Ajukan Pembatalan (Queue Batal)\n";
        cout << "3. Approve Pembatalan (Admin)\n";
        cout << "4. Lihat Riwayat (Stack)\n";
        cout << "5. Analisis Efisiensi Nama (Huffman)\n";
        cout << "6. Lihat ID Properti Terurut (AVL Tree)\n";
        cout << "0. Keluar\nPilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int id; string nama;
            cout << "Input ID: "; cin >> id; cin.ignore();
            cout << "Input Nama: "; getline(cin, nama);
            dll.tambahData(PropertiLinkedList(id, nama, "Rumah", 1000, "Kota"));
            avlRoot = avl.insert(avlRoot, id); // Tambah ke AVL
            stackHistory.push("Menambah properti: " + nama);
        } 
        else if (pilihan == 2) {
            string nama; cout << "Nama properti yg dibatalkan: "; cin.ignore(); getline(cin, nama);
            qBatal.tambahPermintaan(nama);
            stackHistory.push("Mengajukan pembatalan: " + nama);
        }
        else if (pilihan == 3) qBatal.approveAdmin();
        else if (pilihan == 4) stackHistory.tampilkanRiwayat();
        else if (pilihan == 5) {
            string nama; cout << "Nama properti untuk dianalisis: "; cin.ignore(); getline(cin, nama);
            huffman.hitungEfisiensi(nama);
        }
        else if (pilihan == 6) {
            cout << "ID Terurut (AVL): "; avl.inOrder(avlRoot); cout << endl;
        }
    } while (pilihan != 0);
    
    
    return 0;
}