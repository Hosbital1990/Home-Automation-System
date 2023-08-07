/*!
 * \mainpage Home Automation System
 *
 * \author Hossein Bitalebi
 * \version 03.08.2023_V01
 * \date 03 Aug 2023
 * \copyright GNU public license
 *
 * This is the main page for the Home Automation System project.
 * Here, you can provide a general overview of the project and its components.
 *
 * For more details, refer to the source code and documentation for individual classes and functions.
 * 
 *  \link 
 *          https://github.com/Hosbital1990/Home-Automation-System.git
 */

#include <iostream>
#include "device_control.h"
#include "camera.h"


/**
 * \brief HAS Project
 * 
 * \author Hosbital
 * 
 * Hosseinbitalebi@gmail.com 
 * 
*/
int main (){


/**
 * @brief Welcome HAS project powered by Hosbital CO. 
 * 
 */    

std::cout << "Welcome to Home Automation System Project" <<std::endl ;

Device_Control* device {new Device_Control(false, 0, 10, "MusicPlayer", []()->std::string*{

      static std::string message = "No Message";
    return &message;
}()) } ;



return 0;

}