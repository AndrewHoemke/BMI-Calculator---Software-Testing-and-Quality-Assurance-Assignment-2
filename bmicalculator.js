
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


module.exports = [bmicalculator, interpretbmi]