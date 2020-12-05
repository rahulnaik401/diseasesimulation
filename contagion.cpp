// Created by Rahul Naik (rkn423)
// COE 322 Final Project Fall 2020
//
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

int main(){
    srand(time(NULL));
    ofstream outputFile;
    outputFile.open("testoutput3.csv");
    //for (float p=.1;p<1;p=p+.4){
    Population austin(10000,.9);
    austin.random_infection();
    int day=0;
    while(austin.count_infected() != 0){
        outputFile<<austin.count_infected()<<" ";
        austin.updatev1();
        day++;
    }
    outputFile<<austin.count_infected()<<endl;
    outputFile<<day<<endl;
    //}
    outputFile.close();
}
