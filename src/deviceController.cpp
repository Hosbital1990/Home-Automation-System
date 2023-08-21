#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>

#include "deviceController.h"
#include "userCommand.h"
#include "centralProcessing.h"
#include "door.h"

DeviceController::DeviceController(commandStruct& command_struct)
: command_struct(command_struct)
{

    std::cout << "Device controller Object is Created  \n";
}

DeviceController::~DeviceController(){

    std::cout << "Device controller Object is desructed \n";
}

void DeviceController::apply_user_command(){

    Device* deviceDoor = new Door();
    DetectedCommand detected_command;
    // you can extend the other devices object regarding the later odification

    //Also maybe here cant be potencial of Rpi interfaces insitial and setup palce

    while (true){

        std::unique_lock<std::mutex> lock(command_struct.share_mtx);
        command_struct.cv.wait(lock, [this](){return !command_struct.command_queue.empty();});
        detected_command = command_struct.command_queue.front();
        command_struct.command_queue.pop();
        command_struct.share_mtx.unlock();
        command_struct.cv.notify_all();

        switch (detected_command.targetDevice)
        {
        case  TargetDevice::DOOR :

                switch (detected_command.commandType)
                {
                case DooRCommandType::DOOR_POWER_CONNECT :

                    // as a suggestion it is good if you can consider use of exception handler like try

                   if( !deviceDoor->control_device_power(detected_command.commandType,0)){ // 0 means parking door

                        std::cout << "Somethings went wrong!!!!:  to solve ask it operator";
                    } 
                    
                    break;

                case DooRCommandType::DOOR_POWER_DISCONNECT :
                   if( !deviceDoor->control_device_power(detected_command.commandType,0)){ // 0 means parking door

                        std::cout << "Somethings went wrong!!!!:  to solve ask it operator";
                    } 
                      break;
                      
                case DooRCommandType::DOOR_OPEN :
                    /* code */
                    break;

                case DooRCommandType::DOOR_CLOSE :
                    /* code */
                    break;


                default:
                    break;
                }


        break;
            case  TargetDevice::AIR_CONDITIONER :
        /* code */
        break;
            case  TargetDevice::LIGHT :
        /* code */
        break;
            case  TargetDevice::PRINTER :
        /* code */
        break;
            case  TargetDevice::WATERING :
        /* code */
        break;

        default:
            break;
        }

    }


}