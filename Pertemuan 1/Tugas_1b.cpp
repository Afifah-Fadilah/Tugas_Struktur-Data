#include <iostream>
using namespace std;

void garis() //membuat fungsi garis untuk menghasilkan output garis batas
{
    for (int i = 0; i < 46; i++) { //membuat perulangan untuk menghasilkan panjang garis batas
        cout <<"="; //output dari fungsi garis
    }
}

void identitas() { //membuat fungsi identitas yang di dalam nya berupa nama dan npm saya
    garis(); //memanggil fungsi garis di dalam fungsi identitas
    cout << "\nProgram Ini di Buat Oleh :\n";
    cout << "Nama : Afifah Fadilah\n";
    cout << "NPM  : 2310631170003\n";
    garis(); //memanggil fungsi garis di dalam fungsi identitas
}

int main() { //fungsi utama

    const int maxChar = 26; // membuat konstanta jumlah maksimal huruf alfabet
    char huruf[maxChar] = {'\0'}; /* Mendeklarasikan array huruf yang akan digunakan untuk menyimpan jumlah 
    kemunculan setiap huruf,Inisialisasi array dengan karakter null ('\0') */
    
    garis();
    cout << "\n\tProgram Input Array Berupa Char\n"; //membuat judul dari program yang di buat
    garis();

    string input; //inisialisasi variabel input bertipe string
    cout << "\nMasukkan huruf-huruf (contoh a,a,b,c): \n"; //perintah untuk menginputkan huruf huruf dari a - z
    getline(cin, input); //input dari pengguna berupa huruf

    // Menghitung jumlah kemunculan setiap huruf dalam input
    for (char c : input) {  /*Mengiterasi setiap karakter dalam string input. dan memeriksa apakah huruf kecil atau huruf besar*/
        if ('a' <= c && c <= 'z') { //kondisi apabila huruf yang di inputkan huruf hecil (a - z) 
            huruf[c - 'a']++; //Menambahkan jumlah kemunculan huruf yang di input di array huruf yang sudah di input.
        } else if ('A' <= c && c <= 'Z') { //kondisi apabila huruf yang di inputkan huruf besar (A - Z)
            huruf[c - 'A']++; //Menambahkan jumlah kemunculan huruf yang di input di array huruf yang sudah di input.
        }
    }
    cout <<"\n\n";
    garis();
    cout << "\n\tHasil Program Setelah Terkompres\n"; 
    garis();
    cout << endl;

    cout <<"[";
    // Menampilkan output huruf jika lebih dari satu maka output huruf diikuti dengan banyaknya jumlah huruf yang sama)
    for (int i = 0; i < maxChar; i++) {
        if (huruf[i] > 0) { //pengkondisian apabila huruf yang di input lebih dari 0
            char karakter = 'a' + i; // Konversi kembali ke huruf alfabet
            cout << karakter << "," << static_cast<int>(huruf[i]) << ","; /* output berupa jumlah huruf sama
                                                                           yang dikonversi menjadi nilai integer */
        }
    }
    cout <<"]";

    cout <<"\n\n\n";
    identitas(); //memanggil fungsi identitas berupa nama dan npm

    return 0;
}