//
// Created by ahmad on 04/12/2018.
//

#ifndef PERSON_MY_TEMPLATES_H
#define PERSON_MY_TEMPLATES_H

#include<iostream>

template<typename T, unsigned long SIZE>
class AllocTemplate : public T {
public:

    AllocTemplate(const T& obj);
    void *operator new(size_t count);
    void operator delete(void *ptr);

private:
    static void *s_free_list;
    static unsigned char s_pool[];
    const static int POOL_SIZE = 5;

    static void *init_memory_pool();
    void *operator new[](size_t);
    void operator delete[](void *);
};

template<typename T, unsigned long SIZE>
unsigned char AllocTemplate<T, SIZE>::s_pool[sizeof(T) * SIZE];

template<typename T, unsigned long SIZE>
void *AllocTemplate<T, SIZE>::s_free_list = AllocTemplate<T, SIZE>::init_memory_pool();

template<typename T, unsigned long SIZE>
void *AllocTemplate<T, SIZE>::init_memory_pool() {

    unsigned char *memory_pool = AllocTemplate::s_pool;

    for (int i = 0; i < AllocTemplate::POOL_SIZE - 1; i++) {

        *(void **) memory_pool = memory_pool + sizeof(AllocTemplate);
        memory_pool = memory_pool + sizeof(AllocTemplate);
    }
    *(void **) memory_pool = 0;
    return AllocTemplate::s_pool;
}

template<typename T, unsigned long SIZE>
void *AllocTemplate<T, SIZE>::operator new(size_t size) {
    void *free_item = s_free_list;
    if (!free_item) {
        throw std::bad_alloc();
    }
    s_free_list = *(void **) s_free_list;
    return free_item;
}

template<typename T, unsigned long SIZE>
void AllocTemplate<T, SIZE>::operator delete(void *ptr) {
    *(void **) ptr = AllocTemplate::s_free_list;
    AllocTemplate::s_free_list = ptr;

}

//first solution
template<typename T, unsigned long SIZE>
AllocTemplate<T, SIZE>::AllocTemplate(const T &obj): T(obj) {}



#endif //PERSON_MY_TEMPLATES_H
