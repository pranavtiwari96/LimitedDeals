#ifndef DEAL_H
#define DEAL_H


#include <bits/stdc++.h>
using namespace std;

// Deal (id, itemName, price, createTime, endTime, maxQtyAllowed, string itemDesc
class Deal{
    private:
        int dealId;
        string itemName;
        double price;
        time_t createTime;
        time_t endTime;
        int maxQuantityAllowed;

    public:

        Deal(int id, string itemName, double price, time_t createTime, time_t endTime, int maxQuantityAllowed)
        {
            this->dealId = id;
            this->itemName = itemName;
            this->price = price;
            this->createTime = createTime;
            this->endTime = endTime;
            this->maxQuantityAllowed = maxQuantityAllowed;
        }
        int getDealId() {
            return this->dealId;
        }
        void setDealId(int dealId) {
            this->dealId = dealId;
        }


        string getItemName() {
        	return this->itemName;
        }
        void setItemName(string itemName) {
        	this->itemName = itemName;
        }


        double getPrice() {
        	return this->price;
        }
        void setPrice(double price) {
        	this->price = price;
        }


        time_t getCreateTime() {
        	return this->createTime;
        }
        void setCreateTime(time_t createTime) {
        	this->createTime = createTime;
        }


        time_t getEndTime() {
        	return this->endTime;
        }
        void setEndTime(time_t endTime) {
        	this->endTime = endTime;
        }


        int getMaxQuantityAllowed() {
        	return this->maxQuantityAllowed;
        }
        void setMaxQuantityAllowed(int maxQuantityAllowed) {
        	this->maxQuantityAllowed = maxQuantityAllowed;
        }

                


};


#endif