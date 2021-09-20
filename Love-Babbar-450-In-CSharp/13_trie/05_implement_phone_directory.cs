using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _13_trie
{
    public class _05_implement_phone_directory
    {
        [Fact]
        public void reverse_arrayTest() { }

        /*
            link: https://practice.geeksforgeeks.org/problems/phone-directory4628/1#

            sol: https://www.geeksforgeeks.org/implement-a-phone-directory/
        */



        // ----------------------------------------------------------------------------------------------------------------------- //
        public class Solution
        {
            public class TrieNode
            {
                public Dictionary<char, TrieNode> child = new Dictionary<char, TrieNode>();
                public bool isLast;

                public TrieNode()
                {
                    for (char i = 'a'; i <= 'z'; i++)
                    {
                        child[i] = null;
                    }

                    isLast = false;
                }
            }

            public TrieNode root = null;

            public void insert(string s)
            {
                int len = s.Length;

                TrieNode itr = root;
                for (int i = 0; i < len; i++)
                {
                    TrieNode nextNode = itr.child[s[i]];
                    if (nextNode == null)
                    {
                        nextNode = new TrieNode();
                        //C++ TO C# CONVERTER TODO TASK: The following line was determined to be a copy assignment (rather than a reference assignment) - this should be verified and a 'CopyFrom' method should be created:
                        //ORIGINAL LINE: itr->child[s[i]] = nextNode;
                        //itr.child[s[i]].CopyFrom(nextNode);
                    }

                    itr = nextNode;

                    if (i == len - 1)
                    {
                        itr.isLast = true;
                    }
                }
            }

            public void displayContactsUtil(TrieNode curNode, string prefix, List<string> v)
            {
                if (curNode.isLast)
                {
                    v.Add(prefix);
                }

                for (char i = 'a'; i <= 'z'; i++)
                {
                    TrieNode nextNode = curNode.child[i];
                    if (nextNode != null)
                    {
                        displayContactsUtil(nextNode, prefix + (char)i, v);
                    }
                }
            }


            public List<List<string>> displayContactsHelp(string str)
            {
                List<List<string>> ans = new List<List<string>>();

                TrieNode prevNode = root;

                string prefix = "";
                int len = str.Length;

                int i;
                for (i = 0; i < len; i++)
                {
                    prefix += (char)str[i];

                    char lastChar = prefix[i];

                    TrieNode curNode = prevNode.child[lastChar];

                    if (curNode == null)
                    {
                        break;
                    }

                    List<string> v = new List<string>();

                    displayContactsUtil(curNode, prefix, v);
                    ans.Add(v);

                    prevNode = curNode;
                }

                for (; i < len; i++)
                {
                    ans.Add(new List<string>());
                }

                return new List<List<string>>(ans);
            }

            public void insertIntoTrie(string[] contacts, int n)
            {
                root = new TrieNode();

                for (int i = 0; i < n; i++)
                {
                    insert(contacts[i]);
                }
            }

            public List<List<string>> displayContacts(int n, string[] contact, string s)
            {
                insertIntoTrie(contact, n);

                return new List<List<string>>(displayContactsHelp(s));
            }
        }

    }
}
/*
    link: https://practice.geeksforgeeks.org/problems/phone-directory4628/1#

    sol: https://www.geeksforgeeks.org/implement-a-phone-directory/
*/



//// ----------------------------------------------------------------------------------------------------------------------- //
//class Solution
//{
//    public:
//    struct TrieNode
//    {
//        unordered_map<char, TrieNode*> child;
//        bool isLast;

//        TrieNode()
//        {
//            for (char i = 'a'; i <= 'z'; i++)
//                child[i] = NULL;

//            isLast = false;
//        }
//    };

//    TrieNode* root = NULL;

//    void insert(string s)
//    {
//        int len = s.length();

//        TrieNode* itr = root;
//        for (int i = 0; i < len; i++)
//        {
//            TrieNode* nextNode = itr->child[s[i]];
//            if (nextNode == NULL)
//            {
//                nextNode = new TrieNode();
//                itr->child[s[i]] = nextNode;
//            }

//            itr = nextNode;

//            if (i == len - 1)
//                itr->isLast = true;
//        }
//    }

//    void displayContactsUtil(TrieNode* curNode, string prefix, vector<string>& v)
//    {
//        if (curNode->isLast)
//        {
//            v.push_back(prefix);
//        }

//        for (char i = 'a'; i <= 'z'; i++)
//        {
//            TrieNode* nextNode = curNode->child[i];
//            if (nextNode != NULL)
//                displayContactsUtil(nextNode, prefix + (char)i, v);
//        }
//    }


//    vector<vector<string>> displayContactsHelp(string str)
//    {
//        vector<vector<string>> ans;

//        TrieNode* prevNode = root;

//        string prefix = "";
//        int len = str.size();

//        int i;
//        for (i = 0; i < len; i++)
//        {
//            prefix += (char)str[i];

//            char lastChar = prefix[i];

//            TrieNode* curNode = prevNode->child[lastChar];

//            if (curNode == NULL) break;

//            vector<string> v;

//            displayContactsUtil(curNode, prefix, v);
//            ans.push_back(v);

//            prevNode = curNode;
//        }

//        for (; i < len; i++)
//        {
//            ans.push_back({ "0" });
//    }

//        return ans;
//    }

//void insertIntoTrie(string contacts[], int n)
//{
//    root = new TrieNode();

//    for (int i = 0; i < n; i++)
//        insert(contacts[i]);
//}

//vector<vector<string>> displayContacts(int n, string contact[], string s)
//{
//    insertIntoTrie(contact, n);

//    return displayContactsHelp(s);
//}
//};