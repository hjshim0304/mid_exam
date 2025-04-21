#include <iostream>
#include <string>

using namespace std;

class Stack {
    int size;
    int* mem;  // 동적 메모리 할당. 스택 공간
    int tos;   // top of stack. -1이면 스택이 비었음
public:
    Stack(int size = 10) {
        this->size = size;
        this->mem = new int[size];
        tos = -1;
    }
    ~Stack() { delete[] mem; } // 배열 반환
    Stack& operator << (int x) {
        if (tos == size - 1) {
            cout << "스택이 가득 참" << endl;
            return *this;
        }
        tos++;
        mem[tos] = x;
        return *this;
    }
    Stack& operator >> (int& x) {
        if (tos == -1) {
            cout << "스택이 비어있음" << endl;
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
    stack << 3 << 5 << 10; // 3, 5, 10을 순서대로 푸시
    while (true) {
        if (!stack) break; // 스택 empty
        int x;
        stack >> x; // 스택의 탑에 있는 정수 팝
        cout << x << ' ';
    }
    cout << endl;
}