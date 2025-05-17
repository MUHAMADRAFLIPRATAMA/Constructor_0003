#include <iostream>
#include <string>
using namespace std;

class mahasiswa{
    private:
    static int nim;
    public:
    int id;
    string nama;

    void setId();
    void printAll();

    static void setNim(int pNim){nim=pNim; /*definisi fuction*/}
    static int getNim(){return nim;}

    mahasiswa(string pnama):nama(pnama){setId();}
};

int mahasiswa::nim=0;

void mahasiswa::setId(){
    id = ++nim;
}

void mahasiswa::printAll(){
    cout<<"Id="<<id<<endl;
    cout<<"nama="<<nama<<endl;
    cout<<endl;
}

int main(){
    mahasiswa mhs1("Sri Dadi");
    mahasiswa mhs2("Budi Jatmiko");
    mahasiswa::setNim(9);
    mahasiswa mhs3("Andi Janu");
    mahasiswa mhs4("Joko Wahono");

    mhs1.printAll();
    mhs2.printAll();
    mhs3.printAll();
    mhs4.printAll();

    cout<<"akses dari luar objek ="<<mahasiswa::getNim()<<endl;

    return 0;
}
