//
// Created by ahmad on 04/12/2018.
//

#ifndef PERSON_PERSON_H
#define PERSON_PERSON_H
class Person {

public:
    Person(Person &other);
    Person(const char full_name[32], unsigned int id,unsigned char age);
    char* get_full_name();

private:
    char m_full_name[32];
    unsigned int m_id;
    unsigned char m_age;

};

#endif //PERSON_PERSON_H
