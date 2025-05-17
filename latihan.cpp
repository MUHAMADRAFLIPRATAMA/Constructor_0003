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

    