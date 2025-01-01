#include <iostream>
using namespace std;
int a[1005][1005];
int n, m;
int main()
{
    cout << "Nhap so dinh : ";
    cin >> n;
    cout << "Nhap so canh : ";
    cin >> m;

    for(int i = 1; i <= m ; i++){
        int x, y; cin >> x >> y; //Stt cua 2 dinh noi voi nhau
        a[x][y] = 1;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}