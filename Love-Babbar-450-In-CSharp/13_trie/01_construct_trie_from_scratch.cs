using Model;
using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _13_trie
{
    public class _01_construct_trie_from_scratch
    {
        [Fact]
        public void reverse_arrayTest()
        {
            // Input keys (use only 'a'
            // through 'z' and lower case)
            string[] keys = { "the", "a", "there", "answer", "any", "by", "bye", "their" };
            string[] output = { "Not present in trie", "Present in trie" };
            root = new NodeTrie();

            // Construct trie
            int i;
            for (i = 0; i < keys.Length; i++)
                insert(keys[i]);

            // Search for different keys
            if (search("the") == true)
                Console.WriteLine("the --- " + output[1]);
            else Console.WriteLine("the --- " + output[0]);

            if (search("these") == true)
                Console.WriteLine("these --- " + output[1]);
            else Console.WriteLine("these --- " + output[0]);

            if (search("their") == true)
                Console.WriteLine("their --- " + output[1]);
            else Console.WriteLine("their --- " + output[0]);

            if (search("thaw") == true)
                Console.WriteLine("thaw --- " + output[1]);
            else Console.WriteLine("thaw --- " + output[0]);
        }

        // trie node


        static NodeTrie root;

        // If not present, inserts key into trie
        // If the key is prefix of trie node,
        // just marks leaf node
        static void insert(String key)
        {
            int level;
            int length = key.Length;
            int index;

            NodeTrie pCrawl = root;

            for (level = 0; level < length; level++)
            {
                index = key[level] - 'a';
                if (pCrawl.children[index] == null)
                    pCrawl.children[index] = new NodeTrie();

                pCrawl = pCrawl.children[index];
            }

            // mark last node as leaf
            pCrawl.isEndOfWord = true;
        }

        // Returns true if key
        // presents in trie, else false
        static bool search(String key)
        {
            int level;
            int length = key.Length;
            int index;
            NodeTrie pCrawl = root;

            for (level = 0; level < length; level++)
            {
                index = key[level] - 'a';

                if (pCrawl.children[index] == null)
                    return false;

                pCrawl = pCrawl.children[index];
            }

            return (pCrawl.isEndOfWord);
        }
    }
}
