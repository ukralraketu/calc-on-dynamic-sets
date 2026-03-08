#include <iostream>
#include <windows.h>

using namespace std;

class Elem {
public:
    Elem* pointer = nullptr;
    char value;
};

auto addElementInSet(Elem& _E, const char& _ch) {
    /*cout << "func_args: " << &_E << "\t"<<  _ch << endl;*/
    Elem* _tracker = &_E;
    while (_tracker != nullptr) {
        Elem* next = _tracker->pointer;
        // add element if it last or next will be > than it
        if (next == nullptr || next->value > int(_ch)) {
            Elem* EL = new Elem();
            EL->value = _ch;
            EL->pointer = next;
            _tracker->pointer = EL;
            break;
        }
        else {
            _tracker = next;
        }
    }
}

auto showSet(Elem& _E) {
    Elem* _tracker = &_E;
    while (_tracker != nullptr) {
        cout << _tracker->value << endl;
        _tracker = _tracker->pointer;
    }
}

auto cleanMemory(Elem& _E) {
    Elem* cleaner = &_E;
    while (cleaner != nullptr) {
        Elem* next = cleaner->pointer;
        /*cout << "clean " << cleaner->value << endl;*/
        delete cleaner;
        cleaner = next;
    }
}


int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Elem* A = new Elem();
    Elem* tracker = A;

    char s1 = 'A';
    A->value = s1;

    bool session_flag = true;
    while (session_flag) {
        cout << "1. Добавить элемент в множество A" << "\n"
             << "2. Показать множество A" << "\n"
             << "3. Удалить множество A" << "\n"
             << "Ваш выбор: " << endl;
        int userCommand;
        cin >> userCommand;
        switch (userCommand) {
            case 1:
                cout << "Введите значение: ";
                char userElement;
                cin >> userElement;
                addElementInSet(*A, userElement);
                break;
            case 2:
                showSet(*A);
                break;
            case 3:
                cleanMemory(*A);
                session_flag = false;
                break;
            default:
                break;
        }
    }

    return 0;
}