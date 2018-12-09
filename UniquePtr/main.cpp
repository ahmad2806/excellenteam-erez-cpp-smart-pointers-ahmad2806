
#include <iostream>
#include <cassert>
#include <cstring>

#include "UniquePtr.h"
#include "person.h"


int main() {
    char p_name[32] = "ahmad";
    char p_name0[32] = "ahmad0";
    Person *per = new Person(p_name0, 1, 2);


    UniquePtr<Person> p1(new Person(p_name, 1, 2));

    assert(strcmp("ahmad", p1->get_full_name()) == 0);
    assert(strcmp("ahmad", (*p1).get_full_name()) == 0);

    assert(strcmp("ahmad", (p1.get())->get_full_name()) == 0);
    assert(strcmp("ahmad", (*(p1.get())).get_full_name()) == 0);

    {
        UniquePtr<Person> p0(new Person(p_name, 1, 2));
        p0 = per;

        assert(strcmp("ahmad0", p0->get_full_name()) == 0);
        assert(strcmp("ahmad0", (*p0).get_full_name()) == 0);

        assert(strcmp("ahmad0", (p0.get())->get_full_name()) == 0);
        assert(strcmp("ahmad0", (*(p0.get())).get_full_name()) == 0);

    }

    assert(p1);
    p1 = 0;
    assert(!p1);


    return 0;
}