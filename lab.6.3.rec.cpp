#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;


template<typename T>
void Init_(T* b, const int n, int i = 0) {
    if (i < n) {
        b[i] = -10 + rand() % 21;
        Init_(b, n, i + 1); 
    }
}

 void Init(int* b, const int n, int i = 0) {
    if (i < n) {
        b[i] = -10 + rand() % 21;
        Init(b, n, i + 1); 
    }
}


template<typename T>
void Print_(T* b, const int n, int i = 0) {
    if (i == 0) cout << "{ "; 
    if (i < n) {
        cout << b[i] << (i < n - 1 ? ", " : ""); 
        Print_(b, n, i + 1); 
    }
    else if (i == n) cout << " }";
}

void Print(int* b, const int n, int i = 0) {
    if (i == 0) cout << "{ ";
    if (i < n) {
        cout << b[i] << (i < n - 1 ? ", " : "");
        Print(b, n, i + 1);
    }
    else if (i == n) cout << " }";
}

//���������� ��'����� �����
template<typename T>
int CountNegative_(T* b, const int n, int i = 0) {
    if (i >= n) return 0; 
    return (b[i] < 0 ? 1 : 0) + CountNegative_(b, n, i + 1); // ϳ�������� ��'����� �� �������
}

int CountNegative(int* b, const int n, int i = 0) {
    if (i >= n) return 0;
    return (b[i] < 0 ? 1 : 0) + CountNegative(b, n, i + 1);
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    cout << "n = ";
    cin >> n;

    int* a = new int[n];

    Init(a, n); // ����� a

    cout << "Array a: ";
    Print(a, n);
    cout << endl;

    int negativeCount = CountNegative(a, n);
    cout << "The number of negative elements in array a: " << negativeCount << endl << endl;

    int* b = new int[n];

    Init_(b, n); // ����� b 

    cout << "Array b: ";
    Print_(b, n); // ���� ������ b 
    cout << endl;

    int negativeCount_ = CountNegative_(b, n); // ϳ�������� ��'����� � ����� b 
    cout << "The number of negative elements in array b: " << negativeCount_ << endl;

    delete[] a;
    delete[] b;
    return 0;
}
