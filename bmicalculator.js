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



function interpretbmi(bmi)
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


function bmicalculator(feet, inches, pounds)
{
    
    height = 0.0;//meters
    weight = 0.0; //kilograms
    bmi = 0.0;
    //inches = FeetToInches(feet)
    height = 0.025*(parseFloat(inches)+(12.0*parseFloat(feet)));
    weight = 0.45 * (parseFloat(pounds));
    bmi = (weight) / (height * height);
    bmi = parseFloat(bmi).toFixed(2);
    return bmi;
}


function testbmi()
{
    //8 tests.
    failedtests = 0;
    const tests = 
    [
        [6, 0, 216],
        [6, 0, 215],
        [6, 5, 215],
        [6, 0, 180],
        [6, 0, 179],
        [6, 8, 180],
        [5, 3, 102],
        [5, 4, 105],
    ];
    const expvals = ["obese","overweight","overweight","overweight","normal weight","normal weight","normal weight","underweight"];
    for (let i = 0; i < 8; i = i + 1)
    {
        if (interpretbmi(bmicalculator(tests[i][0], tests[i][1], tests[i][2])) != expvals[i])
        {
            rpt = "Test " + i + " failed";
            console.log(rpt)
            failedtests = failedtests + 1;
        }
    }
    if (failedtests == 0)
    {
        console.log("All tests passed");
    }
    return failedtests;
}
testbmi();