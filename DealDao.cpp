#ifndef DEAL_DAO_H
#define DEAL_DEAO_H

#include<bits/stdc++.h>
#include "Person.cpp"
#include "Deal.cpp"
#include "UserDeal.cpp"
#include "IdGenerator.cpp"
using namespace std;


//create , end, update, claim
class DealDao{
    private:
        map <int, Person*> personDb;
        map <int, Deal*> dealDb;
        map <int, UserDeal*> userDealDb;
    public:
        DealDao(){};

        IdGenerator* idGen = idGen->getInstance();
        static DealDao* instance;
        DealDao* getInstance(){
            if(instance == NULL)
                instance = new DealDao();
            return instance;
        }
        Person* loggedInUser;
        Person* login(int personId)
        {
            if(personDb.find(personId) != personDb.end())
            {
                cout << "Person logged in with id " << personId << endl;
                loggedInUser = personDb[personId];
                return loggedInUser;
            }
            
            cout << "User not registered !!" << endl;
            return NULL;
        }
        Person* registerUser(string name, long long phoneNo, string emailId, bool isAdmin)
        {
            for(auto& personDbIterator : personDb)
            {
                if(personDbIterator.second->getEmail() == emailId)
                {
                    cout << "User already registered !!" <<endl;
                    return NULL;
                }
            }
                int id = idGen->getId();
                Person* person = new Person(id, name, phoneNo, emailId, isAdmin);
                personDb.insert({id, person});
                cout<<"Person registered successfully!!" << endl;
                return person;

        }

        Deal* createDeal(string itemName, double price, time_t createTime, time_t endTime, int maxItem)
        {
            if(loggedInUser->getIsAdmin() == false)
            {
                cout << "User cannot add Deals " << endl;
                return NULL;
            }
            int id = idGen->getId();
            Deal* deal = new Deal(id, itemName, price, createTime, endTime, maxItem);
            dealDb.insert({id, deal});
            cout << "Deal created successfully " << endl;
            return deal;
        }
        bool endDeal(int dealId)
        {
            if(dealDb.find(dealId) == dealDb.end())
            {
                cout << "Invalid dealId provided " << endl;
                return false;
            }
            dealDb.erase(dealId);
            return true;
        }

        bool claimDeal(int dealId, int personId)
        {
            if(loggedInUser->getIsAdmin() == true)
            {
                cout << "Admin cant claim Deals" << endl;
                return false;
            }
            if(dealDb.find(dealId) == dealDb.end())
            {
                cout << "Invaild DEAL CLAIMED" << endl;
                return false;
            }
            if(personDb.find(personId) == personDb.end())
            {
                cout << "Invalid person wants to claim the deal " << endl;
                return false;
            }
            Deal* deal = dealDb[dealId];
            if(deal->getMaxQuantityAllowed() > 1)
                deal->setMaxQuantityAllowed(deal->getMaxQuantityAllowed() - 1);
            else
            {
                cout << "Sorry out of stock!!" << endl;
                return false;
            }
            time_t currTime;
            time(&currTime);

            if(difftime(currTime, deal->getCreateTime()) < 0)
            {
                 cout << "deal not started" << endl;
                return false;
        
            }
            else if(difftime(currTime, deal->getEndTime()) > 0)
            {
                 cout << "deal ended" << endl;
                return false;
        
            }   
            dealDb[dealId] = deal;
            int id = idGen->getId();
            UserDeal* userDeal = new UserDeal(id, personId, dealId );
            userDealDb.insert({id, userDeal});
            return true;
        }
        
};
#endif