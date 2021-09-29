// Love-Babbar-450-In-CPP-Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>// for math opration
#include <string>// get user input as string 
using namespace std;

int main()
{
	// data type 
	bool isMail = true;
	char alphabat = 'A';

	int age = 23;
	float profit = 22.3;
	double  gpa = 4.5;
#pragma region Number
	cout << 10 % 3;
	age++;
	++age;
	cout << 15.5 - 5;
	cout << pow(2, 5);//32 2^5
	cout << sqrt(2.5);//
	cout << round(4.5);//
	cout << ceil(4.5);//
	cout << fmax(4.5, 8);//
	cout << fmin(4.5, 8);//

#pragma endregion


	std::string strUsingNameSpace = "the way to add namespace";
	// string fn 
#pragma region String Fn 
	strUsingNameSpace.length();
	char dsf = strUsingNameSpace[2];
	strUsingNameSpace.find('d');
	strUsingNameSpace.find("sfsf");
	strUsingNameSpace.find("sfsf", 5);// look from index 5
	strUsingNameSpace.substr(8, 5);// start , till length
#pragma endregion

	// console section
	cout << "Hello World !" << strUsingNameSpace << "my age is " << age << endl;
	cout << "dfgdg" << strUsingNameSpace << endl;
	cout << "hello" << endl;
	cout << "Want new line\n";
	cout << "Part one ";
	cout << "+ part two";

#pragma region UserInput
	string str;
	cin >> age;
	getline(cin, str);
#pragma endregion

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
