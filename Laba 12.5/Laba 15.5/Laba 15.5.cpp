#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    char data;
    Node* next;

    Node(char val) : data(val), next(nullptr) {}
};

void printStack(Node* top) {
    while (top != nullptr) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

void push(Node*& top, char val) {
    Node* newNode = new Node(val);
    newNode->next = top;
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) {
        cerr << "Stack is empty." << endl;
        return '\0';
    }
    char val = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return val;
}

void sortStack(Node*& top) {
    Node* aux = nullptr;

    while (top != nullptr) {
        char temp = pop(top);
        while (aux != nullptr && aux->data > temp) {
            push(top, pop(aux));
        }
        push(aux, temp);
    }

    while (aux != nullptr) {
        push(top, pop(aux));
    }
}

void readFromFile(Node*& top, const string& filename) {
    ifstream file(filename);

    if (file.is_open()) {
        char inputChar;
        while (file.get(inputChar)) {
            if (inputChar != '\n')
                push(top, inputChar);
        }
        file.close();
    }
    else {
        cerr << "Unable to open file." << endl;
    }
}

int main() {
    Node* unsortedStack = nullptr;
    char inputChar;
    string filename;

    cout << "Enter the filename: ";
    cin >> filename;

    readFromFile(unsortedStack, filename);

    cout << "Unsorted Stack: ";
    printStack(unsortedStack);

    sortStack(unsortedStack);

    cout << "Sorted Stack: ";
    printStack(unsortedStack);


    cout << "Enter characters (enter '#' to stop): ";
    while ((inputChar = cin.get()) != '#') {
        if (inputChar != '\n')
            push(unsortedStack, inputChar);
    }

    cout << "Unsorted Stack: ";
    printStack(unsortedStack);

    sortStack(unsortedStack);

    cout << "Sorted Stack: ";
    printStack(unsortedStack);

    // Free memory
    while (unsortedStack != nullptr) {
        pop(unsortedStack);
    }

    return 0;
}
