using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using Xunit;

namespace _03_string
{
    public class _03_duplicates_char_in_string
    {
		/*
            link: https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/
        */
		[Fact]
		public void Test() 
		{

			String str = "test string";
			printDups(str);
			printDupsDict(str);
		}
		// ----------------------------------------------------------------------------------------------------------------------- //
		/*
			using array of 256 to store occurence count
			TC: O(n)
			SC: O(256) => O(1) constant
		*/
		private void print_duplicates(string s)
		{
			int[] arr = new int[256]; // 256 as its not said there would be only alphabets
									  //C++ TO C# CONVERTER TODO TASK: The memory management function 'memset' has no equivalent in C#:
			foreach (char c in s)
			{
				arr[c - 'a']++;
			}
			for (int i = 0; i < 256; i++)
			{
				if (arr[i] > 1)
				{ // greater than 1 as we have to find the duplicates
					Debug.Write(('a' + i));
					Debug.Write(" Count=");
					Debug.Write(arr[i]);
					Debug.Write("\n");
				}
			}
		}
		static int NO_OF_CHARS = 256;
		static void fillCharCounts(String str,
								 int[] count)
		{
			for (int i = 0; i < str.Length; i++)
				count[str[i]]++;
		}

		/* Print duplicates present in
		the passed string */
		static void printDups(String str)
		{

			// Create an array of size 256 and
			// fill count of every character in it
			int[] count = new int[NO_OF_CHARS];
			fillCharCounts(str, count);

			for (int i = 0; i < NO_OF_CHARS; i++)
				if (count[i] > 1)
					Debug.WriteLine((char)i + ", " +
								  "count = " + count[i]);
		}
		///----------------------------------------------
		///
		static void printDupsDict(String str)
		{
			Dictionary<char,
					   int> count = new Dictionary<char,
												   int>();

			for (int i = 0; i < str.Length; i++)
			{
				if (count.ContainsKey(str[i]))
					count[str[i]]++;
				else
					count[str[i]] = 1;
			}

			foreach (var it in count.OrderBy(key => key.Value))
			{
				if (it.Value > 1)
					Debug.WriteLine(it.Key + ", count = " +
									  it.Value);
			}
		}

	}
}
