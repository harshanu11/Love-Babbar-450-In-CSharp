using System;
using System.Collections.Generic;

namespace Love_Babbar_450_Debug
{
    class Program
    {
        static void Main(string[] args)
        {
			var ans = countSubarrays(new int[] { 1,2,3});

		}

		internal static int[] countSubarrays(int[] arr)
		{
			Stack<int> stack = new Stack<int>();
			int[] ans = new int[arr.Length];
			for (int i = 0; i < arr.Length; i++)
			{
				while (stack.Count > 0 && arr[stack.Peek()] < arr[i])
				{
					ans[i] += ans[stack.Pop()];
				}
				stack.Push(i);
				ans[i]++;
			}
			stack.Clear();
			int[] temp = new int[arr.Length];
			for (int i = arr.Length - 1; i >= 0; i--)
			{
				while (stack.Count > 0 && arr[stack.Peek()] < arr[i])
				{
					int idx = stack.Pop();
					ans[i] += temp[idx];
					temp[i] += temp[idx];
				}
				stack.Push(i);
				temp[i]++;
			}
			return ans;
		}

	}
}
