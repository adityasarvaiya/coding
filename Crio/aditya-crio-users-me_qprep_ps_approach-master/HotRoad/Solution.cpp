#include <bits/stdc++.h>
using namespace std;

// // Finish this function
// int regNumberToInteger(string s)
// {
//     string bench="KA01AA0001";
//     int c=0;
//     c+=(s[9]-'0');
//     c+=(s[8]-'0')*10;
//     c+=(s[7]-'0')*100;
//     c+=(s[6]-'0')*1000;
//     c+=(s[5]-'A')*9999;
//     c+=(s[4]-'A')*9999*26;
//     c+=(s[3]-'1')*9999*26*26;
//     c+=(s[2]-'0')*9999*26*10*26;
//     return c;
// }



int findMaximumNumberOfPeopleAccomodated(vector<pair<string, int>>& broken, 
vector<pair<string,pair<int,int>>>& good, int dist)
{
    // vector <pair<int, int>> broken_cars;
    // vector <pair<int, int>> good_cars;

    // for (auto i:broken) {
    //     broken_cars.push_back({regNumberToInteger(i.first), i.second});
    // }

    // for (auto i:good) {
    //     good_cars.push_back({regNumberToInteger(i.first), i.second.second - i.second.first});
    // }

    // sort(broken_cars.begin(), broken_cars.end()); 
    // sort(good_cars.begin(), good_cars.end());

    // // for (auto i : broken_cars) {
    // //     cout << i.first << " ";
    // // }

    // // cout << endl;

    // // for (auto i : broken_cars) {
    // //     cout << i.second << " ";
    // // }

    // // cout << endl;

    // // for (auto i : good_cars) {
    // //     cout << i.first << " ";
    // // }

    // // cout << endl;

    // // for (auto i : good_cars) {
    // //     cout << i.second << " ";
    // // }

    // // cout << endl;

    // int i=0,j=0,saved=0; 

    // while (i < broken_cars.size() && j < good_cars.size()) {
    //     if (broken_cars[i].first <= good_cars[j].first) {
    //         if (good_cars[j].first - broken_cars[i].first <= dist) {
    //             if (broken_cars[i].second == good_cars[j].second) {
    //                 saved += broken_cars[i].second;
    //                 i++; j++;
    //             } else if (broken_cars[i].second < good_cars[j].second) {
    //                 saved += broken_cars[i].second;
    //                 good_cars[j].second -= broken_cars[i].second;
    //                 i++;
    //             } else {
    //                 saved += good_cars[j].second;
    //                 broken_cars[i].second -= good_cars[j].second;
    //                 j++;
    //             }
    //         } else {
    //             i++;
    //         }
    //     } else {
    //         if (broken_cars[i].first - good_cars[j].first <= dist) {
    //             if (broken_cars[i].second == good_cars[j].second) {
    //                 saved += broken_cars[i].second;
    //                 i++; j++;
    //             } else if (broken_cars[i].second < good_cars[j].second) {
    //                 saved += broken_cars[i].second;
    //                 good_cars[j].second -= broken_cars[i].second;
    //                 i++;
    //             } else {
    //                 saved += good_cars[j].second;
    //                 broken_cars[i].second -= good_cars[j].second;
    //                 j++;
    //             }
    //         } else {
    //             j++;
    //         }
    //     }
    // }

    // return saved;
    return 0;
}
