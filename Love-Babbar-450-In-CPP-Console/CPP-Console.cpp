#include <iostream>
#include <cmath>// for math opration
#include <string>// get user input as string 
#include <vector>
#include<algorithm>; // for sort
#include <set>
#include <map>
using namespace std;
void SayHi(string name)
{
	cout << "\nhello user" << name;
}
int GiveCube(int num)
{
	return  num * num * num;
}
void ConditionFunction()
{
	int age = 0;
	if (true)
	{

	}
	else if (true)
	{

	}
	else
	{

	}
	switch (age)
	{
	case 10:
		cout << "44";
		break;
	default:
		break;
	}
}
void LoopCondition()
{
	int index = 0;
	while (index < 10)
	{
		index++;
	}
	do
	{

	} while (index < 10);
	for (size_t i = 0; i < index; i++)
	{
		for (size_t j = 0; j < 50; j++)
		{

		}
	}

}
class Book
{
private:string rating;
public:string title;
	  string auther;
	  int pages;
	  Book()
	  {

	  }
	  //object function
	  bool HasHonors() {
		  if (true)
		  {
			  return true;

		  }
	  }
	  void SetRaiting() {}
};
class Book1 :public Book
{
private:string rating;
public:string title;
	  string auther;
	  int pages;
	  Book1()
	  {

	  }
	  //object function
	  bool HasHonors() {
		  if (true)
		  {
			  return true;

		  }
	  }
	  void SetRaiting() {}
};
class CppBasic
{
	void comm()
	{
		// data type 
		bool isMail = true;
		char alphabat = 'A';
#pragma region Number
		int age = 23;
		float profit = 22.3;
		double  gpa = 4.5;
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
#pragma region String Fn 
		std::string strUsingNameSpace = "the way to add namespace";
		strUsingNameSpace.length();
		char dsf = strUsingNameSpace[2];
		strUsingNameSpace.find('d');
		strUsingNameSpace.find("sfsf");
		strUsingNameSpace.find("sfsf", 5);// look from index 5
		strUsingNameSpace.substr(8, 5);// start , till length
#pragma endregion
#pragma region UserInput
		// console section
		cout << "Hello World !" << strUsingNameSpace << "my age is " << age << endl;
		cout << "dfgdg" << strUsingNameSpace << endl;
		cout << "hello" << endl;
		cout << "Want new line\n";
		cout << "Part one ";
		cout << "+ part two";
		string str;
		//cin >> age;
		//getline(cin, str);
#pragma endregion
#pragma region Array
		int arr[] = { 5,6,9,8 };
		arr[0];
		arr[10] = 55;// can not be index out on range
		int tdArr[3][2] = {
			{1,2},
			{3,4},
			{5,6}
		};
		tdArr[0][1] = 6;
#pragma endregion
#pragma region Pointer

		cout << "\n ref memory address pointer of age:" << &age;
		int* page = &age; // creting pointer variable to share it
		// dereference of pointer
		cout << *page;
#pragma endregion
#pragma region ClsObject
		Book b;
		b.auther = "abc";
		b.pages = 555;
		b.auther = "me bitch";
#pragma endregion

		SayHi("mu new funciton ");
		cout << GiveCube(3);
	}
};
bool DecOrder(int a, int b)
{
	return a > b;
}
void VectorDemo()
{
	vector<int> A = { 11,2,3,14 };
	cout << A[1] << endl;
	sort(A.begin(), A.end()); // o(NlogN)
	//2,3,11,14
	//o(lonN) binary search 
	bool present = binary_search(A.begin(), A.end(), 3);// true
	present = binary_search(A.begin(), A.end(), 4);// false
	A.push_back(100);
	present = binary_search(A.begin(), A.end(), 100);// true
	//2,3,11,14,100
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	//2,3,11,14,100,100,100,100,100,123
	A.push_back(123);
	vector<int> ::iterator it = lower_bound(A.begin(), A.end(), 100);//>=
	vector<int> ::iterator it2 = upper_bound(A.begin(), A.end(), 100);//> 

	cout << *it << " " << *it2 << endl;
	cout << it2 - it << endl;

	// comparator fn 
	sort(A.begin(), A.end(), DecOrder);
	vector<int> ::iterator it3;//
	// itration
	for (it3 = A.begin(); it3 != A.end(); it3++)
	{
		cout << *it3 << " ";
	}
	cout << " \n";
	//simple itration
	for (int x : A)
	{
		cout << x << " ";
	}
	cout << " \n";
	// ittrate by ref 
	for (int& x : A)
	{
		x++;//can update element 
	}
	for (int x : A)
	{
		cout << x << " ";
	}
	//-------------------

}
void SetDemo()
{
	set<int> S;// 
	S.insert(1);// log n time
	S.insert(2);
	S.insert(-1);
	S.insert(-10);
	for (int x : S)
	{
		cout << x << " ";
	}
	//-10 -1 1 2
	auto it = S.find(-1);
	if (it == S.end())
	{
		// not present
	}
	else
	{
		cout << *it;
	}
	cout << " \n";
	auto it2 = S.upper_bound(-1);//  first >-1 return first -1 means available
	auto it3 = S.upper_bound(0);//  stricktly greter then
	cout << *it2 << " " << *it3 << endl;

	auto it4 = S.upper_bound(2);
	if (it4 == S.end())
	{
		// cant find
	}
	S.erase(14);// llog n
}
void MapDemo()
{
	// find delete  in log(n)
	map<int, int>  A;
	A[1] = 100;
	A[2] = -1;
	A[3] = 200;
	A[100000232] = 1;
	map<char, int> cnt;
	string x = "rachit jain";

	for (char c : x)
	{
		cnt[c]++;
	}
	cout << cnt['a'] << " " << cnt['z'] << endl;
}
void PairDemo()
{
	set<pair<int, int>> S;
	//{a, b}and {c,d}
	//a<c if a== c then compare b<d
	S.insert({ 401,450 });
	S.insert({ 2,3 });
	S.insert({ 10,20 });
	S.insert({ 30,400 });
	// 2,3;10,20;30,400;401,450
	int point = 50;

	auto it = S.upper_bound({ point ,INT_MAX });
	if (it == S.begin())
	{
		// not lying in any interval
	}
	it--;
	pair<int, int > current = *it;
	if (current.first <= point && point <= current.second)
	{
		cout << "Yes its present " << current.first;
	}
	else
	{
		// not present 
	}

}
int main()
{
	PairDemo();

	return 0;
}


