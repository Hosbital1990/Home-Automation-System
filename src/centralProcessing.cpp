
#include "centralProcessing.h"
#include <userCommand.h>

/// @brief Required header file for asynchronouse programming
#include <thread>
#include <future>
#include <mutex>

CentralProcessing::CentralProcessing(){

    std::cout << "Welcome to first step of HAS as Central Processing \n\n";

}



CentralProcessing *CentralProcessing::systemInitilizer()
{

    UserCommand* start_user_command = new UserCommand(0);
    

    std::future<DetectedCommand> async_user_command= std::async(std::launch::async, &UserCommand::provide_user_command, start_user_command);

    DetectedCommand receive_detected_command= async_user_command.get();  ///Be sure .get() func doesnt get any things since be sure data is valid

    [&](){

                std::cout << receive_detected_command.targetDevice << std::endl;
                std::cout << receive_detected_command.commandType << std::endl;
                std::cout << receive_detected_command.userId << std::endl;
                std::cout << receive_detected_command.platfrom << std::endl;
                std::cout << receive_detected_command.CRC << std::endl;


    }();

    return this;
}

CentralProcessing::~CentralProcessing()
{
}