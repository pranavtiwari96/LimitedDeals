#ifndef USER_H
#define USER_H

#include <bits/stdc++.h>
#include "Person.cpp"
using namespace std;


class User : public Person{
    User(int id, string name, long long phoneNo, string email)
        :Person(id, name, phoneNo, email, false)
        {}
};


#endif