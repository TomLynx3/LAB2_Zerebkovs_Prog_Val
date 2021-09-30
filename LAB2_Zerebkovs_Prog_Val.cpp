// LAB2_Zerebkovs_Prog_Val.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string> 


std::vector<int> output;

bool DecomposeNumberToSumOfSquares(int number, int square) {

    if (number == 0) {
        return true;
    }
    else if (number < square * square) {
        return false;
    }

    if (DecomposeNumberToSumOfSquares(number - square * square, square + 1)) {
        output.push_back(square);
        return true;
    }

    if (DecomposeNumberToSumOfSquares(number, square + 1)) {
        return true;
    }

    return false;
}



int main()
{

    int choice = 1;

    while (choice == 1) {
        output = {};
        int a;
        printf("Enter number num= "); scanf("%d", &a);
        std::string result = "";
        if (DecomposeNumberToSumOfSquares(a, 1)) {
            result = std::to_string(a) + "= ";
            for (int i = 0; i < output.size(); i++) {
                if (i == output.size() - 1) {
                    result.append(std::to_string(output.at(i)) + "^2");
                }
                else {
                    result.append(std::to_string(output.at(i)) + "^2 + ");
                }
                /// printf("%d", output.at(i));
            }
        }
        else {
            result = "Can't decompose number";
        }

        std::cout << result << "\n";


        printf("Try one more time? - 1 \nExit from program - 0"); scanf("%d", &choice);
        
    }

    return 0;
}



