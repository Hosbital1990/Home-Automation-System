
#include "centralProcessing.h"
#include "userCommand.h"
#include <thread>
#include <future>
#include <mutex>
#include "door.h"
#include <functional>

CentralProcessing::CentralProcessing(){

    std::cout << "Welcome to first step of HAS as Central Processing \n\n";

}



CentralProcessing *CentralProcessing::systemInitilizer()
{

    UserCommand* start_user_command = new UserCommand(0);
    
    /** @brief Polymorphism creat the object of all included devices
     *  @param with default constructor 
    */
    Device* deviceDoor= new Door();
    //Door* doorObject = new Door();
    std::string textMessage= "first_message" ;
    std::future<DetectedCommand> async_user_command= std::async(std::launch::async, &UserCommand::provide_user_command, start_user_command);

    DetectedCommand receive_detected_command= async_user_command.get();  ///Be sure .get() func doesnt get any things since be sure data is valid



    std::future<int> async_door_handler = std::async(std::launch::async, &Device::update_device_message, deviceDoor, textMessage ) ;
   // std::future<bool> async_door_handler = std::async(std::launch::async, &Door::, deviceDoor, textMessage);

   // async_door_handler.get();
    ///\brief Determine the corresponding device and run its thread

    [&](){
                std::cout << receive_detected_command.targetDevice << std::endl;
                std::cout << receive_detected_command.commandType << std::endl;
                std::cout << receive_detected_command.userId << std::endl;
                std::cout << receive_detected_command.platfrom << std::endl;
                std::cout << receive_detected_command.CRC << std::endl;
    }();

    // delete start_user_command;
    // delete deviceDoor; 

    return this;
}

CentralProcessing::~CentralProcessing()
{
        std::cout<<"Central Processing Object Destroied\n";

}