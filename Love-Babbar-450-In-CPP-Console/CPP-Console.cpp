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
using namespace std;
void SayHi(string name)
{
	int a;
	cout << "\n hello user" << name << '\n' << endl;
	//cin >> a;
	cout << "namaste duniya\t" << a << "\t" << endl;
}
void DataTypeAndVariable()
{
	// data type 
	bool isMail = true;
	char alphabat = 'A';
	//cin.get() give char vale
#pragma region Number
	int age = 23;
	auto max = INT_MAX;
	int b = sizeof(age);
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
	std::string strUsingNameSpace = "the way to add namespace";
	strUsingNameSpace.length();
	char dsf = strUsingNameSpace[2];
	strUsingNameSpace.find('d');
	strUsingNameSpace.find("sfsf");
	strUsingNameSpace.find("sfsf", 5);// look from index 5
	strUsingNameSpace.substr(8, 5);// start , till length
#pragma endregionint a = 5;
}
void PrintPattern()
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
int GiveCube(int num)
{
	return  num * num * num;
}
void BitWiseOperator()
{
	int a = 4;
	int b = 6;
	auto c = ~a;
	//int a = 55;
	// !a == 0  or one
	cout << " a&b " << (a & b) << endl;
	cout << " a|b " << (a | b) << endl;
	cout << " ~a " << ~a << endl;// tows compliment
	cout << " a^b " << (a ^ b) << endl;

	cout << (17 >> 1) << endl;// devide by 2
	cout << (17 >> 2) << endl;// devide by 2
	cout << (19 << 1) << endl; // multiply by 2
	cout << (21 << 2) << endl; // multiply by 2
}
void DecToBin()
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
void BinToDec()
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
void ReverseInt() 
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

	int temp = 1;
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

	cout << endl;
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
void LoopCondition()
{
	int i = 7;

	cout << (++i) << endl;
	// 8 
	cout << (i++) << endl;
	// 8 , i = 9
	cout << (i--) << endl;
	//9 , i = 8 
	cout << (--i) << endl;
	int n;
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

void ArrayDemoLB()
{
	int basic[3] = { 1,2,3 };
	array<int, 4> a = { 1,2,3,4 };// stl 
#define R 4
#define C 4
	int maze[R][C] = { {0, 0, 0, 0},
			   {0, -1, 0, 0},
			   {-1, 0, 0, 0},
			   {0, 0, 0, 0} };
	int size = a.size();

	for (int i = 0; i < size; i++) {
		cout << a[i] << endl;
	}
	cout << "Element at 2nd Index-> " << a.at(2) << endl; //3
	cout << "Empty or not-> " << a.empty() << endl;// false
	cout << "First Element-> " << a.front() << endl;//1
	cout << "last Element-> " << a.back() << endl;//4
};
void VectorDemoLB()
{
	// dynamic arry
	vector<int> v;
	vector<int> a(5, 1);// creat size 5 and set all as 1
	vector<int> last(a);// move all  a in last 

	cout << "print last" << endl;
	for (int i : last) {
		cout << i << " ";
	}cout << endl;

	cout << "Capacity-> " << v.capacity() << endl;//0
	v.push_back(1);
	cout << "Capacity-> " << v.capacity() << endl;
	v.push_back(2);
	cout << "Capacity-> " << v.capacity() << endl;
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
void DeequeDemoLB()
{
	//push pop at both end double ended queue
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
void ListDemoLB()
{
	// list is created via using doubly ll 
	// erasse o(n)
	// add o(1)
	list<int> l;
	list<int> n(5, 100);

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
	l.erase(l.begin());
	cout << "after erase" << endl;
	for (int i : l) {
		cout << i << " ";
	}

	cout << "size of list" << l.size() << endl;
}
void StackDemoLB()
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
void QueueDemoLB()
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
void PriorityQueue_MaxHeapDemoLB()
{
	//max heap
	priority_queue<int> maxi;

	//min - heap
	priority_queue<int, vector<int>, greater<int> > mini;

	maxi.push(1);
	maxi.push(3);
	maxi.push(2);
	maxi.push(0);
	cout << "size-> " << maxi.size() << endl;
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
	}cout << endl;

	cout << "khaali h kya bhai  ?? -> " << mini.empty() << endl;
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
void SetDemoLB()
{
	// unique no duplicate
	// use bst
	// unorderset is faster
	set<int> s;

	s.insert(5);
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
void MapDemoLB()
{
	map<int, string> m;

	m[1] = "babbar";
	m[13] = "kumar";
	m[2] = "love";

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
void AlgoDemoLB()
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
	sort(v.begin(), v.end());
	cout << "after sorting" << endl;
	for (int i : v) {
		cout << i << " ";
	}

}
void decToBin()
{
	int n;
	cin >> n;


	int ans = 0;
	int i = 0;
	while (n != 0) {

		int bit = n & 1;

		ans = (bit * pow(10, i)) + ans;

		n = n >> 1;
		i++;

	}

	cout << " Answer is " << ans << endl;
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
void OopEx()
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
int main()
{
	//SPairDemo();
	string a = "11", b = "1";

	for (int i = 0; i < a.size(); i++) {}
	return 0;
}


