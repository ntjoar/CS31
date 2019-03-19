// Nathan Tjoar
// 005081232
// Lecture 2
// Discussion 2A

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cassert>
using namespace std;

bool isValidUppercaseStateCode(string stateCode) //Checks state code
{
    const string codes =
    {"AL.AK.AZ.AR.CA.CO.CT.DE.FL.GA.HI.ID.IL.IN.IA.KS.KY."
        "LA.ME.MD.MA.MI.MN.MS.MO.MT.NE.NV.NH.NJ.NM.NY.NC.ND."
        "OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY"};
    return (stateCode.size() == 2  &&
            stateCode.find('.') == string::npos  &&  // no '.' in stateCode
            codes.find(stateCode) != string::npos);  // match found
}

bool hasProperSyntax(string pollData)
{
    string upperPollData = pollData; //Upper Case Stored
    for(int k = 0; k < pollData.size(); k++) //Transforms all data to uppercase values
    {
        upperPollData[k] = toupper(pollData[k]); //Store value of the uppercase
    }
    
    string statePollData; //State Code Stored
    if (pollData == "") //Empty String case
    {
        return true;
    }
    
    if(!isValidUppercaseStateCode(upperPollData.substr(0, 2))) //If the first values are not valid state codes, program returns false
    {
        return false;
    }
    for(int i = 0; i < pollData.size(); i++) //Comb through all characters
    {
        statePollData = upperPollData.substr(i + 1, 2);
        if(upperPollData[i] == ',' && !isValidUppercaseStateCode(statePollData)) //Checks for some comma in the program and if the following is not a state code or after state code is not a digit, returns false
        {
            return false;
        }
        else if(!(isalpha(pollData[i])) && !(isdigit(pollData[i])) && pollData[i] != ',') //Checks if all values are either comma, digit, or alphabetic
        {
            return false;
        }
        else if(isdigit(pollData[i]) && !(isalpha(pollData[i + 1]) || isalpha(pollData[i + 2]))) //If we get a digit, and the following is not a letter, return false
        {
            return false;
        }
        else if(isdigit(pollData[i]) && pollData[i + 1] == ',') //If we get a digit, and the following is a comma, return false
        {
            return false;
        }
        else if(upperPollData[i] == ' ') //Return false for any spaces in between
        {
            return false;
        }
    }
    return true;
}

int tallySeats(string pollData, char party, int& seatTally)
{
    if (!hasProperSyntax(pollData)) //Return 1 for improper syntax
    {
        return 1;
    }
    else if (!isalpha(party)) //Return 2 if party is not a character
    {
        return 2;
    }
    else
    {
        seatTally = 0; //Seat tally first value
        string upperPollData1 = pollData; //Upper Case Stored
        for(int l = 0; l < pollData.size(); l++) //Transforms all data to uppercase values
        {
            upperPollData1[l] = toupper(pollData[l]);
        } //Transforms all characters to uppercase values
        char upperParty = toupper(party);

        for(int j = 2; j < upperPollData1.size(); j++) //Runs through the string
            {
                if(upperPollData1[j] == ',') //If it sees a comma, it skips 2 characters because of the statecode
                {
                    j += 3;
                }
                else if(upperPollData1[j] == upperParty) //If the character is a state code
                {
                    if(isdigit(upperPollData1[j - 2])) //Check if there are any digits two spaces before
                    {
                        seatTally += stoi(upperPollData1.substr(j - 2, 2)); //Convert to integer value and
                    }
                    else
                    {
                        seatTally += stoi(upperPollData1.substr(j - 1, 1)); //Get the first digit and add to total seatTally
                    }
                }
            }
        return 0;
    }
}

int main() {

}
