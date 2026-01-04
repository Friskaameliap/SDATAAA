#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>

using namespace std;

struct HuffmanNode {
    char data;
    unsigned freq;
    HuffmanNode *left, *right;
    HuffmanNode(char d, unsigned f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

struct compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) { return l->freq > r->freq; }
};

class HuffmanTree {
public:
    void hitungEfisiensi(string text) {
        if (text.empty()) return;
        map<char, int> freq;
        for (char ch : text) freq[ch]++;

        priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> minHeap;
        for (auto const& x : freq) {
    char ch = x.first;
    int f = x.second;
    minHeap.push(new HuffmanNode(ch, f));
}

        while (minHeap.size() != 1) {
            HuffmanNode *left = minHeap.top(); minHeap.pop();
            HuffmanNode *right = minHeap.top(); minHeap.pop();
            HuffmanNode *top = new HuffmanNode('$', left->freq + right->freq);
            top->left = left; top->right = right;
            minHeap.push(top);
        }

        double originalSize = text.length() * 8;
        double compressedSize = text.length() * 3; // Estimasi rata-rata
        cout << "\n=== ANALISIS HUFFMAN (KOMPRESI NAMA) ===\n";
        cout << "Nama Asli: " << text << endl;
        cout << "Ukuran Awal: " << originalSize << " bits\n";
        cout << "Estimasi Ukuran Kompresi: " << compressedSize << " bits\n";
        cout << "Efisiensi: " << ((originalSize - compressedSize) / originalSize) * 100 << "%\n";
    }
};

#endif