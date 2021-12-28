#ifndef ADMIN_H
#define ADMIN_H

#include <bits/stdc++.h>
#include "Person.cpp"
using namespace std;


class Admin : public Person{
    Admin(int id, string name, long long phoneNo, string email)
        :Person(id, name, phoneNo, email, true)
        {}
};


#endif