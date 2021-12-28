#ifndef PERSON_H
#define PERSON_H

#include <bits/stdc++.h>
using namespace std;

class Person{
    private:
        int personId;
        string name;
        long long phoneNo;
        string email;
        bool isAdmin;

    public:
        Person(int pId, string name, long long phoneNo, string email, bool isAdmin)
        {
            this->personId = pId;
            this->name = name;
            this->phoneNo = phoneNo;
            this->email = email;
            this->isAdmin = isAdmin;
        }

        int getPersonId() {
            return this->personId;
        }
        void setPersonId(int personId) {
            this->personId = personId;
        }


        string getName() {
        	return this->name;
        }
        void setName(string name) {
        	this->name = name;
        }


        long long getPhoneNo() {
            return this->phoneNo;
        }
        void setPhoneNo(long long phoneNo) {
            this->phoneNo = phoneNo;
        }



        string getEmail() {
        	return this->email;
        }
        void setEmail(string email) {
        	this->email = email;
        }


        bool getIsAdmin() {
        	return this->isAdmin;
        }
        void setIsAdmin(bool isAdmin) {
        	this->isAdmin = isAdmin;
        }

};

#endif




/*
Person  (id, name, phoneNo, email, bool isAdmin)
    User
    Admin
    */