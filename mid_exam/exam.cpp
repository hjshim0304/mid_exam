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
            cout << "������ ���� á���ϴ�!" << endl;
            return *this; // ������ ���� ���� ���� ���� ��ü ��ȯ
        }
        tos++;
        mem[tos] = x;
        return *this; // �������� Ǫ�ø� ���� ���� ��ü �ڽ��� ��ȯ
    }

    // �� (pop) ������ >>
    Stack& operator >> (int& x) {
        if (tos == -1) {
            cout << "������ ��� �ֽ��ϴ�!" << endl;
            // ������ ������� ��� x ���� ��� ó������ �����ؾ� �մϴ�.
            // ���⼭�� �������� �ʰ� ���� ��ü�� ��ȯ�մϴ�.
            return *this;
        }
        x = mem[tos];
        tos--;
        return *this; // �������� ���� ���� ���� ��ü �ڽ��� ��ȯ
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