// Nathan Tjoar
// 005081232
// Lecture 2
// Discussion 2A

#include <iostream>
#include <string>
using namespace std;

int main() {
//Round to two decimal places
    cout.precision (2);
    cout.setf(ios::fixed);
    
//Preperation Stage of all variables
    int odometerStart;
    int odometerEnd;
    int rentalDays;
    string customerName;
    string yn;
    int month;
    double chargeLuxury = 61.00;
    double chargeStd = 33.00;
    double priceType;
    double priceMileage;
    double priceMileageSeason;
    int odometerCount;
    double priceFinal;
    
//Starting Odometer
    cout << "Odometer at start: ";
    cin >> odometerStart;
    if (odometerStart < 0)
    {
        cout << "---" << endl;
        cout << "The starting odometer reading must be nonnegative." << endl;
        return 0;
    }
    
//Ending Odometer
    cout << "Odometer at end: ";
    cin >> odometerEnd;
    if (odometerStart > odometerEnd)
    {
        cout << "---" << endl;
        cout << "The final odometer reading must be at least as large as the starting reading." << endl;
        return 0;
    }
   
//Rental Time
    cout << "Rental Days: ";
    cin >> rentalDays;
    cin.ignore(100000,'\n');
    if (rentalDays < 1)
    {
        cout << "---" << endl;
        cout << "The number of rental days must be positive." << endl;
        return 0;
    }
    
//Customer Name recorded
    cout << "Customer Name: ";
    getline(cin, customerName);
    if (customerName == "")
    {
        cout << "---" << endl;
        cout << "You must enter a customer name." << endl;
        return 0;
    }
    
//Luxury or not
    cout << "Luxury Car? (y/n): ";
    getline(cin, yn);
    if (!(yn == "y" || yn == "n"))
    {
        cout << "---" << endl;
        cout << "You must enter y or n." << endl;
        return 0;
    }
    
//Month Recorded
    cout << "Month (1=Jan, 2=Feb, etc.): ";
    cin >> month;
    if (month < 1 || month > 12)
    {
        cout << "---" << endl;
        cout << "The month number must be in the range 1 through 12." << endl;
        return 0;
    }
    
//Luxury or not Calculations
    if (yn == "n")
    {
        priceType = rentalDays * chargeStd;
    }
    else
    {
        priceType = rentalDays * chargeLuxury;
    };
    
//Mileage Count
    odometerCount = odometerEnd - odometerStart; //Total Mileage
    
//Mileage Calculations
    
//First 100 Miles
    if (odometerCount <= 100)
    {
        priceMileage = 0.27 * odometerCount; //Total = Initial
        priceMileageSeason = 0;
    }
//Over 100 Miles
    else
    {
    //Over 400 Miles
        if (odometerCount > 400)
        {
        //Additional Pricing
            priceMileage = (100 * 0.27) + ((odometerCount-400) * 0.19); //Total = Initial + Additional
    //Seasonal Pricing
        //Winter Pricing
            if (month <= 3 || month == 12)
            {
                priceMileageSeason = (0.27 * 300); //Total = Initial + Seasonal
            }
        //Other pricing
            else
            {
                priceMileageSeason = (0.21 * 300); //Total = Initial + Seasonal
            }
        }
        //Between 100 to 400 Miles
        else
        {
    //Seasonal Pricing
        //Winter Pricing
                if (month <= 3 || month == 12)
                {
                    priceMileage = (0.27 * 100); // First 100
                    priceMileageSeason = (0.27 * (odometerCount - 100)); //Seasonal
                }
            //Other pricing
                else
                {
                    priceMileage = (0.27 * 100); // First 100
                    priceMileageSeason = (0.21 * (odometerCount - 100)); //Seasonal
                }
        }
    }
    
    cout << "---" << endl;  //Required dash to seperate the input from output
    
    //Final Price
    priceFinal = priceType + priceMileage + priceMileageSeason; //Final = type + Mileage + Seasonal (If any)

    //Final output//
    cout << "The rental charge for " << customerName << " is $" << priceFinal << endl;
}
