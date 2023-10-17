/* This program requires the student to write 8 functions. Some described
 * in Program project 4 (Page 537) and Program Project 6 (Page 538).
 * The student also need to add a print function to print out an array.
 * The student may watch video notes on MyProgrammingLab to get the idea
 * on how to write the main function and three of these four functions
 *
 * Author: Noel Mrowiec
 * Version: 29JAN2023
 */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void reverse(char* front, char* rear);
// Precondition: The front and rear are pointing to the front
//               and rear of a C-string, respectively
// Postcondition: The C-string is reversed

void encode(char* word1, char* word2);
// Precondition: The word1 and word2 are pointing to the first char of 2 C-strings.
//               The C-strings are of equal length.
// Postcondition: Each word will switch even numbered letters. 

void decode(char* word1, char* word2);
// Precondition: The word1 and word2 are pointing to the first char of 2 C-strings.
//               The C-strings are of equal length.
// Postcondition: Will reverse the encode changes

void encode(char* word1, int addTo);
// Precondition: The word1 is pointing to the first char of a C-string. addTo is the number
//               to be added to the ascii code.
// Postcondition: Word1 will be encoded where the letters will be changed. Example would be the
//                word 'act' and 2 will result in "cev" where 2 was added to the ascii letters 'a'
//                'c' and 't'.

bool findEntry(string* myArray, int& ndx, string wordToFind);
// Precondition: myArray point to a array of strings, ndx is inital value,
//               newEntry is a string
// Postcondition: Function returns true or false if wordToFind is in the string array myArray.
//                ndx will be the index of the wordToFind in the string array myArray.

string* addEntry(string* dynamicArray, int& size, string newEntry);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: A new dynamic array is created, which is one larger than
//                dynamicArray All elements from dynamicArray are copied to
//                new array, the new entry is added to new array, the size
//                is increased, the dynamicArray is deleted, new dynamic
//                array is returned.

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: The function should search dynamicArray for entryToDelete.
//                If not found, the request should be ignored and the
//                unmodified dynamicArray returned. If found, create a new
//                dynamic array one element smaller than dynamicArray. Copy
//                all element except entryToDelete into the new array, delete
//                dynamicArray, decrement size, and return the new dynamic
//                array

void print(const string* dynamicArray, int size);
// Precondition: dynamicArray point to a array of strings with give size,
// Postcondition: The elements in dynamic array will be print out. One
//                element per line forllowed by its index

int main()
{
    //add entry test
    int size = 3;
    string* strArrOld = new string[size]{ "a", "b", "c" };
    print(strArrOld, size);
    string* strArray = addEntry(strArrOld, size, "test");
    print(strArray, size);
    //end test

    //reverse
    {
        const int sizeCharArr1 = 3;
        char origChars1[]{ 'a', 'b', 'c' };
        char* charArr1 = new char[sizeCharArr1] {'a', 'b', 'c'};
        reverse(charArr1, charArr1 + 2);
        bool revTest1 = true;
        for (int i = 0; i < sizeCharArr1; ++i) {
            if (charArr1[i] != origChars1[(sizeCharArr1 - 1) - i]) {        // origChars1 goes in reverse order, from last index to start 

                revTest1 = false;
                break;
            }
        }

        if (revTest1)
            cout << "Reserve test passed" << endl;
        else
            cerr << "Reverse test fail!" << endl;



        const int sizeCharArr2 = 6;
        char origChars2[]{ 'Q', 'W', 'E', 'R' , 'T', 'Y' };
        char* charArr2 = new char[sizeCharArr2] { 'Q', 'W', 'E', 'R', 'T', 'Y' };


        reverse(charArr2, charArr2 + (sizeCharArr2 - 1));
        bool revTest2 = true;
        for (int i = 0; i < sizeCharArr2; ++i) {
            if (charArr2[i] != origChars2[(sizeCharArr2 - 1) - i]) {    // origChars2 goes in reverse order, from last index to start 
                revTest2 = false;
                break;
            }
        }


        if (revTest2)
            cout << "Reserve test passed" << endl;
        else
            cerr << "Reverse test fail!" << endl;
    }
    //end test

    //delete
    {
        int sizeStra = 4;
        string origStrArr[] = { "aa", "bb", "cc", "dd" };
        string* strArr2 = new string[sizeStra]{ "aa", "bb", "cc", "dd" };
        strArr2 = deleteEntry(strArr2, sizeStra, "f");

        bool delTest1 = true;
        for (int i = 0; i < sizeStra; ++i) {
            // Check to make sure no items were deleted
            if (strArr2[i] != origStrArr[i]) {
                delTest1 = false;
                break;
            }
        }
        if (delTest1)
            cout << "Delete test passed" << endl;
        else
            cerr << "Delete test fail!" << endl;

        int sizeStrb = 4;
        strArr2 = deleteEntry(strArr2, sizeStrb, "bb");
        // ""cc" should be at index 1 after the delete
        if (strArr2[1] == origStrArr[2])
            cout << "Delete test passed" << endl;
        else
            cerr << "Delete test fail!" << endl;
    }
    //end test

    //encode
    {
        char encodeTestStr[]{ "act" };
        cout << "Before encode: " << encodeTestStr << endl;
        encode(encodeTestStr, 2);
        cout << "After encode: " << encodeTestStr << endl;
        char* a{};
        encode(a, 3);       //should say need a word to encode
    }
    //end test

    //encode and decode on last ACSII char
    {
        char word1[]{ "|}~" };
        cout << "Before encode: " << word1 << endl;
        encode(word1, 3);
        cout << "After encode: " << word1 << endl;
    }
    //end test

    //encode then decode
    {
        char word1[]{ "apple" };
        char word2[]{ "FLOAT" };
        cout << "Before encode: " << word1 << " and " << word2 << endl;
        encode(word1, word2);
        cout << "After encode: " << word1 << " and " << word2 << endl;

        char word1b[]{ "FACE" };
        char word2b[]{ "test" };
        cout << "Before encode: " << word1b << " and " << word2b << endl;
        encode(word1b, word2b);
        cout << "After encode: " << word1b << " and " << word2b << endl;

        //decode
        cout << "Before decode: " << word1 << " and " << word2 << endl;
        decode(word1, word2);
        cout << "After decode: " << word1 << " and " << word2 << endl;

        cout << "Before decode: " << word1b << " and " << word2b << endl;
        decode(word1b, word2b);
        cout << "After decode: " << word1b << " and " << word2b << endl;
    }
    //end test

    //find word
    {
        int ndx1 = 5;
        string* strArrayFindWord1{ new string[ndx1]{"first", "2nd", "third" ,"4th", "fifth"} };
        cout << "Word= " << strArrayFindWord1[0] << "Index word found? " << static_cast<bool>(findEntry(strArrayFindWord1, ndx1, strArrayFindWord1[0])) << " at index= " << ndx1 << endl;
        delete[] strArrayFindWord1;

        int ndx2 = 4;
        string* strArrayFindWord2{ new string[ndx2]{"first", "2nd", "third" ,"4th"} };
        cout << "Word= " << strArrayFindWord2[3] << "Index word found? " << static_cast<bool>(findEntry(strArrayFindWord2, ndx2, "4th")) << " at index= " << ndx2 << endl;
        delete[] strArrayFindWord2;

        int ndx3 = 5;
        string* strArrayFindWord3{ new string[ndx3]{"first", "2nd", "third" ,"4th", "fifth"} };
        cout << "Word= " << "thir" << "Index word found? " << static_cast<bool>(findEntry(strArrayFindWord3, ndx3, "thir")) << " at index= " << ndx3 << endl;
        delete[] strArrayFindWord3;
    }
    //end test

    //print
    {
        string strArrPrint1[]{ "onE", "twO", "threE", "fouR", "fivE", "siX" };
        print(strArrPrint1, 6);
        string strArrPrint2[]{ "a", "b", "c", "d", "e" };
        print(strArrPrint2, 5);

    }//end test
    return 0;
}

// Precondition: The front and rear are pointing to the front
//               and rear of a C-string, respectively
// Postcondition: The C-string is reversed
void reverse(char* front, char* rear)
{
    //Save the pointers
    char* oldFront { front };
    char* oldRear{ rear };

    //Swap char until reaching the middle
    //String must have more than 1 chars
    while (front < rear) {
        char temp = *front; //save the front char
        *front = *rear;     //assign the rear char into the front
        *rear = temp;       //assign the front char to the rear

        ++front;            //move the pointers to the next char
        --rear;             
    }

    // assign the front and rear pointers to the reversed C-string
    front = oldFront;
    rear = oldRear;
}

// Precondition: The word1 and word2 are pointing to the first char of 2 C-strings.
//               The C-strings are of equal length.
// Postcondition: Each character at a even-numbered index will be swapped between the two C-strings 
void encode(char* word1, char* word2) {
    auto lengthWord1{ strlen(word1) };          // length of word1 must be == to length of word2

    //swap even index chars of the two strings
    for (int i = 0; i < lengthWord1; i += 2) {
        char temp = word1[i];
        word1[i] = word2[i];
        word2[i] = temp;
    }
}

// Precondition: The word1 and word2 are pointing to the first char of 2 C-strings.
//               The C-strings are of equal length.
// Postcondition: Will reverse the encode changes
void decode(char* word1, char* word2) {
    auto lengthWord1{ strlen(word1) };          // length of word1 must be == to length of word2
    //swap even index chars of the two strings
    for (int i = 0; i < lengthWord1; i += 2) {
        char temp = word1[i];
        word1[i] = word2[i];
        word2[i] = temp;
    }
}

// Precondition: The word1 is pointing to the first char of a C-string. addTo is the number
//               to be added to the ascii code.
// Postcondition: Word1 will be encoded where the letters will be changed. Example would be the
//                word 'act' and 2 will result in "cev" where 2 was added to the ascii letters 'a'
//                'c' and 't'.
void encode(char* word1, int addTo) {
    // Check for a string
    if (word1) {
        int length = static_cast<int>(strlen(word1));
        for (int i = 0; i < length; ++i) {
            word1[i] += addTo;        // change char at index by addTo
        }
    }
    else
        cout << "Try again: Must include a word" << endl;
}

// Precondition: myArray points to a array of strings, ndx is size of the array,
//               newEntry is a string
// Postcondition: Function returns true or false if wordToFind is in the string array myArray.
//                ndx will be the index of the wordToFind in the string array myArray. If not 
//                found, ndx will be -1
bool findEntry(string* myArray, int& ndx, string wordToFind)
{  
    // search myArray until find wordToFind is located or reach end of array
    for (int i = 0; i < ndx; ++i) {  // search array of strings for substring wordToFind
        if (myArray[i] == wordToFind) {
            ndx = i;                                        // index of wordToFind in array updated
            return true;
        }
    }

    // end of array reached and word not found
    ndx = -1;                                               // set ndx to -1 because index not found in array
    return false;                                           
}

// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: A new dynamic array is created, which is one larger than
//                dynamicArray All elements from dynamicArray are copied to
//                new array, the new entry is added to new array, the size
//                is increased, the dynamicArray is deleted, new dynamic
//                array is returned.
string* addEntry(string* dynamicArray, int& size, string newEntry)
{
        int newSize = size + 1;
        string* newDynamicArray{ new string[newSize] };

        // copy each string from old array to new
        for (int i = 0; i < size; ++i)
            newDynamicArray[i] = dynamicArray[i];

        newDynamicArray[newSize - 1] = newEntry;   // add the string to the end of the string

        ++size;                             // update the size
        delete[] dynamicArray;              // delete old array
        dynamicArray = nullptr;             // deleted pointer to nullptr so pointer isn't dangling

        return newDynamicArray;

}

// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: The function should search dynamicArray for entryToDelete.
//                If not found, the request should be ignored and the
//                unmodified dynamicArray returned. If found, create a new
//                dynamic array one element smaller than dynamicArray. Copy
//                all element except entryToDelete into the new array, delete
//                dynamicArray, decrement size, and return the new dynamic
//                array
string* deleteEntry(string* dynamicArray, int& size, string entryToDelete)
{
    int originalArrayIndex = 0;
    
    
    // search for entry to delete until reaching the end of the array 
    while (originalArrayIndex < size) {
        string strFromArray = dynamicArray[originalArrayIndex]; 

        // check if string is the one to be delete
        if (strFromArray == entryToDelete) {
            // entry found 
            int indexToDelete = originalArrayIndex;  // originalArrayIndex is the index of the element to delete
            string* reducedDynamicArray{ new string[size - 1] };
            
            // copy all elements upto the element to delete
            for (int i = 0; i < indexToDelete; ++i)
                reducedDynamicArray[i] = dynamicArray[i];

            //copy the elements after indexToDelete not including the index to be deleted
            for (int i = indexToDelete; i < size-1; ++i)
                reducedDynamicArray[i] = dynamicArray[i+1];
            
            --size;                     // update the size of the array
            delete[] dynamicArray;              // delete old array
            dynamicArray = nullptr;             // deleted pointer to nullptr so pointer isn't dangling

            return reducedDynamicArray;           
        }
        else {
            ++originalArrayIndex;    //keep searching
        }
    }

    return dynamicArray;            // entryToDelete not found, so return orginal string
}

// Precondition: dynamicArray point to a array of strings with given size,
// Postcondition: The elements in dynamic array will be print out. One
//                element per line followed by its index
void print(const string* dynamicArray, int size)
{
    for (int i = 0; i < size; i++)
        cout << *(dynamicArray + i) << " " << i << endl;
}// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.

