#include <iostream>
#include <conio.h>

using namespace std;

const int MAX_SIZE = 3; //membuat maks data yang dapat diinput dalam satu menara yaitu 3
string towers[3][MAX_SIZE]; // Array 2D untuk menyimpan menara==

int topIndex[3] = {-1, -1, -1}; // Indeks puncak untuk setiap menara -1 menandakan bahwa awalnya tidak ada elemen yang ada di dalam setiap "menara"

// Fungsi untuk mengecek apakah sebuah menara kosong
bool isEmpty(int tower) {
    return topIndex[tower] == -1;
}

// Fungsi untuk mengecek apakah sebuah menara penuh
bool isFull(int tower) {
    return topIndex[tower] == MAX_SIZE - 1;
}

// Fungsi untuk memasukkan nilai ke menara
void push(int tower, const string& value) {
    if (isFull(tower)) { //pengkondisian apabila menara sudah penuh dengan 3 data
        cout << "===================\n";
        cout << "Menara " << char(tower + 65) << " sudah penuh\n";
        return;
    }
    //pengkondisian lain apabila data masih bisa di input ke dalam menara, dengan kata lain menara belum penuh
    towers[tower][++topIndex[tower]] = value; //fungsi untuk menambahkan nilai "value" ke dalam "menara" yang ditentukan oleh tower
    cout << "===========================================\n";
    cout << "Data '" << value << "' telah dimasukkan ke menara " << char(tower + 65) << endl;
}

// Fungsi untuk memindahkan nilai antara menara
void move(int source, int destination) {
    if (isEmpty(source)) { //pengkondisian apabila data di sumber menara kosong
        cout << "=====================\n";
        cout << "Menara " << char(source + 65) << " sudah kosong\n"; //maka akan mencetak keterangan ini
        return; 
    }
    else if (isFull(destination)) { //pengkondisian lain apabila menara yang dituju untuk perpindahan penuh
        cout << "====================\n";
        cout << "Menara " << char(destination + 65) << " sudah penuh\n"; //maka akan mencetak keterangan ini
        return;
    }
    towers[destination][++topIndex[destination]] = towers[source][topIndex[source]--]; //untuk memindahkan nilai dari "menara" sumber (source) ke "menara" tujuan (destination).
    cout << "\n==========================================\n";
    cout << "Data dipindahkan dari menara " << char(source + 65) << " ke menara " << char(destination + 65) << endl; //akan mencetak keterangan bahwa data berhasil di pindahkan
}

// Fungsi untuk menampilkan isi menara
void display() {
    cout << "\nThis is stuck of Hanoi Tower!\n";
    cout << "=============================\n";
    for (int i = 0; i < 3; ++i) { //perulangan untuk menampilkan 3 menara dan datanya
        cout << "Menara " << char(i + 65) << ": "; //akan menampilkan menara A, B dan C
        for (int j = topIndex[i]; j >= 0; --j) { //membuat perulangan lagi yang mana akan menampilkan data dalam tiap menara
            cout << towers[i][j] << " -> "; //membuat tanda panah untuk pemisah data
        }
        cout << "\n\n";
    }
}

int main() { //fungsi utama
    while (true) { //membuat perulangan
        cout << "\nStack of Hanoi Tower!\n"; 
        cout << "=====================\n";
        cout << "Pilihan Menu :\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "=====================\n";
        int choice;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;
        system("cls"); //membersihkan tampian terminal

        switch (choice) { //membuat pengkondisian dari pilihan yang sudah di input
            case 1: { //blok kode yang akan di eksekusi apabila user menginput 1, yaitu menu push
                string data;
                cout << "\nMasukkan data yang ingin dimasukkan ke menara A: ";
                cin >> data;
                push(0, data); //data akan masuk ke menara A
                cout << "\nTekan enter untuk kembali ke Menu...";
                getch();
                system("cls");
                break;
            }
            case 2: { //blok kode yang akan di eksekusi apabila user menginput 2, yaitu menu pop
                cout << "\n\t\tPilihan Menu Pop\n";
                cout << "===================================================\n";
                cout << "1. Pop data dari menara A dan pindahkan ke menara B\n";
                cout << "2. Pop data dari menara C dan pindahkan ke menara A\n";
                cout << "3. Pop data dari menara B dan pindahkan ke menara A\n";
                cout << "Masukkan pilihan anda : ";
                int pil;
                cin >> pil;
                switch(pil) { //membuat pengkondisian dari inputan user
                    case 1: //jika user menginputkan 1 maka, akan mengeksekusi blok kode ini
                        move(0, 1); //perpindahan data puncak dari menara A ke B
                        cout << "\nTekan enter untuk kembali ke Menu...";
                        getch();
                        system("cls");
                        break;
                    case 2: //jika user menginputkan 2 maka, akan mengeksekusi blok kode ini
                        move(2, 0); //perpindahan data puncak dari mwenara C ke A
                        cout << "\nTekan enter untuk kembali ke Menu...";
                        getch();
                        system("cls");
                        break;
                    case 3: //jika user menginputkan 3 maka, akan mengeksekusi blok kode ini
                        move(1, 0); //perpindahan data puncak dari menara B ke A
                        cout << "\nTekan enter untuk kembali ke Menu...";
                        getch();
                        system("cls");
                        break;
                    default: 
                        cout << "\nPilihan tidak valid. Silahkan pilih kembali\n"; //apabila user menginputkan yang bukan dari case di atas
                        system("cls");
                }
                break;
            }
            case 3: //blok yang akan di eksekusi apabila user menginputkan 3, yaitu menu display
                display(); //memanggil fungsi display yang akan menampilkan data di tiap menara
                cout << "\nTekan enter untuk kembali ke Menu...";
                getch();
                system("cls");
                break;
            case 4: //blok yang akan di eksekusi apabila user menginputkan 4, yaitu menu exit
                cout << "\nTerima kasih, sampai jumpa!\n";
                cout << "=============================";
                cout << "\nDibuat oleh :\n";
                cout << "Nama  : Afifah Fadilah\n";
                cout << "Npm   : 2310631170003\n";
                cout << "Kelas : 2C - Informatika\n";
                return 0; //menandakan program berhenti
            default: //blok yang akan di eksekusi apabila user menginputkan yang diluar dari case di atas
                cout << "\nPilihan tidak valid. Silakan pilih kembali.\n"; 
        }
    }
    return 0;
}