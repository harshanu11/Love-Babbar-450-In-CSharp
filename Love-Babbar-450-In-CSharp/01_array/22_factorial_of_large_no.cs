/*
    link: https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1#

    sol: https://www.geeksforgeeks.org/factorial-large-number/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
using System;
using System.Collections.Generic;

public class Solution
{
	// this function takes k to multiply with array (array here is whole digit with first digit at 0th of array)
	public int mul(List<int> arr, int k, int size)
	{
		int carry = 0;
		for (int i = 0; i < size; i++)
		{
			int curr_mul = k * arr[i] + carry;
			arr[i] = curr_mul % 10;
			carry = curr_mul / 10;
		}
		// if carry is not zero then we have to push_back at the end.
		while (carry != 0)
		{
			arr.Add(carry % 10);
			carry /= 10;
			size++;
		}
		return size;
	}
	public List<int> factorial(int n)
	{
		// code here
		List<int> arr = new List<int>() { 1 };
		int size = 1;
		for (int i = 2; i <= n; i++)
		{
			// updating size and array everytime
			size = mul(arr, i, size);
		}

		// we have first digit at 0th place hence we have to reverse
		// eg. for 5 it will be {0, 2, 1} => {1, 2, 0}
		arr.Reverse();
		return new List<int>(arr);
	}
}

public static class GlobalMembers
{
	// ----------------------------------------------------------------------------------------------------------------------- //
	// alternate solution
	public static string factorial(long n)
	{
		if (n > DefineConstants.MAX)
		{
			Console.Write(" Integer Overflow");
			Console.Write("\n");
			return "";
		}

		long counter;
		double sum = 0;

		// Base case
		if (n == 0)
		{
			return "1";
		}

		// Calculate the sum of logarithmic values
		for (counter = 1; counter <= n; counter++)
		{
			sum = sum + Math.Log(counter);
		}

		// Number becomes too big to hold in unsigned long integers. Hence converted to string
		// Answer is sometimes under estimated due to floating point operations so round() is used
		string result = Convert.ToString(Math.Round(Math.Exp(sum)));
		// here exp is calculated bcoz: log(n!) = sum = log(1) + .... log(n), now n! = e^sum.
		return result;
	}
}

internal static class DefineConstants
{
	public const int MAX = 1000;
}
