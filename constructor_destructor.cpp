/*
1: What is shallow copy and Deep Copy
2: Why the Destructor of Objects is executed in reverse order.

*/
/*
1.
Shallow Copy: A shallow copy creates a new object but copies the references to the original object's data. This means that both the original and the copied object point to the same memory location. Changes made to the data through one object will affect the other object since they share the same data.
2.
The Destructor of Objects is executed in reverse order because when an object of a class is created, the constructor is called first, and when the object goes out of scope or is explicitly deleted, the destructor is called. Since objects are destroyed in the reverse order of their creation, the destructors are also called in reverse order. This ensures that any dependencies or resources held by the objects are properly released in a safe manner.

*/
/*
class Demo {
public:
    int* data;

    Demo(int val) {
        data = new int(val);
    }
};

Demo obj1(10);
Demo obj2 = obj1; 

class Demo {
public:
    int* data;

    Demo(int val) {
        data = new int(val);
    }

    // Deep Copy Constructor
    Demo(const Demo& other) {
        data = new int(*other.data);
    }

    ~Demo() {
        delete data;
    }
};
*/
//2 
#include <iostream>
using namespace std;

class Test {
public:
    Test(int id) { cout << "Constructor " << id << endl; }
    ~Test() { cout << "Destructor called\n"; }
};

int main() {
    Test t1(1);
    Test t2(2);
    Test t3(3);
}