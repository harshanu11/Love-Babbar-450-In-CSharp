/*
    link: https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1
*/

#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(StringClass)
    {
    public:

        TEST_METHOD(areIsomorphicTest)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}
// ----------------------------------------------------------------------------------------------------------------------- //
bool areIsomorphic(string str1, string str2)
{
    unordered_map<char, char> mp, mp2;
    int n = str1.size();
    int m = str2.size();
    if (m != n) return false;
    for (int i = 0;i < n;i++) {
        if (mp.find(str1[i]) == mp.end()) mp[str1[i]] = str2[i];
        if (mp2.find(str2[i]) == mp.end()) mp2[str2[i]] = str1[i];

        if (mp[str1[i]] != str2[i] || mp2[str2[i]] != str1[i]) {
            return false;
        }
    }
    return true;
}



// ----------------------------------------------------------------------------------------------------------------------- //
bool areIsomorphic2(string str1, string str2)
{

    int m = str1.length(), n = str2.length();
    int MAX_CHARS = 33;
    if (m != n)
        return false;

    //using a boolean array to mark visited characters in str2.
    bool marked[5] = { false };

    //using map to store mapping of every character from str1 to
    //that of str2. Initializing all entries of map as -1.
    int map[5];
    memset(map, -1, sizeof(map));


    for (int i = 0; i < n; i++)
    {
        //if current character of str1 is seen first time in map.
        if (map[str1[i]] == -1)
        {
            //if current character of str2 is already
            //seen, one to one mapping is not possible.
            if (marked[str2[i]] == true)
                return false;

            //marking current character of str2 as visited.
            marked[str2[i]] = true;

            //storing mapping of current characters.
            map[str1[i]] = str2[i];
        }

        //if this isn't first appearance of current character in str1 then
        //checking if previous appearance mapped to same character of str2.
        else if (map[str1[i]] != str2[i])
            return false;
    }
    return true;
}