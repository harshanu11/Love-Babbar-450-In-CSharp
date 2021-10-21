/*
    link(java): https://www.tutorialspoint.com/javaexamples/data_stack.htm

    link(cpp): https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
*/

#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
// ----------------------------------------------------------------------------------------------------------------------- //
using namespace std;
#define MAXStack 1000
class StackNode {
    

public:
    int top;
    int a[MAXStack]; // Maximum size of Stack
    StackNode() { top = -1; }

    bool push(int x)
    {
        if (top >= (MAXStack - 1)) {
            cout << "Stack Overflow";
            return false;
        }
        else {
            a[++top] = x;
            cout << x << " pushed into stack\n";
            return true;
        }
    }

    int pop()
    {
        if (top < 0) {
            cout << "Stack Underflow";
            return 0;
        }
        else {
            int x = a[top--];
            return x;
        }
    }
    int peek()
    {
        if (top < 0) {
            cout << "Stack is Empty";
            return 0;
        }
        else {
            int x = a[top];
            return x;
        }
    }

    bool isEmpty()
    {
        return (top < 0);
    }
};

TEST_CLASS(StackQueue)
{
public:
    class StackNode s;


    TEST_METHOD(StackQueueTest)
    {
        s =  StackNode();
        
        s.push(10);
        s.push(20);
        s.push(30);
        cout << s.pop() << " Popped from stack\n";
        //print all elements in stack :
        cout << "Elements present in stack : ";
        while (!s.isEmpty())
        {
            // print top element in stack
            cout << s.peek() << " ";
            // remove top element in stack
            s.pop();
        }

    }

   
};

