# Order Management System (C++)

This is a simple **console-based Order Management System** built using C++.  
The project focuses on using STL containers, handling user input safely, and writing clean, understandable code.

---

## Features

- Create new orders with unique Order IDs  
- Cancel existing orders  
- Update order status (Shipped / Delivered)  
- Display all orders  
- Sort orders by price in ascending order  
- Handles multi-word item names  
- Prevents crashes due to invalid user input  

---

## Technologies Used

- C++
- STL Containers:
  - `vector` for storing orders
  - `unordered_map` for fast lookup using Order ID
- STL Algorithms:
  - `sort()` with lambda function
- Input handling using `cin`, `getline`, and `numeric_limits`

---

## How It Works

- Each order is represented using an `Order` class.
- Orders are stored in a vector for dynamic storage.
- An unordered_map stores the mapping between `orderID` and its index in the vector for quick access.
- Custom input functions are used to safely handle invalid integer and double inputs.
- Orders can be sorted by price using `std::sort` and a lambda comparator.
- After sorting, the index map is rebuilt to keep data consistent.

---

## Menu Options

1. Create Order
2. Cancel Order
3. Update Order Status
4. Display Orders
5. Sort Orders by Price
6. Exit
   
---

## Input Validation

- Prevents non-numeric input for integers and prices
- Ensures price is not negative
- Ensures Order IDs are unique
- Validates order status input

---

## How to Run

1. Compile the program:
(bash g++ order_management.cpp -o order_management)
2. Run the executable:
   (./order_management)
   
---

## Learning Outcomes

---

- Gained hands-on experience with C++ and STL containers  
- Learned to use unordered_map for fast data lookup  
- Implemented sorting using std::sort with a lambda expression  
- Improved understanding of input validation and buffer handling  
- Worked on handling real-world edge cases in console applications  
- Practiced writing clean, structured, and readable code
  
---

## What I Learned

---

- How to use STL containers like vector and unordered_map effectively  
- Implementing custom sorting using std::sort and lambda functions  
- Handling invalid user input safely to avoid program crashes  
- Maintaining data consistency after sorting operations  
- Writing cleaner and more structured C++ code  






