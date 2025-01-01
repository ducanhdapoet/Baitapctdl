#include <iostream>
#include <vector>
using namespace std;

struct Node{
    char name;
    Node* next;

    Node(char x){
        name = x;
        next = NULL;
    }
};
struct Graph{
    vector<Node*> first;
};
void ThemDinh(Graph* dothi, char name)
{
    Node* dinh = new Node(name);
    dothi->first.push_back(dinh);
}
void themLanCanCuaDinh(Node* dinh, char name)
{
    Node* moi = new Node(name);
    Node* tmp = dinh;
    while(tmp->next != NULL) tmp = tmp->next;
    tmp->next = moi;
}
void display(Graph* dothi)
{
    for(Node* x : dothi->first)
    {
        Node* tmp = x;
        if(tmp->next != NULL)
        {
            cout << tmp->name << ": ";
            tmp = tmp->next;
        }
        while(tmp){
            cout << tmp->name << ' ';
            tmp = tmp ->next;
        }
        cout << endl;
    }
}
int main()
{
    Graph* dothi = new Graph();
    ThemDinh(dothi, 'a');
    ThemDinh(dothi, 'b');
    ThemDinh(dothi, 'c');
    ThemDinh(dothi, 'd');
    ThemDinh(dothi, 'e');
    ThemDinh(dothi, 'f');
    ThemDinh(dothi, 'g');
    themLanCanCuaDinh(dothi->first[0], 'b');
    themLanCanCuaDinh(dothi->first[0], 'c');
    themLanCanCuaDinh(dothi->first[0], 'd');
    themLanCanCuaDinh(dothi->first[1], 'e');
    themLanCanCuaDinh(dothi->first[3], 'e');
    themLanCanCuaDinh(dothi->first[3], 'f');
    themLanCanCuaDinh(dothi->first[4], 'c');
    themLanCanCuaDinh(dothi->first[4], 'f');
    themLanCanCuaDinh(dothi->first[4], 'g');

    display(dothi);
}