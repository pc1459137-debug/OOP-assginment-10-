#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// ---------------------------------------------------------------
// FUNCTION TEMPLATES
// ---------------------------------------------------------------

// Returns the larger of two values of the same type
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// Swaps two values of any type
template <typename T>
void swapValues(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Sorts an array in ascending order (bubble sort)
template <typename T>
void sortArray(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swapValues(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Prints all elements of an array
template <typename T>
void printArray(const T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << (i < n - 1 ? ", " : "");
    cout << '\n';
}

// ---------------------------------------------------------------
// CLASS TEMPLATES
// ---------------------------------------------------------------

// Fixed-size stack that works with any data type
template <typename T>
class Stack {
private:
    T *data;
    int capacity;
    int topIndex;

public:
    explicit Stack(int size = 5) : data(nullptr), capacity(size), topIndex(-1) {
        if (size <= 0)
            throw invalid_argument("Stack size must be positive.");
        data = new T[capacity];
    }

    ~Stack() { delete[] data; }

    // Prevent shallow copies (data is a raw pointer)
    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;

    bool isEmpty() const { return topIndex == -1; }
    bool isFull() const { return topIndex == capacity - 1; }
    int size() const { return topIndex + 1; }

    void push(const T &value) {
        if (isFull())
            throw overflow_error("Stack overflow: cannot push.");
        data[++topIndex] = value;
    }

    T pop() {
        if (isEmpty())
            throw underflow_error("Stack underflow: cannot pop.");
        return data[topIndex--];
    }

    T peek() const {
        if (isEmpty())
            throw underflow_error("Stack is empty: nothing to peek.");
        return data[topIndex];
    }
};

// Holds two values of (possibly) different types
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(T1 f, T2 s) : first(f), second(s) {}
    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }
    void display() const {
        cout << "(" << first << ", " << second << ")\n";
    }
};

// ---------------------------------------------------------------
// MAIN
// ---------------------------------------------------------------
int main() {
    cout << "===== FUNCTION TEMPLATES =====\n";
    cout << "findMax(10, 25) = " << findMax(10, 25) << '\n';
    cout << "findMax(3.5, 2.1) = " << findMax(3.5, 2.1) << '\n';
    cout << "findMax('a', 'z') = " << findMax('a', 'z') << '\n';
    cout << "findMax<string>(\"apple\", \"mango\") = "
         << findMax<string>("apple", "mango") << '\n';

    int x = 5, y = 9;
    swapValues(x, y);
    cout << "\nAfter swapValues: x = " << x << ", y = " << y << '\n';

    string s1 = "Hello", s2 = "World";
    swapValues(s1, s2);
    cout << "After swapValues: s1 = " << s1 << ", s2 = " << s2 << '\n';

    int iarr[] = {42, 7, 19, 3, 88};
    double darr[] = {2.5, 9.1, 0.4, 5.5};

    cout << "\nInt array before sort: ";
    printArray(iarr, 5);
    sortArray(iarr, 5);
    cout << "Int array after sort: ";
    printArray(iarr, 5);

    cout << "Double array before sort: ";
    printArray(darr, 4);
    sortArray(darr, 4);
    cout << "Double array after sort: ";
    printArray(darr, 4);

    cout << "\n===== CLASS TEMPLATES =====\n";

    // Stack<int>
    try {
        Stack<int> intStack(3);
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        cout << "Stack<int> size = " << intStack.size()
             << ", top = " << intStack.peek() << '\n';
        cout << "Popped: " << intStack.pop() << '\n';
        cout << "Popped: " << intStack.pop() << '\n';
        intStack.push(40);
        intStack.push(50);
        intStack.push(60);  // exceeds capacity -> overflow
    } catch (const overflow_error &e) {
        cout << "Exception caught: " << e.what() << '\n';
    }

    // Stack<string>
    try {
        Stack<string> strStack(2);
        strStack.push("first");
        strStack.push("second");
        cout << "\nStack<string> popped: " << strStack.pop() << '\n';
        cout << "Stack<string> popped: " << strStack.pop() << '\n';
        strStack.pop();  // empty -> underflow
    } catch (const underflow_error &e) {
        cout << "Exception caught: " << e.what() << '\n';
    }

    // Invalid size
    try {
        Stack<double> bad(0);
    } catch (const invalid_argument &e) {
        cout << "Exception caught: " << e.what() << '\n';
    }

    // Pair with different types
    cout << "\nPair examples:\n";
    Pair<int, string> p1(101, "Alice");
    Pair<string, double> p2("Pi", 3.14159);
    p1.display();
    p2.display();

    return 0;
}
