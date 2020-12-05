//Created by Rahul Naik(rkn423)
//COE 322 Fall 2020

#include <iostream>
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
    srand(time(NULL));
    Person joe;
    int day = 0;
    while (joe.status_string()!="Recovered") {
        joe.update();
        float sickchance = float (rand())/float (RAND_MAX);
        if (sickchance > .5) {
            joe.infect(5);
        }
        cout << "On day " << day << " Joe is " << joe.status_string() << endl;
        if (joe.is_stable()) {
            break;
        }
        if (joe.is_stable()) {
            break;
        }
        day++;
    }
}