#ifndef ID_GEN_H
#define ID_GEN_H

#include <bits/stdc++.h>
using namespace std;

class IdGenerator{
    private:
        int id;
    public:
        IdGenerator(){
            this->id = 0;
        }
        static IdGenerator* instance;
        IdGenerator* getInstance(){
            if(instance == NULL)
                instance = new IdGenerator();
            return instance;
        }
        int getId(){
            return this->id++;
        }
};
#endif