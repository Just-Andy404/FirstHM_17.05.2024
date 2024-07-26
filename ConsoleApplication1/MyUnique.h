#pragma once
#include <iostream>

template <typename T>
class MyUnique
{
    T* _ptr;
public:

    MyUnique();
    explicit MyUnique(T*);
    MyUnique(const MyUnique&) = delete; 
    MyUnique& operator=(const MyUnique&) = delete; 
    void remove(MyUnique&) noexcept;
    T& operator*();
    T* operator->();
    T* get();
    ~MyUnique();
};

template<typename T>
inline MyUnique<T>::MyUnique()
{
    _ptr = nullptr;
}

template<typename T>
inline MyUnique<T>::MyUnique(T* ptr)
{
    _ptr = ptr;
}

template<typename T>
inline void MyUnique<T>::remove(MyUnique& ptr) noexcept
{
    _ptr = ptr._ptr;
    ptr._ptr = nullptr;
}

template<typename T>
inline T& MyUnique<T>::operator*()
{
    if (_ptr == nullptr) {
        std::cerr << "Dereferencing null pointer" << std::endl;
        while (true) {}
    }
    return *_ptr;
}

template<typename T>
inline T* MyUnique<T>::operator->()
{
    return _ptr;
}

template<typename T>
inline T* MyUnique<T>::get()
{
    return _ptr;
}

template<typename T>
inline MyUnique<T>::~MyUnique()
{
    if (_ptr != nullptr)
    {
        delete _ptr;
    }
}
