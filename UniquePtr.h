//
// Created by ahmad on 08/12/2018.
//

#ifndef EXCELLENTEAM_EREZ_CPP_SMART_POINTERS_AHMAD2806_UNIQUEPTR_H
#define EXCELLENTEAM_EREZ_CPP_SMART_POINTERS_AHMAD2806_UNIQUEPTR_H

#include <iostream>
template<typename T>
class UniquePtr {
public:
    explicit UniquePtr(T *ptr);

    ~UniquePtr();

    T *operator->() const;

    T &operator*() const;

    operator bool() const;

    UniquePtr &operator=(T *);

    T *get() const;

private:
    // Prevent coping
    UniquePtr(UniquePtr const &);

    UniquePtr &operator=(UniquePtr const &);
    T *m_ptr;
};

template<typename T>
UniquePtr<T>::UniquePtr(T *ptr): m_ptr(ptr) {}

template<typename T>
UniquePtr<T>::~UniquePtr() {
    delete m_ptr;
}

template<typename T>
T *UniquePtr<T>::operator->() const {
    return m_ptr;
}

template<typename T>
T &UniquePtr<T>::operator*() const {
    return *m_ptr;
}

template<typename T>
UniquePtr<T>::operator bool() const {
    return bool(m_ptr);
}

template<typename T>
UniquePtr<T> &UniquePtr<T>::operator=(T *other) {
    delete m_ptr;
    m_ptr = other;
    return *this;

}

template<typename T>
T *UniquePtr<T>::get() const {
    return m_ptr;
}

template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr const &) {}

template<typename T>
UniquePtr<T> &UniquePtr<T>::operator=(UniquePtr const &) {}

#endif //EXCELLENTEAM_EREZ_CPP_SMART_POINTERS_AHMAD2806_UNIQUEPTR_H
