#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* head = NULL;

void addWord(string w) {
    Node* n = new Node();
    n->data = w;
    n->next = NULL;

    if (head == NULL) {
        head = n;
    } else {
        Node* t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = n;
    }
}

void undo() {
    if (head == NULL) {
        return;
    }
    
    if (head->next == NULL) {
        head = NULL;
    } else {
        Node* t = head;
        while (t->next->next != NULL) {
            t = t->next;
        }
        t->next = NULL;
    }
}

void display() {
    Node* t = head;
    while (t != NULL) {
        cout << "[" << t->data << "] -> ";
        t = t->next;
    }
    cout << "NULL\n";
}

int main() {
    string str;
    
    while (1) {
        cin >> str;
        
        if (str == "EXIT") {
            break;
        }
        if (str == "UNDO") {
            undo();
        } else {
            addWord(str);
        }
        
        display();
    }
}