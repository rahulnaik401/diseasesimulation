// Created by Rahul Naik (rkn423)
// COE 322 Final Project Fall 2020
//The purpose
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <ctime>
#include <cstdlib>
#include "disease.h"

using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::endl;

int main(){
    int trials=100;
    vector<int> days(trials);
    srand(time(NULL));
    Population austin(10000,0);
    for (int i=1;i<=trials;i++) {
        austin.random_infection();
        int day = 0;
        while (austin.count_infected() != 0) {
            austin.updatev1();
            day++;
        }
        days.push_back(day);
    }
    float sum_days=accumulate(days.begin(),days.end(),0.0f);
    int avg_days=sum_days/trials;
    cout<<"Average days for disease to complete: "<<avg_days<<endl;
}
