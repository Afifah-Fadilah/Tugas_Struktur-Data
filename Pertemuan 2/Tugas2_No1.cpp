#include <iostream>
#include <iomanip> //library untuk membuat baris sejajar dari tanggal, dan nama barang yang diinput

using namespace std;

const int min_tgl = 5; //membuat konstanta minimal untuk banyaknya hari
const int max_barang = 10; //membuat konstanta maksimal dari barang yang akan di input

void garis() { //membuat fungsi garis yang berguna untuk membuat batasan dan variasi program
    for (int i = 0; i < 60; i++) {
        cout << "="; //fungsi berupa garis = sebanyak 60 kali
    }
    cout << endl;
}

void identitas() { //membuat fungsi identitas yang berisikan nama npm dan kelas
    cout << "Program ini dibuat oleh:\n";
    cout << "Nama   : Afifah Fadilah\n";
    cout << "NPM    : 2310631170003\n";
    cout << "Kelas  : 2C - Informatika\n";
}


struct dataBarang { //membuat struk yang bernama dataBarang yang didalam nya ada nama dan jumlah
    string nama;
    int jumlah;
};


int main() { //fungsi utama
    int jumlah_barang; //membuat variabel bernama jumlah_barang yang berjenis integer
    int jumlah_tgl; //membuat variabel bernama jumlah_tgl yang berjenis integer
    char ulangi; //membuat variabel bernama ulangi yang berjenis character

    cout << "Masukkan jumlah barang yang akan diinput: "; //perintah untuk menginputkan jumlah barang
    cin >> jumlah_barang; //berupa input dari pengguna mengenai jumlah barang
    if (jumlah_barang > max_barang) { //pengkondisian yang akan terjadi apabila jumlah barang melebihi batas maksimal
        cout << "Maaf, jumlah barang yang diinputkan minimal " << max_barang << endl;
        return 0; //maka program akan berhenti
    }

    cout << "Masukkan tanggal terakhir: "; //perintah untuk menginputkan tanggal terakhir dalam input data barang
    cin >> jumlah_tgl; //berupa input dari pengguna mengenai tanggal terakhir input
    if (jumlah_tgl < min_tgl) { //pengkondisian yang akan terjadi apabila jumlah tanggal kurang dari batas minimal
        cout << "Maaf, jumlah hari yang diinputkan minimal " << min_tgl << endl;
        return 0; //maka program akan berhenti
    }

        // Menyimpan data barang ke dalam array
        dataBarang barang[max_barang];

        // Matriks untuk menyimpan jumlah barang untuk setiap tanggal dan setiap barang
        int jumlahBarangPerTanggal[max_barang][max_barang] = {0};

        for (int i = 0; i < jumlah_barang; i++) { //membuat perulangan perintah untuk menginputkan nama barang
            cout << "Masukkan nama barang ke-" << i + 1 << ": "; //membuat perulangan dengan menambahkan 1 di tiap loopingnya
            cin >> barang[i].nama; //sebuah input dari pengguna yang memanggil struk nama dan akan disimpan di sana
        }

        for (int i = 0; i < jumlah_tgl; i++) { //membuat perulangan yang fungsi nya untuk melooping sebanyak jumlah hari input
            cout << "\nTanggal ke-" << i + 1 << endl; //perulangan beroutput tanggal yang di tambah 1 tiap looping nya
            for (int j = 0; j < jumlah_barang; j++) { //membuat perulangan untuk perintah menginputkan jumlah barang di tiap hari nya
                cout << "Masukkan jumlah " << barang[j].nama << ": "; //perintah untuk menginputkan jumlah barang dengan memanggil struk nama 
                cin >> jumlahBarangPerTanggal[i][j]; //sebuah input dari pengguna, dan di simpan di dalam variabel jumlah barang di tiap tanggal dan barangnya
            }
        }

        garis(); //memanggil fungsi garis
        cout << "\t\tProgram Input Data Barang\n"; //membuat judul program
        garis(); //memanggil fungsi garis

        // Header Tabel menggunakan library iomanip
        cout << setw(8) << "Tanggal"; //membuat panjang tabel dari tanggal
        for (int i = 0; i < jumlah_barang; i++) { //perulangan yang memanggil nama nama barang yang sudah di input hingga akhir
            cout << setw(10) << barang[i].nama; //membuat panjang tabel untuk nama barang
        }
        cout << endl;
        garis(); //memanggil fungsi garis

        // Data Tabel berisikan jumlah barang per barang dan per tanggal nya
        for (int i = 0; i < jumlah_tgl; i++) { //membuat perulangan untuk memanggil tanggal
            cout << setw(8) << i + 1; //mengulang sebuah tanggal dari 1 hingga akhir
            for (int j = 0; j < jumlah_barang; j++) { //membuat perulangan yang memanggil jumlah di tiap barang
                cout << setw(10) << jumlahBarangPerTanggal[i][j]; //dengan memanggil var jumlah barang pertanggal melooping dari awal hingga akhir
            }
            cout << endl;
        }

    do { //membuat perulangan yang terus mengulang selama kondisi memenuhi
        garis(); //memanggil fungsi garis

        // Mencari detail barang
        int kodeCariBarang; //membuat variabel untuk mencari barang menggunakan kode barang berjenis integer
        int cariTanggalBarang; //membuat variabel untuk mencari barang di tanggal tertentu yang berjenis integer

        cout << "Masukkan tanggal dan kode barang untuk mencari detail barang" << endl; //senuah perintah untuk menginputkan tanggal dan kode barang
        cout << "Masukkan tanggal     : "; //perintah memasukkan tanggal
        cin >> cariTanggalBarang; //input dari pengguna berupa tanggal yang ingin di cari
        cout << "Masukkan kode barang : "; //perintah memasukkan kode barang
        cin >> kodeCariBarang; //input dari pengguna berupa kode barang yang ingin di cari dimulai dari 0

        garis(); //memanggil fungsi garis

        //membuat sebuah pengkondisian yang mana jika kita menginputkan dengan benar, maka tanggal, nama, jumlah dan alamat barang dapat ditemukan.
        if (kodeCariBarang >= 0 && kodeCariBarang < jumlah_barang && cariTanggalBarang >= 1 && cariTanggalBarang <= jumlah_tgl) {
            cout << "Detail Barang";
            cout << "\nData Tanggal  : " << cariTanggalBarang; //memanggil var yang berisikan tanggal tertentu yang di cari
            cout << "\nNama Barang   : " << barang[kodeCariBarang].nama; //memanggil nama barang yang di cari
            cout << "\nJumlah Barang : " << jumlahBarangPerTanggal[cariTanggalBarang - 1][kodeCariBarang]; //memanggil jumlah barang di tanggal dan barang yang di cari
            cout << "\nAlamat Barang : " << &barang[kodeCariBarang].nama; //memanggil alamat barang
            cout << "\n";
            garis(); //memanggil fungsi garis
        } else { //sebuah pengkondisian apabila kondisi pertama tidak memenuhi syarat
            cout << "Maaf, Detail barang tidak ditemukan.\n"; //akan mengeluarkan output ini
        }

        // Pilihan untuk mengulangi program
        cout << "Ingin mencari data barang lagi? (Y/N): "; //sebuah pilihan apakah ingin melanjutkan atau keluar program
        cin >> ulangi; //input dari pengguna

    } while (ulangi == 'Y' || ulangi == 'y'); //jika menginputkan y maka program akan kembali ke atas, untuk mencari barang lagi

    garis(); //memanggil fungsi garis
    cout << "Terima kasih telah menggunakan program.\n"; //sebuah output ucapan terima kasih

    garis(); //memanggil fungsi garis
    identitas(); //memanggil fungsi identitas yang berisikan nama npm dan kelas
    garis(); //memanggil fungsi nama

    return 0; //menunjukkan program berhasil dan keluar dengan normal
}