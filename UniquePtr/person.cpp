#include <iostream>
#include <stddef.h>
#include "cstring"
#include "person.h"


Person::Person(const char name[32], unsigned int id, unsigned char age):m_id(id),m_age(age){
    strcpy(m_full_name,name);
}

Person::Person(Person &other) {
    strcpy(m_full_name,other.m_full_name);
    m_id = other.m_id;
    m_age = other.m_age;
}

char *Person::get_full_name() {
    return m_full_name;
}


