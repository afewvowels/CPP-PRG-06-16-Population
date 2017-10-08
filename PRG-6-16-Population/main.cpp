//
//  main.cpp
//  PRG-6-16-Population
//
//  Created by Keith Smith on 9/21/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  In a population, the birth rate is the percentage of the population due to births,
//  and the death rate is the percentage decrease of the population due to deaths. Write a
//  program that displays the size of a population for any number of years. The program
//  should ask for the following data:
//
//  * The starting size of the population
//  * The annual birth rate
//  * The annual death rate
//  * The number of years to display
//
//  Write a function that calculates the size of the population for a year. The formula is
//
//  N = P + BP - DP
//
//  Where N is the new population size, P is the previous population size, B is the birth rate,
//  and D is the death rate.
//
//  Input Validation: Do not accept numbers less than 2 for the starting size. Do not accept
//  negative numbers for birth rate or death rate. Do not accept numbers less than 1 for
//  the number of years.

#include <iostream>

using namespace std;

void calculateGrowth();
int yearsQuery();
void populationQuery(int &, float &, float &);

int main() {
    
    calculateGrowth();
    
    return 0;
}

void calculateGrowth()
{
    int intYearsTotal,
        intPopulationStart,
        intPopulationNew;
    
    float fltBirthRate,
          fltDeathRate;
    
    intYearsTotal = yearsQuery();
    
    populationQuery(intPopulationStart, fltBirthRate, fltDeathRate);
    
    fltBirthRate /= 100.0f;
    fltDeathRate /= 100.0f;
    
    for(int i = 1 ; i <= intYearsTotal ; i++)
    {
        intPopulationNew = intPopulationStart +
                            (intPopulationStart * fltBirthRate) -
                            (intPopulationStart * fltDeathRate);
        
        intPopulationStart = intPopulationNew;
        
        cout << "For year " << i << " the population size is " << intPopulationNew << endl;
    }
}

int yearsQuery()
{
    int intYears;
    
    cout << "How many years should the population grow for?\n";
    cin >> intYears;
    
    while(!cin || intYears < 1 || intYears > 100)
    {
        cout << "Please enter an integer between 1 and 100:\n";
        cin.clear();
        cin.ignore();
        cin >> intYears;
    }
    
    return intYears;
}

void populationQuery(int &refPopStart, float &refBirthRate, float &refDeathRate)
{
    cout << "What is the initial starting size of the population?\n";
    cin >> refPopStart;
    
    while(!cin || refPopStart < 2 || refPopStart > 1000000)
    {
        cout << "Please enter a starting population size\n"
        << "between 2 and 1,000,000:\n";
        cin >> refPopStart;
    }
    
    cout << "What is the birth rate of the population?\n";
    cin >> refBirthRate;
    
    while(!cin || refBirthRate < 0 || refBirthRate > 500)
    {
        cout << "Please enter a birth rate between\n"
        << "0% and 500%:\n";
        cin >> refBirthRate;
    }
    
    cout << "What is the death rate of the population?\n";
    cin >> refDeathRate;
    
    while(!cin || refDeathRate < 0 || refDeathRate > 500)
    {
        cout << "Please enter a death rate between\n"
        << "0% and 500%:\n";
        cin >> refDeathRate;
    }
}

