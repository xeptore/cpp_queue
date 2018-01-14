#include <iostream>
using namespace std;

int length;

void fillQueue(int *queue);

void menu(int *queue);

void push(int *&queue);

void pop(int *&queue);

void printFront(int *queue);

void printBack(int *queue);

void printVertically(int *queue);

void printHorizontally(int *queue);

int numLength(int number);

int size(const int *queue);

int main() {
    cout << endl << "How long would queue you want? ";
    cin >> length;
    auto *queue = new int[length];
    cout << endl << "fill the queue (zero to empty and end)" << endl;
    fillQueue(queue);
    menu(queue);
    return 0;
}

void fillQueue(int *queue) {
    for (int i = 0; i <= length; i++) {
        queue[i] = 0;
    }
    int i = 0;
    do {
        cout << "[" << ++i << "]: ";
        cin >> queue[i - 1];
    } while (i < length && queue[i - 1] != 0);
    cout << "--> filled up <--" << endl;
}

void menu(int *queue) {
    while (true) {
        cout << endl << endl;
        cout << "1. push (add to queue)" << endl << "2. pop (remove front element)" << endl;
        cout << "3. front (print first element)" << endl << "4. back (print last element)" << endl;
        cout << "5. print queue vertically" << endl << "6. print queue horizontally" << endl;
        cout << "0. exit" << endl;
        int select;
        cin >> select;
        switch (select) {
            case 1: {
                push(queue);
                break;
            }
            case 2: {
                pop(queue);
                break;
            }
            case 3: {
                printFront(queue);
                break;
            }
            case 4: {
                printBack(queue);
                break;
            }
            case 5: {
                printVertically(queue);
                break;
            }
            case 6: {
                printHorizontally(queue);
                break;
            }
            case 0: {
                exit(0);
            }
            default: {
                cout << "invalid input. try again.";
            }
                cout << endl;
        }
    }
}

void push(int *&queue) {
    if (size(queue) >= length) {
        system("cls");
        cout << "--> queue is full <--";
        return;
    }
    cout << "enter new value: ";
    int value;
    cin >> value;
    queue[size(queue)] = value;
    system("cls");
    cout << endl << "--> " << value << " pushed <--" << endl;
}

void pop(int *&queue) {
    if (queue[0] == 0) {
        cout << "--> queue is empty <--";
        return;
    }
    for (int i = 0; i < size(queue); i++) {
        queue[i] = queue[i + 1];
    }
    queue[size(queue)] = 0;
    system("cls");
    cout << endl << "--> popped <--" << endl;
}

void printFront(int *queue) {
    system("cls");
    cout << endl << "--> " << queue[0] << " <--" << endl;
}

void printBack(int *queue) {
    system("cls");
    cout << endl << "--> " << queue[size(queue) - 1] << " <--" << endl;
}

void printVertically(int *queue) {
    system("cls");
    cout << "--->" << endl;
    for (int i = 0; i < length; i++) {
        cout << "    " << "[" << i + 1 << "]: " << queue[i] << endl;
    }
    cout << "<---";
}

void printHorizontally(int *queue) {
    system("cls");
    cout << char(201);
    for (int i = 1; i <= length; i++) {
        for (int j = 0; j < numLength(queue[i - 1]); j++) {
            cout << char(205);
        }
        if (i == length) {
            cout << char(187);
        } else {
            cout << char(203);
        }
    }
    cout << endl << char(186);
    for (int i = 0; i < length; i++) {
        cout << queue[i] << char(186);
    }
    cout << endl << char(200);
    for (int i = 1; i <= length; i++) {
        for (int j = 0; j < numLength(queue[i - 1]); j++) {
            cout << char(205);
        }
        if (i == length) {
            cout << char(188);
        } else {
            cout << char(202);
        }
    }
}

int size(const int *queue) {
    for (int i = 0; i < length; i++) {
        if (queue[i] == 0) {
            return i;
        }
    }
}

int numLength(int number) {
    int length = 0;
    if (number == 0) {
        return 1;
    }
    while (number) {
        length++;
        number /= 10;
    }
    return length;
}