#include <iostream> //libarary utama c++
#include <iomanip> //memanggil library untuk memanipulasi tampilan output agar sejajar dan rapi
#include <ctime> //memanggil library untuk  membuat output waktu saat ini, meliputi hari,jam,dan tanggal secara detail

using namespace std;

struct jenisBarang { //membuat struct yang bernama jenisBarang
    string makanan;
    string minuman;
};

struct detailPesanan { //membuat struct yang bernama detail barang
    string tanggalBeli;        
    string namaPembeli;
    string kasir;
    int Harga;
    int pilih;
    int jumlah;
    jenisBarang NamaBarang; //terdapat var bernama Nama barang yang mana memanggil struk jenisBarang dalam penggunaan nya
};

const int maxPesan = 50; //membuat konstanta maksimal jumlah pesanan yang dapat di pesan
detailPesanan detail[maxPesan]; //membuat var bernama detail yang memanggil struck detailPesanan dan berisikan array mhs

const float ppn = 0.10; // Menggunakan float untuk membuat persentase PPN / pajak
const float diskon = 0.20; //menggunakan float untuk membuat persentase diskon untuk mengurangi jumlah harga 

int jumlah = 0;
float totalUang, total_bayar, kembali, diskonHarga, setDiskon;
float total_harga = 0;
float total_ppn = 0;
bool pembayaranSelesai = false; //membuat pengkondisian berupa bool yang nanti nya digunakan

void identitas() { //membuat fungsi identitas pembuat program
    cout << "\n================================================\n";
    cout << "Program Ini Dibuat Oleh : \n";
    cout << "================================================\n";
    cout << "Nama   : Afifah Fadilah \n";
    cout << "NPM    : 2310631170003\n";
    cout << "Kelas  : 2C - Informatika \n";
    cout << "================================================\n";
}

void menu() { // membuat fungsi menu yang berisikan menu menu program
    cout << "\n===================== Menu =====================\n";
    cout << "1. Food / Makanan\n";
    cout << "2. Drink / Minuman\n";
    cout << "3. Lihat Pesanan\n";
    cout << "4. Batalkan Pesanan\n";
    cout << "5. Bayar \n";
    cout << "6. Cetak Struk\n";
    cout << "7. Keluar\n";
    cout << "================================================\n";
    cout << "   Promo! pembelian diatas 500,000 diskon 20%\n"; //membuat pengumaman bahwa adanya diskon jika pembelian di atas 500k
    cout << "================================================\n";
}

void makanan() { //membuat fungsi makanan yang mana berisikan menu makanan yang dapat di pesan
    system("cls"); //digunakan untuk membersihkan tampilan output
    for (int i = jumlah; i < maxPesan; i++) { //membuat perulangan yang mana akan melooping sebanyak pesanan yang sudah di beli
        cout << "\n================== Food Menu ===================\n";
        cout << "1. Chicken                            Rp. 25,000\n";
        cout << "2. Smoked Salmon                      Rp. 35,000\n";
        cout << "3. Smoked Beef                        Rp. 40,000\n";
        cout << "4. Fried Rice                         Rp. 20,000\n";
        cout << "5. Steak Sandwich                     Rp. 30,000\n";
        cout << "================================================\n";
        cout << "Masukkan Pilihan (1/2/3/4/5) : ";
        cin >> detail[i].pilih; //input pengguna untuk memilih pesanan yang memanggil struck pilih dan masuk ke array
        cout << "Masukkan jumlah beli : ";
        cin >> detail[i].jumlah; //input pengguna untuk menginputkan jumlah pesanan yang memanggil struck pilih dan masuk ke array
        cout << "================================================\n";

        switch (detail[i].pilih) { //membuat pengkondisian yang mana pilihan di atas dapat menjalankan kode di case tertentu
            case 1: //jika memilih case 1 maka anda memesan dibawah ini
                detail[i].Harga = 25000; //memanggil array dari struck detail pesanan yaitu harga yang di inisialisasikan 25000
                detail[i].NamaBarang.makanan = "Chicken"; //memanggil struck makanan agar disimpan di sana
                break; //untuk menghentikan eksekusi agar tidak lanjut ke case di bawahnya melainkan melanjutkan eksekusi di luar switch
            case 2:
                detail[i].Harga = 35000;
                detail[i].NamaBarang.makanan = "Smoked Salmon";
                break;
            case 3:
                detail[i].Harga = 40000;
                detail[i].NamaBarang.makanan = "Smoked Beef";
                break;
            case 4:
                detail[i].Harga = 20000;
                detail[i].NamaBarang.makanan = "Fried Rice";
                break;
            case 5:
                detail[i].Harga = 30000;
                detail[i].NamaBarang.makanan = "Steak Sandwich";
                break;
            default:
                cout << "Pilihan tidak ada di daftar, silahkan coba lagi !\n";
        }
        detail[i].NamaBarang.minuman = ""; // Menyatakan tidak ada minuman saat memesan makanan
        jumlah++; //digunakan untuk menambah nilai dari variabel i setiap kali iterasi dilakukan dalam loop for.
        char pesan_lagi; 
        cout << "\t    Item berhasil di pilih\n";
        cout << "================================================\n";
        cout << "Apakah Anda ingin memesan makanan lagi? (y/n): ";
        cin >> pesan_lagi;
        if (pesan_lagi != 'y' && pesan_lagi != 'Y') //jika anda menginputkan y maka fungsi makanan akan terus dijalankan
            break; 
    }
}

void minuman() { //fungsi minuman yang mana berisikan menu minuman yang dpat di pesan. kode di bawah sama dengan fungsi makanan bedanya memanggil struck minuman
    system("cls");
    for (int i = jumlah; i < maxPesan; i++) { 
        cout << "\n================== Drink Menu ==================\n";
        cout << "1. Lychee Tea                         Rp. 15,000\n";
        cout << "2. Lemon Tea                          Rp. 12,000\n";
        cout << "3. Americano Coffee                   Rp. 18,000\n";
        cout << "4. Espresso Coffee                    Rp. 20,000\n";
        cout << "5. Cafe Latte                         Rp. 22,000\n";
        cout << "================================================\n";
        cout << "Masukkan Pilihan (1/2/3/4/5) : ";
        cin >> detail[i].pilih;
        cout << "Masukkan jumlah beli : ";
        cin >> detail[i].jumlah;
        cout << "================================================\n";

        switch (detail[i].pilih) {
            case 1:
                detail[i].Harga = 15000;
                detail[i].NamaBarang.minuman = "Lychee Tea";
                break;
            case 2:
                detail[i].Harga = 12000;
                detail[i].NamaBarang.minuman = "Lemon Tea";
                break;
            case 3:
                detail[i].Harga = 18000;
                detail[i].NamaBarang.minuman = "Americano Coffee";
                break;
            case 4:
                detail[i].Harga = 20000;
                detail[i].NamaBarang.minuman = "Espresso Coffee";
                break;
            case 5:
                detail[i].Harga = 22000;
                detail[i].NamaBarang.minuman = "Cafe Latte";
                break;
            default:
                cout << "Input yang anda masukkan salah, silahkan coba lagi !\n";
        }
        detail[i].NamaBarang.makanan = ""; // Menyatakan tidak ada makanan saat memesan minuman
        jumlah++;
        char pesan_lagi;
        cout << "Apakah Anda ingin memesan minuman lagi? (y/n): ";
        cin >> pesan_lagi;
        if (pesan_lagi != 'y' && pesan_lagi != 'Y')
        break;
    }
}

void lihatPesanan() { //membuat fungsi lihat pesanan yang berfungsi untuk melihat list pesanan yang sudah di pilih
    float total_harga_lihat = 0; // Inisialisasi total harga hanya untuk melihat pesanan
    cout << "\n================ Detail Pesanan ================\n";
    bool adaPesanan = false; // Untuk menandai apakah ada pesanan yang ditampilkan
    for (int i = 0; i < maxPesan; i++) { // Mengubah batas loop menjadi maxPesan
        if (detail[i].Harga != 0) { //pengkondisian apabila detail.harga tidak sama dengan nol
            adaPesanan = true; // Menandai bahwa ada pesanan yang ditampilkan
            cout << i << ". ";
            if (!detail[i].NamaBarang.makanan.empty()) {
                cout << detail[i].NamaBarang.makanan <<endl;
                cout << setw(7) << detail[i].jumlah << right << "     x" << setw(15) << detail[i].Harga << setw(20) << detail[i].jumlah * detail[i].Harga << endl;
            } else if (!detail[i].NamaBarang.minuman.empty()) {
                cout << detail[i].NamaBarang.minuman <<endl;
                cout << setw(7) << detail[i].jumlah << right << "     x" << setw(15) << detail[i].Harga << setw(20) << detail[i].jumlah * detail[i].Harga << endl;
            }
            total_harga_lihat += detail[i].Harga * detail[i].jumlah; // Menghitung total harga sebelum pajak
        }
    }
    cout << "================================================\n";
    cout << left << setw(38) << "Total Harga :" << right << setw(10) << total_harga_lihat << endl; // Memformat total harga
    cout << "================================================\n";
    
    if (!adaPesanan) { // Jika tidak ada pesanan yang ditampilkan
        cout << "Tidak ada pesanan yang aktif.\n";
        return;
    }
}

void batalkanPesanan() {
    int nomorPesanan;
    cout << "\n================ Detail Pesanan ================\n";
    bool adaPesanan = false; // Untuk menandai apakah ada pesanan yang ditampilkan
    for (int i = 0; i < maxPesan; i++) { // Mengubah batas loop menjadi maxPesan
        if (detail[i].Harga != 0) {
            adaPesanan = true; // Menandai bahwa ada pesanan yang ditampilkan
            cout << i << ". ";
            if (!detail[i].NamaBarang.makanan.empty()) {
                cout << detail[i].NamaBarang.makanan <<endl;
                cout << setw(7) << detail[i].jumlah << right << "     x" << setw(15) << detail[i].Harga << setw(20) << detail[i].jumlah * detail[i].Harga << endl;
            } else if (!detail[i].NamaBarang.minuman.empty()) {
                cout << detail[i].NamaBarang.minuman <<endl;
                cout << setw(7) << detail[i].jumlah << right << "     x" << setw(15) << detail[i].Harga << setw(20) << detail[i].jumlah * detail[i].Harga << endl;
            }
        }
    }
    if (!adaPesanan) { // Jika tidak ada pesanan yang ditampilkan
        cout << "Tidak ada pesanan yang aktif.\n";
        return;
    }
    cout << "\n================================================\n";
    cout << "Masukkan nomor pesanan yang ingin dibatalkan: ";
    cin >> nomorPesanan;
    if (nomorPesanan >= 0 && nomorPesanan < maxPesan && detail[nomorPesanan].Harga != 0) {
        detail[nomorPesanan].Harga = 0;
        detail[nomorPesanan].jumlah = 0;
        detail[nomorPesanan].NamaBarang.makanan = "";
        detail[nomorPesanan].NamaBarang.minuman = "";
        system("cls");
        cout << "Pesanan berhasil dibatalkan.\n";
    } else {
        system("cls");
        cout << "Nomor pesanan tidak valid atau pesanan sudah kosong.\n";
    }
}


void bayar() {
    total_harga = 0; // Menginisialisasi total harga sebelum menghitung ulang
    bool adaPesanan = false; //membuat inisialisasi bool bernilai false

    cout << "\n================ Detail Pesanan ================\n";
    cout << left << setw(30) << "Detail Pembelian" << right << setw(19) << "Total\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < maxPesan; ++i) { // Mengubah batas loop menjadi maxPesan
        if (detail[i].Harga != 0) {
            adaPesanan = true; //inisialisasi berubah menjadi true ketika ada pesanan dalam program
            if (!detail[i].NamaBarang.makanan.empty()) {
                cout << detail[i].NamaBarang.makanan <<endl;
                cout << detail[i].jumlah << "   x" << setw(18) << detail[i].Harga << setw(25) << detail[i].jumlah * detail[i].Harga << endl;
            } else if (!detail[i].NamaBarang.minuman.empty()) {
                cout << detail[i].NamaBarang.minuman <<endl;
                cout << detail[i].jumlah << "   X" << setw(18) << detail[i].Harga << setw(25) << detail[i].jumlah * detail[i].Harga << endl;
            }
            total_harga += detail[i].Harga * detail[i].jumlah; // Menghitung total harga sebelum pajak
        }
    }

    if(!adaPesanan) {
        cout << "Tidak ada pesanan yang aktif.\n";
        return;
    }

    total_ppn = total_harga * ppn; //membuat perhitungan total ppn dari total harga di kali ppn
    total_bayar = total_harga + total_ppn; //membuat perhitungan total bayar dari total harga ditambah total ppn

    // Menghitung diskon berdasarkan total sebelum pajak
    if (total_harga >= 500000) { //jika belanja di atas atau sama dengan 500k maka berikan diskon
        diskonHarga = diskon * total_harga; //membuat kalkulator diskon harga
        setDiskon = total_harga - diskonHarga + total_ppn; //membuat kalkulator harga setelah dikurangi diskon
    } else {
        setDiskon = total_harga + total_ppn; //membuat kalkulator bahwa harga tetap tidak di kurangi diskon
    }

    cout << "------------------------------------------------\n";
    cout << left << setw(38) << "Total Harga :" << right << setw(10) << total_harga << endl; // Memformat total harga
    cout << left << setw(38) << "Pajak (10%) :" << right << setw(10) << total_ppn << endl; // Memformat total harga
    cout << left << setw(38) << "Diskon      :" << right << setw(10) << diskonHarga << endl; // Memformat total harga
    cout << "------------------------------------------------\n";
    cout << left << setw(38) << "Total Bayar :" << right << setw(10) << setDiskon << endl; // Memformat total harga
    cout << "================================================\n";

    cout << "Masukkan jumlah uang : ";
    cin >> totalUang;
    if (totalUang < setDiskon) {
        system("cls");
        cout << "Maaf uang kurang, silahkan bayar sesuai total bayar\n";
        bayar(); // Mengulang proses pembayaran jika uang yang dimasukkan kurang
    } else {
        if (totalUang == setDiskon) {
            cout << "Kembalian            : 0\n";
            pembayaranSelesai = true; //menginisialisasi bahwa pembayaran sudah selesai
        } else {
            kembali = totalUang - setDiskon;
            cout << "Kembalian            : " << kembali <<endl;
            pembayaranSelesai = true;
        }
    }
}

void cetakStruk() {
    system("cls");
    cout << "************************************************\n";
    cout << "================== Podjok Cafe =================\n";
    cout << "========== Food, Drink and Cozy Music ==========\n";
    cout << "************************************************\n\n";
    cout << "=============== Struk Pembelian ================\n";
    // Mendapatkan waktu sistem saat ini
    time_t now = time(0);
    cout << "Tanggal Pembelian : " << ctime(&now);
    cout << "Nama Pembeli      : " << detail[0].namaPembeli << endl;
    cout << "Kasir             : " << detail[0].kasir << endl;
    cout << "================================================\n";
    cout << left << setw(30) << "Detail Pembelian:" << right << setw(20) << "Harga\n\n";
    for (int i = 0; i < maxPesan; ++i) {
        if (detail[i].Harga != 0) {
            if (!detail[i].NamaBarang.makanan.empty()) {
                cout << detail[i].NamaBarang.makanan <<endl;
                cout << detail[i].jumlah << "   x" << setw(18) << detail[i].Harga << setw(25) << detail[i].jumlah * detail[i].Harga << endl;
            } else if (!detail[i].NamaBarang.minuman.empty()) {
                cout << detail[i].NamaBarang.minuman <<endl;
                cout << detail[i].jumlah << "   X" << setw(18) << detail[i].Harga << setw(25) << detail[i].jumlah * detail[i].Harga << endl;
            }
        }
    }
    cout << "================================================\n";
    cout << left << setw(38) << "Total Harga       :" << right << setw(10) << total_harga << endl; // Memformat total harga
    cout << left << setw(38) << "Pajak (10%)       :" << right << setw(10) << total_ppn << endl; // Memformat total harga
    cout << "================================================\n";
    cout << left << setw(38) << "Total Bayar       :" << right << setw(10) << total_bayar << endl; // Memformat total harga
    cout << left << setw(38) << "Diskon (20%)      :" << right << setw(10) << diskonHarga << endl; // Memformat total harga
    cout << "================================================\n";

    cout << left << setw(38) << "Total Belanja     :" << right << setw(10) << setDiskon << endl; // Memformat total harga

    cout << left << setw(38) << "Total Bayar       :" << right << setw(10) << totalUang << endl; // Memformat total harga
    cout << "================================================\n";
    cout << left << setw(38) << "Kembali           :" << right << setw(10) << kembali << endl; // Memformat total harga
    cout << "\n************************************************\n";
    cout << "================== Thank You ===================\n";
    cout << "************************************************\n";

}

int main() {

    // Mendapatkan waktu sistem saat ini
    time_t now = time(0);

    cout << "\n================================================\n";
    cout << "\t Selamat Datang di Podjok Cafe \n";
    cout << "================================================\n";
    cout << "================================================\n";
    cout << "Tanggal Pembelian : " << ctime(&now); 
    cout << "Masukkan Nama pelanggan : ";
    getline(cin, detail[0].namaPembeli); //memanggil array pada struct detail, yang mana menmanggil 0 karena hanya ada 1 nama pembeli dalam 1 transaksi
    cout << "Masukkan Nama Kasir : ";
    getline(cin, detail[0].kasir); //memanggil array pada struct detail, yang mana menmanggil 0 karena hanya ada 1 nama kasir dalam 1 transaksi
    system("cls");

    while (true) {
        menu();
        int pilih;
        cout << "Masukkan Pilihan Menu (1/2/3/4/5/6/7): ";
        cin >> pilih;
        cout << "\n";
        system("cls");
        
        switch (pilih) {
            case 1:
            if (pembayaranSelesai){ //pengkondisian apabila pembayaran selesai maka user di perintahkan untuk cetak struk dulu
                cout << "Anda sudah bayar, Silahkan cetak struk dahulu";
                break;
            }
                makanan();
                break;
            case 2:
            if (pembayaranSelesai){
                cout << "Anda sudah bayar, Silahkan cetak struk dahulu";
                break;
            }
                minuman();
                break;
            case 3:
            if (pembayaranSelesai) { //pengkondisian apabila user sudah bayar namun memilih menu pembayaran lagi
                cout << "Tidak dapat melihat pesanan, Anda sudah bayar"; 
                break;
            }
                lihatPesanan();
                break;
            case 4:
            if (pembayaranSelesai) {
                cout << "Tidak dapat membatalkan pesanan, anda sudah bayar";
                break;
            }
                batalkanPesanan();
                break;
            case 5:
            if (pembayaranSelesai) {
                cout <<  "tidak dapat melakukan pembayaran, anda sudah bayar";
                break;
            }
                bayar();
                break;
            case 6:
            if (!pembayaranSelesai){ //pengkondisian apabila pembayaran belum selesai dan anda memilih menu cetak struk 
                cout << "Tidak dapat mencetak struk,silahkan bayar dahulu";
                break;
            }
                cetakStruk();
                return 0;
            case 7:
            if (pembayaranSelesai) { //apabila anda memilih keluar tetapi anda sudah membayar pesanan
                cout << "Tidak dapat keluar program, silahkan cetak struk dulu";
                break;
            }
                cout << "Program di hentikan oleh pengguna.";
                identitas();
                return 0;
            
            default: //jika inputan tidak ada dalam case
                system("cls");
                cout << "Pilihan tidak ada di daftar, silahkan coba lagi\n";
                break;
        }
    }
    return 0; //menandakan bahwa program berhenti dengan tanpa kendala
} 