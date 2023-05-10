#include <iostream>

using namespace std;

void hanoi(int n, char nguon, char dich, char trunggian) {
    if (n == 1) {
        cout << "Di chuyển đĩa 1 từ " << nguon << " sang " << dich << endl;
        return;
    }
    hanoi(n - 1, nguon, trunggian, dich);
    cout << "Di chuyển đĩa " << n << " từ " << nguon << " sang " << dich << endl;
    hanoi(n - 1, trunggian, dich, nguon);
}

int main() {
    int soDia;
    cout << "Nhập số đĩa: ";
    cin >> soDia;
    hanoi(soDia, 'A', 'C', 'B');
    return 0;
}