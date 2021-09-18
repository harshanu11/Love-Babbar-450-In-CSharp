using Model;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace _13_trie
{
    public class _02_Find_shortest_unique_prefix_for_every_word_in_a_given_list
    {
        /*
            https://www.geeksforgeeks.org/find-all-shortest-unique-prefixes-to-represent-each-word-in-a-given-list/
        */


        [Fact]
        public void FindTrieTest() 
        {
            String[] arr = { "zebra", "dog", "duck", "dove" };
            int n = arr.Length;
            findPrefixes(arr, n);
        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        // C++ program to print all prefixes that
        // uniquely represent words.
        //C++ TO C# CONVERTER WARNING: The following #include directive was ignored:
        //#include<bits/stdc++.h>


        // Maximum length of an input word

        // Trie Node.

        static readonly int MAX = 256;

        // Maximum length of an input word
        static readonly int MAX_WORD_LEN = 500;

        static NodeTrie root;

        // Method to insert a new string into Trie
        void insert(String str)
        {
            // Length of the URL
            int len = str.Length;
            NodeTrie pCrawl = root;

            // Traversing over the length of given str.
            for (int level = 0; level < len; level++)
            {
                // Get index of child node from 
                // current character in str.
                int index = str[level];

                // Create a new child if not exist already
                if (pCrawl.children[index] == null)
                    pCrawl.children[index] = new NodeTrie(MAX);
                else
                    (pCrawl.children[index].freq)++;

                // Move to the child
                pCrawl = pCrawl.children[index];
            }
        }

        // This function prints unique prefix for every word stored
        // in Trie. Prefixes one by one are stored in prefix[].
        // 'ind' is current index of prefix[]
        void findPrefixesUtil(NodeTrie root, char[] prefix,
                            int ind)
        {
            // Corner case
            if (root == null)
                return;

            // Base case
            if (root.freq == 1)
            {
                prefix[ind] = '\0';
                int i = 0;
                while (prefix[i] != '\0')
                    Debug.Write(prefix[i++]);
                Debug.Write(" ");
                return;
            }

            for (int i = 0; i < MAX; i++)
            {
                if (root.children[i] != null)
                {
                    prefix[ind] = (char)i;
                    findPrefixesUtil(root.children[i], prefix, ind + 1);
                }
            }
        }

        // Function to print all prefixes that uniquely
        // represent all words in arr[0..n-1]
        void findPrefixes(String[] arr, int n)
        {
            // Construct a Trie of all words
            root = new NodeTrie(MAX);
            root.freq = 0;
            for (int i = 0; i < n; i++)
                insert(arr[i]);

            // Create an array to store all prefixes
            char[] prefix = new char[MAX_WORD_LEN];

            // Print all prefixes using Trie Traversal
            findPrefixesUtil(root, prefix, 0);
        }

   
    }
}
