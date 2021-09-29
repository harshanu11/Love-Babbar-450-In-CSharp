#include <iostream>
#include <cmath>// for math opration
#include <string>// get user input as string 
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
class Book1:public Book
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
	b.auther =  "abc";
	b.pages = 555;
	b.auther = "me bitch";
#pragma endregion


	SayHi("mu new funciton ");
	cout << GiveCube(3);
	return 0;
}


