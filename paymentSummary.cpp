#include <iostream>

/*
 *HoursWorked
 *selection statement
 * regularRate(male=500,female= 550)
 * overtimeRate = 1.50 * regularRate
 *
 * ///////////////deductions///////////
 * incomeTax = 0.15 * grossPay
 * NationalHealthTax  = 0.025 * grossPay
 * districtTax = 0.01* grossPay
 * childrenFund = 10 for male and 20 for females........
 *
 *  ///// netPay at the end of everyweek/////
 *  grossPay- deductions(childrenFund,districtTax,NationalHealthTax,incomeTax)
 */


double grossPayCalc(int hoursWorked,int gender);
int getGender();
double deductions(double grossPay,int eduFund);
int getEduFund(int gender);

int  main() {
    int gender = getGender();
    if (gender != 1 && gender != 2) {
        std::cout<<"Choose a valid gender "<<std::endl;
        return 1;
    }

    int hoursWorked;
    do {
        std::cout<<"Enter the number of hours the employee worked"<<std::endl;
        std::cin>>hoursWorked;
    }while (hoursWorked <1);
    int eduFund = getEduFund(gender);
    double grossPay = grossPayCalc(hoursWorked,gender);
    double allDeductions = deductions( grossPay,eduFund);
    double netPay = grossPay - allDeductions;

    std::cout<<"-----PAYMENT SUMMARY-------"<<std::endl;
    std::cout<<"The TotalPay for the week is "<<grossPay<<std::endl;
    std::cout<<"The total deductions "<<allDeductions<<std::endl;
    std::cout<<"The net pay after all the deductions is  "<<netPay<<std::endl;
    std::cout<<"----------------------------------------------"<<std::endl;
    return 0;
}
double grossPayCalc(int hoursWorked,int gender) {
    //calculating the grossPay of the person
    // checkin the gender before proceeding with everything.......
    //i trying to use the variables instead of the hardcoded values.............
   double regularRate = (gender==1)?500.00:550.00;
    double overtimeRate = 1.50 * regularRate;
    double grossPay = 0.00;

        if (hoursWorked <= 40 ){
            grossPay = hoursWorked * regularRate;
        }else{
            grossPay = (40  * regularRate) + ((hoursWorked-40) * overtimeRate);
        }

   return grossPay;
}
double deductions(double grossPay,int eduFund) {
    double incomeTax = 0.15* grossPay;
    double nationalHealthTax = 0.025 * grossPay;
    double districtTax = 0.01 * grossPay;
    double deductions = incomeTax + nationalHealthTax + districtTax + eduFund;
    return deductions;
}
//calculating the educational fund for the employees with more than 3  children;
int getEduFund(int gender) {
    int numofChildren;
    do {
        std::cout<<"Enter the number of Children of the Employees"<<std::endl;
        std::cin>>numofChildren;
    }while (numofChildren < 0);
    if ( numofChildren > 3) {
        return (gender==1)? 10:20;
    }
    return 0;
}
//this is a bit complicated.....................
//trying to get the gender using  a function
int getGender() {
    int sex;
     do{
        std::cout<<"Choose your  Gender from the following: "<<std::endl;
        std::cout<<"1. male "<<std::endl;
        std::cout<<"2. female "<<std::endl;
        std::cin>>sex;
    }while (sex != 1 && sex != 2 );

    return sex;
}