#ifndef EXCELLENTEAM_EREZ_CPP_SMART_POINTERS_AHMAD2806_SHAREDPTR_H

#define EXCELLENTEAM_EREZ_CPP_SMART_POINTERS_AHMAD2806_SHAREDPTR_H

#include "gtest/gtest.h"
#include <iostream>

template<typename T>
class SharedPtr {
public:
    explicit SharedPtr(T *ptr);

    ~SharedPtr();

    T *operator->() const;

    T &operator*() const;

    operator bool() const;

    template<typename U>
    SharedPtr<T> &operator=(U *t);

    SharedPtr<T> &operator=(T *t);

    T *get() const;

    SharedPtr(SharedPtr const &);

    SharedPtr &operator=(SharedPtr const &);

private:
    T *m_ptr;
    size_t *m_counter;

};


template<typename T>
SharedPtr<T>::SharedPtr(T *ptr): m_ptr(ptr) {
    m_counter = new size_t;
    *m_counter = 1;
}
template<typename T>
template<typename U>
SharedPtr<T> &SharedPtr<T>::operator=(U *ptr) {
    if (m_ptr != ptr) {
        this->check_and_delete();
        m_counter = new size_t(1);
        m_ptr = ptr;
    }
    return *this;

}
template<typename T>
SharedPtr<T>::~SharedPtr() {
    --(*m_counter);

    if (!*m_counter) {
        delete m_ptr;
        delete m_counter;
    }

}

template<typename T>
T *SharedPtr<T>::operator->() const {
    return m_ptr;
}

template<typename T>
T &SharedPtr<T>::operator*() const {
    return *m_ptr;
}

template<typename T>
SharedPtr<T>::operator bool() const {
    return bool(m_ptr);
}

template<typename T>
SharedPtr<T> &SharedPtr<T>::operator=(T *ptr) {
    if (m_ptr != ptr) {
        --(*m_counter);
        if (!*m_counter) {
            delete m_ptr;
            delete m_counter;
        }
        m_counter = new size_t;
        *m_counter = 1;
        m_ptr = ptr;
    }
    return *this;

}

template<typename T>
T *SharedPtr<T>::get() const {
    return m_ptr;
}

template<typename T>
SharedPtr<T>::SharedPtr(SharedPtr const &other) {
    m_counter = other.m_counter;
    m_ptr = other.m_ptr;
    ++(*m_counter);
}

template<typename T>
SharedPtr<T> &SharedPtr<T>::operator=(SharedPtr const &other) {
    --(*m_counter);

    if (!*m_counter) {
        delete m_ptr;
        delete m_counter;
    }

    m_counter = other.m_counter;
    m_ptr = other.m_ptr;
    ++(*m_counter);

    return *this;

}


TEST(SharedPointerBasicTests, AddressTest
) {
int *p = new int;
SharedPtr<int> tmp_ptr(p);
ASSERT_TRUE (p
== tmp_ptr.

get()

);
}

TEST(SharedPointerBasicTests, ArrowOperatorTest
) {
SharedPtr<std::string> tmp_ptr(new std::string);
*
tmp_ptr = "testing";
ASSERT_TRUE (tmp_ptr
->compare("testing") == 0);
}

TEST(SharedPointerBasicTests, StarOperatorTest
) {
int *p = new int;
*
p = 5;
SharedPtr<int> tmp_ptr(p);
ASSERT_TRUE (*p
== *tmp_ptr);

}

TEST(SharedPointerBasicTests, BoolCastTest
) {
SharedPtr<std::string> tmp_ptr(new std::string);
*
tmp_ptr = "testing";

ASSERT_TRUE(bool(tmp_ptr));

SharedPtr<std::string> tmp_ptr2(new std::string);
tmp_ptr2 = NULL;

ASSERT_FALSE(bool(tmp_ptr2));

}

TEST(SharedPointerBasicTests, GetTest
) {
int *p = new int;
SharedPtr<int> tmp_ptr(p);
ASSERT_EQ (tmp_ptr
.

get(), p

);

}

TEST(SharedPointerBasicTests, AssignmentFromPointerTest
) {
int *p = new int;
SharedPtr<int> tmp_ptr(p);
int *p1 = new int;
*
p1 = 5;
tmp_ptr = p1;
ASSERT_EQ (p1, tmp_ptr
.

get()

);

}

TEST(SharedPointerBasicTests, AssignmentFromSharedPointerTest
) {
int *p = new int;
*
p = 6;
SharedPtr<int> tmp_ptr(p);
int *p1 = new int(5);
SharedPtr<int> tmp_ptr1(p1);
tmp_ptr = tmp_ptr1;
ASSERT_EQ (tmp_ptr1
.

get(), tmp_ptr

.

get()

);

}

TEST(SharedPointerBasicTests, CopyCtorSharedPointerTest) {
int *p = new int;
*p = 6;
SharedPtr<int> tmp_ptr(p);
SharedPtr<int> tmp_ptr1(tmp_ptr);
ASSERT_EQ (tmp_ptr1.get(), tmp_ptr.get());

}
#endif //EXCELLENTEAM_EREZ_CPP_SMART_POINTERS_AHMAD2806_SHAREDPTR_H