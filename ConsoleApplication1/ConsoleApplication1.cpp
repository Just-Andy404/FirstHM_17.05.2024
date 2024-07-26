/*
Создайте пользовательские классы умных указателей для пользователя.
Один из классов должен повторять функциональность
стандартного класса unique_ptr, а другой shared_ptr. Напишите код по тестированию ваших классов.
*/
#include <iostream>
#include "MyUnique.h"
#include "MyShared.h"
using namespace std;


int main()
{
	//MyUnique
    cout << endl << "--------------------------------" << endl;
    cout << "MyUnique" << endl;
    cout << "--------------------------------" << endl << endl;
    MyUnique<int> newPtr(new int(1000));
    cout << "My ptr1 :" << *newPtr << endl;
    cout << "--------------------------------" << endl;
    MyUnique<int> newPtr2;
    newPtr2.remove(newPtr); 

    if (newPtr2.get() != nullptr) {
        cout << "My ptr2 :" << *newPtr2 << endl;
    }
    else {
        cout << "newPtr2 is null" << endl;
    }

    if (newPtr.get() != nullptr) {
        cout << "My ptr1 :" << *newPtr << endl;
    }
    else {
        cout << "newPtr is null" << endl;
    }


	////MyShared
    cout << endl << "--------------------------------" << endl;
    cout << "MyShared" << endl;
	cout << "--------------------------------" << endl << endl;
	MyShared<int> ptr(new int(500));
	cout << "My ptr :" << *ptr << endl;
	MyShared<int> ptr2(ptr);
	cout << "My ptr2 :" << *ptr2 << endl;

	return 0;
}