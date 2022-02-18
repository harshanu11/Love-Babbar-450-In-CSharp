#include <iostream>// input output 
#include <limits.h> // for int_max
#include<array> // for array
#include <vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include <cmath>// for math opration
#include <string>// get user input as string 
#include<algorithm>; // for sort
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

void printArr(int arr[], int s)
{
	for (int i = 0; i < s; i++)
	{
		cout << arr[i] << " ";
	}
}
void printArr(vector<int> arr, int s = 0)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
}
#pragma region Phase one basic loop function array string math 
void sayHi(string name)
{
	int a = 0;
	string user;
	cin >> user;
	// "\n"  for next line '\t' tab
	cout << "\n hello user" << name << user << '\n' << endl;
	cout << "\0 null char " << name << user << '\n' << endl;
	//cin >> a;
	cout << "namaste duniya\t" << a << "\t" << endl;
}
void boolFn()
{
	bool isMail = true;
}
void numberFn()
{

#define R 4 // define local var
#define C 4
	int age = 23;
	int* p = new int;// dynamic int 
	delete p;
	cout << "\n ref memory address pointer of age:" << &age;
	int* page = &age; // creting pointer variable to share it
	// dereference of pointer
	cout << *page;

	//Programmer prog = Programmer(" ", " ", 55);
	//Employee* ee = &prog;
	//ee->work();

	auto max = INT_MAX;//#include <limits.h> // for int_max
	int b = sizeof(age);// give size in byte
	unsigned  int a = 33;// only positive no
	float profit = 22.3;
	double  gpa = 4.5;
	cout << 10 % 3;
	age++;
	++age;
	cout << 15.5 - 5;

	// type caste 
	int res = 1;
	res = 1LL * res * (4);
}
void bitWiseOperator()
{
	int a = 4;
	int b = 6;
	auto c = ~a;// to get once compliment
	//int a = 55;
	// !a == 0  or one
	cout << (a & 1);// return false bcz last digit is 0
	cout << " a&b " << (a & b) << endl;
	cout << " a|b " << (a | b) << endl;
	cout << " ~a " << ~a << endl;// once compliment
	cout << " a^b " << (a ^ b) << endl;//r(a^a=0

	cout << (17 >> 1) << endl;// devide by 2 once 
	cout << (17 >> 2) << endl;// devide by 2 twise
	cout << (19 << 1) << endl; // multiply by 2
	cout << (21 << 2) << endl; // multiply by 2
}
void stringFn()
{
	char alphabat = 'A';
	char c = 'A' + 1;// B  
	cin.get();//give char vale invluding space


	// "\n"  for next line '\t' tab
	auto comp = strcmp("dsfs", "dd");// not 0
	char str1[] = "Hello Geeks!";
	char str2[] = "GeeksforGeeks";
	char str3[40];
	char str4[40];
	char str5[] = "GfG";
	cout << str1;
	string str;
	str = to_string('5');
	str = to_string(5);
	//string str4("This is an example sentence.");
	cout << str << '\n';
	str.erase(10, 8);                        //            ^^^^^^^^m
	cout << str << '\n';
	str.erase(str.begin() + 9);               //           ^
	cout << str << '\n';
	str.erase(str.begin() + 5, str.end() - 9);  //       ^^^^^
	cout << str << '\n';

	//string str5("There are two needles in this haystack with needles.");
	string str22("needle");

	// different member versions of find in the same order as above:
	size_t found = str.find(str2);
	if (found != string::npos)
		cout << "first 'needle' found at: " << found << '\n';

	found = str.find("needles are small", found + 1, 6);
	if (found != string::npos)
		cout << "second 'needle' found at: " << found << '\n';

	//strcpy(str2, str1);
	//strcpy(str3, "Copy successful");
	auto alphanumeric = isalnum('c');
	auto lower = tolower('A');
	string strUsingNameSpace = "the way to add namespace";
	strUsingNameSpace.length();
	char dsf = strUsingNameSpace[2];
	strUsingNameSpace.find('d');
	strUsingNameSpace.find("sfsf");
	strUsingNameSpace.find("sfsf", 5);// look from index 5
	strUsingNameSpace.substr(8, 5);// start , till length

	string s1 = "Example of replace";
	string s2 = "Demonstration";
	s1.replace(0, 7, s2);//Demonstration of replace
	string str6("GeeksforGeeks ");
	string str7("Hello World! ");
	str6.append(str7, 0, 5);
}
char stringToLower(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return c;
	}
	else if (c >= '0' && c <= '9')
	{
		return '0';
	}
	else
	{
		return c + ('a' - 'A');
	}

}
void stlFn()
{
	vector<int> vect1{ 1, 2, 3, 4 };
	// Declaring new vector
	vector<int> vect2;
	cout << pow(2, 5);//32 2^5
	cout << sqrt(2.5);//
	cout << round(4.5);//
	cout << ceil(4.5);//
	cout << fmax(4.5, 8);//
	cout << fmin(4.5, 8);//
	int a = 3;
	int b = 5;
	swap(a, b);
	min(3, 3);
	max(3, 3);
	copy(vect1.begin(), vect1.end(), back_inserter(vect2));
}
void conditionFunction()
{
	int age = 0;
	if (true or true)
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
	char ch = '1';
	int num = 1;

	cout << endl;
	switch (2 * num) {

	case 2: cout << "First" << endl;
		cout << " First again " << endl;
		break;

	case '1': switch (num) {
	case 1: cout << " Value of num is " << num << endl;
		break;
	}
			break;

	default: cout << " It is default case" << endl;

	}
	int input = 0;
	int temp = 0;
	cin >> input;
	int x = 0, y = 0, z = 0, v = 0;
	switch (1) {
	case 1: x += input / 100;
		cout << "100 rupees notes: " << x << endl;
		temp = input - (x * 100);

	case 2: y += temp / 50;
		cout << "50 rupees notes: " << y << endl;
		temp = temp - (y * 50);

	case 3: z += temp / 20;
		cout << "20 rupees notes: " << z << endl;
		temp = temp - (z * 20);

	case 4: v += temp / 1;
		cout << "1 rupee notes: " << v;
		temp = temp - (v * 1);
		break;
	}
	cout << endl;
}
void loopCondition()
{
	int i = 7;
	int n = 0;
	cout << (++i) << endl;
	// 8 
	cout << (i++) << endl;
	// 8 , i = 9
	cout << (i--) << endl;
	//9 , i = 8 
	cout << (--i) << endl;
	for (; ; ) {
		if (i <= n) {
			cout << i << endl;
		}
		else {
			break;
		}
		i++;
	}
	for (int a = 0, b = 1, c = 2; a >= 0 && b >= 1 && c >= 2; a--, b--, c--) {
		cout << a << " " << b << " " << c << endl;
	}
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
	vector<int> v;
	v.pop_back();// remove last

	cout << "after pop" << endl;
	for (int i : v) {
		cout << i << " ";
	}
	set<int> s;
	s.insert(5);// o(logn)
	set<int>::iterator itr = s.find(5);
	for (auto it = itr; it != s.end(); it++) {
		cout << *it << " ";
	}cout << endl;

}
void printPattern()
{
	//D
	//CD
	//BCD
	//ABCD

	int row = 4;
	int col = 4;
	int i = 1;
	int k = 4;
	while (i <= row)
	{
		int j = 1;
		char c = 'A' + row - i;
		while (j <= i)
		{
			cout << c;
			c++;
			j++;
		}
		cout << "\n";
		k--;
		i++;
	}
}
void decToBin()
{
	int number = 5;
	int i = 0;
	int ans = 0;
	while (number != 0)
	{
		int bit = number & 1;
		ans = pow(10, i) * bit + ans;
		i++;
		number = number >> 1;
	}
	//ans = ~ans;
	//ans = ans + 1;
	//cout << ans;

	cout << ans;
}
void binToDec()
{
	int number = 110;
	int ans = 0;
	int i = 0;
	while (number != 0)
	{
		int digit = number % 10;
		if (digit == 1)
			ans = pow(2, i) + ans;
		number = number / 10;
		i++;
	}
	cout << ans;
}
void passbyVal(int* p)
{
	cout << "memory add = " << p << endl;
	cout << "val = " << *p << endl;
}
void update(int* p) {

	// p = p + 1;
	//cout << "inside "<< p <<endl;
	*p = *p + 1;

}
int getSum(int* arr, int n) {

	cout << endl << "Size : " << sizeof(arr) << endl;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}
void referenceTyep()
{
	int age = 31;
	int* page = &age; // creting pointer variable to share it
	// dereference of pointer
	cout << *page;
	int num = 5;
	// & is address operator
	cout << "ref add" << &num << endl;//0x7ffe20c611a8 address in hexa decimal
	// pointer save address
	int* ptr = &num; // 
	cout << "ptr add " << ptr << endl;//ptr = 0x7ffe20c611a8
	cout << "ptr add " << *ptr << endl;// 5

	int arr[10];
	cout << "reference of first element =" << arr << endl;
	cout << "reference of first element =" << &arr[0] << endl;
	cout << "val of first memory address =" << *arr << endl;
	// arr[i] = *(arr+i)
	// i[arr] = *(i+arr)
	cout << "val of first memory address =" << *(arr + 1) << endl;// first+1 location

	// pass by val 
	int* p = 0;
	passbyVal(page);
	cout << " Before " << *p << endl;//5
	update(p);
	cout << " After " << *p << endl;//6

	int arr2[6] = { 1,2,3,4,5,8 };

	cout << "Sum is " << getSum(arr + 3, 3) << endl;// sendign part of array 

	// reference variable
	int i = 0;
	int& j = i;
	cout << i << endl;
	i++;
	cout << i << endl;
	j++;

	int* a = new int[88];



}
int recurtion(int n)
{
	if (n == 0) return 1;
	cout << "head val =" << n << endl;
	int val = n * recurtion(n - 1);
	cout << "tail val =" << n << endl;
	return val;
}
int  recurReverseNum(int n)
{
	if (n % 10 == 0) {
		return n;
	}
	int p = n % 10;
	int pp = n / 10;
	recurReverseNum(pp);
	cout << " num=" << p << endl;
	return pp;
}
void reverseInt()
{
	int x = 1288888999;
	int ans = 0;
	int i = 0;
	while (x != 0)
	{
		int digit = x % 10;
		//cout << digit  << endl;
		if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
		{
			//cout << 0; 
			//return 0;
		}

		ans = digit + ans * 10;
		cout << ans << endl;
		i++;
		x = x / 10;
	}
	cout << ans;
}
void makOfNo()
{
	int  n = 5;
	int m = n;
	int mask = 0;
	while (m != 0)
	{
		mask = (mask << 1) | 1;
		m = m >> 1;
	}
	int ans = ~n;
	ans = ans & mask;
	cout << ans;
}
bool twoPow() {
	int n = 5;
	int temp = 0;
	for (int i = 0; i < 31; i++)
	{
		temp = pow(2, i);
		if (temp == n) return true;
		else if (temp > n)
			return false;
	}
	return false;

	for (int i = 0; i < 31; i++)
	{
		if (temp == n) return true;
		else if (temp > n)
			return false;
		if (temp < INT_MAX / 2) //return false;
			temp = 2 * temp;

	}
	return false;
}
void rupees1330problemsolve() {

	int input = 0;
	int temp = 0;
	cin >> input;
	int x = 0, y = 0, z = 0, v = 0;
	switch (1) {
	case 1: x += input / 100;
		cout << "100 rupees notes: " << x << endl;
		temp = input - (x * 100);

	case 2: y += temp / 50;
		cout << "50 rupees notes: " << y << endl;
		temp = temp - (y * 50);

	case 3: z += temp / 20;
		cout << "20 rupees notes: " << z << endl;
		temp = temp - (z * 20);

	case 4: v += temp / 1;
		cout << "1 rupee notes: " << v;
		temp = temp - (v * 1);
		break;
	}
	return;
}
int pow(int a, int b)
{
	int ans = 0;
	for (int i = 0; i < b; i++)
	{
		ans = ans * a;
	}
	return ans;
}
int fact(int n)
{
	int fact = 1;
	for (int i = 0; i < n; i++)
	{
		fact *= (i + 1);
	}
	return fact;
}
int nCr(int n, int r)
{
	int ans = 0;
	ans = fact(n) / (fact(r) * fact(n - r));
	return ans;
}
void forFib()
{
	int n = 10;
	int a = 0;
	int b = 1;
	cout << a << " " << b << " ";
	for (int i = 1; i <= n; i++) {

		int nextNumber = a + b;
		cout << nextNumber << " ";

		a = b;
		b = nextNumber;
	}
}
void forPrime() {
	int n;
	cout << " enter the value of n" << endl;
	cin >> n;

	bool isPrime = 1;

	for (int i = 2; i < n; i++) {

		//rem = 0, Not a Prime
		if (n % i == 0) {
			//cout<<" Not a Prime Number" << endl;
			isPrime = 0;
			break;
		}
	}

	if (isPrime == 0) {
		cout << " Not a Prime Number" << endl;
	}
	else
	{
		cout << "is a Prime Number " << endl;
	}

}

void array2d()
{
	int arr[3][3];
	//taking input -> row wise input
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			cin >> arr[row][col];
		}
	}


	/*
	//taking input -> col wise input
		for(int col=0; col<4; col++) {
			for(int row=0; row<3; row++) {
				cin >> arr[row][col];
			}
		}
	*/
	int arr1[3][4] = { 1,2,3,4,5,6,7,8,9,10,13,14 };// column wise print
	int arr2[3][4] = { {0,1,2,3},{0,1,2,3},{0,1,2,3} };

}
void arrayDemoLB()
{
	//fill with specific val
	int arr22[100];
	fill_n(arr22, 100, -17);
	int size = 10;
	// static arr
	int dost[10];
	int sizeDost = sizeof(dost) / sizeof(int);// not always correct(sizeof(dost)=40)/sizeof(int)=4
	int basic[3] = { 1,2,3 };
	delete basic;
	// dynamic array size
	int* aa = new int[size];// using heap
	array<int, 4> a = { 1,2,3,4 };//  this stl array so need namespace
	size = a.size();
	// dynamic array 
	int* result = new int[size];
	int* arr2 = new int[size];

	//Programmer prog = Programmer(" ", " ", 55);
	//Employee* ee = &prog;
	//ee->work();

#define R 4
#define C 4
	int maze[R][C] = { {0, 0, 0, 0},
			   {0, -1, 0, 0},
			   {-1, 0, 0, 0},
			   {0, 0, 0, 0} };
	// dynamic array 
	int row;
	cin >> row;

	int col;
	cin >> col;

	//creating a 2D array
	int** arr = new int* [row];
	for (int i = 0; i < row; i++) {
		arr[i] = new int[col];
	}
	//releasing memory
	for (int i = 0; i < row; i++) {
		delete[] arr[i];
	}

	delete[]arr;

	for (int i = 0; i < size; i++) {
		cout << a[i] << endl;
	}
	cout << "Element at 2nd Index-> " << a.at(2) << endl; //3 o(1)
	cout << "Empty or not-> " << a.empty() << endl;// false o(1)
	cout << "First Element-> " << a.front() << endl;//1 o(1)
	cout << "last Element-> " << a.back() << endl;//4 o(1)
};
void swapAlternateNo()
{
	// 12785
	// convert to 
	//21975
}
bool uniqueOccurrences() {
	vector<int> arr = { -3,0,1,-3,1,1,1,-3,10,0 };
	vector<int> c(2000, 0);
	vector<int> co(2000, 0);
	int i = 0;
	while (i < arr.size())
	{
		if (c[arr[i]] >= 0)
		{
			c[arr[i]]++;
		}
		else
		{
			cout << arr[i];
			c[arr[i] * -2]++;
		}
		i++;
	}
	i = 0;
	while (i < c.size())
	{
		if (c[i] >= 1)
		{
			co[c[i]]++;
		}
		i++;
	}
	i = 0;
	while (i < c.size())
	{
		if (co[i] > 1)
		{
			return false;
		}
		i++;
	}
	return true;
}
int getMin(int num[], int n) {

	int mini = INT_MAX;

	for (int i = 0; i < n; i++) {

		mini = min(mini, num[i]);

		//if(num[i] < min){
		//    min = num[i];
		//}
	}

	//returning min value
	return mini;
}
int getMax(int num[], int n) {

	int maxi = INT_MIN;

	for (int i = 0; i < n; i++) {

		maxi = max(maxi, num[i]);

		// if(num[i] > max){
		  //   max = num[i];
		// }
	}

	//returning max value
	return maxi;
}
bool linearSearch(int arr[], int size, int key) {

	for (int i = 0; i < size; i++) {

		if (arr[i] == key) {
			return 1;
		}

	}
	return 0;
}
void swapAlternate(int arr[], int size) {

	for (int i = 0; i < size; i += 2) {
		if (i + 1 < size) {
			swap(arr[i], arr[i + 1]);
		}
	}

}
int binarySearch(int arr[], int size, int key) {

	int start = 0;
	int end = size - 1;

	int mid = start + (end - start) / 2;

	while (start <= end) {

		if (arr[mid] == key) {
			return mid;
		}

		//go to right wala part
		if (key > arr[mid]) {
			start = mid + 1;
		}
		else { //key < arr[mid]
			end = mid - 1;
		}

		mid = start + (end - start) / 2;
	}

	return -1;
}
bool binarySearchRecur(int* arr, int s, int e, int k) {

	//base case

	//element not found
	if (s > e)
		return false;

	int mid = s + (e - s) / 2;

	//element found
	if (arr[mid] == k)
		return true;

	if (arr[mid] < k) {
		return binarySearchRecur(arr, mid + 1, e, k);
	}
	else {
		return binarySearchRecur(arr, s, mid - 1, k);
	}
}
vector<int> quickSort(vector<int> nums, int target)
{
	vector<int> ans;
	int step = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		cout << "step=" << step << endl;
		int select = i;
		cout << "select = " << select << endl;
		int nastedStep = 0;
		for (int j = i + 1; j < nums.size(); j++)
		{
			cout << "Nested step=" << nastedStep << endl;
			if (nums[select] > nums[j])
			{
				cout << "new selected item/index =" << nums[select] << "/" << select << "new/index=" << nums[j] << "/" << j << endl;
				select = j;
				cout << "   new select is now =" << j << endl;
			}
			nastedStep++;
		}
		cout << "time to swap nums[i] " << nums[i] << "to " << nums[select] << endl;
		printArr(nums);
		swap(nums[i], nums[select]);
		printArr(nums);


		step++;
	}
	printArr(nums);
	return ans;
}
vector<int> bubbleSort(vector<int> nums, int target)
{
	vector<int> ans;
	int step = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		cout << "step=" << step << endl;
		for (int j = 0; j < nums.size() - i; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				printArr(nums);
				swap(nums[j], nums[j + 1]);
				printArr(nums);
			}
		}
		step++;
	}
	printArr(nums);
	return ans;
}
void merge(int* arr, int s, int e)
{
	int mid = (s + e) / 2;
	int len1 = mid - s + 1;
	int len2 = e - mid;
	int* first = new int[len1];
	int* second = new int[len2];

	int mainIndex = s;
	// copy value 
	for (int i = 0; i < len1; i++)
	{
		first[i] = arr[mainIndex++];
	}
	mainIndex = mid + 1;
	for (int i = 0; i < len2; i++)
	{
		second[i] = arr[mainIndex++];
	}

	// merge to main arr
	int index1 = 0;
	int index2 = 0;
	mainIndex = s;
	while (index1 < len1 && index2 < len2)
	{
		if (first[index1] < second[index2])
		{
			arr[mainIndex++] = first[index1++];
		}
		else
		{
			arr[mainIndex++] = second[index2++];
		}
	}
	while (index1 < len1)
	{
		arr[mainIndex++] = first[index1++];

	}
	while (index2 < len2)
	{
		arr[mainIndex++] = second[index2++];
	}
	delete[]first;
	delete[]second;
}
void mergeSort(int* arr, int s, int e)
{
	// base case
	if (s >= e)return;
	int mid = (s + e) / 2;
	//first half
	mergeSort(arr, s, mid);
	// merge second
	mergeSort(arr, mid + 1, e);
	// merge
	merge(arr, s, e);

}
#pragma endregion


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
	int GiveCube(int num)
	{
		return  num * num * num;
	}
	void comm()
	{
		// data type 
		bool isMail = true;
		char alphabat = 'A';
#pragma region Number
		int age = 23;
		unsigned  int a = 33;
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
		string strUsingNameSpace = "the way to add namespace";
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

		sayHi("mu new funciton ");
		cout << GiveCube(3);
	}
};
bool decOrder(int a, int b)
{
	return a > b;
}


void vectorDemo1()
{
	// dynamic arry
	vector<int> v;
	vector<int> a(5, 1);// creat size 5 and set all as 1
	vector<int> last(a);// move all a vector in last vector

	cout << "print last" << endl;
	for (int i : last) {
		cout << i << " ";
	}cout << endl;

	cout << "Capacity-> " << v.capacity() << endl;//0
	v.push_back(1);
	v.pop_back();
	cout << "Capacity-> " << v.capacity() << endl;
	v.push_back(2);
	cout << "Capacity-> " << v.capacity() << endl;// double the size bcz half if full
	v.push_back(3);
	cout << "Capacity-> " << v.capacity() << endl;
	cout << "Size-> " << v.size() << endl;
	cout << "Elemetn at 2nd Index" << v.at(2) << endl;

	cout << "front " << v.front() << endl;
	cout << "back " << v.back() << endl;

	cout << "before pop" << endl;
	for (int i : v) {
		cout << i << " ";
	}cout << endl;

	v.pop_back();// remove last

	cout << "after pop" << endl;
	for (int i : v) {
		cout << i << " ";
	}
	cout << "before clear size " << v.size() << endl;
	v.clear();
	cout << "after clear size " << v.size() << endl;
}
void vectorDemo2()
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
	sort(A.begin(), A.end(), decOrder);
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
void deequeDemoLB()
{
	//push pop at both end double ended queue
	// created by many static fixed size array
	// its dynamic
	deque<int> d;

	d.push_back(1);
	d.push_front(2);

	//d.pop_front();
	cout << endl;

	cout << "Print First INdex Element-> " << d.at(1) << endl;

	cout << "front " << d.front() << endl;
	cout << "back " << d.back() << endl;

	cout << "Empty or not" << d.empty() << endl;

	cout << "before erase" << d.size() << endl;
	d.erase(d.begin(), d.begin() + 1);
	cout << "after erase" << d.size() << endl;
	for (int i : d) {
		cout << i << endl;
	}

}
void listDemoLB_usedByDD_LL()
{
	// doubly ll using
	// list is created via using doubly ll 
	// erasse o(n)
	// add o(1)
	list<int> l;
	list<int> copy(l);// copy list
	list<int> n(5, 100);// add five element with 100 as value

	cout << "Printing n" << endl;
	for (int i : n) {
		cout << i << " ";
	}cout << endl;
	l.push_back(1);
	l.push_front(2);

	for (int i : l) {
		cout << i << " ";
	}
	cout << endl;
	l.erase(l.begin());// it ll delete index
	cout << "after erase" << endl;
	for (int i : l) {
		cout << i << " ";
	}

	cout << "size of list" << l.size() << endl;
}
void stackDemoLB()
{
	stack<string> s;
	s.push("love");
	s.push("babbar");
	s.push("Kumar");
	cout << "Top Element-> " << s.top() << endl;
	s.pop();
	cout << "Top Element-> " << s.top() << endl;
	cout << "size of stack" << s.size() << endl;
	cout << "Empty or not " << s.empty() << endl;
}
void queueDemoLB()
{
	// complexity on
	queue<string> q;
	q.push("love");
	q.push("Babbar");
	q.push("Kumar");
	cout << "Size before pop" << q.size() << endl;
	cout << "First Element " << q.front() << endl;
	q.pop();
	cout << "First Element " << q.front() << endl;
	cout << "Size after pop" << q.size() << endl;
	q.empty();
	// double ended queue
	deque<int> d;
}
void priorityQueue_MaxHeapDemoLB()
{
	// first element always gratest
	//max heap
	priority_queue<int> maxi;
	maxi.empty();// true;
	//min - heap
	priority_queue<int, vector<int>, greater<int> > mini;

	maxi.push(1);// takes only log n
	maxi.push(3);
	maxi.push(2);
	maxi.push(0);
	cout << "size-> " << maxi.size() << endl; //3210
	int n = maxi.size();
	for (int i = 0; i < n; i++) {
		cout << maxi.top() << " ";
		maxi.pop();
	}cout << endl;

	mini.push(5);
	mini.push(1);
	mini.push(0);
	mini.push(4);
	mini.push(3);

	int m = mini.size();
	for (int i = 0; i < m; i++) {
		cout << mini.top() << " ";
		mini.pop();
	}cout << endl;//012345

	cout << "khaali h kya bhai  ?? -> " << mini.empty() << endl;
}
void setDemo1()
{
	// always store unique without err
	// implemented by bst
	// return sorted way 
	// unique no duplicate
	// use bst
	// unorderset is faster
	set<int> s;
	s.insert(5);// o(logn)
	s.insert(5);
	s.insert(5);
	s.insert(1);
	s.insert(6);
	s.insert(6);
	s.insert(0);
	s.insert(0);
	s.insert(0);
	auto count = s.count(0);
	auto pos = s.find(5);
	if (pos != s.end())
	{
		// found val
	}

	for (auto i : s) {
		cout << i << endl;
	}cout << endl;
	s.erase(s.begin());
	set<int>::iterator it = s.begin();
	it++;

	s.erase(it);

	for (auto i : s) {
		cout << i << endl;
	}
	cout << endl;
	cout << "-5 is present or not -> " << s.count(-5) << endl;

	set<int>::iterator itr = s.find(5);
	set<int>::iterator itr1 = s.find(55);

	for (auto it = itr; it != s.end(); it++) {
		cout << *it << " ";
	}cout << endl;

}
void setDemo2()
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
void mapDemo1()
{
	// key val
	// non sorted
	// searhc o log n 
	//increasing  order
	map<int, string> m;
	m[1] = "babbar";
	m[13] = "kumar";
	m[13] = "kumar1";
	m[2] = "love";


	unordered_map<int, string> umap;
	umap[0] = "umap";
	//auto b = umap.find(1);
	//b->first;
	m.insert({ 5,"bheem" });
	m.erase(4);
	cout << "before erase" << endl;
	for (auto i : m) {
		cout << i.first << " " << i.second << endl;
	}

	cout << "finding -13 -> " << m.count(13) << endl;
	cout << "finding -13 -> " << m.count(-13) << endl;

	// m.erase(13);
	cout << "after erase" << endl;
	for (auto i : m) {
		cout << i.first << " " << i.second << endl;
	}cout << endl << endl;

	auto it = m.find(5);

	for (auto i = it; i != m.end(); i++) {
		cout << (*i).first << endl;
	}

	map<int, int> mp;

	// Insert elements in random order
	mp.insert({ 2, 30 });
	mp.insert({ 1, 40 });
	mp.insert({ 3, 20 });
	mp.insert({ 3, 2 });
	mp.insert({ 4, 50 });
	mp.insert({ 5, 50 });

	cout << "Elements from position of 3 in the map are : \n";
	cout << "KEY\tELEMENT\n";

	// find() function finds the position
	// at which 3 is present
	for (auto itr = mp.find(3); itr != mp.end(); itr++) {

		cout << itr->first << '\t' << itr->second << '\n';
	}

}
void mapDemo2()
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
void pairDemo()
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
void algoDemoLB()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(6);
	v.push_back(7);
	cout << "Finding 6-> " << binary_search(v.begin(), v.end(), 6) << endl;
	cout << "lower bound-> " << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl;
	cout << "Uppper bound-> " << upper_bound(v.begin(), v.end(), 4) - v.begin() << endl;
	int a = 3;
	int b = 5;
	cout << "max -> " << max(a, b);
	cout << "min -> " << min(a, b);
	swap(a, b);
	cout << endl << "a-> " << a << endl;
	string abcd = "abcd";
	reverse(abcd.begin(), abcd.end());
	cout << "string-> " << abcd << endl;
	rotate(v.begin(), v.begin() + 1, v.end());
	cout << "after rotate" << endl;
	for (int i : v) {
		cout << i << " ";
	}
	sort(v.begin(), v.end());// intro sort // quick heap and insertion sort 
	cout << "after sorting" << endl;
	for (int i : v) {
		cout << i << " ";
	}

}

//oop 
class AbstractEmployee
{
	void AskForPromotion();
	// pure abstract
	virtual void AskForPromotion1() = 0;;
};
class Employee :AbstractEmployee {
	// default private modifire
private:
	string Key;
public:
	string Name;
	string Company;
	int Age;
	// getter settet
	void setKey(string key) {
		Key = key;
	}
	string getKey() {
		return Key;
	}
	Employee(string name,
		string company,
		int age)
	{
		Name = name;
		Company = company;
		Age = age;
	}
	void IntrouduceYoureself()
	{
		cout << "sdfsf" << endl;
	}
	void AskForPromotion1() {}
	void work() {}
};
// inheheritance
class Programmer :public Employee
{
public:
	string Language;
	Programmer(string name,
		string company,
		int age) :Employee(name, company, age) {

	}
	void work() {}

};
void oopEx()
{
	Employee employee1 = Employee("dfsdf", "dfsdf", 5);
	employee1.Name = "dfsdf";
	employee1.Company = "dfsdf";
	employee1.Age = 5;

	//Employee employee2;
	//employee2.Name = "dsfdsfsdf";
	//employee2.Company = "dfsdsdfsf";
	//employee2.Age = 5;
	employee1.setKey("23242");
	employee1.getKey();
	Programmer prog = Programmer(" ", " ", 55);
	Employee* ee = &prog;

	ee->work();
}

int count(int arr[], int size, int num)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (num == arr[i]) {
			arr[i] = INT_MIN;
			count++;
		}
	}
	return count;
}

bool checkUniqueCount(int arr[], int size = 0)
{
	int* result = new int[size];
	int* arr2 = new int[size];
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		arr2[i] = arr[i];
	}
	for (int i = 0; i < size; i++)
	{
		int c = count(arr2, size, arr[i]);
		// cout << c;
		if (c != 0)
		{
			result[k] = c;
			cout << result[i] << endl;
			k++;
		}
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (i != j && result[i] == result[j])
			{
				return false;
			}
		}
	}
	return true;
}
class NodeSingle
{
public:
	int data;
	NodeSingle* next;
	NodeSingle(int data)
	{
		this->data = data;
		this->next = NULL;
	}
	//destructor
	~NodeSingle() {
		int value = this->data;
		//memory free
		if (this->next != NULL) {
			delete next;
			this->next = NULL;
		}
		cout << " memory is free for node with data " << value << endl;
	}
};
void printLL(NodeSingle*& head) {
	NodeSingle* temp = head;

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
void deleteNode(int position, NodeSingle*& head) {

	//deleting first or start node
	if (position == 1) {
		NodeSingle* temp = head;
		head = head->next;
		//memory free start ndoe
		temp->next = NULL;
		delete temp;
	}
	else
	{
		//deleting any middle node or last node
		NodeSingle* curr = head;
		NodeSingle* prev = NULL;

		int cnt = 1;
		while (cnt < position) {
			prev = curr;
			curr = curr->next;
			cnt++;
		}

		prev->next = curr->next;
		curr->next = NULL;
		delete curr;

	}
}
void insertAtHead(NodeSingle*& head, int d) {

	// new node create
	NodeSingle* temp = new NodeSingle(d);
	temp->next = head;
	head = temp;
}
void insertAtTail(NodeSingle*& tail, int d) {
	// new node create
	NodeSingle* temp = new NodeSingle(d);
	tail->next = temp;
	tail = temp;
}
void insertAtPosition(NodeSingle*& tail, NodeSingle*& head, int position, int d) {


	//insert at Start
	if (position == 1) {
		insertAtHead(head, d);
		return;
	}

	NodeSingle* temp = head;
	int cnt = 1;

	while (cnt < position - 1) {
		temp = temp->next;
		cnt++;
	}

	//inserting at Last Position
	if (temp->next == NULL) {
		insertAtTail(tail, d);
		return;
	}

	//creating a node for d
	NodeSingle* nodeToInsert = new NodeSingle(d);

	nodeToInsert->next = temp->next;

	temp->next = nodeToInsert;
}
void LL()
{
	// run time dynamic ds , no memory waste
	//no shift needed in case beech men push karne pe 
	// type = single,double,circular,circular double ll
	NodeSingle* node0 = new NodeSingle(5);
	cout << node0->data << " " << node0->next << endl;//10 0x0

	 //created a new node
	NodeSingle* node1 = new NodeSingle(10);
	//cout << node1 -> data << endl;
   // cout << node1 -> next << endl;

	//head pointed to node1
	NodeSingle* head = node1;
	NodeSingle* tail = node1;
	printLL(head);

	insertAtHead(head, 12);

	printLL(head);

	insertAtTail(tail, 22);

	printLL(head);
	insertAtPosition(tail, head, 4, 23);
	printLL(head);

	deleteNode(4, head);
	printLL(head);
}
class NodeDouble
{
public:
	int data;
	NodeDouble* prev;
	NodeDouble* next;
	NodeDouble(int data)
	{
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}
	//destructor
	~NodeDouble() {
		int val = this->data;
		if (next != NULL) {
			delete next;
			next = NULL;
		}
		cout << "memory free for node with data " << val << endl;
	}
};
void printDLL(NodeDouble* head) {
	NodeDouble* temp = head;

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
//gives length of Linked List
int getLength(NodeDouble* head) {
	int len = 0;
	NodeDouble* temp = head;

	while (temp != NULL) {
		len++;
		temp = temp->next;
	}

	return len;
}
void insertAtHead(NodeDouble*& tail, NodeDouble*& head, int d) {

	//empty list
	if (head == NULL) {
		NodeDouble* temp = new NodeDouble(d);
		head = temp;
		tail = temp;
	}
	else {
		NodeDouble* temp = new NodeDouble(d);
		temp->next = head;
		head->prev = temp;
		head = temp;
	}

}
void insertAtTail(NodeDouble*& tail, NodeDouble*& head, int d) {
	if (tail == NULL) {
		NodeDouble* temp = new NodeDouble(d);
		tail = temp;
		head = temp;
	}
	else {
		NodeDouble* temp = new NodeDouble(d);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}

}
void insertAtPosition(NodeDouble*& tail, NodeDouble*& head, int position, int d) {

	//insert at Start
	if (position == 1) {
		insertAtHead(tail, head, d);
		return;
	}

	NodeDouble* temp = head;
	int cnt = 1;

	while (cnt < position - 1) {
		temp = temp->next;
		cnt++;
	}

	//inserting at Last Position
	if (temp->next == NULL) {
		insertAtTail(tail, head, d);
		return;
	}

	//creating a node for d
	NodeDouble* nodeToInsert = new NodeDouble(d);

	nodeToInsert->next = temp->next;
	temp->next->prev = nodeToInsert;
	temp->next = nodeToInsert;
	nodeToInsert->prev = temp;
}

void deleteNode(int position, NodeDouble*& head) {

	//deleting first or start node
	if (position == 1) {
		NodeDouble* temp = head;
		temp->next->prev = NULL;
		head = temp->next;
		temp->next = NULL;
		delete temp;
	}
	else
	{
		//deleting any middle node or last node
		NodeDouble* curr = head;
		NodeDouble* prev = NULL;

		int cnt = 1;
		while (cnt < position) {
			prev = curr;
			curr = curr->next;
			cnt++;
		}

		curr->prev = NULL;
		prev->next = curr->next;
		curr->next = NULL;

		delete curr;

	}
}
void LLDouble()
{
	//NodeDouble* head = NULL;
	NodeDouble* tail = NULL;
	NodeDouble* node1 = new NodeDouble(10);
	NodeDouble* head = node1;
	printDLL(head);
	getLength(head);
	insertAtHead(tail, head, 11);

}
class NodeCircular {
public:
	int data;
	NodeCircular* next;

	//constrcutor
	NodeCircular(int d) {
		this->data = d;
		this->next = NULL;
	}

	~NodeCircular() {
		int value = this->data;
		if (this->next != NULL) {
			delete next;
			next = NULL;
		}
		cout << " memory is free for node with data " << value << endl;
	}

};
void insertNodeCircular(NodeCircular*& tail, int element, int d) {


	//empty list
	if (tail == NULL) {
		NodeCircular* newNode = new NodeCircular(d);
		tail = newNode;
		newNode->next = newNode;
	}
	else {
		//non-empty list
		//assuming that the element is present in the list

		NodeCircular* curr = tail;

		while (curr->data != element) {
			curr = curr->next;
		}

		//element found -> curr is representing element wala node
		NodeCircular* temp = new NodeCircular(d);
		temp->next = curr->next;
		curr->next = temp;

	}

}

void printCircular(NodeCircular* tail) {

	NodeCircular* temp = tail;

	//empty list
	if (tail == NULL) {
		cout << "List is Empty " << endl;
		return;
	}

	do {
		cout << tail->data << " ";
		tail = tail->next;
	} while (tail != temp);

	cout << endl;
}

void deleteNodeCircular(NodeCircular*& tail, int value) {

	//empty list
	if (tail == NULL) {
		cout << " List is empty, please check again" << endl;
		return;
	}
	else {
		//non-empty

		//assuming that "value" is present in the Linked List
		NodeCircular* prev = tail;
		NodeCircular* curr = prev->next;

		while (curr->data != value) {
			prev = curr;
			curr = curr->next;
		}

		prev->next = curr->next;

		//1 NodeCircular Linked List
		if (curr == prev) {
			tail = NULL;
		}

		//>=2 NodeCircular linked list
		else if (tail == curr) {
			tail = prev;
		}

		curr->next = NULL;
		delete curr;

	}

}

void llCircular()
{
	NodeCircular* tail = NULL;

	insertNodeCircular(tail, 5, 3);
	printCircular(tail);

	insertNodeCircular(tail, 3, 5);
	printCircular(tail);
	/*
		insertNodeCircular(tail, 5, 7);
		printCircular(tail);
		insertNodeCircular(tail, 7, 9);
		printCircular(tail);
		insertNodeCircular(tail, 5, 6);
		printCircular(tail);

		insertNodeCircular(tail, 9, 10);
		printCircular(tail);
		insertNodeCircular(tail, 3, 4);
		printCircular(tail);
		*/

	deleteNodeCircular(tail, 5);
	printCircular(tail);
}
class NodeTrie {
public:
	string word;
	bool is_word = false;
	NodeTrie* children[26] = { NULL };
};
void insertTri(string& s, NodeTrie* root) {
	NodeTrie* temp = root;
	for (auto& i : s) {
		int k = i - 'a';
		if (temp->children[k] == NULL) {
			temp->children[k] = new NodeTrie;
		}
		temp = temp->children[k];
	}
	temp->word = s;
	temp->is_word = true;
}
void dfsTri(vector<vector<char>>& board, vector<string>& res, NodeTrie* temp, int i, int j) {

	if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '*' || !(temp->children[board[i][j] - 'a']))
		return;

	temp = temp->children[board[i][j] - 'a'];

	if (temp->is_word) {
		res.push_back(temp->word);
		temp->is_word = false;
	}

	char temp_char = board[i][j];
	board[i][j] = '*';

	dfsTri(board, res, temp, i + 1, j);
	dfsTri(board, res, temp, i, j + 1);
	dfsTri(board, res, temp, i - 1, j);
	dfsTri(board, res, temp, i, j - 1);

	board[i][j] = temp_char;

	return;
}
bool startsWith(string prefix, NodeTrie* root) {
	NodeTrie* cur = root;
	for (char c : prefix) {
		if (cur->children[c - 'a'] == NULL)return false;
		cur = cur->children[c - 'a'];
	}
	return true;
}
int main()
{
	mapDemo1();
	return 0;
}


