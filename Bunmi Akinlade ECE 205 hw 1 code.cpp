#include <iostream>
#include <iomanip>

using namespace std;

int main()
{ //Problem 1
    //Constants
    const int seconds_per_hour = 3600;
    const int seconds_per_minute = 60;

    //Variables
    int total_seconds;
    int hours, minutes, seconds;
    double real_hours, real_minutes;

    //Prompt for user input
    cout <<"Enter time in seconds: ";
    cin >> total_seconds;

    //Conversions
    hours = total_seconds / seconds_per_hour; //convert seconds to hours
    minutes = (total_seconds % seconds_per_hour) / seconds_per_minute; //convert remaining seconds to minutes
    seconds = total_seconds % seconds_per_minute; //remaining seconds after removing hours and minutes

    real_hours = total_seconds / static_cast<double>(seconds_per_hour); //convert total seconds to hours in decimal
    real_minutes = total_seconds / static_cast<double>(seconds_per_minute); //convert total seconds to minutes in decimal

    //Outputs
    cout << fixed << setprecision(4); //output to 4 decimal places
    cout <<hours <<" hours, "<< minutes <<" minutes, "<< seconds <<" seconds"<< endl;
    cout << real_hours <<" hours"<< endl;
    cout << real_minutes <<" minutes"<< endl;  


    //Problem 2
    //Constants
    const double hourly_rate = 36.75; //hourly pay rate
    const double overtime_multiplier = 1.5; //overtime pay rate multiplier
    const double social_security_rate = 0.06; //6% social security tax rate
    const double federal_tax_rate = 0.15; //15% federal income tax rate
    const double state_tax_rate = 0.04; //4% state tax rate
    const double local_tax_rate = 0.01; //1% local tax rate
    const double union_dues = 20.00; //union dues
    const double health_insurance = 40.00; //health insurance cost
    const double regular_hours = 40.0; //max regular hours before overtime

    //Variables
    double hours_worked; //total hours worked in the week
    int dependents; //number of dependents
    double regular_pay, overtime_pay, gross_pay; //pay amounts
    double social_security, federal_tax, state_tax, local_tax; //social security and tax deductions
    double total_deductions, net_pay; //sum of deductions and net pay

    //Prompts for user input
    cout <<"Enter hours worked this week: ";
    cin >> hours_worked;

    cout <<"Enter number of dependents: ";
    cin >> dependents;

    //Gross pay calculations
    if (hours_worked <=regular_hours)
    {
        regular_pay = hours_worked * hourly_rate;
        overtime_pay = 0.0;

    }
    else
    {
        regular_pay = regular_hours * hourly_rate;
        overtime_pay = (hours_worked - regular_hours) * hourly_rate * overtime_multiplier;
    }

    gross_pay = regular_pay + overtime_pay; //total gross pay

    //Deductions calculations
    social_security = gross_pay * social_security_rate;
    federal_tax = gross_pay * federal_tax_rate;
    state_tax = gross_pay * state_tax_rate;
    local_tax = gross_pay * local_tax_rate;

    total_deductions = social_security + federal_tax + state_tax + local_tax + union_dues; //sum of deductions

    //add health insurance if applicable
    if (dependents >= 2)
    {
        total_deductions += health_insurance;
    }


    net_pay = gross_pay - total_deductions;//calculate net pay

    //Outputs
    cout << fixed << setprecision(2);
    cout << "Gross Pay: $" << gross_pay << endl;
    cout << "Social Security: $" << social_security << endl;
    cout << "Federal Income Tax: $" << federal_tax << endl;
    cout << "State Tax: $" << state_tax << endl;
    cout << "Local Tax: $" << local_tax << endl;
    cout << "Union Dues: $" << union_dues << endl;
    
    if (dependents >= 2)
    {
        cout << "Health Insurance: $" << health_insurance << endl;
    }

    cout <<"Net Pay: $" << net_pay << endl;
    


    //Problem 3
    //Constants
    const double initial_balance = 1000.00; //initial loan balance
    const double monthly_interest_rate = 0.015; //1.5% monthly interest rate
    const double monthly_payment = 50.00; //fixed monthly payment

    //Variables
    int month = 0; //month counter
    double balance = initial_balance; //remaining loan balance
    double interest, principal, total_interest, total_paid = 0.0; //current interest, principal, totals 
    double payment; //actual payment made for the month

    //Table Header
    cout <<fixed << setprecision(2);    //set decimal places to 2
    cout <<setw (6) <<"Month"
            <<setw (12) <<"Interest"
            <<setw (12) <<"Principal"
            <<setw (12) <<"Balance"
            <<setw (16) <<"Total Interest"
            <<setw (14) <<"Total Paid" << endl;

    //loop until loan is paid off
    while (balance > 0.0)
    {
        month++; //increment month counter
        interest = balance * monthly_interest_rate; //calculate interest for the current month
        
        //determine payment amount
        if (balance+interest <= monthly_payment)
        {
            payment = balance + interest;
        }
        else
        {
            payment = monthly_payment;
        }

        principal = payment - interest; //calculate principal paid
        balance -= principal; //update remaining balance

        total_interest += interest; //update total interest paid
        total_paid += payment; //update total amount paid

        //ensure balance does not go negative
        if (balance < 0.0)
        {
            balance = 0.0;
        }
        //Output the month's data
        cout <<setw (6) << month
            <<setw (12) << interest
            <<setw (12) << principal
            <<setw (12) << balance
            <<setw (16) << total_interest
            <<setw (14) << total_paid << endl;
    }

    return 0;
}