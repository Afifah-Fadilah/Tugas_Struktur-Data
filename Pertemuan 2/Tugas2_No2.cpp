#include <iostream>

using namespace std;

void garis(){ //membuat fungsi garis untuk membuat variasi 
    for (int i = 0; i < 55; i++){ 
    cout <<"="; //berupa tanda = yang di looping sebanyak 55 kali
    }
    cout <<endl;
}

void identitas(){ //membuat fungsi identitas yang berisikan nama, npm dan kelas
    cout << "Program Ini Di Buat Oleh :\n"; 
    cout << "Nama   : Afifah Fadilah\n";
    cout << "NPM    : 2310631170003\n";
    cout << "Kelas  : 2C - Informatika\n";

}

int main(){ //fungsi utama

    int matriksAwal[3][3]; //sebuah array matriks awal yang berisikan 3 baris dan 3 kolom yang berjenis integer
    int matriksHasil[3][3]; //sebuah array matriks akhir yang berisikan 3 baris dan 3 kolom yang berjenis integer

    garis(); //memanggil fungsi garis
    cout << "\tProgram Putar Array Matriks 90 Derajat\n"; //membuat judul program
    garis(); //memanggil fungsi garis
    cout << "Masukkan nilai matriks berukuran 3x3\n\n"; //perintah untuk memasukkan nilai matriks 3x3
    for (int i = 0; i < 3; i++){ //membuat perulangan untuk membuat urutan baris dari 1 hingga 3
        for (int j = 0; j < 3; j++){ //membuat perulangan untuk membuat urutan kolom dari 1 hingga 3
            cout << "Masukan nilai dari matriks [" << i <<"][" << j << "] : "; //memanggil looping di atas dari awal hingga akhir
            cin >> matriksAwal[i][j]; //inputan dari pengguna yang masuk ke dalam array Matriks awal
        }
        cout <<endl;
    }

    //membuat perulangan untuk merotasikan array sebesar 90 derajat searah jarum jam
    for (int i = 0; i < 3; i++){ 
        for (int j = 0; j < 3; j++){
            matriksHasil[i][j] = matriksAwal[2 - j][i]; //operasi untuk mentransformasikan nilai matriks agar berubah
        }
    }

    garis(); //memanggil fungsi garis
    cout << "\t\t      Matriks Awal\n"; //membuat judul untuk menampilkan matriks awal
    garis(); //memanggil fungsi garis

    //perulangan untuk memanggil semua nilai array yang sudah di inputkan
    for (int i = 0; i < 3; i++){ 
        cout << "\t\t\t ";
        for (int j = 0; j < 3; j++){
        cout << matriksAwal[i][j] << " "; //memanggil array dalam var matriks awal, yang berisikan nilai yang sudah di input
    }
    cout <<endl;
    }

    garis(); //memanggil fungsi garis
    cout << "\t\tMatriks Setelah Di Putar\n"; //membuat judul untuk menampilkan matriks akhir setelah di putar
    garis(); //memanggil fungsi garis

    //perulangan untuk memanggil semua nilai array yang sudah di transformasi ke bentuk akhir
    for (int i = 0; i < 3; i++){
        cout << "\t\t\t ";
        for (int j = 0; j < 3; j++){
        cout << matriksHasil[i][j] << " "; //memanggil array dalam var matriks hasil yang sudah di transformasi di atas
    }
    cout <<endl;
    }

    garis(); //memanggil fungsi garis
    identitas(); //memanggil fungsi identitas yang berisikan nama, npm, dan kelas
    garis(); //memanggil fungsi garis

    return 0; //menunjukkan akhir dari program, dan program keluar dengan normal

}