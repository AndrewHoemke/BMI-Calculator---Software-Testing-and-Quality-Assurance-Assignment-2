function feetval(val)
{ 
    document.getElementById("feet").value = document.getElementById("feet").value + val
} 

function inchesval(val)
{ 
    document.getElementById("inches").value = document.getElementById("inches").value + val
} 

function poundsval(val)
{ 
    document.getElementById("pounds").value = document.getElementById("pounds").value + val
} 



InterpretBMI(bmi)
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


BMICalculator(feet, inches, pounds)
{
    input;
    height = 0;//meters
    weight = 0; //kilograms
    bmi = 0;
    //inches = FeetToInches(feet);
    height = 0.025 * static_cast<float>(inches+(12*feet));
    weight = 0.45 * static_cast<float>(pounds);
    bmi = (weight) / (height * height);
    return bmi;
}

TestBMI()
{
    //8 tests.
    failedTests = 0;
    tests[8][3] = 
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