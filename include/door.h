#ifndef DOOR_H
#define DOOR_H

#include<iostream>
#include "device.h"

enum DoorType{

    PARKING_DOOR,
    ENTERANCE_DOOR,
    OUTSIDE_DOOR

};

enum DooRCommandType{

    DOOR_POWER_CONNECT,
    DOOR_POWER_DISCONNECT,
    DOOR_OPEN,
    DOOR_CLOSE
};

class Door : public Device
{

//Door() =default;

public:
/// @brief 
/// @param door_state Door is open or close
/// @param door_type Entrance Door, Parking Door or Outside Door(Yard)
/// @param door_lock lock or Unlock
/// @param power_state Electricite connected or not
/// @param device_name 
/// @param device_message keep device message
Door(int door_type= PARKING_DOOR , int door_state=0, bool door_lock=true, int power_state=false,
     std::string device_name="DooR", std::string device_message="No Message");

int  update_device_message(std::string new_message) override;
bool control_device_power(int new_power_state, int door_type) override;

~Door();

protected:


private:

int  door_type;
int  door_state;
bool door_lock;

bool toggle_gpio_pin (int pinNumber, int portNumber);

bool readMessage (void);





};





#endif  // DOOR_H