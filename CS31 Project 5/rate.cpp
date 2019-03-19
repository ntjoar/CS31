// Nathan Tjoar
// 005081232
// Lecture 2
// Discussion 2A

#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAX_WORD_LENGTH = 20; //Word in a pattern that is no longer than 20 characters
const int MAX_DOCU_LENGTH = 250; //Characters in document will be no longer than 250 characters
const int MAX_ARRAY_SIZE = 256;

//Input the values into an array iff the value does match the description
int makeProper(char word1[][MAX_WORD_LENGTH+1], char word2[][MAX_WORD_LENGTH+1], int separation[], int nPatterns)
{
    int counter = 0; //Count how many values are in our array
    char storeWord1[MAX_ARRAY_SIZE][MAX_WORD_LENGTH] = {'\0'}; //Store correct word1
    char storeWord2[MAX_ARRAY_SIZE][MAX_WORD_LENGTH] = {'\0'}; //Store correct word2
    int storeSeparation[MAX_ARRAY_SIZE] = {0}; //Store correct separation values
    int testRow = 0; //Row Testing data
    
    for(int e = 0; e < nPatterns; e++)
    {
        if(separation[e] < 0) //separation is negative
        {
            testRow = 1;
        }
        
        if(strcmp(word1[e], "") == 0  || strcmp(word2[e], "") == 0) //Empty string
        {
            testRow = 1;
        }
        
        for(int c = 0; c < strlen(word1[e]); c++) //word1 not alphabetic at any point
        {
            if(!isalpha(word1[e][c]))
            {
                testRow = 1;
            }
        }
        
        for(int d = 0; d < strlen(word2[e]); d++) //word2 not alphabetic at any point
        {
            if(!isalpha(word2[e][d]))
            {
                testRow = 1;
            }
        }
        
        //Testing for repition
        for(int f = 1; (e + f) < nPatterns; f++)
        {
            if(strcmp(word1[e], word1[e + f]) == 0) //If repititon of word1 in word1 array
            {
                if(strcmp(word2[e], word2[e + f]) == 0) //If corresponding array has same corresponding value
                {
                    if(separation[e] > separation[e + f]) //Check separation value
                    {
                        if(e == 0)//Position that is greater is zero (Mainly so array doesn't confuse missing as zeroes)
                        {
                            testRow = 1;
                            break;
                        }
                    }
                }
            }
            else if(strcmp(word1[e], word2[e + f]) == 0) //If repition of word1 in word 2 array
            {
                if(strcmp(word2[e], word1[e + f]) == 0) //If corresponding array has same corresponding value
                {
                    if(separation[e] > separation[e + f]) //Check separation value
                    {
                        testRow = 1;
                        break;
                    }
                }
            }
            else
            {
                continue;
            }
        }
        for(int f = 1; (e - f) >= 0; f++) //Similarly, for before the array posn
        {
            if(strcmp(word1[e], word1[e - f]) == 0) //If repition of word1 in word1 array
            {
                if(strcmp(word2[e], word2[e - f]) == 0) //If corresponding array has same corresponding value
                {
                    if(separation[e] > separation[e - f]) //Check separation value
                    {
                        if(e == 0)//Position that is greater is zero (Mainly so array doesn't confuse missing as zeroes)
                        {
                            testRow = 1;
                            break;
                        }
                    }
                }
            }
            else if(strcmp(word1[e], word2[e - f]) == 0) //If repition of word1 in word 2 array
            {
                if(strcmp(word2[e], word1[e - f]) == 0) //If corresponding array has same corresponding value
                {
                    if(separation[e] > separation[e - f]) //Check separation value
                    {
                        testRow = 1;
                        break;
                    }
                }
            }
            else
            {
                continue;
            }
        }
        if(testRow == 1) //If it does not fit description
        {
            testRow = 0;
            continue;
        }
        else
        {
            for(int x = 0; x < strlen(word1[e]); x++)
            {
                word1[e][x] = tolower(word1[e][x]);
            }
            for(int j = 0; j < strlen(word2[e]); j++)
            {
                word2[e][j] = tolower(word2[e][j]);
            }
            strcpy(storeWord1[e], word1[e]); //Copy word1
            strcpy(storeWord2[e], word2[e]); //Copy word2
            storeSeparation[e] = separation[e]; //Copy the value
            counter++;
        }
    }
    
    int arrayPos = 0;
    for(int i = 0; i < nPatterns; i++)
    {
        if(strcmp(storeWord1[i], "") == 0) //If it does not fit description
        {
            continue;
        }
        else
        {
            strcpy(word1[arrayPos], storeWord1[i]); //Copy word1
            strcpy(word2[arrayPos], storeWord2[i]); //Copy word2
            separation[arrayPos] = storeSeparation[i]; //Copy the value
            arrayPos++;
        }
    }
    
    for(int j = arrayPos; j < nPatterns; j++) //Fill the rest of the array with clear
    {
        strcpy(word1[j], ""); //Copy word1
        strcpy(word2[j], ""); //Copy word2
        separation[j] = -1; //Copy the value
    }
    
    return counter;
}

//Outputs the size of the array
int rate(const char document[], const char word1[][MAX_WORD_LENGTH+1], const char word2[][MAX_WORD_LENGTH+1], const int separation[], int nPatterns)
{
    if(nPatterns < 0) //nPatterns is less than 0
    {
        return 0;
    }
    
    int countMatches = 0; //Matches found
    char lowerDocument[MAX_DOCU_LENGTH + 1] = {'\0'};
    
    for(int m = 0 , n = 0; m < strlen(document); m++)//Translates all letters into lower case while keeping the spaces
    {
        if(isalpha(document[m]))
        {
            lowerDocument[n] = tolower(document[m]);
            n++;
        }
        else if(isspace(document[m]))
        {
            lowerDocument[n] = '%';
            n++;
        }
        else //Skip anything else
        {
            continue;
        }
    }
    
    char docWords[MAX_DOCU_LENGTH][MAX_WORD_LENGTH + 1] = {'\0'};
    for(int o = 0, arrayPos = 0, charPos = 0; o < strlen(document); o++)
    {
        if(isalpha(lowerDocument[o]))
        {
            strcpy(&docWords[arrayPos][charPos], &lowerDocument[o]); //Input words to array
            charPos++;
        }
        else if(lowerDocument[o] == '%')
        {
            docWords[arrayPos][charPos] = '\0'; //Input empty for spaces and skip to next position
            charPos = 0;
            arrayPos++;
        }
    }
    
    int keepRunning = 1; //Shall we keep checking?
    for(int x = 0; x < nPatterns; x++) //Runs thru iterations of the array matching words
    {
        keepRunning = 1;
        for(int r = 0; r < strlen(document) && keepRunning == 1; r++) //Runs through the document
        {
            if(strcmp(docWords[r], word1[x]) == 0) //Check if any word in the document is the same in word1 place
            {
                for(int s = 1; s <= (separation[x] + 1) && (r + s) < strlen(lowerDocument); s++) //Word2 appears first
                {
                    if(strcmp(docWords[r + s], word2[x]) == 0)
                    {
                        countMatches++;
                        keepRunning = 0;//Break out of parent loop
                        break;
                    }
                }
            }
            else if(strcmp(docWords[r], word2[x]) == 0) //Word2 appears first
            {
                for(int t = 1; t <= (separation[x] + 1) && (t + r) < strlen(lowerDocument); t++) //Word2 appears first
                {
                    if(strcmp(docWords[t + r], word1[x]) == 0)
                    {
                        countMatches++;
                        keepRunning = 0;//Break out of parent loop
                        break;
                    }
                }
            }
        }
    }
    return countMatches;
}

int d[3] =                      {    1,    0,    2 };
char w1[3][MAX_WORD_LENGTH+1] = { "aa", "bb", "cc" };
char w2[3][MAX_WORD_LENGTH+1] = { "dd", "ee", "ff" };

int e[2] =                      {    3,    3 };
char x1[2][MAX_WORD_LENGTH+1] = { "aa", "cc" };
char x2[2][MAX_WORD_LENGTH+1] = { "bb", "dd" };

const int THREE_LETTERS = 26*26*26;
int dd[THREE_LETTERS];
char ww1[THREE_LETTERS][MAX_WORD_LENGTH+1];
char ww2[THREE_LETTERS][MAX_WORD_LENGTH+1];

bool eq(int c, int dist, const char wd1[], const char wd2[])
{
    return d[c] == dist  &&  strcmp(w1[c], wd1) == 0  &&
    strcmp(w2[c], wd2) == 0;
}

void testone(int n)
{
    switch (n)
    {
        case  1: {
            assert(makeProper(w1, w2, d, 0) == 0);
        } break; case  2: {
            assert(makeProper(w1, w2, d, 1) == 1  &&
                   eq(0, 1, "aa", "dd"));
        } break; case  3: {
            d[0] = -1;
            assert(makeProper(w1, w2, d, 1) == 0);
        } break; case  4: {
            d[0] = -1;
            assert(makeProper(w1, w2, d, 2) == 1  &&
                   eq(0, 0, "bb", "ee"));
        } break; case  5: {
            d[1] = -1;
            assert(makeProper(w1, w2, d, 2) == 1  &&
                   eq(0, 1, "aa", "dd"));
        } break; case  6: {
            d[1] = -1;
            d[2] = -1;
            assert(makeProper(w1, w2, d, 3) == 1  &&
                   eq(0, 1, "aa", "dd"));
        } break; case  7: {
            d[0] = -1;
            d[1] = -1;
            assert(makeProper(w1, w2, d, 3) == 1  &&
                   eq(0, 2, "cc", "ff"));
        } break; case  8: {
            d[0] = -1;
            d[1] = -1;
            d[2] = -1;
            assert(makeProper(w1, w2, d, 3) == 0);
        } break; case  9: {
            strcpy(w1[1], "");
            assert(makeProper(w1, w2, d, 3) == 2  &&
                   ((eq(0, 1, "aa", "dd")  &&  eq(1, 2, "cc", "ff"))  ||
                    (eq(1, 1, "aa", "dd")  &&  eq(0, 2, "cc", "ff"))
                    )
                   );
        } break; case 10: {
            strcpy(w2[1], "");
            assert(makeProper(w1, w2, d, 3) == 2  &&
                   ((eq(0, 1, "aa", "dd")  &&  eq(1, 2, "cc", "ff"))  ||
                    (eq(1, 1, "aa", "dd")  &&  eq(0, 2, "cc", "ff"))
                    )
                   );
        } break; case 11: {
            strcpy(w1[1], "bb@");
            assert(makeProper(w1, w2, d, 3) == 2  &&
                   ((eq(0, 1, "aa", "dd")  &&  eq(1, 2, "cc", "ff"))  ||
                    (eq(1, 1, "aa", "dd")  &&  eq(0, 2, "cc", "ff"))
                    )
                   );
        } break; case 12: {
            strcpy(w1[1], "bb ");
            assert(makeProper(w1, w2, d, 3) == 2  &&
                   ((eq(0, 1, "aa", "dd")  &&  eq(1, 2, "cc", "ff"))  ||
                    (eq(1, 1, "aa", "dd")  &&  eq(0, 2, "cc", "ff"))
                    )
                   );
        } break; case 13: {
            strcpy(w1[1], "bBBb");
            assert(makeProper(w1, w2, d, 2) == 2  &&
                   ((eq(0, 1, "aa", "dd")  &&  eq(1, 0, "bbbb", "ee"))  ||
                    (eq(1, 1, "aa", "dd")  &&  eq(0, 0, "bbbb", "ee"))
                    )
                   );
        } break; case 14: {
            strcpy(w1[1], "bBBb");
            strcpy(w2[1], "EeEeE");
            assert(makeProper(w1, w2, d, 2) == 2  &&
                   ((eq(0, 1, "aa", "dd")  &&  eq(1, 0, "bbbb", "eeeee"))  ||
                    (eq(1, 1, "aa", "dd")  &&  eq(0, 0, "bbbb", "eeeee"))
                    )
                   );
        } break; case 15: {
            strcpy(w2[1], "bb");
            assert(makeProper(w1, w2, d, 2) == 2  &&
                   ((eq(0, 1, "aa", "dd")  &&  eq(1, 0, "bb", "bb"))  ||
                    (eq(1, 1, "aa", "dd")  &&  eq(0, 0, "bb", "bb"))
                    )
                   );
        } break; case 16: {
            strcpy(w2[0], "aa");
            strcpy(w1[1], "aa");
            strcpy(w2[1], "aa");
            assert(makeProper(w1, w2, d, 2) == 1  &&
                   eq(0, 1, "aa", "aa")
                   );
        } break; case 17: {
            strcpy(w1[1], "aa");
            strcpy(w2[1], "dd");
            assert(makeProper(w1, w2, d, 3) == 2  &&
                   ((eq(0, 1, "aa", "dd")  &&  eq(1, 2, "cc", "ff"))  ||
                    (eq(1, 1, "aa", "dd")  &&  eq(0, 2, "cc", "ff"))
                    )
                   );
        } break; case 18: {
            strcpy(w1[1], "aa");
            strcpy(w2[1], "dd");
            d[1] = 1;
            assert(makeProper(w1, w2, d, 3) == 2  &&
                   ((eq(0, 1, "aa", "dd")  &&  eq(1, 2, "cc", "ff"))  ||
                    (eq(1, 1, "aa", "dd")  &&  eq(0, 2, "cc", "ff"))
                    )
                   );
        } break; case 19: {
            strcpy(w1[1], "aa");
            strcpy(w2[1], "dd");
            d[1] = 4;
            assert(makeProper(w1, w2, d, 3) == 2  &&
                   ((eq(0, 4, "aa", "dd")  &&  eq(1, 2, "cc", "ff"))  ||
                    (eq(1, 4, "aa", "dd")  &&  eq(0, 2, "cc", "ff"))
                    )
                   );
        } break; case 20: {
            strcpy(w1[1], "aa");
            strcpy(w2[1], "dd");
            strcpy(w1[2], "aa");
            strcpy(w2[2], "dd");
            assert(makeProper(w1, w2, d, 3) == 1  &&
                   eq(0, 2, "aa", "dd")
                   );
        } break; case 21: {
            strcpy(w1[2], "aa");
            strcpy(w2[2], "dd");
            d[1] = -1;
            assert(makeProper(w1, w2, d, 3) == 1  &&
                   eq(0, 2, "aa", "dd")
                   );
        } break; case 22: {
            strcpy(w1[1], "abcdefghijklmnopqrst");
            strcpy(w2[1], "abcdefghijklmnopqrsu");
            d[0] = -1;
            assert(makeProper(w1, w2, d, 2) == 1  &&
                   eq(0, 0, "abcdefghijklmnopqrst",
                      "abcdefghijklmnopqrsu")
                   );
        } break; case 23: {
            strcpy(w2[0], "DD");
            strcpy(w1[1], "AA");
            strcpy(w2[1], "dD");
            assert(makeProper(w1, w2, d, 3) == 2  &&
                   ((eq(0, 1, "aa", "dd")  &&  eq(1, 2, "cc", "ff"))  ||
                    (eq(1, 1, "aa", "dd")  &&  eq(0, 2, "cc", "ff"))
                    )
                   );
        } break; case 24: {
            strcpy(w1[1], "dd");
            strcpy(w2[1], "aa");
            assert(makeProper(w1, w2, d, 3) == 2  &&
                   ((eq(0, 1, "aa", "dd")  &&  eq(1, 2, "cc", "ff"))  ||
                    (eq(1, 1, "aa", "dd")  &&  eq(0, 2, "cc", "ff"))
                    )
                   );
        } break; case 25: {
            strcpy(w1[1], "dd");
            strcpy(w2[1], "aa");
            d[1] = 1;
            assert(makeProper(w1, w2, d, 3) == 2  &&
                   (((eq(0, 1, "aa", "dd")  ||  eq(0, 1, "dd", "aa")
                      )  &&  eq(1, 2, "cc", "ff")
                     )  ||
                    ((eq(1, 1, "aa", "dd")  ||  eq(1, 1, "dd", "aa")
                      )  &&  eq(0, 2, "cc", "ff")
                     )
                    )
                   );
        } break; case 26: {
            strcpy(w1[1], "Dd");
            strcpy(w2[1], "aA");
            assert(makeProper(w1, w2, d, 3) == 2  &&
                   ((eq(0, 1, "aa", "dd")  &&  eq(1, 2, "cc", "ff"))  ||
                    (eq(1, 1, "aa", "dd")  &&  eq(0, 2, "cc", "ff"))
                    )
                   );
        } break; case 27: {
            int dx[7] = { 1, 3, 0, 2, 1, 0, 12 };
            char w1x[7][MAX_WORD_LENGTH+1] = { "mad", "deranged",
                "NEFARIOUS", "half-witted", "robot", "plot", "have" };
            char w2x[7][MAX_WORD_LENGTH+1] = { "scientist", "robot",
                "PLOT", "assistant", "deranged", "Nefarious", "mad" };
            assert(makeProper(w1x, w2x, dx, 7) == 4);
        } break; case 28: {
            assert(rate("", x1, x2, e, 2) == 0);
        } break; case 29: {
            assert(rate(" ", x1, x2, e, 2) == 0);
        } break; case 30: {
            assert(rate("aa bb", x1, x2, e, 2) == 1);
        } break; case 31: {
            e[0] = 0;
            assert(rate("aa bb", x1, x2, e, 2) == 1);
        } break; case 32: {
            e[0] = 0;
            assert(rate("aa     bb", x1, x2, e, 2) == 1);
        } break; case 33: {
            assert(rate(" aa bb", x1, x2, e, 2) == 1);
        } break; case 34: {
            assert(rate("aa bb ", x1, x2, e, 2) == 1);
        } break; case 35: {
            assert(rate("aa bb cc dd xx", x1, x2, e, 2) == 2);
        } break; case 36: {
            assert(rate("aa bb cc dd xx", x1, x2, e, 1) == 1);
        } break; case 37: {
            assert(rate("aa xx cc bb xx dd xx", x1, x2, e, 2) == 2);
        } break; case 38: {
            assert(rate("xx dd bb cc aa xx", x1, x2, e, 2) == 2);
        } break; case 39: {
            assert(rate("aa xx xx xx bb cc dd xx", x1, x2, e, 2) == 2);
        } break; case 40: {
            assert(rate("aa xx xx xx xx bb cc dd xx", x1, x2, e, 2) == 1);
        } break; case 41: {
            e[0] = 0;
            e[1] = 0;
            assert(rate("aa xx bb cc dd xx", x1, x2, e, 2) == 1);
        } break; case 42: {
            e[0] = 1;
            e[1] = 1;
            assert(rate("aa cc bb dd xx", x1, x2, e, 2) == 2);
        } break; case 43: {
            assert(rate("aa bb aa bb cc dd xx", x1, x2, e, 2) == 2);
        } break; case 44: {
            assert(rate("aa aa bb bb cc dd xx", x1, x2, e, 2) == 2);
        } break; case 45: {
            strcpy(x2[0], "aa");
            assert(rate("aa xx xx aa", x1, x2, e, 2) == 1);
        } break; case 46: {
            strcpy(x2[0], "aa");
            assert(rate("xx aa xx", x1, x2, e, 2) == 0);
        } break; case 47: {
            assert(rate("aA bb cc dd xx", x1, x2, e, 2) == 2);
        } break; case 48: {
            assert(rate("aa @@ ## $$ %% ^^ bb cc dd xx", x1, x2, e, 2) == 2);
        } break; case 49: {
            assert(rate("aa b@@b cc dd xx", x1, x2, e, 2) == 2);
        } break; case 50: {
            assert(rate("aa b123456789012345678901234567890b cc dd xx", x1, x2, e, 2) == 2);
        } break; case 51: {
            e[0] = 0;
            assert(rate("aa abcdefghijklmnopqrstuvwxyz bb cc dd xx", x1, x2, e, 2) == 1);
        } break; case 52: {
            e[0] = 1;
            assert(rate("aa abcdefghijklmnopqrstuvwxyz bb cc dd xx", x1, x2, e, 2) == 2);
        } break; case 53: {
            strcpy(x1[0], "abcdefghijklmnopqrst");
            assert(rate("abcdefghijklmnopqrst bb cc dd xx", x1, x2, e, 2) == 2);
        } break; case 54: {
            strcpy(x1[0], "abcdefghijklmnopqrst");
            assert(rate("abcdefghijklmnopqrstu bb cc dd xx", x1, x2, e, 2) == 1);
        } break; case 55: {
            assert(rate("aaa bb cc dd xx", x1, x2, e, 2) == 1);
        } break; case 56: {
            assert(rate("aa@bb cc dd xx", x1, x2, e, 2) == 1);
        } break; case 57: {
            assert(rate("aa bb@cc dd xx", x1, x2, e, 2) == 0);
        } break; case 58: {
            e[0] = 1000;
            assert(rate("xx aa xx", x1, x2, e, 2) == 0);
        } break; case 59: {
            strcpy(x1[0], "a");
            strcpy(x2[0], "b");
            e[0] = 123;
            char doc[250+1];
            strcpy(doc, "a ");
            for (int k = 0; k < 123; k++)
                strcpy(doc+2+2*k, "x ");
            strcpy(doc+248, "b ");
            assert(rate(doc, x1, x2, e, 2) == 1);
        } break; case 60: {
            for (int k = 0; k < THREE_LETTERS; k++)
            {
                dd[k] = (k % 2) - 1;
                strcpy(ww1[k], "a");
                strcpy(ww2[k], "aaa");
                int kk = k;
                ww2[k][2] += kk % 26;
                kk /= 26;
                ww2[k][1] += kk % 26;
                kk /= 26;
                ww2[k][0] += kk;
            }
            assert(makeProper(ww1, ww2, dd, THREE_LETTERS) == THREE_LETTERS / 2);
            for (int k = 0; k < THREE_LETTERS / 2; k++)
                assert(dd[k] == 0 && strcmp(ww1[k], "a") == 0 &&
                       islower(ww2[k][2]) &&
                       (ww2[k][2] - 'a') % 2 == 1);
        } break; case 61: {
            for (int k = 0; k < THREE_LETTERS; k++)
            {
                dd[k] = 0;
                strcpy(ww1[k], "a");
                strcpy(ww2[k], "aaa");
                int kk = k;
                ww2[k][2] += kk % 26;
                kk /= 26;
                ww2[k][1] += kk % 26;
                kk /= 26;
                ww2[k][0] += kk;
            }
            assert(rate("a aaa a iaa a pzz a zzz", ww1, ww2, dd, THREE_LETTERS) == 4);
            assert(rate("a aaaa a iaaa a pzzz a zzzz", ww1, ww2, dd, THREE_LETTERS) == 0);
        } break;
    }
}

int main()
{
//    for(int i = 16; i < 62; i++)
//    {
//        testone(i);
//    }
//    cout << "All tests passed";
    int i = makeProper(w1, w2, d, 2);
    cout << i;
}
