/*
3 Programming Challenges with Classes:
1. Bank Customer Class:
Challenge: Design a Customer class for a bank system that manages customer information and basic operations.
Attributes:
name: String containing the customer's full name.
accountNumber: Unique integer identifying the customer's account.
accountBalance: Double representing the current balance in the account.
isActive: Boolean indicating whether the account is active.
Methods:
deposit(amount): Adds the specified amount to the account balance.
withdraw(amount): Deducts the specified amount from the account balance (check for sufficient funds).
transfer(amount, targetAccount): Transfers the specified amount to another customer's account (within the system).
printDetails(): Prints the customer's name, account number, and current balance.
2. Car Class:
Challenge: Create a Car class that simulates the behavior of a vehicle.
Attributes:
model: String representing the car model name.
year: Integer indicating the car's manufacturing year.
fuelLevel: Double representing the remaining fuel quantity (percentage or liters).
speed: Integer representing the current speed in kilometers per hour.
isRunning: Boolean indicating whether the car is currently running.
Methods:
startEngine(): Sets isRunning to true and prints a starting message.
stopEngine(): Sets isRunning to false and prints a stopping message.
accelerate(amount): Increases the car's speed by the specified amount (check engine state and fuel level).
brake(amount): Decreases the car's speed by the specified amount (ensure speed doesn't become negative).
refuel(amount): Increases the fuel level by the specified amount (check for tank capacity).
printStatus(): Displays the car's model, speed, fuel level, and running state.
3. Laptop Class:
Challenge: Design a Laptop class that represents a portable computer system.
Attributes:
brand: String representing the laptop brand and model.
screenSize: Double indicating the screen size in inches.
processor: String specifying the processor type and speed.
ram: Integer representing the available RAM capacity in gigabytes.
storage: Integer representing the storage capacity in gigabytes.
batteryLevel: Double showing the remaining battery percentage.
isOn: Boolean indicating whether the laptop is currently powered on.
Methods:
powerOn(): Sets isOn to true and prints a startup message.
powerOff(): Sets isOn to false and prints a shutdown message.
openApps(numApps): Simulates opening a specified number of applications, potentially impacting battery life.
closeApps(numApps): Simulates closing applications, restoring battery life.
charge(amount): Increases the battery level by the specified amount (check for maximum capacity).
printSpecs(): Displays the laptop's brand, screen size, processor, RAM, storage, and battery level.

*/
// Bank Customer Class

#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    string name;
    int accountNumber;
    double accountBalance;
    bool isActive;

public:
    Customer(string name, int accountNumber, double balance, bool isActive = true) {
        this->name = name;
        this->accountNumber = accountNumber;
        this->accountBalance = balance;
        this->isActive = isActive;
    }

    void deposit(double amount) {
        if (!isActive) {
            cout << "Account is inactive\n";
            return;
        }
        if (amount <= 0) {
            cout << "Invalid deposit amount\n";
            return;
        }
        accountBalance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (!isActive) {
            cout << "Account is inactive\n";
            return;
        }
        if (amount <= 0) {
            cout << "Invalid withdrawal amount\n";
            return;
        }
        if (amount > accountBalance) {
            cout << "Insufficient funds\n";
            return;
        }
        accountBalance -= amount;
        cout << "Withdrawn: " << amount << endl;
    }

    void transfer(double amount, Customer &targetAccount) {
        if (this == &targetAccount) {
            cout << "Cannot transfer to same account\n";
            return;
        }
        if (!isActive || !targetAccount.isActive) {
            cout << "One of the accounts is inactive\n";
            return;
        }
        if (amount <= 0 || amount > accountBalance) {
            cout << "Invalid or insufficient funds\n";
            return;
        }

        accountBalance -= amount;
        targetAccount.accountBalance += amount;

        cout << "Transferred " << amount 
             << " to " << targetAccount.name << endl;
    }

    void printDetails() const {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << accountBalance << endl;
        cout << "Status: " << (isActive ? "Active" : "Inactive") << endl;
    }
};

// Car Class
class Car {
private:
string model;
int year;
double fuelLevel;
int speed;
bool isRunning;
double maxFuel = 50.0;
public:
Car (string m, int y) {
    model = m;
    year = y;
    fuelLevel = 10;
    speed =0;
    isRunning = false;
}
void startEngine() {
    if(fuelLevel <= 0) {
        cout << "No fuel" << endl;
        return;
    }
    isRunning = true;
    cout << "Engine start" << endl;
}
void stopEngine() {
    isRunning = false;
    cout << "Engine stop" << endl;
}
void acceLerate(int amount) {
    if (!isRunning) {
        cout << "Engine off" << endl;
        return;
    }
    if (fuelLevel <= 0) {
        cout << "No fuel" << endl;
        return;
    }
    speed += amount;
    fuelLevel -= amount * 0.05;
    if (fuelLevel < 0) fuelLevel = 0;
}
void brake(int amount) {
    speed -= amount;
    if (speed < 0) speed = 0;
}
void refuel (int amount) {
    fuelLevel += amount;
    if (fuelLevel > maxFuel) fuelLevel = maxFuel;
}
void printStatus() {
    cout << "Model " << model << endl;
    cout << "Year" << year << endl;
    cout << "Fuel Level " << fuelLevel << endl;
    cout << "Speed" << speed << endl;
    cout << "Running " << (isRunning ? "Yes" : "No") << endl;
}
};

// Laptop class
class Laptop {
    private:
    string brand;
    double screenSize;
    string processor;
    int ram;
    int storage;
    double batteryLevel;
    bool isOn;
    public:
    Laptop(string b, double s, string p, int r, int st) {
        brand = b;
        screenSize = s;
        processor = p;
        ram = r;
        storage = st;
        batteryLevel = 100;
        isOn = false;
    }
    void powerOn() {
       if(batteryLevel <= 0) {
        cout << "Battery dead" << endl;
        return;
       }
       isOn = true;
       cout << "Laptop on" << endl;
     }
     void powerOff() {
        isOn = false;
        cout << "Laptop off" << endl;
     }
     void openApps(int numApps) {
        if (!isOn) {
            cout << "Laptop off" << endl;
            return;
        }
        batteryLevel -= numApps * 2;
        if (batteryLevel < 0) batteryLevel = 0;
     }
     void closeApps(int numApps) {
       batteryLevel += numApps * 2;
       if (batteryLevel > 100) batteryLevel = 100;
        }
        void charge(int amount) {
            batteryLevel += amount;
            if(batteryLevel > 100) batteryLevel = 100;
        }
         void printSpecs() {
        cout << "Brand: " << brand << endl;
        cout << "Screen: " << screenSize << " inches\n";
        cout << "Processor: " << processor << endl;
        cout << "RAM: " << ram << " GB\n";
        cout << "Storage: " << storage << " GB\n";
        cout << "Battery: " << batteryLevel << "%\n";
    }
};