#include <iostream>
#include <string>
using namespace std;

class angka{
private:
    int *arr;
    int panjang;
public:
    angka(int);
    ~angka();
    void cetakData();
    void isiData();
};

angka::angka(int i){
    panjang = i;
    arr = new int[i];
    isiData();
}

angka::~angka(){
    cout<<endl;
    cetakData();
    delete[]arr;
    cout<<"alamt array sudah dilepaskan"<<endl;
}

void angka::cetakData(){
    for(int i=1;i<=panjang;i++){
        cout<<i<<" = "<<arr[i]<<endl;
    }
    cout<<endl;
}

int main(){
    angka belajarcpp(3);
    angka *ptrBelajarcpp = new angka(5);
    delete ptrBelajarcpp;
    
    return 0;
}
