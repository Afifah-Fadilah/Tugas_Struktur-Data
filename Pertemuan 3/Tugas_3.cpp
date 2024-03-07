#include <iostream> 
#include <iomanip> //library untuk memanipulasi input output untuk membuat tampilan sejajar

using namespace std;

struct nilaiMhs { //membuat struct bernama nilaiMHs yang berisikan variabel mengenai nilai nilai mahasiswa
    int absen; //membuat variabel bernama absen yang berjenis integer, digunakan untuk menyimpan nilai absensi
    float tugas; //membuat variabel bernama tugas yang berjenis float, digunakan untuk menyimpan nilai tugas
    float uts; //membuat variabel bernama uts yang berjenis float, digunakan untuk menyimpan nilai uts
    float uas; //membuat variabel bernama uas yang berjenis float, digunakan untuk menyimpan nilai uas
    float nilaiAkhir; //membuat variabel bernama nilaiAkhir yang berjenis float, digunakan untuk menyimpan nilai akhir
    char indexHuruf; //membuat variabel bernama indexHuruf yang berjenis float, digunakan untuk menyimpan dan membuat indeks huruf
};

struct Mahasiswa { //membuat struct bernama Mahasiswa yang berisikan variabel mengenai identitas mahasiswa
    string nama; //membuat variabel bernama nama yang berjenis string, yang digunakan untuk menyimpan nama mahasiswa
    string npm; //membuat variabel bernama npm yang berjenis string, yang digunakan untuk menyimpan npm mahasiswa
    nilaiMhs nilai; //membuat variabel nilai dengan memanggil struck nilaiMhs
};

const int maxMhs = 20; //membuat konstanta maksimal jumlah mahasiswa yang bisa di tambahkan
Mahasiswa mhs[maxMhs]; //membuat variabel bernama mhs yang memanggil struck mahasiswa dan berisikan array mhs
int jumlah = 0; //membuat variabel bernama jumlah bernilai 0 berjenis integer yang akan digunakan untuk menyimpan jumlah mhs

char nilaiHuruf(float nilai); // Menambahkan prototipe fungsi, yang akan digunakan untuk menentukan index huruf mahasiswa


void identitas() { //membuat fungsi identitas yang berisikan nama, npm, dan kelas
    cout << "|==========================================================|\n";
    cout << "|\t\t  Program Ini Di Buat Oleh \t\t   |\n";
    cout << "|==========================================================|\n";
    cout << "| Nama    : Afifah Fadilah\t\t\t\t   |\n";
    cout << "| NPM     : 2310631170003\t\t\t\t   |\n";
    cout << "| Kelas   : 2C - Informatika\t\t\t\t   |\n";
    cout << "|==========================================================|\n";
}

void menu () { //membuat fungsi untuk menampilkan menu apa saja yang tersedia
    cout << "|==========================================================|\n";
    cout << "|\t\t\t   PROGRAM \t\t\t   |\n"; 
    cout << "|\t      Sistem Manajemen Data Mahasiswa \t\t   |\n";
    cout << "|==========================================================|\n";
    cout << "| 1. Tambah Data Mahasiswa\t\t\t\t   |\n"; //menu tambah mahasiswa ,dimana user dapat menambahkan data mahasiswa jika memilih menu ini
    cout << "| 2. Tampil Data Mahasiswa\t\t\t\t   |\n"; //menu tampilkan data mahasiswa,dimana pada menu ini user dapat melihat data yang tersimpan dalam sistem
    cout << "| 3. Edit Data Mahasiswa\t\t\t\t   |\n"; //menu untuk mencari data mahasiswa, untuk menampilkan data, harus menggunakan npm yang sudah di input sebelumnya
    cout << "| 4. Hapus Data Mahasiswa\t\t\t\t   |\n"; //menu untuk mengedit data mahasiswa,untuk mengedit data, harus menggunakan npm yang sudah di input
    cout << "| 5. Keluar\t\t\t\t\t\t   |\n"; //menu keluar dari program
    cout << "|==========================================================|\n";
}


void inputDataMhs() { //membuat fungsi bernama inputDataMhs yang fungsinya untuk menginputkan data data mahasiswa
    system("cls"); //memanggil perintah untuk men clear / membersihkan tampilan layar
    int tambahan;  // Variabel untuk menyimpan jumlah data tambahan
    cout << "Masukkan jumlah Mahasiswa yang ingin ditambahkan: "; //perintah untuk memasukkan jumlah data tambahan
    cin >> tambahan; //inputan dari pengguna yang nantinya masuk ke var tambahan

    if (jumlah + tambahan > maxMhs) { //membuat pengkondisian yang mana jika jumlah awal ditambah jumlah data baru lebih besar dari makMhs = 20, maka
        system("cls"); //membuat perintah untuk membersihkan layar tampilan
        cout << "Maaf, jumlah data yang ingin ditambahkan melebihi batas maksimal\n\n"; //maka akan mengeluarkan output ini
        cout << "Anda hanya boleh menginputkan data hingga "<< maxMhs << "\n\n"; //membuat kata penegasan kepada user untuk menginputkan data sesuai maksimal
    } else { //pengkondisian lain apabila kondisi di atas tidak memenuhi
        for (int i = jumlah; i < jumlah + tambahan; i++) { //membuat perulangan sebanyak jumlah tambahan yang sudah diinputkan sebelumnya
            cout << "\nMasukkan Data Mahasiswa Ke- " << i + 1 << endl; //membuat kata penegasan di urutan berapa data mahasiswa
            cout << "NPM Mahasiswa        : "; //membuat perintah untuk memasukkan npm mahasiswa
            cin >> mhs[i].npm; //inputan dari user berupa npm yang nantinya akan di simpan di array npm melalui struct mhs
            cout << "Nama Mahasiswa       : "; //membuat perintah untuk memasukkan nama mahasiswa
            cin >> mhs[i].nama; //inputan dari user berupa nama yang nantinya akan di simpan di array nama melalui struct mhs
            cout << "Nilai Mahasiswa     \n";
            cout << "    Nilai Absensi    : "; //membuat perintah untuk memasukkan nilai absen mahasiswa
            cin >> mhs[i].nilai.absen; //inputan dari user berupa nilai absen yang nantinya akan di simpan di array nilai absen melalui struct mhs
            cout << "    Nilai Tugas      : "; //membuat perintah untuk memasukkan nilai tugas mahasiswa
            cin >> mhs[i].nilai.tugas; //inputan dari user berupa nilai tugas yang nantinya akan di simpan di array nilai tugas melalui struct mhs
            cout << "    Nilai UTS        : "; //membuat perintah untuk memasukkan nilai uts mahasiswa
            cin >> mhs[i].nilai.uts; //inputan dari user berupa nilai uts yang nantinya akan di simpan di array nilai uts melalui struct mhs
            cout << "    Nilai UAS        : "; //membuat perintah untuk memasukkan nilai uas mahasiswa
            cin >> mhs[i].nilai.uas; //inputan dari user berupa nilai uas yang nantinya akan di simpan di array nilai uas melalui struct mhs

            // Membuat perhitungan nilaiAkhir
            mhs[i].nilai.nilaiAkhir = (0.1 * mhs[i].nilai.absen) + (0.2 * mhs[i].nilai.tugas) + (0.3 * mhs[i].nilai.uts) + (0.4 * mhs[i].nilai.uas);

            // Menambahkan pemanggilan nilaiHuruf
            mhs[i].nilai.indexHuruf = nilaiHuruf(mhs[i].nilai.nilaiAkhir);
        }
        jumlah += tambahan;  // Update jumlah total data mahasiswa
        system("cls"); //mengclear / membersihkan tampilan layar
        cout << "\nTerima Kasih, Data Anda Telah di Input\n\n"; //membuat penegasan bahwa data berhasil di simpan
    }
}


// Menambahkan implementasi fungsi nilaiHuruf
char nilaiHuruf(float nilai) { //membuat dan memanggil nilai huruf yang sesuai dengan nilaiakhir
    if (nilai > 80) { //membuat pengkondisian jika nilai lebih besar dari 80 maka
        return 'A'; //maka ia akan mengeluarkan output indexHuruf A
    } else if (nilai > 70 && nilai <= 80) { //pengkondisian jika nilai lebih besar dari 70 dan nilai lebih kecil sama dengan 80
        return 'B'; //maka ia akan mengeluarkan otput indexHuruf B
    } else if (nilai > 60 && nilai <= 70) { //pengkondisian jika nilai lebih besar dari 60 dan nilai lebih kecil sama dengan 70
        return 'C'; //maka ia akan mengeluarkan otput indexHuruf C
    } else { //pengkondisian lain apabila 3 kondisi di atas tidak memenuhi
        return 'D'; //maka ia akan mengeluarkan otput indexHuruf D
    }
}

void tampilDataMhs() { //membuat fungsi bernama tampil data mahasiswa yang fungsinya akan menampilkan seluruh data mhs yang sudah diinput
    system("cls"); //memanggil perintah untuk mengclear tampilan output
    cout << "======================================================================================\n";
    cout << "|        |          |                               Nilai                            |\n";
    cout << "|  NPM   |   Nama   |================================================================|\n";
    cout << "|        |          |  Absensi    Tugas    UTS     UAS    Nilai Akhir   Index Huruf  |\n";
    cout << "======================================================================================\n";
    for (int i = 0; i < jumlah; i++) { //membuat perulangan sejumlah sebanyak jumlah yang sudah diinput
    cout << "  " << left << setw(9) << mhs[i].npm; //memanggil array npm di dalam struct mhs dari inputan awal hingga akhir 
    cout << left << setw(9) << mhs[i].nama; //memanggil array nama di dalam struct mhs dari inputan awal hingga akhir 
    cout << right << setw(8) << mhs[i].nilai.absen; //memanggil array nilai absen di dalam struct mhs dari inputan awal hingga akhir 
    cout << right << setw(10) << mhs[i].nilai.tugas; //memanggil array nilai tugas di dalam struct mhs dari inputan awal hingga akhir 
    cout << right << setw(8) << mhs[i].nilai.uts; //memanggil array nilai uts di dalam struct mhs dari inputan awal hingga akhir 
    cout << right << setw(8) << mhs[i].nilai.uas; //memanggil array nilai uas di dalam struct mhs dari inputan awal hingga akhir 
    cout << right << setw(13) << fixed << setprecision(1) << mhs[i].nilai.nilaiAkhir; //memanggil array nilai akhir di dalam struct mhs dari hasil data awal - akhir 
    cout << right << setw(12) << mhs[i].nilai.indexHuruf << endl; //memanggil array indexHuruf, mengeluarkan indexHuruf dari data awal hingga akhir
    }
    cout << "======================================================================================\n";
    cout <<endl;
}


void editDataMhs() { //membuat fungsi edit data mahasiswa, yang berfungsi untuk mengedit data mahasiswa dengan memasukkan npm mhs yang datanya ingin di edit
    system("cls"); //mengclear hasil tampilan output sebelumnya
    string editData; //membuat var bernama edit data yang bertipe string
    awal: //digunakan untuk mengalihkan eksekusi program ke bagian sini (awal)
    cout << "|==========================================================|\n";
    cout << "\t\tMenu Edit Data Mahasiswa\n";
    cout << "|==========================================================|\n";

    cout << "Masukkan npm mahasiswa yang ingin di ubah : "; //membuat perintah untuk memasukkan npm mahasiswa yang ingin di ubah data nya
    cin >> editData; //input dari user yang akan masuk ke var editData

    bool ada = false; //membuat inisialisasi var bernama ada bernilai false yang artinya data belum di temukan
    for(int i = 0; i < jumlah; i++){ //membuat perulangan sejumlah banyak nya jumlah yang sudah di input, Tujuannya untuk mencari data mahasiswa dalam suatu array
        if (mhs[i].npm == editData) { //pengkondisian yang terjadi apabila npm yang dimasukkan sama dengan nilai npm yang ada dalam array npm
            cout << "\nMahasiswa ditemukan\n\n"; //maka akan mengeluarkan output data mahasiswa saat ini sebelum di edit
            cout << "NPM Mahasiswa        : " << mhs[i].npm <<endl; //memanggil npm yang ada dalam array sesuai dengan npm yang sudah di input
            cout << "Nama Mahasiswa       : " << mhs[i].nama <<endl; //memanggil nama yang ada dalam array sesuai dengan npm yang sudah di input
            cout << "Nilai Mahasiswa       \n";
            cout << "    Nilai Absensi    : " << mhs[i].nilai.absen <<endl; //memanggil nilai absensi yang ada dalam array sesuai dengan npm yang sudah di input
            cout << "    Nilai Tugas      : " << mhs[i].nilai.tugas <<endl; //memanggil nilai tugas yang ada dalam array sesuai dengan npm yang sudah di input
            cout << "    Nilai UTS        : " << mhs[i].nilai.uts <<endl; //memanggil nilai uts yang ada dalam array sesuai dengan npm yang sudah di input
            cout << "    Nilai UAS        : " << mhs[i].nilai.uas <<endl; //memanggil nilai uas yang ada dalam array sesuai dengan npm yang sudah di input
            
            do{ //menggunakan perulangan do-while agar statement dijalankan sekali lalu akan dijalankan lagi ketika kondisi di while terpenuhi
            cout << "\nData mana yang ingin anda ubah ? ";
            char dataMhs; //membuat var bernama data mhs bertipe char, untuk memilih data yang akan di edit
            cout << "\nA. NPM\n";
            cout << "B. Nama\n";
            cout << "C. Nilai Absensi\n";
            cout << "D. Nilai Tugas\n";
            cout << "E. Nilai UTS\n";
            cout << "F. Nilai UAS\n";
            cout << "G. Semua Data\n";
            cout << "H. Batal Edit Data\n";
            cout << "\nMasukkan Pilihan Anda (A/B/C/D/E/F/G/H) : "; //pertanyaan untuk memilih data mana yang akan di edit
            cin >> dataMhs; //user menginputkan pilihan dari A-H, yang masuk ke var dataMhs
            cout <<endl;
            if (dataMhs == 'A' || dataMhs == 'a'){ //membuat pengkondisian jika user menginputkan A atau a maka,
                cout << "NPM Sebelumnya  : " << mhs[i].npm <<endl; //pertama akan di tampilkan terlebih dahulu npm sebelumnya
                cout << "NPM Mahasiswa   : "; //perintah memasukkan npm baru
                cin >> mhs[i].npm; //inputan user yang masuk ke array npm di dalam struct mhs
                ada = true; //menandai bahwa perubahan pada NPM mahasiswa telah dilakukan.
            }else if (dataMhs == 'B' || dataMhs == 'b'){ //membuat pengkondisian jika user menginputkan B atau b maka,
                cout << "Nama Sebelumnya  : " << mhs[i].nama <<endl; //pertama akan di tampilkan terlebih dahulu nama sebelumnya
                cout << "Nama Mahasiswa : "; //perintah memasukkan nama baru
                cin >> mhs[i].nama; //inputan user yang masuk ke array nama di dalam struct mhs
                ada = true; //menandai bahwa perubahan pada nama mahasiswa telah dilakukan.
            }else if (dataMhs == 'C' || dataMhs == 'c'){ //membuat pengkondisian jika user menginputkan C atau c maka,
                cout << "Nilai Absensi Sebelumnya  : " << mhs[i].nilai.absen <<endl; //akan di tampilkan terlebih dahulu nilai absen sebelumnya
                cout << "Nilai Absensi Mahasiswa   : ";
                cin >> mhs[i].nilai.absen; //inputan user yang masuk ke array nilai absen di dalam struct mhs
                ada = true; //menandai bahwa perubahan pada Nilai absen mahasiswa telah dilakukan.
            }else if (dataMhs == 'D' || dataMhs == 'd'){ //membuat pengkondisian jika user menginputkan D atau d maka,
                cout << "Nilai Tugas Sebelumnya  : " << mhs[i].nilai.tugas <<endl; //akan di tampilkan terlebih dahulu nilai tugas sebelumnya
                cout << "Nilai Tugas Mahasiswa   : ";
                cin >> mhs[i].nilai.tugas; //inputan user yang masuk ke array nilai tugas di dalam struct mhs
                ada = true; //menandai bahwa perubahan pada Nilai tugas mahasiswa telah dilakukan.
            }else if (dataMhs == 'E' || dataMhs == 'e'){ //membuat pengkondisian jika user menginputkan E atau e maka,
                cout << "Nilai UTS Sebelumnya  : " << mhs[i].nilai.uts <<endl; //akan di tampilkan terlebih dahulu nilai uts sebelumnya
                cout << "Nilai UTS Mahasiswa : ";
                cin >> mhs[i].nilai.uts; //inputan user yang masuk ke array nilai uts di dalam struct mhs
                ada = true; //menandai bahwa perubahan pada Nilai uts mahasiswa telah dilakukan.
            }else if (dataMhs == 'F' || dataMhs == 'f'){ //membuat pengkondisian jika user menginputkan F atau f maka,
                cout << "Nilai UAS Sebelumnya  : " << mhs[i].nilai.uas <<endl; //akan di tampilkan terlebih dahulu nilai uas sebelumnya
                cout << "Nilai UAS Mahasiswa : ";
                cin >> mhs[i].nilai.uas; //inputan user yang masuk ke array nilai uas di dalam struct mhs
                ada = true; //menandai bahwa perubahan pada Nilai uas mahasiswa telah dilakukan.
            }else if (dataMhs == 'G' || dataMhs == 'g'){ //pengkondisian jika user menginputkan G atau g maka, semua data sebelumnya akan di ganti ke data baru
                cout << "NPM Mahasiswa : ";
                cin >> mhs[i].npm; //inputan user berupa npm yang baru
                cout << "Nama Mahasiswa : ";
                cin >> mhs[i].nama; //inputan user berupa nama yang baru
                cout << "Nilai Absensi Mahasiswa : ";
                cin >> mhs[i].nilai.absen; //inputan user berupa nilai absen yang baru
                cout << "Nilai Tugas Mahasiswa : ";
                cin >> mhs[i].nilai.tugas; //inputan user berupa nillai tugas yang baru
                cout << "Nilai UTS Mahasiswa : ";
                cin >> mhs[i].nilai.uts; //inputan user berupa niai uts yang baru
                cout << "Nilai UAS Mahasiswa : ";
                cin >> mhs[i].nilai.uas; //inputan user berupa nilai uas yang baru
                ada = true; //menandai bahwa perubahan pada semua data mahasiswa telah dilakukan.
            }else if (dataMhs == 'H' || dataMhs == 'h'){ //pengkondisian jika user menginputkan H atau h maka,
                goto awal; //program akan kembali ke bagian awal menggunakan goto
            }else{ //pengkondisian jika pilihan tidak valid, maka akan meng cout kata di bawah dan kembali meminta user untuk menginputkan char yang sesuai
                system("cls"); //perintah untuk menclear tampilan output sebelumnya
                cout << "\nMasukkan pilihan yang benar.\n";
                }
                system("cls"); //perintah untuk menclear tampilan output sebelumnya
                cout << "Data Berhasil Di Edit\n\n";        
            }while (!ada); //program dalam do while akan terus dijalankan selagi kondisi !ada
        }
        system("cls"); //perintah untuk menclear tampilan output sebelumnya
    }if (!ada) { //pengkondisian dimana jika mahasiswa dengan NPM yang ingin diedit tidak ada dalam sistem
        cout << "\nMahasiswa dengan NPM " << editData << " tidak ditemukan.\n";//statement yang akan dijalankan jika npm tidak ada
    cout << "\n";
    }
}

void hapusDataMhs() { //membuat fungsi hapus data mhs yang berfungsi untuk menghapus data mahasiswa menggunakan npm
    system("cls"); //perintah menclear taampilan output
    string hapusData; //membuat var bernama hapusData bertipe string
    cout << "Masukkan NPM Data Mahasiswa Yang Ingin di Hapus : ";
    cin >> hapusData; //input dari user berupa npm yang akan di hapus data nya

    bool ditemukan = false; //membuat inisialisasi var bernama ditemukan bernilai false yang artinya data belum di temukan
    for (int i = 0; i < jumlah; i++) { //membuat perulangan sejumlah banyak nya jumlah yang sudah di input, Tujuannya untuk mencari data mahasiswa dalam suatu array
        if (mhs[i].npm == hapusData) { //pengkondisian apabila npm yang tadi di inputkan sama dengan npm yang ada dalam array, maka
            //geser data ke belakang untuk menutup data yang di hapus
            for (int j = i; j < jumlah - 1; j++ ) { //dibuat perulangan yang mana fungsi nya untuk menghapus data mahasiswa
            mhs[j] = mhs[j + 1];
            }
            system("cls"); //perintah untuk menclear tampilan output 
            ditemukan = true; //menandai bahwa penghapus data mahasiswa telah berhasil dilakukan.
            jumlah--; //kurangi jumlah mahasiswa setelah penghapusan
            cout << "\nData Dengan NPM " <<hapusData<< " Berhasil Di Hapus\n\n";
            break;
        }
    }if(!ditemukan) { //pengkondisian yang terjadi jika data dengan npm yang diinputkan tidak ada dalam sistem
        cout << "\nMahasiswa dengan NPM " << hapusData << "Tidak Ditemukan\n";
    }
}

int main() {

        int pilih; //membuat var bernama pilih, ber jenis integer
        while(true) { //membuat perulangan menggunakan while berkondisi true, yang mana program akan terus berjalan hingga program dihentikan manual
        menu(); //memanggil fungsi menu
        cout << "Masukkan Pilihan Menu (1/2/3/4/5):";//perintah untuk menginputkan pilihan 1 hingga 5
        cin >> pilih; //input berupa variabel menu
        cout <<"\n";

        switch (pilih){ //membuat pengkondisian switch case untuk mengeksekusi tindakan sesuai pilihan user, jika
        case 1: //jika user menginputkan 1 maka program akan mengeksekusi fungsi inputDataMhs
            inputDataMhs(); //memanggil fungsi inputDataMhs yang sudah di buat di atas
            break; //digunakan untuk menghentikan eksekusi dan keluar dari blok switch sehingga program tidak akan melanjutkan ke case berikutnya
        case 2: //jika user menginputkan 2 maka program akan mengeksekusi fungsi tampilDataMhs
            tampilDataMhs(); //memanggil fungsi tampilDataMhs yang sudah di buat di atas
            break; //digunakan untuk menghentikan eksekusi dan keluar dari blok switch sehingga program tidak akan melanjutkan ke case berikutnya
        case 3: //jika user menginputkan 3 maka program akan mengeksekusi fungsi editDataMhs
            editDataMhs(); //memanggil fungsi editDataMhs yang sudah di buat di atas
            break; //digunakan untuk menghentikan eksekusi dan keluar dari blok switch sehingga program tidak akan melanjutkan ke case berikutnya
        case 4:  //jika user menginputkan 4 maka program akan mengeksekusi fungsi hapusDataMhs
            hapusDataMhs(); //memanggil fungsi hapusDataMhs yang sudah di buat di atas
            break; //digunakan untuk menghentikan eksekusi dan keluar dari blok switch sehingga program tidak akan melanjutkan ke case berikutnya
        case 5: //jika user menginputkan 5 maka program akan mengeluarkan output
            cout << "Apakah Anda Yakin Ingin Keluar Dari Program (y/n) : "; //statement apakah user yakin ingin keluar dari program
            char keluar; //membuat var bernama keluar bertipe char 
            cin >> keluar; //input dari user yang masuk ke var keluar
            system("cls"); //perintah untuk menclear tampilan output
            if (keluar == 'N' || keluar == 'n'){ //jika user menginput N/n maka anda akan tetap di dalam program dan akan kembali ke menu
                cout << "\nAnda Memilih Untuk Tetap di Dalam Program\n\n";
            }else{ //pengkondisian lain apabila kondisi di atas tidak memenuhi, maka program akan di hentikan
                system("cls"); //perintah untuk menclear tampilan output
                cout << "\nTerima Kasih Telah Menggunakan Program\n\n"; 
                identitas(); //memanggil fungsi identitas yang di dalamnya berupa nama npm dan kelas
                return 0; //sebuah statement bahwa program telah berhasil di eksekusi hingga akhir
                cout <<endl;
            }
            break; //digunakan untuk menghentikan eksekusi dan keluar dari blok switch sehingga program tidak akan melanjutkan ke case berikutnya
        default: //apabila input yang anda ketik tidak ada dalam pengkondisian case maka program akan kembali ke menu
        system("cls");
            cout << "Pilihan Tidak Valid, Silahkan Pilih Kembali\n";
            break; //digunakan untuk menghentikan eksekusi dan keluar dari blok 
        }
        }
    return 0; //sebuah statement bahwa program telah berhasil di eksekusi hingga akhir
}