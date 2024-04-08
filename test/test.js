const assert = require("assert");
var bmicalculator = require('../bmicalculator.js')[0];
var interpretbmi = require('../bmicalculator.js')[1];

describe('testing for coverage', () => {

    it ('Should correctly calculate bmi', () => {
  
      assert.equal(bmicalculator(5,4,105), 18.46);
      assert.equal(bmicalculator(5,3,102), 18.50);
      assert.equal(bmicalculator(6,8,180), 20.25);
      assert.equal(bmicalculator(6,0,179), 24.86);
      assert.equal(bmicalculator(6,0,180), 25.00);
      assert.equal(bmicalculator(6,5,215), 26.11);
      assert.equal(bmicalculator(6,0,215), 29.86);
      assert.equal(bmicalculator(6,0,216), 30.00);
  
    });
    describe('Should correctly report that the values indicate being', () => {

      it ('underweight', () => {
  
        assert.equal(interpretbmi(18.46), "underweight");
    
      });

      it ('normal Weight', () => {
  
        assert.equal(interpretbmi(18.50), "normal weight");
        assert.equal(interpretbmi(20.25), "normal weight");
        assert.equal(interpretbmi(24.86), "normal weight");
    
      });
  
      it ('overweight', () => {
  
        assert.equal(interpretbmi(25.0), "overweight");
        assert.equal(interpretbmi(26.11), "overweight");
        assert.equal(interpretbmi(29.86), "overweight");
    
      });

      it ('obese', () => {
  
        assert.equal(interpretbmi(30.0), "obese");
    
      });

    });
  

  });