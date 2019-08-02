// Smart Pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <memory>

using namespace std;
int* returnuniqueptr();
shared_ptr<vector<int>> returnsharedptr();


//Struct used for weak pointer that prints out when the constructor is made and when the destructor is made.
struct returnweakptr{
	returnweakptr() 
	{
		cout << "\nWeakptr constructor" << endl;
	}
	~returnweakptr() 
	{
		cout << "\nWeakptr destructor" << endl;
		
		system("pause");
	}

};



int main()
{
	//Testing unique  pointer by returning a unique pointer.
	int* testuniqueptr = returnuniqueptr();
	//Prints out what's inside the pointer and what elements are inside.
	cout << "\nInside main:\n";
	cout << "Pointer: " << testuniqueptr << endl;
	cout << " Element 1: " << *testuniqueptr << endl;
	cout << " Element 2: " << *(++testuniqueptr) << endl;
	//Testing a shared pointer by returning a shared pointer.
	auto testsharedpointer = returnsharedptr();
	//Prints out what's inside the pointer and what elements are inside.
	cout << "\nInside main:\n";
	cout << "Pointer: " << testsharedpointer.get() << endl;
	cout << " Element 1: " << (*testsharedpointer)[0] << endl;
	cout << " Element 2: " << testsharedpointer->back() << endl;
	//Counts and prints how many references there is to the shared pointer
	cout << " Count: " << testsharedpointer.use_count() << endl;
	
	//Counts the references of the shared pointer and weak pointer.
	shared_ptr<returnweakptr> sp(new returnweakptr);
	cout << "Count one: " << sp.use_count() << endl;
	weak_ptr<returnweakptr> wp = sp;
	cout << "Count two: " << sp.use_count() << endl;

	system("pause");
	return 0;

}

int* returnuniqueptr()
{
	cout << "Inside returnuniqueptr:\n";
	//Created unique pointer that stores integer array with two elements.
	unique_ptr<int[]> uniqueptrarray(new int[2]);
	//Sets the two elements inside the array.
	uniqueptrarray[0] = 3;
	uniqueptrarray[1] = 4;
	//Getting raw pointer from unique pointer.
	int* arrayptr = uniqueptrarray.get();
	cout << "Pointer: " << arrayptr << endl;
	cout << " Element 1: " << *arrayptr << endl;
	cout << " Element 2: " << *(++arrayptr) << endl;
	//Return the unique pointer
	return (uniqueptrarray.get());
}

shared_ptr<vector<int>> returnsharedptr()
{

	cout << "\nInside returnsharedptr:\n";
	//Create a vector to store values.
	vector<int> vect;
	//Shared pointer that is a pointer to the vector.
	//Add values to pointer.
	vect.push_back(3);
	vect.push_back(4);
	shared_ptr<vector<int>> sharedvectorptr = make_shared<vector<int>>(vect);
	//Print out pinter a long with both the elements.
	cout << "Pointer: " << sharedvectorptr.get() << endl;
	cout << " Element 1: " << (*sharedvectorptr)[0] << endl;
	cout << " Element 2: " << sharedvectorptr->back() << endl;
	cout << " Count: " << sharedvectorptr.use_count() << endl;
	//Return the shared pointer
	return sharedvectorptr;
	
}
