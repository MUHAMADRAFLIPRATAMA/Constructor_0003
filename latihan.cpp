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
    
        // Friend class agar Dosen bisa ubah nilai
        friend class Dosen;
    
        void tampilkan() {
            cout << "Mahasiswa: " << nama << ", NIM: " << NIM << ", Nilai: " << nilai << endl;
        }
    };
    
    void Dosen::beriNilai(Mahasiswa* m, float nilaiBaru) {
        m->nilai = nilaiBaru;
    }
    
    float aksesGajiDosen(Dosen* d) {
        return d->gaji;
    }
    
    class Staff {
        private:
            string nama;
            string idStaff;
            float gaji;
        
            public:
            Staff(string nama, string idStaff, float gaji)
                : nama(nama), idStaff(idStaff), gaji(gaji) {}
        
                void ubahPangkat(Dosen* d, string pangkatBaru) {
                    d->pangkat = pangkatBaru;
                }
            
                friend float aksesGajiStaff(Staff* s);
            };
            
            float aksesGajiStaff(Staff* s) {
                return s->gaji;
            }
            
            class Universitas {
                public:
                    void lihatGajiDosen(Dosen* d) {
                        cout << "Gaji Dosen: " << aksesGajiDosen(d) << endl;
                    }
                
                    void lihatGajiStaff(Staff* s) {
                        cout << "Gaji Staff: " << aksesGajiStaff(s) << endl;
                    }
                };
                
                int main() {
                    // Membuat objek
                    Mahasiswa m("Ani", "M1234", 80);
                    Dosen d("Pak Joko", "D5678", "Lektor", 10000000);
                    Staff s("Bu Rina", "S001", 6000000);
                    Universitas u;
                
                    cout << "--- Sebelum perubahan ---" << endl;
                    m.tampilkan();
                    u.lihatGajiDosen(&d);
                    u.lihatGajiStaff(&s);
                
                    // Dosen beri nilai
                    d.beriNilai(&m, 95);
                
                    // Staff ubah pangkat dosen
                    s.ubahPangkat(&d, "Profesor");
                
                    cout << "\n--- Setelah perubahan ---" << endl;
                    m.tampilkan();
                    u.lihatGajiDosen(&d);
                    u.lihatGajiStaff(&s);
                
                    return 0;
                } 