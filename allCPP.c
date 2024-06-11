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
