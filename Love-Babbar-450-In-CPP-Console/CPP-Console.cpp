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

#pragma region Debug section
void printArr(int arr[], int s)
{
	for (int i = 0; i < s; i++)
	{
		cout << arr[i] << " ";
	}
}
void printArr(vector<int> arr, int s=0)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
}
vector<int> towSum(vector<int> nums, int target)
{
	vector<int> ans;
	vector<int> num0(nums);
	sort(nums.begin(), nums.end());
	int start = 0, end = nums.size() - 1;
	int step = 0;
	int arr1 = 0, arr2 = 0;

	while (start <= end)
	{
		cout << "Step =" << step << ";s1=" << start << "/" << nums[start] << "    s2="
			<< end << "/" << nums[end] << ";";
		int sum = nums[start] + nums[end];
		cout << "sum value= " << sum << ";target =" << target;
		if (sum == target)
		{
			cout << endl;
			cout << "target achieved" << ";  s1=" << start << "/" << nums[start] << "    s2="
				<< end << "/" << nums[end] << ";" << endl << endl;
			arr1 = nums[start];
			arr2 = nums[end];
			break;
		}
		if (sum > target)
		{
			end--;
			//cout << "change end " << end << "arr =" <<nums[end];
		}
		else if (sum < target)
		{
			start++;
			//cout << "change start " << start << "arr =" <<nums[start];
		}
		step++;
		cout << endl << endl;
	}
	step = 0;
	int ind1 = 0, ind2 = 0;
	for (int i = 0; i < num0.size(); i++)
	{
		cout << "Step =" << step;
		if (num0[i] == arr1)
		{
			ind1 = i;
			cout << "num0[i] == arr1 =" << i;
			cout << endl;
			break;
		}
		cout << endl;
		step++;
	}
	step = 0;
	for (int i = 0; i < num0.size(); i++)
	{
		cout << "Step =" << step;
		if (num0[i] == arr2 && i != ind2)
		{
			ind2 = i;
			cout << "num0[i] == arr2 =" << i;
			cout << endl;
			break;
		}
		cout << endl;
		step++;
	}
	ans.push_back(ind1);
	ans.push_back(ind2);

	cout << ind1 << endl;
	cout << ind2 << endl;
	return ans;
}
#pragma endregion


#pragma region Phase one basic loop function array string math 
void sayHi(string name)
{
	int a = 0;
	string user;
	cin >> user;
	// "\n"  for next line '\t' tab
	cout << "\n hello user" << name << user << '\n' << endl;
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


	string strUsingNameSpace = "the way to add namespace";
	strUsingNameSpace.length();
	char dsf = strUsingNameSpace[2];
	strUsingNameSpace.find('d');
	strUsingNameSpace.find("sfsf");
	strUsingNameSpace.find("sfsf", 5);// look from index 5
	strUsingNameSpace.substr(8, 5);// start , till length
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


void arrayDemoLB()
{
	int dost[10];
	int sizeDost = sizeof(dost) / sizeof(int);// not always correct
	int basic[3] = { 1,2,3 };
	array<int, 4> a = { 1,2,3,4 };//  this stl array so need namespace
	int size = a.size();
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
}
void priorityQueue_MaxHeapDemoLB()
{
	// first element always gratest
	//max heap
	priority_queue<int> maxi;

	//min - heap
	priority_queue<int, vector<int>, greater<int> > mini;

	maxi.push(1);
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
	m[2] = "love";


	unordered_map<int, string> umap;
	umap[0] = "umap";
	m.insert({ 5,"bheem" });

	cout << "before erase" << endl;
	for (auto i : m) {
		cout << i.first << " " << i.second << endl;
	}

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

int main()
{
	mapDemo1();
	return 0;
}


