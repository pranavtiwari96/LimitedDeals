#include "Admin.cpp"
#include "Deal.cpp"
#include "DealDao.cpp"
#include "IdGenerator.cpp"
#include "Person.cpp"
#include "User.cpp"
#include "UserDeal.cpp"
#include <bits/stdc++.h>
using namespace std;

IdGenerator* IdGenerator::instance = 0;
DealDao* DealDao::instance = 0;

int main ()
{
    DealDao* deal = deal->getInstance();
    Person* admin = deal->registerUser("Pranav", 9646111111, "pranav@gmail.com", true);
    admin = deal->login(admin->getPersonId());

    tm* startDate;
    time_t rawTime;
    time(&rawTime);
    startDate = localtime(&rawTime);
    startDate->tm_year = 2021 - 1900;
    startDate->tm_mon = 11 - 1;
    startDate->tm_mday = 28;
    startDate->tm_hour = 21;
    startDate->tm_min = 00;
    

    tm* endDate;
    endDate = localtime(&rawTime);
    endDate->tm_year = 2021 - 1900;
    endDate->tm_mon = 11 - 1;
    endDate->tm_mday = 28;
    endDate->tm_hour = 23;
    endDate->tm_min = 00;

    time_t startTime = mktime(startDate);
    time_t endTime = mktime(endDate);

    Deal* deal1 = deal->createDeal("Phone", 150.00, startTime, endTime, 20);
    int idReq = deal1->getDealId();

    Person* user = deal->registerUser("Raghav", 9646396118, "raghav@gmail.com", false);
    user = deal->login(user->getPersonId());

    if(deal->claimDeal(deal1->getDealId(), user->getPersonId()))
    {
        cout << "Deal claimed !!"<< endl;
    }
    else
    {
        cout << "Deal Not claimed "<< endl;
    }

    



    return 0;
}