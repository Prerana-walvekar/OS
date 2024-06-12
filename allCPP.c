1. write a simple c++ program to write a data inside the text file in file handling

#include <iostream>
#include <fstream>

int main() {
    // Create an ofstream object to write to a file
    std::ofstream outFile;

    // Open the file. If the file doesn't exist, it will be created
    outFile.open("example.txt");

    // Check if the file is open
    if (outFile.is_open()) {
        // Write data to the file
        outFile << "Hello, this is a test." << std::endl;
        outFile << "Writing to a file in C++ is simple!" << std::endl;
        outFile << "Let's add some more text." << std::endl;

        // Close the file
        outFile.close();

        std::cout << "Data has been written to the file successfully." << std::endl;
    } else {
        std::cerr << "Unable to open the file for writing." << std::endl;
    }

    return 0;
}
##################################################################################################
2. write a simple c++ program to read the number of characters, words and lines from given text file in file handling

#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Create an ifstream object to read from a file
    std::ifstream inFile("example.txt");

    // Check if the file is open
    if (!inFile.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return 1;
    }

    std::string line;
    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;

    while (std::getline(inFile, line)) {
        lineCount++;
        charCount += line.length();

        // Split the line into words
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            wordCount++;
        }
    }

    // Close the file
    inFile.close();

    // Output the results
    std::cout << "Number of characters: " << charCount << std::endl;
    std::cout << "Number of words: " << wordCount << std::endl;
    std::cout << "Number of lines: " << lineCount << std::endl;

    return 0;
}
###################################################################################################
3. write a simple c++ program to implement linear search using function template
#include <iostream>
using namespace std;

// Function template for linear search
template <typename T>
int linearSearch(T arr[], int size, T key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i; // Return the index of the key if found
        }
    }
    return -1; // Return -1 if the key is not found
}

int main() {
    // Integer array example
    int intArray[] = {1, 2, 3, 4, 5};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    int intKey = 3;
    int intIndex = linearSearch(intArray, intSize, intKey);
    if (intIndex != -1) {
        cout << "Integer key " << intKey << " found at index " << intIndex << endl;
    } else {
        cout << "Integer key " << intKey << " not found" << endl;
    }

    // Double array example
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    double doubleKey = 4.4;
    int doubleIndex = linearSearch(doubleArray, doubleSize, doubleKey);
    if (doubleIndex != -1) {
        cout << "Double key " << doubleKey << " found at index " << doubleIndex << endl;
    } else {
        cout << "Double key " << doubleKey << " not found" << endl;
    }

    // String array example
    string strArray[] = {"apple", "banana", "cherry", "date"};
    int strSize = sizeof(strArray) / sizeof(strArray[0]);
    string strKey = "cherry";
    int strIndex = linearSearch(strArray, strSize, strKey);
    if (strIndex != -1) {
        cout << "String key \"" << strKey << "\" found at index " << strIndex << endl;
    } else {
        cout << "String key \"" << strKey << "\" not found" << endl;
    }

    return 0;
}
###################################################################################################
4. write a simple c++ program to implement stack using class template

#include <iostream>
#include <vector>
#include <stdexcept>

class Stack {
private:
    std::vector<int> elements; // Container to store elements

public:
    // Push element onto the stack
    void push(int element) {
        elements.push_back(element);
    }

    // Remove and return the top element from the stack
    int pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        int element = elements.back();
        elements.pop_back();
        return element;
    }

    // Return the top element of the stack without removing it
    int top() const {
        if (elements.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return elements.back();
    }

    // Check if the stack is empty
    bool empty() const {
        return elements.empty();
    }

    // Return the number of elements in the stack
    size_t size() const {
        return elements.size();
    }
};

int main() {
    // Create a stack
    Stack intStack;

    // Push some elements onto the stack
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    // Print the size of the stack
    std::cout << "Size of stack: " << intStack.size() << std::endl;

    // Pop and print elements from the stack
    while (!intStack.empty()) {
        std::cout << "Top element: " << intStack.top() << std::endl;
        intStack.pop();
    }

    return 0;
}

###############################################################################3

 C++ program for the matrix class using operator overloading

#include "bits/stdc++.h"
#define rows 50
#define cols 50
using namespace std;

int N;

// Class for Matrix operator overloading
class Matrix {

	// For input Matrix
	int arr[rows][cols];

public:
	// Function to take input to arr[][]
	void input(vector<vector<int> >& A);
	void display();

	// Functions for operator overloading
	void operator+(Matrix x);
	void operator-(Matrix x);
	void operator*(Matrix x);
};

// Functions to get input to Matrix
// array arr[][]
void Matrix::input(vector<vector<int> >& A)
{

	// Traverse the vector A[][]
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			arr[i][j] = A[i][j];
		}
	}
}

// Function to display the element
// of Matrix
void Matrix::display()
{

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			// Print the element
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

// Function for addition of two Matrix
// using operator overloading
void Matrix::operator+(Matrix x)
{
	// To store the sum of Matrices
	int mat[N][N];

	// Traverse the Matrix x
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			// Add the corresponding
			// blocks of Matrices
			mat[i][j] = arr[i][j]
						+ x.arr[i][j];
		}
	}

	// Display the sum of Matrices
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			// Print the element
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}
}

// Function for subtraction of two Matrix
// using operator overloading
void Matrix::operator-(Matrix x)
{
	// To store the difference of Matrices
	int mat[N][N];

	// Traverse the Matrix x
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			// Subtract the corresponding
			// blocks of Matrices
			mat[i][j] = arr[i][j]
						- x.arr[i][j];
		}
	}

	// Display the difference of Matrices
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			// Print the element
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}
}

// Function for multiplication of
// two Matrix using operator
// overloading
void Matrix::operator*(Matrix x)
{
	// To store the multiplication
	// of Matrices
	int mat[N][N];

	// Traverse the Matrix x
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			// Initialise current block
			// with value zero
			mat[i][j] = 0;

			for (int k = 0; k < N; k++) {
				mat[i][j] += arr[i][k] * (x.arr[k][j]);
			}
		}
	}

	// Display the multiplication
	// of Matrices
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			// Print the element
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}
}

// Driver Code
int main()
{

	// Dimension of Matrix
	N = 3;

	vector<vector<int> > arr1
		= { { 1, 2, 3 },
			{ 4, 5, 6 },
			{ 1, 2, 3 } };

	vector<vector<int> > arr2
		= { { 1, 2, 3 },
			{ 4, 5, 16 },
			{ 1, 2, 3 } };

	// Declare Matrices
	Matrix mat1, mat2;

	// Take Input to matrix mat1
	mat1.input(arr1);

	// Take Input to matrix mat2
	mat2.input(arr2);

	// For addition of matrix
	cout << "Addition of two given"
		<< " Matrices is : \n";
	mat1 + mat2;

	// For subtraction of matrix
	cout << "Subtraction of two given"
		<< " Matrices is : \n";
	mat1 - mat2;

	// For multiplication of matrix
	cout << "Multiplication of two"
		<< " given Matrices is : \n";
	mat1* mat2;

	return 0;
}

#############################################################################################
write a simple c++ program for complex number class to perform the addition and subtraction of complex objects using + and - operator overloading
#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Overloading + operator for addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Overloading - operator for subtraction
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    // Function to display the complex number
    void display() const {
        std::cout << real << " + " << imaginary << "i";
    }
};

int main() {
    // Create two complex numbers
    Complex num1(2.5, 3.5);
    Complex num2(1.5, 2.5);

    // Perform addition
    Complex sum = num1 + num2;
    std::cout << "Sum: ";
    sum.display();
    std::cout << std::endl;

    // Perform subtraction
    Complex diff = num1 - num2;
    std::cout << "Difference: ";
    diff.display();
    std::cout << std::endl;

    return 0;
}

###############################################################################3

 C++ program for Vehicle 3rd Experiment

#include <iostream>
#include <string>

class Vehicle {
private:
    int numWheels;
    std::string color;
    int maxSpeed;
    int maxGears;
    int curGear;
    int curSpeed;
    bool started;
    bool stopped;

public:
    Vehicle() {
        numWheels = 4;
        color = "Black";
        maxSpeed = 200;
        maxGears = 5;
        curGear = 0;
        curSpeed = 0;
        started = false;
        stopped = true;
    }

    Vehicle(int wheels, std::string clr, int speed, int gears) {
        numWheels = wheels;
        color = clr;
        maxSpeed = speed;
        maxGears = gears;
        curGear = 0;
        curSpeed = 0;
        started = false;
        stopped = true;
    }

    int getWheels() {
        return numWheels;
    }

    int getMaxGears() {
        return maxGears;
    }

    int getMaxSpeed() {
        return maxSpeed;
    }

    void setSpeed(int speed) {
        curSpeed = speed;
    }

    int getSpeed() {
        return curSpeed;
    }

    std::string getColor() {
        return color;
    }

    void start() {
        started = true;
        stopped = false;
    }

    void stop() {
        started = false;
        stopped = true;
    }

    void increaseSpeed() {
        if (curSpeed < maxSpeed)
            curSpeed += 10;
    }

    void decreaseSpeed() {
        if (curSpeed > 0)
            curSpeed -= 10;
    }

    void nextGear() {
        if (curGear < maxGears)
            curGear++;
    }

    void previousGear() {
        if (curGear > 0)
            curGear--;
    }

    void displayStatus() {
        std::cout << "Current Speed: " << curSpeed << " km/h" << std::endl;
        std::cout << "Current Gear: " << curGear << std::endl;
        if (started)
            std::cout << "Vehicle is running." << std::endl;
        else if (stopped)
            std::cout << "Vehicle is stopped." << std::endl;
    }
};

int main() {
    Vehicle car(4, "Red", 250, 6);

    // Direct assignment
    // car.numWheels = 4; // Error: numWheels is private

    // Using set methods
    // car.setSpeed(100);
    // car.start();

    // Displaying member variables using get methods
    std::cout << "Wheels: " << car.getWheels() << std::endl;
    std::cout << "Max Gears: " << car.getMaxGears() << std::endl;
    std::cout << "Max Speed: " << car.getMaxSpeed() << std::endl;
    std::cout << "Color: " << car.getColor() << std::endl;

    // Loop for user interaction
    int choice;
    while (true) {
        std::cout << "Enter choice (1. Increase Speed, 2. Decrease Speed, 3. Next Gear, 4. Previous Gear, 5. Start, 6. Stop, 7. Exit): ";
        std::cin >> choice;
        if (choice == 1) {
            car.increaseSpeed();
        } else if (choice == 2) {
            car.decreaseSpeed();
        } else if (choice == 3) {
            car.nextGear();
        } else if (choice == 4) {
            car.previousGear();
        } else if (choice == 5) {
            car.start();
        } else if (choice == 6) {
            car.stop();
        } else if (choice == 7) {
            break;
        }

        car.displayStatus();
    }

    return 0;
}

###################################################################################################
4. write a simple c++ program to implement stack using class template

#include <iostream>
#include <string>
 
using namespace std;
 
#define SIZE 10

template <class T> class Stack {
public:

    Stack();

    void push(T k);

    T pop();

    T topElement();

    bool isFull();

    bool isEmpty();
 

private:

    int top;

    T st[SIZE];
};

template <class T> Stack<T>::Stack() { top = -1; }
 

template <class T> void Stack<T>::push(T k)
{
    if (isFull()) {

        cout << "Stack is full\n";

    }

    cout << "Inserted element " << k << endl;

    top = top + 1;

    st[top] = k;
}

template <class T> bool Stack<T>::isEmpty()
{

    if (top == -1)

        return 1;

    else

        return 0;
}

template <class T> bool Stack<T>::isFull()
{

    if (top == (SIZE - 1))

        return 1;

    else

        return 0;
}

template <class T> T Stack<T>::pop()
{
    T popped_element = st[top];

    top--;

    return popped_element;
}

template <class T> T Stack<T>::topElement()
{

    T top_element = st[top];

    return top_element;
}

int main()
{
    Stack<int> integer_stack;

    Stack<string> string_stack;
 

    integer_stack.push(2);

    integer_stack.push(54);

    integer_stack.push(255);
 
  string_stack.push("Welcome");

    string_stack.push("to");

    string_stack.push("GeeksforGeeks");
 
    cout << integer_stack.pop() << " is removed from stack"

         << endl;
 
    cout << string_stack.pop() << " is removed from stack "

         << endl;

    cout << "Top element is " << integer_stack.topElement()

         << endl;
 
    cout << "Top element is " << string_stack.topElement()

         << endl;
 

    return 0;
}

###################################################################################################
write a simple c++ program to implement queue using class template

#include<iostream>
#include<cstdlib>  //for exit() function
using namespace std;
#define MAX 4
//const X MAX = 10;
template <class X>
class queue
{
    int front;
    int rear;
public:
    X arr[MAX];
    queue();
    void display();
    void dequeue();
    void enqueue(X x);
    void Front();
    int size();
    int IsEmpty();
};

template <class X>
void queue<X>::display()
{
    cout<<"front="<<front<<" ";
    cout<<"rear="<<rear<<endl;
}

template <class X>
void queue<X>::dequeue()
{
   if(IsEmpty())
   {
       cout<<"UnderFlow\nProgram Terminated\n";
       exit(EXIT_FAILURE);
   }
   arr[front]=NULL;
   front=(front+1)%MAX;
}

template <class X>
void queue<X>::enqueue(X item)
{
    if(size()==MAX-1)
    {
        cout<<"OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    arr[rear]=item;
    rear=(rear+1)% MAX;
}

template <class X>
void queue<X>::Front()
{
    if(IsEmpty()){
       cout<<"UnderFlow\nProgram Terminated\n";
       exit(EXIT_FAILURE);
    }
    cout<<arr[front];
}

template <class X>
queue<X>::queue()
{
    front=0;
    rear=0;
}

template <class X>
int queue<X>::size()
{
    return (MAX-front+rear)%MAX;
}

template <class X>
int queue<X>::IsEmpty()
{
    return front==rear;
}

int main()
{
    queue<const char*>ob;
    ob.enqueue("a");
    ob.display();
    ob.enqueue("b");
    //ob.Front();
    ob.display();
    ob.enqueue("c");
    ob.display();
    ob.dequeue();
    ob.display();
    ob.enqueue("d");
//    enqueue(5);
    ob.display();
    cout<<"size="<<ob.size()<<endl;
    ob.dequeue();
    ob.display();
    ob.dequeue();
    ob.display();
    ob.dequeue();
    ob.display();
    cout<<"IsEmpty="<<ob.IsEmpty();

    return 0;
}

###################################################################################################
write a simple c++ program to implement all constructor

#include <iostream>
using namespace std;

class MyClass {
public:
    // Default constructor
    MyClass() {
        cout << "Default constructor called." << endl;
    }

    // Parameterized constructor
    MyClass(int value) {
        cout << "Parameterized constructor called with value: " << value << endl;
    }

    // Copy constructor
    MyClass(MyClass &source) {
        cout << "Copy constructor called." << endl;
    }
};

int main() {
    // Using default constructor
    cout << "Object 1:" << endl;
    MyClass obj1;

    // Using parameterized constructor
    cout << "Object 2:" << endl;
    MyClass obj2(10);

    // Using copy constructor
    cout << "Object 3:" << endl;
    MyClass obj3(obj2);
    return 0;
}

###################################################################################################
write a simple c++ program to implement person customer employee in inheritance

#include <iostream>
using namespace std;

// Base class: Person
class Person {
public:
    Person(string name) : name(name) {}
    
    virtual void display() const {
        cout << "Name: " << name << endl;
    }
    
protected:
    string name;
};

// Derived class: Customer
class Customer : public Person {
public:
    Customer(string name, string email) : Person(name), email(email) {}
    
    void display() const override {
        cout << "Customer Name: " << name << ", Email: " << email << endl;
    }
    
private:
    string email;
};

// Derived class: Employee
class Employee : public Person {
public:
    Employee(string name, string position) : Person(name), position(position) {}
    
    void display() const override {
        cout << "Employee Name: " << name << ", Position: " << position << endl;
    }
    
private:
    string position;
};

// Main function
int main() {
    Customer customer("John Doe", "johndoe@example.com");
    Employee employee("Jane Smith", "Software Developer");
    
    customer.display();
    employee.display();
    
    return 0;
}

###################################################################################################
write a simple c++ program to implement linked list using class

#include <iostream>
using namespace std;

// Node class to represent a node of the linked list.
class Node {
public:
    int data; // Data field
    Node* next; // Pointer to the next node

    // Default constructor
    Node() : data(0), next(NULL) {}

    // Parameterized constructor
    Node(int data) : data(data), next(NULL) {}
};

// LinkedList class to implement a linked list.
class LinkedList {
private:
    Node* head; // Head of the list

public:
    LinkedList() : head(NULL) {} // Constructor

    // Function to insert a node at the end of the linked list.
    void insertNode(int data) {
        Node* newNode = new Node(data); // Create a new node
        if (head == NULL) {
            head = newNode; // If the list is empty, assign the new node to head
        } else {
            Node* temp = head; // Start from the head
            while (temp->next!= NULL) { // Traverse to the end
                temp = temp->next;
            }
            temp->next = newNode; // Link the new node to the last node
        }
    }

    // Function to delete a node at a given position
    void deleteNode(int nodeOffset) {
        if (head == NULL) {
            cout << "List empty." << endl;
            return;
        }
        if (nodeOffset == 1) { // If the node to be deleted is the head
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp1 = head, *temp2 = NULL;
        int ListLen = 0;
        while (temp1!= NULL) {
            temp1 = temp1->next;
            ListLen++;
            if (ListLen == nodeOffset) {
                break;
            }
        }
        if (ListLen < nodeOffset || temp1 == NULL) {
            cout << "Index out of range" << endl;
            return;
        }
        temp2 = head;
        while (temp2->next!= temp1) {
            temp2 = temp2->next;
        }
        temp2->next = temp1->next;
        delete temp1;
    }

    // Function to print the elements of the linked list.
    void printList() {
        if (head == NULL) {
            cout << "List empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp!= NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Driver code
int main() {
    LinkedList list;
    // Inserting nodes
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    cout << "Elements of the list are: ";
    // Print the list
    list.printList();
    cout << endl;
    // Delete node at position 2.
    list.deleteNode(2);
    return 0;
}
###################################################################################################
#include <iostream>

// Node class represents each element in the linked list
class Node {
public:
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node

    // Constructor to initialize a node with given data
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// LinkedList class manages the linked list
class LinkedList {
private:
    Node* head; // Pointer to the first node in the list

public:
    // Constructor initializes an empty list
    LinkedList() {
        head = nullptr;
    }

    // Destructor to deallocate memory used by the list
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int data) {
        // Create a new node
        Node* newNode = new Node(data);
        
        // If the list is empty, make the new node the head
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Traverse the list to find the last node
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        // Set the next of the last node to the new node
        current->next = newNode;
    }

    // Function to display the elements of the list
    void display() {
        Node* current = head;
        // Traverse the list and print each node's data
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create a linked list object
    LinkedList list;

    // Insert elements into the list
    list.insertAtEnd(5);
    list.insertAtEnd(10);
    list.insertAtEnd(15);

    // Display the list
    std::cout << "Linked List: ";
    list.display();

    return 0;
}

###################################################################################################
write a simple c++ program to implement aggregation

#include <iostream>
using namespace std;

class Wheel {
public:
    void rotate() {
        cout << "Wheel is rotating." << endl;
    }
};

class Car {
private:
    Wheel* Left;
    Wheel* Right;

public:
    Car() : Left(new Wheel()), Right(new Wheel()) {}

    ~Car() {
        delete Left;
        delete Right;
    }

    void drive() {
        cout << "Car is driving." << endl;
        Left->rotate();
        Right->rotate();
    }
};

int main() {
    Car myCar;
    myCar.drive();

    return 0;
}

###################################################################################################
write a simple c++ program to implement composition

#include <iostream>
using namespace std;
class Engine {
public:
    void start() {
        cout << "Engine started." << endl;
    }
};

class Car {
private:
    Engine engine;

public:
    void accelerate() {
        cout << "Car is accelerating." << endl;
        engine.start();
    }
};

int main() {
    Car myCar;
    myCar.accelerate();

    return 0;
}
