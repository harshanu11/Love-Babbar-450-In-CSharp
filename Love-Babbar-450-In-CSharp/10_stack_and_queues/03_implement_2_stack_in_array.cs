using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace _10_stack_and_queues
{
    public class _03_implement_2_stack_in_array
    {
        [Fact]
        public void reverse_arrayTest()
        {
            twoStacks ts = new twoStacks(5);
            ts.push1(5);
            ts.push2(10);
            ts.push2(15);
            ts.push1(11);
            ts.push2(7);
            Debug.Write("Popped element from stack1 is " + " : " + ts.pop1() + "\n");
            ts.push2(40);
            Debug.Write("Popped element from stack2 is " + ": " + ts.pop2() + "\n");
        }

    }


    internal class twoStacks
    {
        internal int[] arr;
        internal int size;
        internal int top1, top2;

        // Constructor
        internal twoStacks(int n)
        {
            size = n;
            arr = new int[n];
            top1 = n / 2 + 1;
            top2 = n / 2;
        }

        // Method to push an element x to stack1
        internal virtual void push1(int x)
        {

            // There is at least one empty
            // space for new element
            if (top1 > 0)
            {
                top1--;
                arr[top1] = x;
            }
            else
            {
                Debug.Write("Stack Overflow" + " By element :" + x + "\n");
                return;
            }
        }

        // Method to push an element
        // x to stack2
        internal virtual void push2(int x)
        {

            // There is at least one empty
            // space for new element
            if (top2 < size - 1)
            {
                top2++;
                arr[top2] = x;
            }
            else
            {
                Debug.Write("Stack Overflow" + " By element :" + x + "\n");
                return;
            }
        }

        // Method to pop an element from first stack
        internal virtual int pop1()
        {
            if (top1 <= size / 2)
            {
                int x = arr[top1];
                top1++;
                return x;
            }
            else
            {
                Debug.Write("Stack UnderFlow");
                Environment.Exit(1);
            }
            return 0;
        }

        // Method to pop an element
        // from second stack
        internal virtual int pop2()
        {
            if (top2 >= size / 2 + 1)
            {
                int x = arr[top2];
                top2--;
                return x;
            }
            else
            {
                Debug.Write("Stack UnderFlow");
                Environment.Exit(1);
            }
            return 1;
        }
    }


}

