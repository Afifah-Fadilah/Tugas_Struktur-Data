#include <iostream>

using namespace std;

void identitas() { //fungsi untuk menampilkan identitas nama,npm dan kelas
    cout << "=================================================\n";
    cout << "Program Ini di Buat Oleh : \n";
    cout << "Nama    : Afifah Fadilah\n";
    cout << "NPM     : 2310631170003\n";
    cout << "Kelas   : 2c - Informatika\n";
    cout << "=================================================\n";
}

// Node class untuk merepresentasikan elemen dalam linked list
class Node {
public:
    int data;         // Membuat var data yang disimpan di dalam node
    Node* next;       // Pointer ke node selanjutnya dalam linked list

    Node(int value) : data(value), next(nullptr) {}
    // Konstruktor untuk membuat node baru dengan data tertentu
};

// Class LinkedList untuk mengelola linked list
class LinkedList {
private:
    Node* head;        // Pointer ke node pertama (head) dalam linked list

public:
    LinkedList() : head(nullptr) {}
    // Konstruktor untuk inisialisasi linked list dengan head yang kosong

    // Fungsi untuk menambahkan elemen ke linked list
    void addNode(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;  // Menyisipkan newNode di awal linked list
        head = newNode;        // Mengubah head menjadi newNode
    }

    // Fungsi untuk membalikkan linked list
    void reverseList() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;   // Simpan node berikutnya
            current->next = prev;    // Balikkan panah next
            prev = current;          // Geser prev ke node saat ini
            current = next;          // Geser current ke node berikutnya
        }

        head = prev;  // Set head ke node terakhir setelah membalikkan
    }

    // Fungsi untuk menampilkan linked list dalam urutan yang benar
    void displayList() {
        displayListHelper(head);  // Memanggil fungsi helper rekursif
        cout << endl;
    }

private:
    // Fungsi rekursif untuk menampilkan linked list dalam urutan yang benar
    void displayListHelper(Node* node) {
        if (node == nullptr) {
            return;  // Jika node kosong, kembali dari rekursi
        }

        displayListHelper(node->next);  // Panggil rekursi untuk node berikutnya
        cout << node->data << " ";     // Tampilkan data dari node saat ini
    }
};

int main() {
    LinkedList myList;

    int n, value;
    cout << "=================================================\n";
    cout << "  Program LinkedList Membalikkan data (reverse)\n";
    cout << "=================================================\n";
    cout << "Masukkan jumlah angka: ";
    cin >> n;

    cout << "Masukkan angka-angka tersebut:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Angka ke-" << i + 1 << ": ";
        cin >> value;
        myList.addNode(value);  // Menambahkan angka ke linked list menggunakan perulangan for
    }
    
    cout <<endl;
    cout << "=================================================\n\n";
    cout << "Linked List sebelum dibalik: ";
    myList.displayList();  // Menampilkan linked list sebelum dibalik

    // Memanggil fungsi untuk membalikkan linked list
    myList.reverseList();

    cout << "Linked List setelah dibalik: ";
    myList.displayList();  // Menampilkan linked list setelah dibalik

    cout <<endl;
    identitas();
    return 0;
}