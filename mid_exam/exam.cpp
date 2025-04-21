#include <iostream>
#include <string>

using namespace std;

class Stack {
    int size;
    int* mem;  // ���� �޸� �Ҵ�. ���� ����
    int tos;   // top of stack. -1�̸� ������ �����
public:
    Stack(int size = 10) {
        this->size = size;
        this->mem = new int[size];
        tos = -1;
    }
    ~Stack() { delete[] mem; } // �迭 ��ȯ
    Stack& operator << (int x) {
        if (tos == size - 1) {
            cout << "������ ���� ��" << endl;
            return *this;
        }
        tos++;
        mem[tos] = x;
        return *this;
    }
    Stack& operator >> (int& x) {
        if (tos == -1) {
            cout << "������ �������" << endl;
            return *this;
        }
        x = mem[tos];
        tos--;
        return *this;
    }
    bool operator ! () {
        return this->tos == -1 ? true : false;
    }
};

int main() {
    Stack stack;
    stack << 3 << 5 << 10; // 3, 5, 10�� ������� Ǫ��
    while (true) {
        if (!stack) break; // ���� empty
        int x;
        stack >> x; // ������ ž�� �ִ� ���� ��
        cout << x << ' ';
    }
    cout << endl;
}