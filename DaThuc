#include <iostream>
using namespace std;

struct Node {
    int heSo;    
    int bac;     
    Node* tiepTheo;  

    Node(int hs, int b) : heSo(hs), bac(b), tiepTheo(nullptr) {}
};

class DaThuc {
private:
    Node* dau;  

public:
    DaThuc() : dau(nullptr) {}
    void themHangTu(int heSo, int bac) {
        if (heSo == 0) return;

        Node* nutMoi = new Node(heSo, bac);
        
        if (!dau || dau->bac < bac) {
            nutMoi->tiepTheo = dau;
            dau = nutMoi;
        } else {
            Node* hienTai = dau;
            while (hienTai->tiepTheo && hienTai->tiepTheo->bac > bac) {
                hienTai = hienTai->tiepTheo;
            }
            if (hienTai->bac == bac) {
                hienTai->heSo += heSo;
                delete nutMoi;
                if (hienTai->heSo == 0) {
                    xoaHangTu(bac);
                }
            } else {
                nutMoi->tiepTheo = hienTai->tiepTheo;
                hienTai->tiepTheo = nutMoi;
            }
        }
    }
    void xoaHangTu(int bac) {
        if (!dau) return;

        if (dau->bac == bac) {
            Node* temp = dau;
            dau = dau->tiepTheo;
            delete temp;
        } else {
            Node* hienTai = dau;
            while (hienTai->tiepTheo && hienTai->tiepTheo->bac != bac) {
                hienTai = hienTai->tiepTheo;
            }
            if (hienTai->tiepTheo) {
                Node* temp = hienTai->tiepTheo;
                hienTai->tiepTheo = temp->tiepTheo;
                delete temp;
            }
        }
    }
    void nhapDaThuc() {
        int heSo, bac;
        char tiepTuc;
        do {
           cout << "Nhap he so: ";
            cin >> heSo;
            cout << "Nhap bac: ";
            cin >> bac;
            themHangTu(heSo, bac);

            cout << "Nhap tiep (y/n)? ";
            cin >> tiepTuc;
        } while (tiepTuc == 'y' || tiepTuc == 'Y');
    }
    void inDaThuc() const {
        if (!dau) {
            cout << "0\n";
            return;
        }
        Node* hienTai = dau;
        while (hienTai) {
            if (hienTai->heSo > 0 && hienTai != dau) std::cout << " + ";
            if (hienTai->heSo < 0) cout << " - ";
            cout << abs(hienTai->heSo);
            if (hienTai->bac != 0) cout << "x^" << hienTai->bac;
            hienTai = hienTai->tiepTheo;
        }
      cout << endl;
    }
    ~DaThuc() {
        while (dau) {
            Node* temp = dau;
            dau = dau->tiepTheo;
            delete temp;
        }
    }
};

int main() {
    DaThuc daThuc;
    daThuc.nhapDaThuc();  
 	cout << "Da thuc vua nhap la: ";
    daThuc.inDaThuc();    // In đa thức
    return 0;
}
