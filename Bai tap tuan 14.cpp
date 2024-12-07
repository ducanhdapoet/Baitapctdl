#include <iostream>
#include <string>
using namespace std;

struct Node {
    string value;
    Node* left;
    Node* right;

    Node(string val) : value(val), left(nullptr), right(nullptr) {}
};
class CayBieuThuc {
public:
    Node* goc;
    CayBieuThuc() : goc(nullptr) {}
    Node* xayDungCayDeQuy(const string& bieuThuc, int& chiSo) {
        if (chiSo < 0) return nullptr;
        Node* nutMoi = new Node(string(1, bieuThuc[chiSo--]));
        if (nutMoi->value == "+" || nutMoi->value == "-" ||
            nutMoi->value == "*" || nutMoi->value == "/") {
            nutMoi->right = xayDungCayDeQuy(bieuThuc, chiSo);
            nutMoi->left = xayDungCayDeQuy(bieuThuc, chiSo);
        }
        return nutMoi;
    }
    void xayDungCay(const string& bieuThuc) {
        int chiSo = bieuThuc.length() - 1;
        goc = xayDungCayDeQuy(bieuThuc, chiSo);
    }
    void duyetTrungTo(Node* nut) {
        if (nut) {
            if (nut->left) cout << "(";
            duyetTrungTo(nut->left);
            cout << nut->value;
            duyetTrungTo(nut->right);
            if (nut->right) cout << ")";
        }
    }
    void duyetTienTo(Node* nut) {
        if (nut) {
            cout << nut->value;
            duyetTienTo(nut->left);
            duyetTienTo(nut->right);
        }
    }
    void duyetHauTo(Node* nut) {
        if (nut) {
            duyetHauTo(nut->left);
            duyetHauTo(nut->right);
            cout << nut->value;
        }
    }
    void inCay() {
        cout << "Trung to: ";
        duyetTrungTo(goc);
        cout << endl;
        cout << "Tien to: ";
        duyetTienTo(goc);
        cout << endl;
        cout << "Hau to: ";
        duyetHauTo(goc);
        cout << endl;
    }
};
int main() {
    CayBieuThuc cay;
    string bieuThuc = "45*31+-";
    cay.xayDungCay(bieuThuc);
    cay.inCay();
    return 0;
}
