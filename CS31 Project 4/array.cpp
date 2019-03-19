//Nathan Tjoar
//005081232
//Lecture 2
//Discussion 2A

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cassert>

using namespace std;

int appendToAll(string a[], int n, string value) //Appends some value to every string
{
    if(n < 0) //Check n value
    {
        return -1;
    }
    else
    {
        for(int i = 0; i < n; i++) //For each value in the array, add the required value on
        {
            a[i] += value;
        }
    }
    return n; //Return size of the array
}

int lookup(const string a[], int n, string target) //Looks for the target value
{
    if(n < 0) //Check n value
    {
        return -1;
    }
    
    for(int i = 0; i < n; i++) //Run through each loop
    {
        if(a[i] == target) //Compare if the target is there
        {
            return i; //Case appears at position i
        }
    }
    return -1; //No such case appears
}

int positionOfMax(const string a[], int n)
{
    int maxPos = 0; //Set some holder value of maxPosition
    string maxString = a[maxPos]; //Set holder of string that is maximal
    
    if(n <= 0) //Check if n is less than 0
    {
        return -1;
    }
    
    for (int j = 1; j < n; j++) //Run through the array
    {
        if(maxString < a[j]) //Check if the string will be greater than or equal to current held
        {
            maxString = a[j]; //If it is, replace the maxString value and maxPos value with current values
            maxPos = j;
        }
    }
    return maxPos; //Return position of the string
}

int rotateLeft(string a[], int n, int pos)
{
    if(n < 0 || n <= pos || pos < 0) //Check n value
    {
        return -1;
    }
    else if(n == 0)
    {
        return 0;
    }
    
    string tempCopy = a[pos]; //Store a temporary copy of what value needs to be moved
    a[pos] = ""; //Clear that position
    
    for(int l = pos; l < (n - 1); l++) //Run through all values of the string
    {
        a[l] = a[l + 1]; //Replace values of the string with the values following it
    }
    a[n - 1] = tempCopy; //For final value, replace it with the temporary copy we stored
    return pos; //Return the initial position of the value copied
}

int countRuns(const string a[], int n)
{
    if(n < 0) //Check n value
    {
        return -1;
    }
    
    int countConsecutive = 1; //Set a placeholder for the array to count how many overlap iterations

    for(int m = 0; m < (n - 1); m++) //Check through loop
    {
        if(a[m] != a[m + 1]) //Check that the current consecutive is being continued
        {
            countConsecutive++;
        }
    }
    return countConsecutive; //Return total value
}

int flip(string a[], int n)
{
    if(n < 0) //Check n value
    {
        return -1;
    }
    int init = 0;
    int replace = n - 1; //n corresponds to array size
    
    while(init < replace)
    {
        while(init < replace)
        {
            string tempString = a[init]; //Store string b
            a[init] = a[replace]; //Swap b with string a
            a[replace] = tempString; //Swaps b with a
            init++; //Increment the init
            replace--;
        }
        init++; //Increment the init
        replace--;
    }
    return n; //Return size of the array
}

int differ(const string a1[], int n1, const string a2[], int n2)
{
    if(n1 < 0 || n2 < 0) //Check n value
    {
        return -1;
    }
    
    for(int b = 0; b < n1 && b < n2; b++) //Check all values under size n1 and n2
    {
        if(a1[b] != a2[b]) //Check for if any a1 does not equal a2
        {
            return b;
        }
    }
    
    if(n1 < n2) //If not, check if n1 is greater than n2 or vice versa and return the value that is less
    {
        return n1;
    }
    else
    {
        return n2;
    }
}

int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    if(n2 == 0 && n1 >= 0) //Check for size 0 in array
    {
        return 0;
    }
    
    for(int c = 0; c < n1; c++) //Run through the first string
    {
        if(a1[c] == a2[0]) //If there is some thing from the first string that is equal to the first value from the second string...
        {
            for(int d = 1; d < n2; d++) //Check for the other values of the second string
            {
                if(a1[c + d] == a2[d]) //Check for corresponding values after
                {
                    return c;
                }
                if((c + d) > (n2 - 1)) //Checks for the undefined sequence
                {
                    return -1;
                }
            }
        }
    }
    return -1;
}

int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
    if (n2 == 0 && n1 >= 0)
    {
        return 0;
    }

    for(int x = 0; x < n1; x++) //Check for all values of the first matrix
    {
        for(int y = 0; y < n2; y++) //Check for all values of the second matrix
        {
            if(a1[x] == a2[y]) //Check for values in the second matrix that could equal the first matrix
            {
                return x;
            }
        }
    }
    return -1;
}

int divide(string a[], int n, string divider)
{
    if(n < 0) //Check n value
    {
        return -1;
    }
    int firstVal = 0; //Store first value
    
    for(int p = 0; p < n - 1; p++) //Runs through the p terms of the array
    {
        for (int z = 0; z < n - p - 1 ; z++) //Take away checking for values of p since they were already checked
        {
            if (a[z] > a[z + 1]) //Check if your current is greater than the next
            {
                    string tempString = a[z]; //Store string b
                    a[z] = a[z + 1]; //Swap b with string a
                    a[z + 1] = tempString;
            }
        }
    }
    for(int o = 0; o < n; o++) //Runs through loop
    {
        if(a[o] >= divider) //Finds the first value greater than divider
        {
            return o;
        }
    }
    return firstVal;
}

//int main() {
//    //Given Tests
//    string h[7] = { "greg", "gavin", "ed", "xavier", "", "eleni", "fiona" };
//    assert(lookup(h, 7, "eleni") == 5);
//    assert(lookup(h, 7, "ed") == 2);
//    assert(lookup(h, 2, "ed") == -1);
//    assert(positionOfMax(h, 7) == 3);
//
//    string g[4] = { "greg", "gavin", "fiona", "kevin" };
//    assert(differ(h, 4, g, 4) == 2);
//    assert(appendToAll(g, 4, "?") == 4 && g[0] == "greg?" && g[3] == "kevin?");
//    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "fiona?" && g[3] == "gavin?");
//
//    string e[4] = { "ed", "xavier", "", "eleni" };
//    assert(subsequence(h, 7, e, 4) == 2);
//
//    string d[5] = { "gavin", "gavin", "gavin", "xavier", "xavier" };
//    assert(countRuns(d, 5) == 2);
//
//    string f[3] = { "fiona", "ed", "john" };
//    assert(lookupAny(h, 7, f, 3) == 2);
//    assert(flip(f, 3) == 3 && f[0] == "john" && f[2] == "fiona");
//
//    assert(divide(h, 7, "fiona") == 3);
//
//    //Data from the Description
//    string people[5] = { "dianne", "fiona", "ed", "xavier", "greg" };
//    assert(lookup(people, 5, "greg"));
//
//    assert(appendToAll(people, 5, "!!!") == 5 && people[0] == "dianne!!!" && people[1] == "fiona!!!" && people[4] == "greg!!!");
//
//    string candidate[6] = { "dianne", "fiona", "gavin", "xavier", "ed", "betty" };
//    assert(positionOfMax(candidate, 6) == 3);
//
//    string politician[5] = { "eleni", "dianne", "fiona", "kevin", "gavin" };
//    assert(rotateLeft(politician, 5, 1) == 1 && politician[0] == "eleni" && politician[1] == "fiona" && politician[2] == "kevin" && politician[3] == "gavin" && politician[4] == "dianne");
//
//    string test0[9] = { "xavier", "betty", "john", "john", "ed", "ed", "ed", "john", "john" };
//    assert(countRuns(test0, 9) == 5);
//
//    string folks[6] = { "betty", "john", "", "xavier", "kevin", "dianne" };
//    assert(flip(folks, 4) == 4 && folks[0] == "xavier" && folks[1] == "" && folks[2] == "john" && folks[3] == "betty" && folks[4] == "kevin" && folks[5] == "dianne");
//
//    string folksOrij[6] = { "betty", "john", "", "xavier", "kevin", "dianne" };
//    string group[5] = { "betty", "john", "dianne", "", "xavier" };
//    assert(differ(folksOrij, 6, group, 5) == 2);
//    assert(differ(folksOrij, 2, group, 1) == 1);
//
//    string names[10] = { "eleni", "gavin", "kevin", "greg", "betty", "fiona" };
//    string names1[10] = { "gavin", "kevin", "greg" };
//    assert(subsequence(names, 6, names1, 3) == 1);
//    string names2[10] = { "eleni", "greg" };
//    assert(subsequence(names, 5, names2, 2) == -1);
//
//    string namesOrij[10] = { "eleni", "gavin", "kevin", "greg", "betty", "fiona" };
//    string set1[10] = { "dianne", "betty", "greg", "gavin" };
//    assert(lookupAny(namesOrij, 6, set1, 4) == 1);
//    string set2[10] = { "xavier", "ed" };
//    assert(lookupAny(namesOrij, 6, set2, 2) == -1);
//
//    string candidate1[6] = { "dianne", "fiona", "gavin", "xavier", "ed", "betty" };
//    assert(divide(candidate1, 6, "eleni") == 3);
//
//    string candidate2[4] = { "gavin", "kevin", "fiona", "john" };
//    assert(divide(candidate2, 4, "john") == 2);
//
//    //My tests
//    string people2[5] = { "dianne", "fiona", "ed", "xavier", "greg" };
//    assert(lookup(people2, -1, "greg") == -1); // returns -1
//    assert(lookup(people2, 5, "xavier") == 3); //returns 3
//    assert(lookup(people2, 3, "") == -1); // returns -1
//    assert(lookup(people2, 3, "Greg") == -1); // returns -1
//    assert(lookup(people2, 0, "") == -1); // returns -1
//
//    string people3[5] = { "dianne", "fiona", "ed", "xavier", "greg" };
//    assert(appendToAll(people3, -1, "!!!") == -1); //Returns -1
//    assert(appendToAll(people3, 5, "!") == 5 && people3[0] == "dianne!" && people3[1] == "fiona!" && people3[4] == "greg!"); //Returns 5
//    // now people[0] is "dianne!", people[1] is "fiona!", ...,
//    // and people[4] is "greg!"
//    assert(appendToAll(people3, 0, "!") == 0);
//
//    string candidate3[6] = { "dianne", "fiona", "gavin", "xavier", "ed", "betty" };
//    assert(positionOfMax(candidate3, -1) == -1);  // returns -1
//    assert(positionOfMax(candidate3, 3) == 2);  // returns 2
//    assert(positionOfMax(candidate3, 0) == -1);  // returns -1
//
//    string b[4] = {"a", "a", "a", "a"};
//    assert(positionOfMax(b, 4) == 0); //Returns 0
//
//    string politician1[5] = { "eleni", "dianne", "fiona", "kevin", "gavin" };
//    assert(rotateLeft(politician1, 5, -1) == -1); // returns -1
//    assert(rotateLeft(politician1, 5, 3) == 3 && politician1[0] == "eleni" && politician1[1] == "dianne" && politician1[2] == "fiona" && politician1[3] == "gavin" && politician1[4] == "kevin"); // returns 3
//    // politician now contains: "eleni", "dianne", "fiona", "gavin", "kevin"
//    assert(rotateLeft(politician1, 0, 3) == -1);
//
//    string d1[9] = { "xavier", "betty", "john", "john", "ed", "ed", "ed", "john", "john" };
//    assert(countRuns(d1, -1) == -1); // returns -1
//    assert(countRuns(d1, 0) == 1);
//
//    string folks1[6] = { "betty", "john", "", "xavier", "kevin", "dianne" };
//    assert(flip(folks1, -1) == -1);  // returns -1
//    assert(flip(folks1, 4) == 4 && folks1[0] == "xavier" && folks1[1] == "" && folks1[2] == "john" && folks1[3] == "betty" && folks1[4] == "kevin" && folks1[5] == "dianne"); // returns 4
//    // folks now contains: "kevin", "xavier", "", "john", "betty", "dianne"
//    assert(flip(folks1, 0) == 0);
//
//    string folks2[6] = { "betty", "john", "", "xavier", "kevin", "dianne" };
//    string group2[5] = { "betty", "john", "dianne", "", "xavier" };
//    assert(differ(folks2, -2, group2, 5) == -1); // returns -1
//    assert(differ(folks2, 2, group2, -3) == -1); // returns -1
//    assert(differ(folks2, 2, group2, 0) == 0);
//    assert(differ(folks2, 0, group2, 2) == 0);
//
//    string names0[10] = { "eleni", "gavin", "kevin", "greg", "betty", "fiona" };
//    string names01[10] = { "gavin", "kevin", "greg" };
//    assert(subsequence(names0, -6, names01, 3) == -1); // returns -1
//    string names02[10] = { "eleni", "greg" };
//    assert(subsequence(names0, 6, names02, -3) == -1); // returns -1
//    assert(subsequence(names0, 0, names02, 3) == -1);
//    assert(subsequence(names0, 6, names02, 0) == 0); //0 sub 6
//
//    string names00[10] = { "eleni", "gavin", "kevin", "greg", "betty", "fiona" };
//    string set01[10] = { "dianne", "betty", "greg", "gavin" };
//    assert(lookupAny(names00, -6, set01, 4) == -1);  // returns -1
//    string set02[10] = { "xavier", "ed" };
//    assert(lookupAny(names00, 6, set01, -4) == -1);  // returns -1
//    assert(lookupAny(names00, 0, set01, 4) == -1);
//    assert(lookupAny(names00, 6, set01, 0) == 0);
//
//    string candidate4[6] = { "dianne", "fiona", "gavin", "xavier", "ed", "betty" };
//    assert(divide(candidate4, -6, "eleni") == -1);  //  returns -1
//    assert(divide(candidate4, 0, "eleni") == 0);
//
//    cout << "All tests succeeded" << endl;
//}

string c[6] = {
    "alpha", "beta", "beta", "delta", "gamma", "gamma"
};

bool dividecheck(const string a[], int n, int p, string divider)
{
    for (int k = 0; k < p; k++)
        if (a[k] >= divider)
            return false;
    for ( ; p < n  &&  a[p] == divider; p++)
        ;
    for (int k = p; k < n; k++)
        if (a[k] <= divider)
            return false;
    string b[100];
    copy(a, a+n, b);
    sort(b, b+n);
    return equal(b, b+n, c);
}

void testone(int n)
{
    const int N = 6;
    
    // Act as if  a  were declared:
    //   string a[N] = {
    //       "alpha", "beta", "gamma", "gamma", "beta", "delta"
    //   };
    // This is done in a way that will probably cause a crash if
    // a[-1] or a[N] is accessed:  We place garbage in those positions.
    string aa[1+N+1] = {
        "", "alpha", "beta", "gamma", "gamma", "beta", "delta", ""
    };
    string* a = &aa[1];
    string* z = aa;
    a[-1].string::~string();
    a[N].string::~string();
    fill_n(reinterpret_cast<char*>(&a[-1]), sizeof(a[-1]), 0xEF);
    fill_n(reinterpret_cast<char*>(&a[N]), sizeof(a[N]), 0xEF);
    
    string b[N] = {
        "alpha", "beta", "gamma", "delta", "beta", "delta"
    };
    
    string d[9] = {
        "alpha", "beta",  "beta", "beta", "alpha",
        "alpha", "delta", "beta", "beta"
    };
    
    switch (n)
    {
        case  1: {
            assert(appendToAll(z, -1, "rho") == -1 && a[0] == "alpha");
        } break; case  2: {
            assert(appendToAll(z, 0, "rho") == 0 && a[0] == "alpha");
        } break; case  3: {
            assert(appendToAll(a, 1, "rho") == 1 && a[0] == "alpharho" &&
                   a[1] == "beta");
        } break; case  4: {
            assert(appendToAll(a, 6, "rho") == 6 && a[0] == "alpharho" &&
                   a[1] == "betarho" && a[2] == "gammarho" &&
                   a[3] == "gammarho" && a[4] == "betarho" &&
                   a[5] == "deltarho");
        } break; case  5: {
            assert(lookup(z, -1, "alpha") == -1);
        } break; case  6: {
            assert(lookup(z, 0, "alpha") == -1);
        } break; case  7: {
            assert(lookup(a, 1, "alpha") == 0);
        } break; case  8: {
            assert(lookup(a, 6, "delta") == 5);
        } break; case  9: {
            assert(lookup(a, 6, "beta") == 1);
        } break; case 10: {
            assert(lookup(a, 6, "zeta") == -1);
        } break; case 11: {
            assert(positionOfMax(z, -1) == -1);
        } break; case 12: {
            assert(positionOfMax(z, 0) == -1);
        } break; case 13: {
            assert(positionOfMax(a, 1) == 0);
        } break; case 14: {
            assert(positionOfMax(a, 3) == 2);
        } break; case 15: {
            assert(positionOfMax(a, 6) == 2);
        } break; case 16: {
            assert(positionOfMax(a+3, 3) == 0);
        } break; case 17: {
            a[0] = "";
            a[1] = " ";
            a[2] = "";
            assert(positionOfMax(a, 3) == 1);
        } break; case 18: {
            assert(rotateLeft(z, -1, 0) == -1 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 19: {
            assert(rotateLeft(a, 6, -1) == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 20: {
            assert(rotateLeft(a, 6, 6) == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 21: {
            assert(rotateLeft(z, 0, 0) == -1 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 22: {
            assert(rotateLeft(a, 1, 0) == 0 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 23: {
            assert(rotateLeft(a, 6, 0) == 0 &&
                   a[0] == "beta" && a[1] == "gamma" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "delta" && a[5] == "alpha");
        } break; case 24: {
            assert(rotateLeft(a, 6, 5) == 5 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 25: {
            assert(rotateLeft(a, 6, 3) == 3 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "delta" && a[5] == "gamma");
        } break; case 26: {
            assert(rotateLeft(a, 5, 3) == 3 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "gamma" && a[5] == "delta");
        } break; case 27: {
            assert(countRuns(z, -1) == -1);
        } break; case 28: {
            assert(countRuns(z, 0) == 0);
        } break; case 29: {
            assert(countRuns(a, 1) == 1);
        } break; case 30: {
            assert(countRuns(a, 3) == 3);
        } break; case 31: {
            assert(countRuns(a, 4) == 3);
        } break; case 32: {
            assert(countRuns(a+2, 4) == 3);
        } break; case 33: {
            assert(countRuns(d, 9) == 5);
        } break; case 34: {
            assert(flip(z, -1) == -1 && a[0] == "alpha");
        } break; case 35: {
            assert(flip(z, 0) == 0 && a[0] == "alpha");
        } break; case 36: {
            assert(flip(a, 1) == 1 && a[0] == "alpha" &&
                   a[1] == "beta");
        } break; case 37: {
            assert(flip(a, 2) == 2 && a[0] == "beta" &&
                   a[1] == "alpha" && a[2] == "gamma");
        } break; case 38: {
            assert(flip(a, 5) == 5 && a[0] == "beta" &&
                   a[1] == "gamma" && a[2] == "gamma" && a[3] == "beta" &&
                   a[4] == "alpha" && a[5] == "delta");
        } break; case 39: {
            a[2] = "zeta";
            assert(flip(a,6) == 6 && a[0] == "delta" && a[1] == "beta" &&
                   a[2] == "gamma" && a[3] == "zeta" && a[4] == "beta" &&
                   a[5] == "alpha");
        } break; case 40: {
            assert(differ(z, -1, b, 6) == -1);
        } break; case 41: {
            assert(differ(a, 6, z, -1) == -1);
        } break; case 42: {
            assert(differ(z, 0, b, 0) == 0);
        } break; case 43: {
            assert(differ(a, 3, b, 3) == 3);
        } break; case 44: {
            assert(differ(a, 3, b, 2) == 2);
        } break; case 45: {
            assert(differ(a, 2, b, 3) == 2);
        } break; case 46: {
            assert(differ(a, 6, b, 6) == 3);
        } break; case 47: {
            assert(subsequence(z, -1, b, 6) == -1);
        } break; case 48: {
            assert(subsequence(a, 6, z, -1) == -1);
        } break; case 49: {
            assert(subsequence(z, 0, b, 6) == -1);
        } break; case 50: {
            assert(subsequence(a, 6, z, 0) == 0);
        } break; case 51: {
            assert(subsequence(a, 6, b, 1) == 0);
        } break; case 52: {
            assert(subsequence(a, 6, b+4, 2) == 4);
        } break; case 53: {
            assert(subsequence(a, 6, b+3, 1) == 5);
        } break; case 54: {
            assert(subsequence(a, 6, b+3, 2) == -1);
        } break; case 55: {
            assert(subsequence(a, 6, b+2, 2) == -1);
        } break; case 56: {
            assert(subsequence(a, 6, a, 6) == 0);
        } break; case 57: {
            assert(lookupAny(a, 6, z, -1) == -1);
        } break; case 58: {
            assert(lookupAny(z, -1, b, 6) == -1);
        } break; case 59: {
            assert(lookupAny(z, 0, b, 1) == -1);
        } break; case 60: {
            assert(lookupAny(a, 6, z, 0) == -1);
        } break; case 61: {
            assert(lookupAny(a, 1, b, 1) == 0);
        } break; case 62: {
            assert(lookupAny(a, 6, b+3, 3) == 1);
        } break; case 63: {
            assert(lookupAny(a, 4, b+3, 3) == 1);
        } break; case 64: {
            assert(lookupAny(a, 2, b+2, 2) == -1);
        } break; case 65: {
            assert(divide(z, -1, "beta") == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 66: {
            assert(divide(z, 0, "beta") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 67: {
            assert(divide(a, 1, "aaa") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 68: {
            assert(divide(a, 1, "alpha") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 69: {
            assert(divide(a, 1, "zeta") == 1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 70: {
            assert(divide(a, 2, "aaa") == 0 &&
                   dividecheck(a, 2, 0, "aaa") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 71: {
            assert(divide(a, 2, "alpha") == 0 &&
                   dividecheck(a, 2, 0, "alpha") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 72: {
            assert(divide(a, 2, "beta") == 1 &&
                   dividecheck(a, 2, 1, "beta") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 73: {
            assert(divide(a, 2, "zeta") == 2 &&
                   dividecheck(a, 2, 2, "zeta") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 74: {
            assert(divide(a, 6, "aaa") == 0 && dividecheck(a, 6, 0, "aaa"));
        } break; case 75: {
            assert(divide(a, 6, "alpha") == 0 &&
                   dividecheck(a, 6, 0, "alpha"));
        } break; case 76: {
            assert(divide(a, 6, "beta") == 1 &&
                   dividecheck(a, 6, 1, "beta"));
        } break; case 77: {
            assert(divide(a, 6, "delta") == 3 &&
                   dividecheck(a, 6, 3, "delta"));
        } break; case 78: {
            assert(divide(a, 6, "gamma") == 4 &&
                   dividecheck(a, 6, 4, "gamma"));
        } break; case 79: {
            assert(divide(a, 6, "zeta") == 6 &&
                   dividecheck(a, 6, 6, "zeta"));
        } break; case 80: {
            a[2] = "mu";
            c[5] = "mu";
            assert(divide(a, 6, "mu") == 5 && dividecheck(a, 6, 5, "mu"));
        } break; case 81: {
            assert(divide(a, 6, "chi") == 3 && dividecheck(a, 6, 3, "chi"));
        } break; case 82: {
            // To earn the bonus point for rotateLeft, this and all other
            // rotateLeft tests must pass, and that function must not
            // use any additional arrays.
            const int BIG = 500;
            string h[BIG];
            for (int k = 0; k < BIG; k++)
                h[k] = (k % 2 == 0 ? "alpha" : "beta");
            h[BIG-2] = "gamma";
            h[BIG-1] = "delta";
            rotateLeft(h, BIG, 0);
            assert(h[BIG-3] == "gamma"  &&  h[BIG-2] == "delta");
        } break; case 83: {
            // To earn the bonus point for flip, this and all other
            // flip tests must pass, and that function must not
            // use any additional arrays.
            const int BIG = 500;
            string h[BIG];
            for (int k = 0; k < BIG; k++)
                h[k] = (k % 2 == 0 ? "alpha" : "beta");
            h[0] = "gamma";
            h[BIG-1] = "delta";
            flip(h, BIG);
            assert(h[0] == "delta"  &&  h[BIG-1] == "gamma");
        } break; case 84: {
            // To earn the bonus point for divide, this and all other
            // divide tests must pass, and that function must not
            // use any additional arrays.
            const int BIG = 500;
            string h[BIG];
            string i[3] = { "alpha", "beta", "gamma" };
            for (int k = 0; k < BIG; k++)
                h[k] = i[k % 3];
            divide(h, BIG, "beta");
            int m = 0;
            for (m = 0; m < (BIG+2)/3; m++)
                assert(h[m] == "alpha");
            for ( ; m < (BIG+1)/3; m++)
                assert(h[m] == "beta");
            for ( ; m < BIG/3; m++)
                assert(h[m] == "gamma");
        } break;
    }
    
    new (&a[-1]) string;
    new (&a[N]) string;
}

int main()
{
    for(int i = 81; i < 84; i++)
    {
        testone(i);
        cout << "Passed test " << i << endl;
    }
}
