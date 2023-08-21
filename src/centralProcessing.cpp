
#include "centralProcessing.h"
#include "userCommand.h"
#include <thread>
#include <future>
#include <mutex>
#include "door.h"
#include <functional>
#include "deviceController.h"

CentralProcessing::CentralProcessing(){

    std::cout << "Welcome to first step of HAS as Central Processing \n\n";

}

CentralProcessing *CentralProcessing::systemInitilizer()
{
    commandStruct command_struct;
    UserCommand* start_user_command = new UserCommand(0, command_struct);  /// creat object of user coomand
    DeviceController* device_contrller = new DeviceController(command_struct);  // creat object of device controller

   std::future<DetectedCommand> async_user_command= std::async(std::launch::async, &UserCommand::provide_user_command, start_user_command);

   // DetectedCommand receive_detected_command= async_user_command.get();  ///Be sure .get() func doesnt get any things since be sure data is valid

    std::future<void> async_door_handler = std::async(std::launch::async, &DeviceController::apply_user_command, device_contrller ) ;
   // std::future<bool> async_door_handler = std::async(std::launch::async, &Door::, deviceDoor, textMessage);

    return this;
}

CentralProcessing::~CentralProcessing()
{
        std::cout<<"Central Processing Object Destroied\n";

}