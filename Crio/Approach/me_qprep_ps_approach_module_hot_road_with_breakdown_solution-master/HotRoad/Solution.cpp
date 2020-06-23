#include <bits/stdc++.h>
using namespace std;
// CRIO_SOLUTION_START_MODULE_HOT_ROAD

int regNumberToInteger(string s)
{
    string bench="KA01AA0001";
    int c=0;
    c+=(s[9]-'0');
    c+=(s[8]-'0')*10;
    c+=(s[7]-'0')*100;
    c+=(s[6]-'0')*1000;
    c+=(s[5]-'A')*9999;
    c+=(s[4]-'A')*9999*26;
    c+=(s[3]-'1')*9999*26*26;
    c+=(s[2]-'0')*9999*26*10*26;
    return c;
}

int seatsLeft(pair<int, pair<int,int > >& goodCar){
    return goodCar.second.second - goodCar.second.first;
}
bool inRange(pair<int, pair<int,int > > code_of_first_car,pair<int,int >  code_of_second_car ,int dist)
{
    return abs(code_of_first_car.first - code_of_second_car.first) <= dist;
}

// CRIO_SOLUTION_END_MODULE_HOT_ROAD

// Finish this function

int findMaximumNumberOfPeopleAccomodated(vector< pair<string , int> >& broken, vector<pair< string ,pair<int,int > > >& good, int dist)
{
    // CRIO_SOLUTION_START_MODULE_HOT_ROAD
    vector<pair<int,int > > brokenCars;
    vector<pair<int, pair<int,int > > > goodCars;
    for(auto i:broken)
	brokenCars.push_back({regNumberToInteger(i.first),i.second});
    sort(brokenCars.begin(),brokenCars.end());
    for(auto i:good)
	goodCars.push_back({regNumberToInteger(i.first),{i.second.first,i.second.second}});
    sort(goodCars.begin(),goodCars.end());
    int numBrokenCars = brokenCars.size();
    int numGoodCars = goodCars.size();

    int goodCount = 0;
    int brokenCount = 0 ;
    int result =0;

    while(goodCount < numGoodCars && brokenCount < numBrokenCars){
	pair<int, pair<int,int > > oneGoodCar = goodCars[goodCount];
	pair<int,int > oneBrokenCar = brokenCars[brokenCount];
	int numSeatsLeft = seatsLeft(oneGoodCar);

	if(!inRange(oneGoodCar, oneBrokenCar, dist))
	{
	    if (oneGoodCar.first > oneBrokenCar.first)
		brokenCount += 1;
	    else
		goodCount += 1;
	}
	else
	{
	    int accomodated = min(numSeatsLeft, oneBrokenCar.second);
	    goodCars[goodCount] = {oneGoodCar.first, {oneGoodCar.second.first + accomodated, oneGoodCar.second.second}};
	    brokenCars[brokenCount] = {oneBrokenCar.first, oneBrokenCar.second - accomodated};
	    if( seatsLeft(goodCars[goodCount]) == 0)
		goodCount += 1;
	    if (brokenCars[brokenCount].second == 0)
		brokenCount += 1;

	    result += accomodated;
	}
    }
    return result;
    // CRIO_SOLUTION_END_MODULE_HOT_ROAD
}
