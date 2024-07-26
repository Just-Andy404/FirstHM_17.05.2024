#pragma once

template <typename T>
class MyShared
{
    T* _ptr;
    int* _ptrCounter;
    void ptrCheck() {
        if (--(*_ptrCounter) == 0) {
            delete _ptr;
            delete _ptrCounter;
        }
    }
public:

    MyShared();
    explicit MyShared(T*);
    MyShared(const MyShared&);
    T* operator=(const MyShared&) noexcept;
    T& operator*();
    T* operator->();
    T* get();
    ~MyShared();

};

template<typename T>
inline MyShared<T>::MyShared()
{
    _ptr = nullptr;
    _ptrCounter = new int(0);
}

template<typename T>
inline MyShared<T>::MyShared(T* ptr)
{
    _ptr = ptr;
    _ptrCounter = new int(1);
}

template<typename T>
inline MyShared<T>::MyShared(const MyShared& ptr)
{
    _ptr = ptr._ptr;
    _ptrCounter = ptr._ptrCounter;
    (*_ptrCounter)++;
}

template<typename T>
inline T* MyShared<T>::operator=(const MyShared& newPtr) noexcept
{
    if (this != &newPtr) {
        ptrCheck();
        _ptr = newPtr._ptr;
        _ptrCounter = newPtr._ptrCounter;
        ++(*_ptrCounter);
    }
    return *this;
}

template<typename T>
inline T& MyShared<T>::operator*()
{
    return *_ptr;
}

template<typename T>
inline T* MyShared<T>::operator->()
{
    return _ptr;
}

template<typename T>
inline T* MyShared<T>::get()
{
    return _ptr;
}

template<typename T>
inline MyShared<T>::~MyShared()
{
    ptrCheck();
}