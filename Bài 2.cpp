#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Node {
    string tu;
    int dem;
    Node* tiep;

    Node(string w) : tu(w), dem(1), tiep(nullptr) {}
};

void themHoacCapNhatTu(Node*& dau, const string& tu) {
    Node* temp = dau;
    Node* truoc = nullptr;

    while (temp) {
        if (temp->tu == tu) {
            temp->dem++;
            return;
        }
        truoc = temp;
        temp = temp->tiep;
    }

    Node* moi = new Node(tu);
    if (!truoc) {
        dau = moi;
    } else {
        truoc->tiep = moi;
    }
}

string timTuXuatHienNhieuNhat(Node* dau) {
    Node* temp = dau;
    string nhieuNhat;
    int maxDem = 0;

    while (temp) {
        if (temp->dem > maxDem) {
            maxDem = temp->dem;
            nhieuNhat = temp->tu;
        }
        temp = temp->tiep;
    }

    return nhieuNhat;
}

void xoaTuLay(Node*& dau) {
    Node* temp = dau;

    while (temp && temp->tiep) {
        if (temp->tu == temp->tiep->tu) {
            Node* trung = temp->tiep;
            temp->tiep = temp->tiep->tiep;
            delete trung;
        } else {
            temp = temp->tiep;
        }
    }
}

int demSoTu(Node* dau) {
    Node* temp = dau;
    int dem = 0;

    while (temp) {
        dem++;
        temp = temp->tiep;
    }

    return dem;
}

int main() {
    Node* dau = nullptr;

    string cau = "xanh xanh đỏ đỏ tím tím vàng vàng";
    char* cstr = new char[cau.length() + 1];
    strcpy(cstr, cau.c_str());

    char* token = strtok(cstr, " ");
    while (token) {
        themHoacCapNhatTu(dau, string(token));
        token = strtok(nullptr, " ");
    }

    delete[] cstr;

    string nhieuNhat = timTuXuatHienNhieuNhat(dau);
    cout << "Từ xuất hiện nhiều nhất: " << nhieuNhat << endl;

    xoaTuLay(dau);
    int soTu = demSoTu(dau);
    cout << "Số từ trong danh sách sau khi loại bỏ từ láy: " << soTu << endl;

    while (dau) {
        Node* temp = dau;
        dau = dau->tiep;
        delete temp;
    }

    return 0;
}
