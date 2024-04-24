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
class customAlgs {

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
    static int binarySearchScore(std::vector<E> v, E e) {
        int start = 0;
        int end = v.size() - 1;
        int midd;
        while ((end != start)) {
            midd = (start + end) / 2;           //assumption 1:  the generic type has the following operators overloaded:
            if (e < v.at(midd)) {               //              >       <       ==
                end = midd - 1;
            }
            else if (e > v.at(midd)) {          //assumption 2: the vector is sorted. Hence always maintain the vector to be sorted
                start = midd + 1;
            }
            else if (e == v.at(midd)) {
                return midd;
            }
            else {
                return -1;
            }
        }
        if (v.at(start) == e) {
            return start;
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
    static int binarySearchUsername(std::vector<E> v, E e) {
        int start = 0;
        int end = v.size() - 1;
        int midd;
        while ((end != start)) {
            midd = (start + end) / 2;           //assumption 1:  the generic type has the following operators overloaded:
            if (e <= v.at(midd)) {               //              >       <       ==
                end = midd - 1;
            }
            else if (e >= v.at(midd)) {          //assumption 2: the vector is sorted. Hence always maintain the vector to be sorted
                start = midd + 1;
            }
            else if (e % v.at(midd)) {
                return midd;
            }
            else {
                return -1;
            }
        }
        if (v.at(start) % e) {
            return start;
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
    static void insertScore(std::vector<E>& v, E e) {
        int i = 0;
        while (i < v.size() && v.at(i) < e) {
            i++;
        }
        if (i < v.size()) {
            v.insert(v.begin() + i, e);
        }
        else {
            v.push_back(e);
        }

    }

    /*method that inserts an element into a sorted vector, such that the vector remains sorted
    OUTPUT: none. Method is void, so it modifies the original vector without returning anything
    //TIME COMPLEXITY: O(n). This cannot be improved even by binary search due to the shifting that would need to occur.
    //Usage: inserting a score / user into a textfile, to keep the textfile sorted

    //NOTE: REFER TO OVERLOADED OPERATORS IN playerInfo. Because this method uses <=
    //This method compares players based on their USERNAME.
    */
    static void insertName(std::vector<E>& v, E e) {
        int i = 0;
        while (i < v.size() && v.at(i) <= e) {
            i++;
        }
        if (i < v.size()) {
            v.insert(v.begin() + i, e);
        }
        else {
            v.push_back(e);
        }

    }



    /*method that returns M random elements from another vector
    OUTPUT: the method returns a vector of the M elements
    //TIME COMPLEXITY: O(M). This time complexity is clearly optimal.
    //Usage: choosing 8 of 16 A B C D, and 2 of 4 T/F
    */
    static std::vector<E> chooseRandomMfromN(std::vector<E> v, int M) {
        srand(time(0));                                 //srand() is necessary to ensure that different values are generated each time
        std::vector<E> result;
        for (int i = 0; i < M; i++) {
            if (v.size() == 1) {
                E e = v.at(0);
                v.erase(v.begin());
                result.push_back(e);
            }
            else {
                int random = rand() % (v.size() - 1);
                E e = v.at(random);
                v.erase(v.begin() + random);
                result.push_back(e);
            }

        }
        return result;
    }

    /*method to shuffle a vector
    OUTPUT: the method returns the shuffled vector
    //TIME COMPLEXITY: O(n). This time complexity is also also clearly optimal.
    */
    //Usage: to shuffle the questions, etc
    static std::vector<E> shuffle(std::vector<E> v) {
        return chooseRandomMfromN(v, v.size()); //really this is just the case of chooseRandomMfromN where you want the result vector to have the same size as the original
    }
};