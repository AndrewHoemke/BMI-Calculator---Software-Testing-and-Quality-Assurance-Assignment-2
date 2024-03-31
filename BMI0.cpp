// BMI0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>


std::string InterpretBMI(float bmi)
{
    if (bmi < 18.5)
    {
        return "underweight";
    }
    else if (bmi < 25)
    {
        return "normal weight";
    }
    else if (bmi < 30)
    {
        return "overweight";
    }
    else
    {
        return "obese";
    }
}


float BMICalculator(int feet, int inches, int pounds)
{
    int input;
    float height = 0;//meters
    float weight = 0; //kilograms
    float bmi = 0;
    //inches = FeetToInches(feet);
    height = 0.025 * static_cast<float>(inches+(12*feet));
    weight = 0.45 * static_cast<float>(pounds);
    bmi = (weight) / (height * height);
    return bmi;
}

int TestBMI()
{
    //8 tests.
    int failedTests = 0;
    int tests[8][3] = 
    {
        {6, 0, 216},
        {6, 0, 215},
        {6, 5, 215},
        {6, 0, 180},
        {6, 0, 179},
        {6, 8, 180},
        {5, 3, 102},
        {5, 4, 105}
    };
    std::string expVals[8] = {"obese","overweight","overweight","overweight","normal weight","normal weight","normal weight","underweight"};
    for (int i = 0; i < 8; i = i + 1)
    {
        if (InterpretBMI(BMICalculator(tests[i][0], tests[i][1], tests[i][2])) != expVals[i])
        {
            std::cout << "Test " << i << " failed\n";
            failedTests = failedTests + 1;
        }
    }
    return failedTests;
}

int main(int argc, char* argv[])
{
    //std::cout << "1: " <<argv[1] << "\n";
    //std::cout << "2: " << argv[2] << "\n";
    //std::cout << "3: " << argv[3] << "\n";
    //argv[1] is height in feet
    //argv[2] is height in inches
    //argv[3] is weight in pounds
    //return bmi value
    //if argc is 1 (program run with no arguments) begin testing.
    //std::cout << "argc is " << argc;
    if (argc == 1)
    {
        int failedTests = TestBMI();
        if (failedTests == 0)
        {
            std::cout << "All tests passed";
        }
        else
        {
            std::cout << failedTests << " tests failed";
        }
        
    }
    else
    {
        std::cout << "You are " << BMICalculator(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])) << "\n";
        std::cout << "You are " << InterpretBMI(BMICalculator(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])));
    }
    
}

