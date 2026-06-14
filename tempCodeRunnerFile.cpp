#include <iostream>
#include <string>
using namespace std;

int main() {
    int jumlahMahasiswa, jumlahUjian;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlahMahasiswa;
    cout << "Masukkan jumlah ujian: ";
    cin >> jumlahUjian;

    // Pointer untuk nilai (1 dimensi, simulasi 2D)
    float *nilai = new float[jumlahMahasiswa * jumlahUjian];

    // Pointer ke array string (nama mahasiswa)
    string *nama = new string[jumlahMahasiswa];

    // Input nama mahasiswa
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "Nama mahasiswa ke-" << i + 1 << ": ";
        cin >> nama[i];
    }

    // Input nilai ujian
    for (int i = 0; i < jumlahMahasiswa; i++) {
        for (int j = 0; j < jumlahUjian; j++) {
            cout << "Nilai mahasiswa " << nama[i] << " ujian ke-" << j + 1 << ": ";
            cin >> *(nilai + i * jumlahUjian + j);
        }
    }

    // Hitung dan tampilkan data
    cout << "\n=== Data Mahasiswa ===\n";
    for (int i = 0; i < jumlahMahasiswa; i++) {
        float total = 0;

        cout << "Nama: " << nama[i] << endl;
        cout << "Nilai: ";

        for (int j = 0; j < jumlahUjian; j++) {
            float n = *(nilai + i * jumlahUjian + j);
            cout << n << " ";
            total += n;
        }

        float rata = total / jumlahUjian;
        cout << "\nRata-rata: " << rata << endl;
        cout << "----------------------\n";
    }

    // Dealokasi memori
    delete[] nilai;
    delete[] nama;

    return 0;
}