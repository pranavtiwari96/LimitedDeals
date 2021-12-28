#ifndef USER_DEAL_H
#define USER_DEAL_H


#include <bits/stdc++.h>
using namespace std;

class UserDeal
{
    private:
        int id;
        int userId;
        int dealId;

    public:
        UserDeal(int id, int userId, int dealId)
        {
            this->id = id;
            this->userId  = userId;
            this->dealId = dealId;
        }
        int getId() {
        	return this->id;
        }
        void setId(int id) {
        	this->id = id;
        }


        int getUserId() {
        	return this->userId;
        }
        void setUserId(int userId) {
        	this->userId = userId;
        }


        int getDealId() {
        	return this->dealId;
        }
        void setDealId(int dealId) {
        	this->dealId = dealId;
        }

};
#endif