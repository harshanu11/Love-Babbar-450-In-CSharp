using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace _08_greedy
{
	/*
	link: https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1

	video (just to understand): https://youtu.be/co4_ahEDCho
*/


	// ----------------------------------------------------------------------------------------------------------------------- //
	/*
		Time complexity: O(nlogn) where n is the number of unique characters. If there are n nodes, extractMin() is called 2*(n – 1) times. extractMin() takes O(logn) time as it calles minHeapify(). So, overall complexity is O(nlogn).
	If the input array is sorted, there exists a linear time algorithm. We will soon be discussing in our next post.

	Applications of Huffman Coding:
		1. They are used for transmitting fax and text.
		2. They are used by conventional compression formats like PKZIP, GZIP, etc.
	 It is useful in cases where there is a series of frequently occurring characters.

	*/
	// C++ program for Huffman Coding with STL
	public class _03_huffman_coding
    {
		[Fact]
		public void reverse_arrayTest()

		{

		}
	}




}
