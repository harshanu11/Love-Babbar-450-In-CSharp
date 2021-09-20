using Model;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace _10_stack_and_queues
{
    public partial class _02_implement_queue_from_scratch
    {
        [Fact]
        public void create_Queue() 
        {
            NodeQueueArray q = new NodeQueueArray(20);
            q.queueEnqueue(10);
            var peek = q.Peek1();
            q.queueEnqueue(20);
            q.queueDequeue();
            q.queueDequeue();
            q.queueEnqueue(30);
            q.queueEnqueue(40);
            q.queueEnqueue(50);
            q.queueDequeue();
            Debug.WriteLine("Queue Front : " + NodeQueueArray.front);
            Debug.WriteLine("Queue Rear : " + NodeQueueArray.rear);


            NodeQueueUsingLL qq = new NodeQueueUsingLL();
            qq.enqueue(10);
            qq.enqueue(20);
            qq.dequeue();
            qq.dequeue();
            qq.enqueue(30);
            qq.enqueue(40);
            qq.enqueue(50);
            qq.dequeue();
            Debug.WriteLine("Queue Front : " + qq.front.data);
            Debug.WriteLine("Queue Rear : " + qq.rear.data);


            NodeQueueUsingStackNode qqq = new NodeQueueUsingStackNode();
            qqq.enQueue(1);
            qqq.enQueue(2);
            qqq.enQueue(3);
            //q.Peek()  just peek without removing obj
            //q.ToArray()
            Debug.Write(qqq.deQueue() + " ");
            Debug.Write(qqq.deQueue() + " ");
            Debug.Write(qqq.deQueue());
        }
    }
}
/*
    link: https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/

    methods:
    1. enqueue
    2. dequeue
    3. isFull
    4. isEmpty
    5. getFront
    6. getRear
*/


//// ----------------------------------------------------------------------------------------------------------------------- //
//class MyQueue
//{
//    public:
//    int front, rear, size;
//    unsigned capacity;
//    int arr[];

//    MyQueue(unsigned cap)
//    {
//        capacity = cap;
//        front = 0;
//        rear = capacity - 1;
//    }

//    bool isFull() return size == capacity;

//    bool isEmpty() return size == 0;

//    void enqueue(int x)
//    {
//        if (isFull()) return;

//        rear = (++rear) % capacity;
//        arr[rear] = x;
//        size++;
//        cout << x << " is enqueued!" << endl;
//    }

//    void dequeued()
//    {
//        if (isEmpty()) return;

//        int curr = arr[front];
//        front = (++front) % capacity;
//        size--;
//        cout << curr << " is dequeued!" << endl;
//    }

//    int isFront()
//    {
//        if (isEmpty()) return INT_MIN;

//        return arr[front];
//    }

//    int isRear()
//    {
//        if (isEmpty()) return INT_MIN;

//        return arr[rear];
//    }

//}

//int main()
//{
//    MyQueue q = new MyQueue(10);
//}