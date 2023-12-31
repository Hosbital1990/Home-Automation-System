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
#include "camera.h"
#include "userCommand.h"
#include <centralProcessing.h>
#include <thread>
#include<chrono>

int main (){


/**
 * @brief Welcome HAS project powered by Hosbital CO. 
 * 
 */    

std::cout << "Welcome to Home Automation System Project" <<std::endl;


CentralProcessing central_processing ; 

std::thread secondMainThread (&CentralProcessing::systemInitilizer, &central_processing);
//central_processing.systemInitilizer();

secondMainThread.join();

// while (true)
// {
//     /* code */
//     std::this_thread::sleep_for(std::chrono::milliseconds(100000));
// }

  //  std::this_thread::sleep_for(std::chrono::milliseconds(10000));


return 0;

}