//Created by Rahul Naik(rkn423)
//COE 322 Fall 2020

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
    srand(time(NULL));
    ofstream outputFile;
    outputFile.open("testoutputvacc.csv");
    Population austin(10000, .9);
    austin.random_infection();
    austin.vaccination(100);
    int days = 0;
    while (austin.count_infected() != 0) {
        outputFile << austin.count_infected() << " ";
        austin.updatev1();
        days++;
    }
    outputFile << austin.count_infected() << endl;
    outputFile << days << endl;
    outputFile.close();
}