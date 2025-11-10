#include <iostream>
using namespace std;

class Passenger {
public:
    struct Record {
        string name;
        string destTerminal;
        string ticketType;
    };

private:
    Record* arr;
    int size;
    int front;
    int rear;
    int capacity;

public:
    Passenger() {
        capacity = 10;
        arr = new Record[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    Passenger(int cap) {
        capacity = (cap > 0) ? cap : 10;
        arr = new Record[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Passenger() {
        delete[] arr;
    }

    bool is_full() {
        return size == capacity;
    }

    bool is_empty() {
        return size == 0;
    }

    void enqueue( Record& r) {
        if (is_full()) {
            cout << "Queue is full." << endl;
            return;
        }
        arr[++rear] = r;
        size++;
    }

    Record dequeue() {
        if (is_empty()) {
            cout << "No element to dequeue." << endl;
            return{"","",""};
}
        Record r = arr[front++];
        size--;
        if (is_empty()) {
            front = 0;
            rear = -1;
        }
        return r;
    }

    void display() {
        if (is_empty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << "Name: " << arr[i].name
                 << ", Destination Terminal: " << arr[i].destTerminal
                 << ", Ticket Type: " << arr[i].ticketType << endl;
        }
        cout << "Displayed successfully." << endl;
    }
};

int main() {
    Passenger p1;
    Passenger p2(12);

    Passenger::Record r1 = {"Alice", "Terminal 1", "Economy"};
    Passenger::Record r2 = {"Bob", "Terminal 2", "Business"};
    Passenger::Record r3 = {"Charlie", "Terminal 3", "Economy"};
    Passenger::Record r4 = {"Diana", "Terminal 1", "VIP"};

    p1.enqueue(r1);
    p1.enqueue(r2);
    p2.enqueue(r3);
    p2.enqueue(r4);

    Passenger::Record d1 = p1.dequeue();

    if (!d1.name.empty()) 
        cout << "Dequeued from Queue 1: " << d1.name << endl;

    cout << "Queue 1:" << endl;
    p1.display();

    cout << "Queue 2:" << endl;
    p2.display();

    return 0;
}
