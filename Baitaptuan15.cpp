#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string tenMuc;
    int soTrang;
    vector<Node*> con;
    Node* next;
};

Node* nhapNode() {
    Node* node = new Node;
    cout << "Nhap ten muc (chapter/section/subsection/subsubsection): ";
    cin.ignore();
    getline(cin, node->tenMuc);
    cout << "Nhap so trang: ";
    cin >> node->soTrang;
    node->next = nullptr;
    return node;
}

void nhapMucLuc(Node*& root) {
    root = nhapNode();
    cout << "Nhap muc con cho " << root->tenMuc << " (nhap so luong muc con): ";
    int soLuongCon;
    cin >> soLuongCon;
    for (int i = 0; i < soLuongCon; ++i) {
        Node* child = nullptr;
        nhapMucLuc(child);
        root->con.push_back(child);
    }
    cout << "Nhap muc tiep theo cho " << root->tenMuc << " (0 neu khong co): ";
    int chon;
    cin >> chon;
    if (chon == 1) {
        nhapMucLuc(root->next);
    }
}

int soChuong(Node* root) {
    if (root == nullptr) return 0;
    int count = 0;
    if (root->tenMuc == "chapter") {
        count = 1;
    }
    int childrenCount = 0;
    for(Node* child : root->con){
        childrenCount += soChuong(child);
    }
    return count + childrenCount + soChuong(root->next);
}

int tinhTongSoTrang(Node* root) {
    if (!root) return 0;
    int tongSoTrang = root->soTrang;
    for (Node* child : root->con) {
        tongSoTrang += tinhTongSoTrang(child);
    }
    return tongSoTrang;
}

Node* chuongDaiNhat(Node* root) {
    if (!root) return nullptr;
    Node* maxChuong = root;
    int maxSoTrang = tinhTongSoTrang(root);
    for(Node* child : root->con){
        Node* childMax = chuongDaiNhat(child);
        if(childMax){
            int childMaxSoTrang = tinhTongSoTrang(childMax);
            if(childMaxSoTrang > maxSoTrang){
                maxSoTrang = childMaxSoTrang;
                maxChuong = childMax;
            }
        }
    }
    Node* nextMax = chuongDaiNhat(root->next);
    if(nextMax){
        int nextMaxSoTrang = tinhTongSoTrang(nextMax);
            if(nextMaxSoTrang > maxSoTrang){
                maxSoTrang = nextMaxSoTrang;
                maxChuong = nextMax;
            }
    }
    return maxChuong;
}

void xoaMuc(Node*& root, const string& tenMucCanXoa, Node* parent = nullptr) {
    if (!root) return;
    if (root->tenMuc == tenMucCanXoa) {
        if (parent) {
            for(size_t i = 0; i < parent->con.size(); ++i){
                if(parent->con[i] == root){
                    parent->con.erase(parent->con.begin() + i);
                    break;
                }
            }
        } else {
            Node* temp = root;
            root = root->next;
            delete temp;
        }
        return;
    }
    for(Node* child : root->con){
        xoaMuc(child, tenMucCanXoa, root);
    }
    xoaMuc(root->next, tenMucCanXoa, root);
}

void inMucLuc(Node* root, int level = 0) {
    if (!root) return;
    for (int i = 0; i < level; ++i) cout << "  ";
    cout << root->tenMuc << " (" << root->soTrang << " trang)" << endl;
    for(Node* child : root->con){
        inMucLuc(child, level + 1);
    }
    inMucLuc(root->next, level);
}

int main() {
    Node* root = nullptr;
    cout << "Nhap vao muc luc cua cuon sach:" << endl;
    nhapMucLuc(root);
    cout << "\nMuc luc da nhap:" << endl;
    inMucLuc(root);
    cout << "\nSo chuong: " << soChuong(root) << endl;
    Node* chuongDaiNhatNode = chuongDaiNhat(root);
    if (chuongDaiNhatNode != nullptr) {
        cout << "Chuong dai nhat la: " << chuongDaiNhatNode->tenMuc << endl;
    }
    cout << "\nNhap ten muc can xoa: ";
    string mucCanXoa;
    cin.ignore();
    getline(cin, mucCanXoa);
    xoaMuc(root, mucCanXoa);
    cout << "\nMuc luc sau khi xoa:" << endl;
    inMucLuc(root);
    return 0;
}