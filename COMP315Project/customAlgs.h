#pragma once
#include <math.h>
#include <vector>
#include <time.h> 
#include <cstdlib> 
//@author jaedonnaidu

//Template class to handle some algorithms we use frequently
//Note: methods are static, so no need to instantiate an object (what would be the point of that?)
//Example of sytax to use methods:
//  vector<int> v;
//  customAlgs<int>::insert(v, -1);





template <class E>
ref class customAlgs {

public:
    /*method that searches for an element inside an array
    OUTPUT: if element found, the index of the element is returned.
            if the element is not found, -1 is returned.
    TO CHECK IF ELEMENT IS FOUND: if(binarySearch(v, e))!= -1
    But in the case where we need to get the element's index, that is returned.
    //TIME COMPLEXITY: O(log(n)). This is known to be optimal for a generic sorted array.

    //NOTE: REFER TO OVERLOADED OPERATORS IN playerInfo. Because this method uses > < and ==,
    //This method compares players based on their SCORE.
    */
    static int binarySearchScore(List<E>^ v, E e) {
        int start = 0;
        int end = v->Count - 1;
        int midd=-1;
        while ((end > start && (midd!= 0)) && (midd!= v->Count-1)) {
            midd = (start + end) / 2;           //assumption 1:  the generic type has the following operators overloaded:
            if (e < v[midd]) {               //              >       <       ==
                end = midd - 1;
            }
            else if (e > v[midd]) {          //assumption 2: the vector is sorted. Hence always maintain the vector to be sorted
                start = midd + 1;
            }
            else if (e == v[midd]) {
                return midd;
            }
            else {
                return -1;
            }
        }
        if ((start >= 0 && start < v->Count) && v[start] % e) {
            return start;
        }

        if ((end >= 0 && end < v->Count) && v[end] % e) {
            return end;
        }
        else {
            return -1;
        }
    }

    /*method that searches for an element inside an array
    OUTPUT: if element found, the index of the element is returned.
            if the element is not found, -1 is returned.
    TO CHECK IF ELEMENT IS FOUND: if(binarySearch(v, e))!= -1
    But in the case where we need to get the element's index, that is returned.
    //TIME COMPLEXITY: O(log(n)). This is known to be optimal for a generic sorted array.

    //NOTE: REFER TO OVERLOADED OPERATORS IN playerInfo. Because this method uses >= <= and %,
    //This method compares players based on USERNAME.
    */
    static int binarySearchUsername(List<E>^ v, E e) {
        int start = 0;
        int end = v->Count - 1;
        int midd=-1;
        while ((end > start && (midd!= 0)) && (midd != v->Count - 1)) {
            midd = (start + end) / 2;           //assumption 1:  the generic type has the following operators overloaded:
            if (e <= v[midd]) {                  //              >       <       ==
                end = midd - 1;
            }
            else if (e >= v[midd]) {          //assumption 2: the vector is sorted. Hence always maintain the vector to be sorted
                start = midd + 1;
            }
            else if (e % v[midd]) {
                return midd;
            }
            else {
                return -1;
            }
        }
        if ((start>=0 && start <v->Count) && v[start] % e) {
            return start;
        }
        if ((end >= 0 && end < v->Count) && v[end] % e) {
            return end;
        }
        else {
            return -1;
        }
    }

    /*method that inserts an element into a sorted vector, such that the vector remains sorted
    OUTPUT: none. Method is void, so it modifies the original vector without returning anything
    //TIME COMPLEXITY: O(n). This cannot be improved even by binary search due to the shifting that would need to occur.
    //Usage: inserting a score / user into a textfile, to keep the textfile sorted

    //NOTE: REFER TO OVERLOADED OPERATORS IN playerInfo. Because this method uses <
    //This method compares players based on their SCORE.
    */
    static List<E>^ insertScore(List<E>^ v, E e) {
        int i = 0;
        while (i < v->Count && v[i] < e) {
            i++;
        }
        if (i < v->Count) {
            v->Insert(i, e);
        }
        else {
            v->Add(e);
        }
        return v;

    }

    /*method that inserts an element into a sorted vector, such that the vector remains sorted
    OUTPUT: none. Method is void, so it modifies the original vector without returning anything
    //TIME COMPLEXITY: O(n). This cannot be improved even by binary search due to the shifting that would need to occur.
    //Usage: inserting a score / user into a textfile, to keep the textfile sorted

    //NOTE: REFER TO OVERLOADED OPERATORS IN playerInfo. Because this method uses <=
    //This method compares players based on their USERNAME.
    */
    static void insertName(List<E>^& v, E e) {
        int i = 0;
        while (i < v->Count && v[i] <= e) {
            i++;
        }
        if (i < v->Count) {
            v->Insert(i, e);
        }
        else {
            v->Add(e);
        }

    }



    /*method that returns M random elements from another vector
    OUTPUT: the method returns a vector of the M elements
    //TIME COMPLEXITY: O(M). This time complexity is clearly optimal.
    //Usage: choosing 8 of 16 A B C D, and 2 of 4 T/F
    */
    static List<E>^ chooseRandomMfromN(List<E>^ v, int M) {
                                        //srand() is necessary to ensure that different values are generated each time
        //srand(time(0));                                 //srand() is necessary to ensure that different values are generated each time
        List<E>^ result = gcnew List<E>;
        for (int i = 0; i < M; i++) {
            if (v->Count == 1) {
                E e = v[0];
                v->RemoveAt(0);
                result->Add(e);
            }
            else {
                int random = rand() % (v->Count - 1);
                E e = v[random];
                v->RemoveRange(random, 1);
                result->Add(e);
            }
        }
        return result;
    }

    static void srandom() {
        
        srand(time(0));
    }
    /*method to shuffle a vector
    OUTPUT: the method returns the shuffled vector
    //TIME COMPLEXITY: O(n). This time complexity is also also clearly optimal.
    */
    //Usage: to shuffle the questions, etc
    static  List<E>^ shuffle(List<E>^ v) {
        List<E>^ result = gcnew List<E>;
        result = chooseRandomMfromN(v, v->Count);
        return result; //really this is just the case of chooseRandomMfromN where you want the result vector to have the same size as the original
    }
};
