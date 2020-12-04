// Created by Rahul Naik (rkn423)
// COE 322 Final Project Fall 2020

#include <iostream>
#include <vector>
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
    /*
    srand(time(NULL));
    ofstream outputFile;
    outputFile.open("testoutputvacc.csv");
    //for (float p=.1;p<1;p=p+.4){
    Population austin(10000,.9);
    austin.random_infection();
    austin.vaccination(100);
    int days=0;
    while(austin.count_infected() != 0){
        outputFile<<austin.count_infected()<<" ";
        austin.update();
        days++;
    }
    outputFile<<austin.count_infected()<<endl;
    outputFile<<days<<endl;
    //}
    outputFile.close();

*/
/*
    srand(time(NULL));
    ofstream outputFile;
    outputFile.open("testoutput3.csv");
    //for (float p=.1;p<1;p=p+.4){
    Population austin(10000,.9);
    austin.random_infection();
    int day=0;
    while(austin.count_infected() != 0){
        outputFile<<austin.count_infected()<<" ";
        austin.update();
        day++;
    }
    outputFile<<austin.count_infected()<<endl;
    outputFile<<day<<endl;
    //}
    outputFile.close();
*/

/*
    Person joe;
    int day = 1;
    for (;; day++) {
        joe.update();
        float sickchance = (float) rand() / (float) RAND_MAX;
        if (sickchance > .50) {
            joe.infect(5);
        }
        cout << "On day " << day << ", Joe is " << joe.status_string() << endl;
        if (joe.is_stable()) {
            break;
        }
        if (joe.is_stable()) {
            break;
        }
    }
*/

/*
    srand(time(NULL));
    Population austin(5,.5);
    austin.random_infection();
    while(austin.count_infected()>0){
        austin.status_string();
        austin.updatev1();
        if (austin.count_infected()==0){
           cout<<"Disease ran its course everyone is recovered"<<endl;
        }
    }
*/

    srand (time(NULL));
    Population austin (1000000,.2);
    int interactions=6;
    int daycnt=0;
    float percent_vacc = .2; //percent of population to vaccinate from 0 to 1
    austin.random_infection();
    austin.vaccination(percent_vacc*austin.get_popsize());
    while (austin.count_infected()>0){
        for (int i=0;i<austin.get_popsize();i++){
            if (austin.getelement(i).status_string()=="Currently Sick") {
                for (int j=0;j<interactions;j++) {
                    int h1=i;
                    int h2=rand()%austin.get_popsize();
                    austin.spreading(h1,h2);
                }
            }
        }
        austin.updatev2();
        daycnt++;
        cout<<"On day "<<daycnt<<": "<<austin.count_infected()<<" people are sick"<<endl;
    }
    cout<<"Total days for disease to complete: "<<daycnt<<endl;
    cout<<"Total left untouched: "<<austin.count_healthy()<<endl;

}