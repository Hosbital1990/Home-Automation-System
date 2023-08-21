#include <iostream>
#include "device.h"
#include "door.h"
#include "userCommand.h"
#include <thread>
#include <ctime>
#include <cstdlib>
#include <chrono>

Door::Door(int door_type, int door_state, bool door_lock, int power_state,
            std::string device_name, std::string device_message)
    :   door_type(door_type), 
        door_state(door_state), 
        door_lock(door_lock),
        Device(power_state,device_name,device_message)
{
    std::cout << "Helloe from Door derived class! :))\n";
}

bool Door::control_device_power(int new_power_state, int door_type)
{
    if (this->power_state == new_power_state){
            std::cout << "Nothing Happened, Door power has already been connected!";
        return true; //State doesnt need to change
    }
    else if(this->power_state != new_power_state){

        //Toggle device power state
        power_state= new_power_state;
        
        ///Write directly the new value in corresponding GPIO pin to trige the Power state
        if (door_type == PARKING_DOOR ){
            int pinNumber= 1;
            int portNumber= 10;
            std::cout << " Parking Door power connected!";
            return toggle_gpio_pin (pinNumber, portNumber);
        }

        else if(door_type == ENTERANCE_DOOR){
            int pinNumber = 2;
            int portNumber= 20;
                        std::cout << " Entrance Door power connected!";
            return toggle_gpio_pin (pinNumber, portNumber);
        }

        else if (door_type == OUTSIDE_DOOR){
            int pinNumber= 3;
            int portNumber= 30;
        std::cout << " Outside Door power connected!";
         return toggle_gpio_pin (pinNumber, portNumber);

        }
    }

    return false;
}

int Door::update_device_message(std::string new_message)
{
    std::thread updateMessageThread(&Door::readMessage, this );
    updateMessageThread.detach();
    return 1;
}


bool Door::toggle_gpio_pin (int pinNumber, int portNumber){

    // Do somthing to toggle the power state

    return true;
}

bool Door::readMessage(){

    bool updatingMessage=true;

    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator

    while (updatingMessage)
    {

    int randomValue = std::rand() % 100 + 1; // Generate a random integer between 1 and 100
    Device::device_message= "Nothing for Update! Number: "+std::to_string(randomValue) ;

    // Sleep the thread for 1000 milliseconds (1 second)
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << Device::device_message << std::endl ;

    }
    
    return false;
}


Door::~Door(){

    std::cout<<"Door Object Destroied\n";
}


