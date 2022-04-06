#pragma once

#include <map>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

//exceptii
struct IndexOutOfBounds : public exception {
    const char* what() const throw () {
        return "Exception: Index Out Of Bounds!";
    }
};

