#include <iostream>
#include <string>
using namespace std;

// Forward declaration
class Mahasiswa;
class Staff;
class Universitas;

class Dosen {
    private:
    string nama;
    string NIDN;
    string pangkat;
    float gaji;

    public:
    Dosen(string nama, string NIDN, string pangkat, float gaji)
        : nama(nama), NIDN(NIDN), pangkat(pangkat), gaji(gaji) {}

    // Memberi nilai ke mahasiswa
    void beriNilai(Mahasiswa* m, float nilaiBaru);

    // Friend function untuk akses gaji oleh Universitas
    friend float aksesGajiDosen(Dosen* d);

    // Staff bisa ubah pangkat
    friend class Staff;
};

class Mahasiswa {
    private:
        string nama;
        string NIM;
        float nilai;
    
        public:
        Mahasiswa(string nama, string NIM, float nilai)
            : nama(nama), NIM(NIM), nilai(nilai) {}
    
        