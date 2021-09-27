using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace _10_stack_and_queues
{
    /*
    link(java): https://www.tutorialspoint.com/javaexamples/data_stack.htm

    link(cpp): https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
    */
    public class _01_implement_stack_from_scratch
    {
        [Fact]
        public void reverse_arrayTest()
        {
            StackWtihArray stackWtihArray = new StackWtihArray(5);
            stackWtihArray.push(5);
            stackWtihArray.push(8);
            stackWtihArray.push(2);
            stackWtihArray.push(9);
            stackWtihArray.pop();

            StackUsingArrayList stkArrayLst = new StackUsingArrayList();

            stkArrayLst.push(5);
            stkArrayLst.push(8);
            stkArrayLst.push(2);
            stkArrayLst.push(9);
            stkArrayLst.pop();


            StackUsingList stkList = new StackUsingList();

            stkList.push(5);
            stkList.push(8);
            stkList.push(2);
            stkList.push(9);
            stkList.pop();



        }
    }
    class StackWtihArray
    {
        private int[] ele;
        private int top;
        private int max;
        public StackWtihArray(int size)
        {
            ele = new int[size]; // Maximum size of Stack
            top = -1;
            max = size;
        }

        public void push(int item)
        {
            // Debug.WriteLine("Stack Overflow");
            if (top == max - 1) return;
            else ele[++top] = item;
        }

        public int pop()
        {
            //Debug.WriteLine("Stack is Empty");
            if (top == -1) return -1;
            // Debug.WriteLine("{0} popped from stack ", ele[top]);
            else return ele[top--];
        }

        public int peek()
        {
            //Debug.WriteLine("Stack is Empty");
            if (top == -1) return -1;
            //Debug.WriteLine("{0} popped from stack ", ele[top]);
            else return ele[top];
        }

        public void printStack()
        {
            Debug.WriteLine("Stack is Empty");
            if (top == -1) return;
            else
                for (int i = 0; i <= top; i++)
                {
                    Debug.WriteLine("{0} pushed into stack", ele[i]);
                }
        }
    }
    public class FixedMultiStack
    {
        private int numberOfStacks = 3;
        private int stackCapacity;
        private int[] values;
        private int[] sizes;
        public FixedMultiStack(int stackSize)
        {
            stackCapacity = stackSize;
            values = new int[stackSize * numberOfStacks];
            sizes = new int[numberOfStacks];
        }
        public void push(int stackNum, int value)
        {
            /* Check that we have space fo r the next element */
            if (isFull(stackNum))
            {
                throw new System.StackOverflowException();
                //ackingTheCodinglnterview.com | 6t h Edition 227 Solutions to Chapter 3 j Stacks and Queues
            }
            sizes[stackNum]++;
            values[indexOfTop(stackNum)] = value;
        }
        /* Pop item from top stack. */
        public int pop(int stackNum)
        {
            if (isEmpty(stackNum))
            {
                throw new System.Exception("Stack empty");
            }
            int topindex = indexOfTop(stackNum);
            int value = values[topindex]; // Get top 
            values[topindex] = 0; // Clear 
            sizes[stackNum]--; // Shrink 
            return value;
        }

        /* Return top element. */
        public int peek(int stackNum)
        {
            if (isEmpty(stackNum))
            {
                throw new System.Exception("Stack empty");
            }
            return values[indexOfTop(stackNum)];
        }
        public bool isEmpty(int stackNum)
        {
            return sizes[stackNum] == 0;
        }
        public bool isFull(int stackNum)
        {
            return sizes[stackNum] == stackCapacity;
        }
        /* Returns index of the top of the stack. */
        private int indexOfTop(int stackNum)
        {
            int offset = stackNum + stackCapacity;
            int size = sizes[stackNum];
            return offset + size - 1;
        }
    }
    /// <summary>
    /// Design a stack that supports getMin() in O(1) time and O(1) extra space
    /// </summary>
    public class MyMinStack
    {
        public Stack s;
        public int minEle;

        // Constructor
        public MyMinStack()
        {
            s = new Stack();
        }
        public void getMin()
        {
            if (s.Count == 0)
                Debug.WriteLine("Stack is empty");
            else
                Debug.WriteLine("Minimum Element in the " +
                                " stack is: " + minEle);
        }
        public void Peek()
        {
            if (s.Count == 0)
            {
                Debug.WriteLine("Stack is empty ");
                return;
            }
            int t = (int)s.Peek();
            Debug.Write("Top Most Element is: ");
            if (t < minEle)
                Debug.WriteLine(minEle);
            else
                Debug.WriteLine(t);
        }
        public void Pop()
        {
            if (s.Count == 0)
            {
                Debug.WriteLine("Stack is empty");
                return;
            }

            Debug.Write("Top Most Element Removed: ");
            int t = (int)s.Pop();
            if (t < minEle)
            {
                Debug.WriteLine(minEle);
                minEle = 2 * minEle - t;
            }

            else
                Debug.WriteLine(t);
        }
        public void Push(int x)
        {
            if (s.Count == 0)
            {
                minEle = x;
                s.Push(x);
                Debug.WriteLine("Number Inserted: " + x);
                return;
            }
            if (x < minEle)
            {
                s.Push(2 * x - minEle);
                minEle = x;
            }

            else
                s.Push(x);

            Debug.WriteLine("Number Inserted: " + x);
        }
    }

    /// <summary>
    /// Design a stack that returns a minimum element without using an auxiliary stack
    /// </summary>
    public class MinStack
    {
        // main stack to store elements
        private Stack<int> s = new Stack<int>();

        // variable to store the minimum element
        //JAVA TO C# CONVERTER NOTE: Fields cannot have the same name as methods of the current type:
        private int min_Conflict;

        // Inserts a given element on top of the stack
        public virtual void push(int x)
        {
            if (s.Count == 0)
            {
                s.Push(x);
                min_Conflict = x;
            }
            else if (x > min_Conflict)
            {
                s.Push(x);
            }
            else
            {
                s.Push(2 * x - min_Conflict);
                min_Conflict = x;
            }
        }

        // Removes the top element from the stack and returns it
        public virtual void pop()
        {
            if (s.Count == 0)
            {
                Debug.WriteLine("Stack underflow!!");
            }

            int top = s.Peek();
            if (top < min_Conflict)
            {
                min_Conflict = 2 * min_Conflict - top;
            }
            s.Pop();
        }

        // Returns the minimum element from the stack in constant time
        public virtual int min()
        {
            return min_Conflict;
        }
    }

    public class StackUsingArrayList
    {
        internal ArrayList stackList;
        internal StackUsingArrayList() => stackList = new ArrayList();
        internal virtual void push(int value) => stackList.Add(value);
        internal virtual int pop()
        {

            if (!Empty)
            { // checks for an empty Stack
                int popValue = Convert.ToInt32(stackList[stackList.Count - 1]);
                stackList.RemoveAt(stackList.Count - 1); // removes the poped element
                return popValue;
            }
            else
            {
                Debug.Write("The stack is already empty  ");
                return -1;
            }
        }
        internal virtual bool Empty
        {
            get
            {
                if (stackList.Count == 0) return true;
                else return false;
            }
        }
        internal virtual int peek()
        {
            return Convert.ToInt32(stackList[stackList.Count - 1]);
        }
    }
    public class StackUsingList
    {
        internal List<int> stackList;
        internal StackUsingList() => stackList = new List<int>();
        internal virtual void push(int value) => stackList.Add(value);
        internal virtual int pop()
        {

            if (!Empty)
            { // checks for an empty Stack
                int popValue = Convert.ToInt32(stackList[stackList.Count - 1]);
                stackList.RemoveAt(stackList.Count - 1); // removes the poped element
                return popValue;
            }
            else
            {
                Debug.Write("The stack is already empty  ");
                return -1;
            }
        }
        internal virtual bool Empty
        {
            get
            {
                if (stackList.Count == 0) return true;
                else return false;
            }
        }
        internal virtual int peek()
        {
            return Convert.ToInt32(stackList[stackList.Count - 1]);
        }
    }
}
