// BMI0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>


int line = 0;
//Aquired function from stackoverflow. Changed function and variable names to better match my intent.
void SetPosition(int x, int y)
{
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void ClearLine(int length)
{
    for (int i = 0; i < length; i = i + 1)
    {
        std::cout << ' ';
    }
}

int FeetToInches(int feet)
{
    
    return 12 * feet;
}

float InchesToMeters(int inches)
{
    return 0.025 * static_cast<float>(inches);
}

float PoundsToKilograms(int pounds)
{
    return 0.45 * static_cast<float>(pounds);
}

int ConvertInput(std::string input)
{
    //If any non-numeral characters are found, return -1.
    for (int i = 0; i < input.length(); i = i + 1)
    {
        if (input.at(i) < 48 || input.at(i) > 57)
        {
            return -1;
        }
    }
    //cast to integer
    return std::stoi(input);
}

void BMICalculator()
{
    std::string input;//typed input, before checks.
    int inches = 0;
    int pounds = 0;
    float height = 0;//meters
    float weight = 0; //kilograms
    line = 0;
    system("cls");
    std::cout << "Please answer the following questions with whole numbers only:";
    line = line + 1;
    SetPosition(0, line);
    std::cout << "How tall are you in feet?";
    line = line + 1;
    SetPosition(0, line);
    std::cin >> input;
    line = line + 1;
    SetPosition(0, line);
    while (ConvertInput(input) == -1)
    {
        //clear line and line before
        ClearLine(input.length());
        line = line - 1;
        SetPosition(0, line);
        std::cout << "Please enter a whole number";
        line = line + 1;
        SetPosition(0, line);
        std::cin >> input;
        line = line + 1;
        SetPosition(0, line);
        if (ConvertInput(input) == -1)
        {
            line = line - 1;
            SetPosition(0, line);
        }
    }
    inches = FeetToInches(ConvertInput(input));

    std::cout << "How many inches taller are you than that?";
    line = line + 1;
    SetPosition(0, line);
    std::cin >> input;
    line = line + 1;
    SetPosition(0, line);
    while (ConvertInput(input) == -1)
    {
        //clear line and line before
        ClearLine(input.length());
        line = line - 1;
        SetPosition(0, line);
        std::cout << "Please enter a whole number";
        line = line + 1;
        SetPosition(0, line);
        std::cin >> input;
        line = line + 1;
        SetPosition(0, line);
        if (ConvertInput(input) == -1)
        {
            line = line - 1;
            SetPosition(0, line);
        }
    }
    inches = inches + ConvertInput(input);
    height = InchesToMeters(inches);

    std::cout << "How much do you weigh in pounds?";
    line = line + 1;
    SetPosition(0, line);
    std::cin >> input;
    line = line + 1;
    SetPosition(0, line);
    while (ConvertInput(input) == -1)
    {
        //clear line and line before
        ClearLine(input.length());
        line = line - 1;
        SetPosition(0, line);
        std::cout << "Please enter a whole number";
        line = line + 1;
        SetPosition(0, line);
        std::cin >> input;
        line = line + 1;
        SetPosition(0, line);
        if (ConvertInput(input) == -1)
        {
            line = line - 1;
            SetPosition(0, line);
        }
    }
    weight = PoundsToKilograms(pounds);
    //std::cout << 
}

void MenuSystem()
{
    std::string input;
    bool badCmd = false;
    while (1)
    {
        system("cls");
        line = 0;
        if (badCmd)
        {
            std::cout << "Command not understood. ";
            badCmd = false;
        }
        std::cout << "Please select one of the listed functions. Type 'exit' to exit the program. \n1: bmi\n";
        line = line + 2;
        std::cin >> input;
        line = line + 1;
        //only one function right now
        if (input == "1" || input == "bmi" || input == "BMI" || input == "Bmi")
        {
            BMICalculator();
        }
        else if (input == "exit" || input == "Exit" || input == "EXIT")
        {
            return;
        }
        else
        {
            badCmd = true;
        }
    }
    
}

int main()
{
    MenuSystem();
}

