#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>//to clear input buffer safely.
using namespace std;

int getIntInput(string prompt);
double getDoubleInput(string prompt);
void createOrder();
void cancelOrder();
void updateStatus();
void displayOrders();
void sortByPrice();

class Order {//creating a class for our orders.
public:
    int orderID;//member variables
    string itemName;
    double price;
    string status;

    Order(int id, string item, double p) {//constructor
        orderID = id;
        itemName = item;
        price = p;
        status = "Created";
    }
};

//globally declared variables
vector<Order> orderList;//stores all orders
unordered_map<int, int> orderIndex; //stores orderID to index mapping for quick access

int main() {
    int choice;

    do {
        cout << "\n1. Create Order";
        cout << "\n2. Cancel Order";
        cout << "\n3. Update Order Status";
        cout << "\n4. Display Orders";
        cout << "\n5. Sort Orders by Price";
        cout << "\n6. Exit";
        choice = getIntInput("Enter choice: ");

       

        switch (choice) {
            case 1: createOrder(); break;
            case 2: cancelOrder(); break;
            case 3: updateStatus(); break;
            case 4: displayOrders(); break;
            case 5: sortByPrice(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

int getIntInput(string prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if(cin.fail()) { // input failed (not an integer)
            cin.clear(); // clear the buffer fail state.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // remove invalid input from buffer
            cout << "Invalid input! Please enter a number.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // remove leftover newline
            return value;
        }
    }
}

double getDoubleInput(string prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if(cin.fail()) { // input failed (not a double)
            cin.clear(); // clear the buffer.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // remove invalid input
            cout << "Invalid input! Please enter a valid number.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // remove leftover newline
            return value;
        }
    }
}

void createOrder() {//function to create a new order
    int id;
    string item;
    double price;

    id = getIntInput("Enter Order ID: ");//using this new function and not cin directly to avoid any errors.

    if (orderIndex.find(id) != orderIndex.end()) {//finding if id already exists(if id dosen't exists,find function gives end() that is one past the last element)
        cout << "Order ID already exists. Please use a unique ID.\n";
        return;
    }
    cout << "Enter Item Name: ";
    getline(cin, item);

    price = getDoubleInput("Enter Price: ");//same like before, not using cin directly to avoid errors.

    if(price < 0) {
    cout << "Price cannot be negative!\n";
    return;
}


    orderList.push_back(Order(id, item, price));//adding new order to the list
    orderIndex[id] = orderList.size() - 1;//mapping orderID to its index in orderList

    cout << "Order added successfully!\n";
}


void cancelOrder() {
    int id;
    id = getIntInput("Enter Order ID to cancel:");

    if (orderIndex.find(id) == orderIndex.end()) {//checking if order exists
        cout << "Order not found!\n";
        return;
    }

    int index = orderIndex[id];//taking the index of id from our map
    orderList[index].status = "Cancelled";//updating status to cancelled
    cout << "Order cancelled.\n";
}

void updateStatus() {
    int id;
    string newStatus;

    id = getIntInput("Enter Order ID: ");
    

    if (orderIndex.find(id) == orderIndex.end()) {//checking if order exists
        cout << "Order not found!\n";
        return;
    }

    cout << "Enter new status (Shipped/Delivered): ";
    cin >> newStatus;
    transform(newStatus.begin(), newStatus.end(), newStatus.begin(), ::tolower);
    newStatus[0] = toupper(newStatus[0]);

    if(newStatus != "Shipped" && newStatus != "Delivered") {
    cout << "Invalid status!\n";
    return;
}

    orderList[orderIndex[id]].status = newStatus;//updating status
    cout << "Status updated.\n";
}

void displayOrders() {
    if (orderList.empty()) {//checking if there are any orders
        cout << "No orders to display.\n";
        return;
    }

    cout << "\n--- All Orders ---\n";
    for (auto &o : orderList) {
        cout << "ID: " << o.orderID
             << " | Item: " << o.itemName
             << " | Price: " << o.price
             << " | Status: " << o.status << endl;
    }
}

void sortByPrice() {
    sort(orderList.begin(), orderList.end(), [](Order &a, Order &b) {
        return a.price < b.price;//a simple unnamed lambda function to compare prices if true then don't swap(correct order) if false then swap(wrong order).
    });//here a simple sort function can't be used because orderList has orders in it which is a object and sort doesn't  which member to use for sorting. 
//whole orderList is changed according to price in ascending order and so the indexes also are changed.
//therefore now we need to make oderIndex map again according to new indexes.  
orderIndex.clear();
    for (int i = 0; i < orderList.size(); i++) {
        orderIndex[orderList[i].orderID] = i;
    }

    cout << "Orders sorted by price.\n";
}
