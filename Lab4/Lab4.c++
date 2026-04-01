#include <iostream>
#include <string>

using namespace std;

struct Package {
    string packageID;
    string destinationCity;
    int dimensions[3];
    Package* next;
};

struct Courier {
    string courierName;
    string vehicleType;
};

struct PackageStack {
    Package* top;
    
    PackageStack() {
        top = nullptr;
    }
    
    void push(string id, string city, int l, int w, int h) {
        Package* newPackage = new Package();
        newPackage->packageID = id;
        newPackage->destinationCity = city;
        newPackage->dimensions[0] = l;
        newPackage->dimensions[1] = w;
        newPackage->dimensions[2] = h;
        newPackage->next = top;
        top = newPackage;
    }
};

struct CourierQueue {
    Courier couriers[5];
    int front;
    int rear;
    
    CourierQueue() {
        front = -1;
        rear = -1;
    }
    
    void enqueue(string name, string type) {
        if ((rear + 1) % 5 == front) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % 5;
        couriers[rear].courierName = name;
        couriers[rear].vehicleType = type;
    }
};

void dispatch(PackageStack& stack, CourierQueue& queue) {
    if (stack.top == nullptr || queue.front == -1) {
        cout << "Cannot dispatch\n";
        return;
    }
    
    Package* p = stack.top;
    stack.top = stack.top->next;
    
    cout << queue.couriers[queue.front].courierName << " - " << p->packageID << "\n";
    
    if (queue.front == queue.rear) {
        queue.front = -1;
        queue.rear = -1;
    } else {
        queue.front = (queue.front + 1) % 5;
    }
}

void display(PackageStack& stack, CourierQueue& queue) {
    Package* tempStack = stack.top;
    cout << "Packages:\n";
    while (tempStack != nullptr) {
        cout << tempStack->packageID << " " << tempStack->destinationCity << "\n";
        tempStack = tempStack->next;
    }
    
    cout << "Couriers:\n";
    if (queue.front != -1) {
        int i = queue.front;
        while (true) {
            cout << queue.couriers[i].courierName << " " << queue.couriers[i].vehicleType << "\n";
            if (i == queue.rear) {
                break;
            }
            i = (i + 1) % 5;
        }
    }
}

int main() {
    PackageStack s;
    CourierQueue q;
    
    s.push("P100", "Istanbul", 10, 5, 5);
    s.push("P101", "Ankara", 20, 10, 10);
    
    q.enqueue("Ahmet", "Motorcycle");
    q.enqueue("Mehmet", "Van");
    
    display(s, q);
    cout << "\n";
    
    dispatch(s, q);
    cout << "\n";
    
    display(s, q);
    
    return 0;
}