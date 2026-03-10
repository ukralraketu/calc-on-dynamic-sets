#include <iostream>
#include <windows.h>

using namespace std;

int LEFT_BORDER_SET = 'A';
int RIGHT_BORDER_SET = 'Z';

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
    /**/ cout << "Хуй" << endl;
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

auto takeUserSet() {
    cout << "Введите название множества (A-Z): ";
    char userSet;
    cin >> userSet;
    if (int(userSet) < LEFT_BORDER_SET || int(userSet) > RIGHT_BORDER_SET) {
        cout << "Недопустимое имя множества" << endl;
        return char(0);
    }
    return userSet;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Elem* setList[26] = {nullptr};

    bool session_flag = true;
    while (session_flag) {
        cout << "1. Cоздать множество" << "\n"
             << "2. Добавить элемент в множество A" << "\n"
             << "3. Показать множество A" << "\n"
             << "4. Удалить множество A" << "\n"
             << "0. Выход" << "\n"
             << "Ваш выбор: " << endl;
        int userCommand;
        cin >> userCommand;
        if (userCommand == 0) {
            session_flag = false;
            continue;
        }
        char userSet = takeUserSet();
        if (userSet == char(0)) {
                continue;;
        }
        int setpos = int(userSet) - LEFT_BORDER_SET;
        switch (userCommand) {
            case 1: {
                if (setList[setpos] != nullptr) {
                    cout << "Такое множество уже существует" << endl;
                    break;
                }
                Elem* newSet = new Elem();
                newSet->value = userSet;
                setList[setpos] = newSet;
                break;
            }
            case 2: {
                cout << "Введите значение: ";
                char userElement;
                cin >> userElement;
                addElementInSet(*setList[setpos], userElement);
                break;
            }
            case 3: {
                showSet(*setList[setpos]);
                break;
            }
            case 4: {
                cleanMemory(*setList[setpos]);
                setList[setpos] = nullptr;
                break;
            }
            default: {
                break;
            }
        }
    }

    for (size_t i = 0; i < 26; i++) {
        if (setList[i] != nullptr) {
            cleanMemory(*setList[i]);
            cout << "Атоматическое освобождение памяти для множества: " << char(LEFT_BORDER_SET + i) << endl;
        }
    }
    return 0;
}