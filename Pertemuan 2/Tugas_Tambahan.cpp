#include <iostream>

using namespace std;

void garis(){ //membuat fungsi garis menggunakan looping for
    for(int i = 0; i < 55; i++){
    cout << "=";
    }
}

void identitas() {
    garis();
    cout << "\nProgram Ini Dibuat Oleh :\n";
    cout << "Nama  : Afifah Fadilah\n";
    cout << "Kelas : 2C Informatika\n";
    garis();
}

int main() { //fungsi utama

    int rowM1, colM1, rowM2, colM2; //membuat variabel variabel
 
    garis(); //memanggil fungsi garis
    cout << "\n|\t\tProgram Perkalian Matriks\t      |\n"; //judul projek
    garis(); //memanggil fungsi garis
    
    cout << "\nMatriks A" <<endl;
    cout << "Masukkan jumlah baris matriks A : "; //perintah untuk menginputkan jumlah baris matriks A
    cin >> rowM1; //input pengguna pada variabel baris matriks pertama (rowM1)
    cout << "Masukkan jumlah kolom matriks A : "; //perintah untuk menginputkan jumlah kolom matriks A
    cin >> colM1; //input pengguna pada variabel baris matriks pertama (colM1)
    cout << "\nMatriks B" <<endl;
    cout << "Masukkan jumlah baris matriks B : "; //perintah untuk menginputkan jumlah baris matriks B
    cin >> rowM2; //input pengguna pada variabel baris matriks kedua (rowM2)
    cout << "Masukkan jumlah kolom matriks B : "; //perintah untuk menginputkan jumlah kolom matriks B
    cin >> colM2; //input pengguna pada variabel baris matriks kedua (rowM2)
    cout << endl;

    int M1[rowM1][colM1], M2[rowM2][colM2], M3[rowM1][colM2]; /*sebuah variabel array yang memanggil nilai variabel yang sudah diinputkan di atas*/

    if (colM1 != rowM2) { //pengkondisian apabila kolom matriks pertama jumlahnya tidak sama dengan jumlah baris matriks kedua
        cout << "Maaf, Operasi tidak dapat dilakukan"; //output yang akan keluar
    } else { //pengkondisian yang terjadi apabila tidak memenuhi pengkondisian di if

        //menginputkan nilai nilai pada matriks pertama (A)
        for (int i = 0; i < rowM1; i++) { //membuat perulangan yang mana jumlahnya mengambil dari jumlah baris matriks pertama yang di inputkan tadi
            for (int j = 0; j < colM1; j++) { //dibuat perulangan lagi yang melooping sebanyak jumlah kolom matriks pertama yang sudah di inputkan
                cout << "Masukkan nilai matriks pertama [ " << i << " ] [ " << j << " ] : "; //perintah untuk menginputkan nilai sejumlah variabel i dan j
                cin >> M1[i][j]; //perintah untuk memasukkan nilai
            }
        }
        cout << endl;
        //menginputkan nilai nilai pada matriks kedua (B)
        for (int i = 0; i < rowM2; i++) { //membuat perulangan yang mana jumlahnya mengambil dari jumlah baris matriks kedua yang di inputkan tadi
            for (int j = 0; j < colM2; j++) { //dibuat perulangan lagi yang melooping sebanyak jumlah kolom matriks kedua yang sudah di inputkan
                cout << "Masukkan nilai matriks kedua [ " << i << " ] [ " << j << " ] : "; //perintah untuk menginputkan nilai sejumlah variabel i dan j
                cin >> M2[i][j]; //perintah untuk memasukkan nilai
            }
        }
        cout << endl;

        //membuat perulangan agar hasil perkalian matriks sesuai dengan operasi matriks di dunia nyata
        for (int i = 0; i < rowM1; i++) {
            for (int j = 0; j < colM2; j++) {
                int sum = 0;  // Inisialisasi sum di sini (sum artinya jumlah)
                for (int k = 0; k < rowM2; k++) {
                    sum = sum + M1[i][k] * M2[k][j]; //membuat kondisi yang mana jumlah sum adalah sum + M1 " M2"
                }
                M3[i][j] = sum;  // Setel M3[i][j] ke hasil perkalian yaitu sum
            }
        }

        //memanggil output dari matriks pertama (A) yang sudah di input kan
        cout << "Matriks A\n";
        for (int i = 0; i < rowM1; i++) {
            for (int j = 0; j < colM1; j++) {
                cout << M1[i][j] << " ";
            }
            cout << endl;
        }
        
        //memanggil output dari matriks (B) yang sudah di inputkan 
        cout << "\nMatriks B\n";
        for (int i = 0; i < rowM2; i++) {
            for (int j = 0; j < colM2; j++) {
                cout << M2[i][j] << " ";
            }
            cout << endl;
        }
        
        //output berupa hasil dari perkalian matriks A dan B
        cout << "\nHasil Operasi Perkalian matriks : "<<endl;
        for (int i = 0; i < rowM1; i++) {
            for (int j = 0; j < colM2; j++) {
                cout << M3[i][j] << " "; //memanggil M3 yang berisikan hasil dari perkalian matriks A dan matriks B
            }
            cout << endl;
        }
    }
    cout << endl;
    identitas();

    return 0;
}