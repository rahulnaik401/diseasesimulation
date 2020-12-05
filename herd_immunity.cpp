/*
Created by Rahul Naik (rkn423)
COE 322 Final Project Fall 2020

This program simulates the spread of an infectious disease through a theoretical population of 1,000,000 people (to resemble the actual population of Austin, TX).
The following variables are kept constant:
 Risk of Infection (following exposure to the virus): .2
 Population Size: 1,000,000
 Number of Trials: 100 (To ensure accuracy of results)
 Number of Interactions: 6 (Means that each person in 'Austin' will have 6 random interactions with other people daily)
 Disease Duration: 5 days (Throughout this project the disease duration, the number of days someone will be sick, is kept at 5.
The following variables are changed and meant to be studied:
 Percent Vaccinated: This is to see the effect on vaccincation rates on disease duration through the population and herd immunity.
Herd Immunity for this program is the number of people who are untouched by the disease shown as a percentage out of the total number who were never vaccinated.
This is done to demonstrate the property of herd immunity to protect those in society from infection who are not even immunized.

*/

#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "disease.h"

using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::ofstream;



int main() {

    srand (time(NULL));
    Population austin (1000000,.2);
    int trials=100;
    vector<float> herd(trials);
    vector<int> untouched(trials);
    vector<int> days(trials);
    int interactions=6;
    int daycnt=0;
    float percent_vacc; //percent of population to vaccinate from 0 to 1
    cout<<"Enter percent to vaccinate as a number from 0 to 1"<<endl;
    cin>>percent_vacc;
    austin.vaccination(percent_vacc*austin.get_popsize());
    for (int i=1;i<=trials;i++) {
        austin.random_infection();
        while (austin.count_infected() > 0) {
            for (int j = 0; j < austin.get_popsize(); j++) {
                if (austin.get_person(j).status_string() == "Currently Sick") {
                    for (int k = 0; k < interactions; k++) {
                        int h1 = j;
                        int h2 = rand() % austin.get_popsize();
                        austin.spreading(h1, h2);
                    }
                }
            }
            austin.updatev2();
            daycnt++;
        }
        float never_vacc = (1 - percent_vacc) * austin.get_popsize();
        int end_healthy = austin.count_healthy();
        float herd_immunity = (end_healthy / never_vacc) * 100;
        herd.push_back(herd_immunity);
        untouched.push_back(end_healthy);
        days.push_back(daycnt);
    }
    float sum_herd=accumulate(herd.begin(),herd.end(),0.0f);
    float avg_herd=sum_herd/trials;
    float sum_untouched=accumulate(untouched.begin(),untouched.end(),0.0f);
    float avg_untouched=sum_untouched/trials;
    float sum_days=accumulate(days.begin(),days.end(),0.0f);
    int avg_days=sum_days/trials;
    cout<<"Average herd immunity "<<avg_herd<<"%"<<endl;
    cout<<"Average days for disease to complete: "<<avg_days<<endl;
    cout<<"Average left untouched: "<<avg_untouched<<endl;
}