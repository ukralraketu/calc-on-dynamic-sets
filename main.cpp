#include <iostream>

using namespace std;

class Elem {
public:
    Elem* pointer = nullptr;
    char value;
};


int main() {
    Elem* A = new Elem();
    Elem* tracker = A;

    char s1 = 'a';
    A->value = s1;

    for (size_t i = 0; i < 5; i++) {
        Elem* EL = new Elem();
        (*tracker).pointer = EL;
        tracker = EL;
        EL->value = char(98 + i);
    }
    tracker = A;
    while ((*tracker).pointer != nullptr) {
        cout << (*tracker).value << endl;
        tracker = (*tracker).pointer;
    }

    Elem* cleaner = A;
    while (cleaner != nullptr) {
        Elem* next = cleaner->pointer;
        delete cleaner;
        cleaner = next;
    }

    return 0;
}