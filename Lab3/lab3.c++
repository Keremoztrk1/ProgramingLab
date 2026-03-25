#include <iostream>
#include <string>

using namespace std;

struct Song {
    string title;
    string artist;
    int ratings[3];
    Song* next;
    Song* prev;
};

Song* head = NULL;
Song* tail = NULL;
Song* current = NULL;

void addSong(string t, string a, int r1, int r2, int r3) {
    Song* newSong = new Song;
    newSong->title = t;
    newSong->artist = a;
    newSong->ratings[0] = r1;
    newSong->ratings[1] = r2;
    newSong->ratings[2] = r3;
    newSong->next = NULL;
    newSong->prev = NULL;

    if (head == NULL) {
        head = newSong;
        tail = newSong;
        current = newSong;
    } else {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }
}

void nextSong() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
    }
}

void prevSong() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
    }
}

void removeCurrent() {
    if (current == NULL) return;

    Song* temp = current;

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
        current = current->next;
    } else {
        tail = current->prev;
        current = current->prev;
    }

    delete temp;
}

void display() {
    Song* temp = head;
    while (temp != NULL) {
        if (temp == current) {
            cout << "-> ";
        } else {
            cout << "   ";
        }
        cout << temp->title << " - " << temp->artist << " [";
        for (int i = 0; i < 3; i++) {
            cout << temp->ratings[i] << " ";
        }
        cout << "]" << endl;
        temp = temp->next;
    }
}

int main() {
    addSong("Sarki 1", "Sarkici A", 8, 7, 9);
    addSong("Sarki 2", "Sarkici B", 9, 9, 10);
    addSong("Sarki 3", "Sarkici C", 7, 8, 8);

    display();
    cout << "-----------------\n";

    nextSong();
    display();
    cout << "-----------------\n";

    removeCurrent();
    display();

    return 0;
}
A