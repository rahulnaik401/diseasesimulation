//
// Created by Rahul Naik on 11/30/20.
//

#ifndef COE322_DISEASE_H
#define COE322_DISEASE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>


using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::ofstream;

// healthy w/o vacc=0, recovered=-1; vacc=-2; sick with n days to go=n

class Person{
private:
    int status;
public:
    Person () {
        status=0;
    }
    string status_string() {
        if (status == 0) {
            return "Healthy";
        } else if (status == -1) {
            return "Recovered";
        } else if (status == -2) {
            return "Vaccinated";
        } else {
            return "Currently Sick";
        }
    }
    //if someone is sick their status changes each day by -1 until they recover wherein their status is -1
    void update(){
        if (status > 1){
            status--;
        }
        else if (status==1){
            status=-1;
        }
    }
    //Infecting the healthy for n days
    void infect(int n) {
        if (status==0){
            status=n;
        }
    }

    void vaccination(){
        status=-2;
    }

    bool is_stable(){
        if (status==-1){
            return true;
        }
        else {
            return false;
        }
    }
};

class Population {

private:
    vector<Person> population; //population of persons by creating a vector of persons
    int pop; //total number of population
    float prob; //probability of infection


public:
    int step;
    Population (int numPeople, float infectionrisk){
        pop=numPeople;
        prob=infectionrisk;
        step=1;
        for (int i=0;i<pop;i++){
            population.push_back(Person());
        }
    }

    int count_infected(){
        int count=0;

        for (int i=0;i<pop;i++){
            if(population[i].status_string()=="Currently Sick"){
                count++;

            }

        }
        return count;
    }

    int count_healthy(){
        int count=0;
        for (int i=0;i<pop;i++){
            if (population[i].status_string()=="Healthy"){
                count++;
            }
        }
        return count;
    }

    void status_string(){
        cout<<"In step"<<step<<"  #sick:  "<<count_infected()<<": ";

        for (int i=0;i<pop;i++){
            cout<<population[i].status_string()<<",";
        }
        cout<<endl;
    }

    void random_infection(){
        int rando=rand()%pop;
        Person rando1=population[rando];
        rando1.infect(5);
        population[rando]=rando1;
    }

    void random_infection_vacc(){
        int rando= rand()% pop;
        Person rando1= population[rando];
        if(rando1.status_string()=="Vaccinated"){
            rando=rand()%pop;
            rando1=population[rando];
        }
        rando1.infect(5);
        population[rando]=rando1;
    }


    void updatev1(){
        step++;
        int x;
        for (int i=0;i<pop;i++){
            if (population[i].status_string()=="Healthy"){
                if ((i<pop-1 && population[i+1].status_string()=="Currently Sick") || (i>0 && population[i-1].status_string()=="Currently Sick")){
                    x=rand()%100;
                    if(x<prob*100){
                        population[i].infect(5);
                    }
                }
            }
            population[i].update();
        }
    }
    void updatev2(){
        step++;
        for(int i=0;i<pop;i++){
            population[i].update();
        }
    }


    void vaccination (int maxVacc){
        int s;
        int vacc=0;

        while (vacc<=maxVacc){
            s=rand()%pop;
            if (population[s].status_string()=="Healthy"){
                population[s].vaccination();
                vacc++;
            }
        }
    }

  void spreading (int human1,int human2){
        Person h1=population[human1];
        Person h2=population[human2];
        if (h2.status_string()=="Healthy" || h1.status_string()=="Healthy"){
            int z= rand()%100;
            if (z<prob*100){
                if (h1.status_string()=="Currently Sick"){
                    h2.infect(5);
                }
                else if(h2.status_string()=="Currently Sick"){
                    h1.infect(5) ;
                }
            }

        }
        population[human1]=h1;
        population[human2]=h2;
    }

    int get_popsize(){
        return pop;
    }

    Person getelement (int i){
        return population[i];
    }

};

#endif //COE322_DISEASE_H
