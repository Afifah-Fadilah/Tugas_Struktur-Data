#include <iostream>
using namespace std;

    void garis() //membuat fungsi garis untuk menghasilkan output garis batas
    {
    for (int i = 0; i < 44; i++) { //membuat perulangan untuk menghasilkan panjang garis batas
      cout <<"="; //output dari fungsi garis
      }
    }

    void identitas() //membuat fungsi identitas yang berisikan nama dan npm
    {
      garis(); //memanggil fungsi garis didalam fungsi identitas
      cout << "\nProgram Ini Dibuat Oleh :\n";
      cout << "Nama : Afifah Fadilah\n";
      cout << "NPM  : 2310631170003\n";
      garis(); //memanggil fungsi garis didalam fungsi identitas
    }

int main(){ //fungsi utama

    int jumlahMhs; //membuat inisial dari variabel bertipe int
    string namaMhs[30]; //membuat batas array dari namaMhs yaitu berukuran 30 yang bervariabel string
    string* pNama; //membuat pointer bervariabel string
    pNama = &namaMhs[0]; //mengambil data dari namaMhs yang sudah diinputkan di dalam array

    garis(); //memanggil fungsi garis
    cout <<endl;
    garis(); //memanggil fungsi garis
    cout << "\n    Membuat Program Data Nama Mahasiswa\n"; //membuat judul dari program yang dibuat
    garis(); //memanggil fungsi garis
    cout <<endl;
    garis(); //memanggil fungsi garis
    while (true) {  //membuat perulangan while yang meminta untuk menginputkan jumlah dari mhs yang akan di input
      cout << "\nMasukkan jumlah mahasiswa : "; //perintah untuk menginputkan jumlah 
      cin >> jumlahMhs; //input dari pengguna yang ber variabel integer
      garis(); //memanggil fungsi garis
      if (jumlahMhs > 30) { /*membuat pengkondisian dari jumlah yang diinputkan di atas, apabila data yang ingin di inputkan
                            lebih dari 30, maka output nya akan seperti di bawah*/
        cout << "\nJumlah Data yang akan diinputkan melebihi batas,\nSilahkan Inputkan kembali dari range 1 - 30!\n";
      } 
      else { /*pengkondisian lain yang apabila jumlah dari yang diinputkan sebelumnya tidak melebihi array maka while
             akan berhenti karena adanya break, dan program akan lanjut ke kode berikutnya*/
      cin.ignore(); //digunakan untuk membersihkan atau menghapus karakter yang tersisa di buffer input, agar tidak terjadi kesalahan2
      break;
      }
    }

    for (int i = 0; i < jumlahMhs; i++) { //membuat perulangan untuk mengoutput kan nama mhs sebanyak jumlah yang sudah diinputkan sebelumnya
    cout << "\nMasukkan nama siswa ke- " << i+1 <<" : "; //meminta untuk menginputkan nama mhs
    getline (cin, namaMhs[i]); //input dari pengguna, disini menggunakan getline agar nama yang diinputkan menggunakan spasi tidak eror

    }
    cout <<"\n\n";
    garis(); //memanggil fungsi garis
    cout << "\nNama Siswa\t\tAlamat Pada Komputer\n"; 
    garis();//memanggil fungsi garis
    cout <<endl;
    for (int i = 0; i < jumlahMhs; i++) { //membuat perulangan yang akan mengoutputkan nama nama yang sudah di input
      cout << "" << *pNama << "\t\t\t" << pNama <<endl; //output dari dalam array, berupa nama dan alamat nya di komputer
      pNama++; //agar pointer nama dari array berjalan dari awal hingga akhir
    }
  
  cout <<"\n\n";
  identitas();

}