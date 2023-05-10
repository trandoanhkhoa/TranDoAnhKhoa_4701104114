#include <iostream>
#include <vector>
using namespace std;

// Hàm cộng hai đa thức
vector<int> addPolynomials(const vector<int>& A, const vector<int>& B) {
    int n = A.size();
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = A[i] + B[i];
    }
    return result;
}

// Hàm trừ hai đa thức
vector<int> subtractPolynomials(const vector<int>& A, const vector<int>& B) {
    int n = A.size();
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = A[i] - B[i];
    }
    return result;
}

// Hàm nhân đa thức
vector<int> multiplyPolynomials(const vector<int>& A, const vector<int>& B) {
    int n = A.size();

    // Nếu đa thức chỉ có một hệ số
    if (n == 1) {
        vector<int> C(1);
        C[0] = A[0] * B[0];
        return C;
    }

    // Chia đa thức thành hai nửa
    int mid = n / 2;
    vector<int> AL(A.begin(), A.begin() + mid);
    vector<int> AH(A.begin() + mid, A.end());
    vector<int> BL(B.begin(), B.begin() + mid);
    vector<int> BH(B.begin() + mid, B.end());

    // Tính các giá trị sau đệ quy
    vector<int> P1 = multiplyPolynomials(AL, BL);
    vector<int> P2 = multiplyPolynomials(AH, BH);
    vector<int> P3 = multiplyPolynomials(addPolynomials(AL, AH), addPolynomials(BL, BH));
    vector<int> P4 = subtractPolynomials(subtractPolynomials(P3, P1), P2);

    // Tạo đa thức kết quả
    vector<int> result(2 * n - 1);

    // Gán các giá trị vào đa thức kết quả
    for (int i = 0; i < n; i++) {
        result[i] = P1[i];
    }
    for (int i = 0; i < n; i++) {
        result[i + n] = P2[i];
    }
    for (int i = 0; i < n; i++) {
        result[i + mid] += P4[i];
    }
    return result;
}

// Hàm in đa thức
void printPolynomial(const vector<int>& polynomial) {
    int n = polynomial.size();
    for (int i = 0; i < n; i++) {
        cout << polynomial[i];
        if (i != n - 1) {
            cout << "x^" << i << " + ";
        }
    }
    cout << endl;
}

int main() {
    vector<int> A = {1, 2, 3}; // Đa thức A = 1 + 2x + 3x^2
    vector<int> B = {4, 5, 6}; // Đa thức B = 4 + 5x + 6x^2

    cout << "Đa thức A: ";
    printPolynomial(A);
    cout << "Đa thức B: ";
    printPolynomial(B);

    // Nhân đa thức A và B
    vector<int> result = multiplyPolynomials(A, B);

    cout << "Kết quả: ";
    printPolynomial(result);

    return 0;
}