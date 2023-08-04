
#include <iostream>

#include "device.h"
#include "camera.h"

using namespace std ;

int a; 

class Test {

public:
double a_axis {5} ;
double b_axis {10};

double multiply (){

    return a_axis*b_axis ;
}

};

int main (){

std::cout << "Hello! Home Automation System!" << std::endl ;

Test test1 ;

std::cout << "Resylt: !" << test1.multiply() << std::endl ;

test1.a_axis = 7 ;
test1.b_axis = 7 ;

Test test2 ; 
std::cout << "Resylt: !" << test2.multiply() << std::endl ;
std::cout << "Resylt: !" << test1.multiply() << std::endl ;

}