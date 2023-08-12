#ifndef DOOR_H
#define DOOR_H

#include<iostream>
#include "device.h"

class door : public Device
{

public:
/// @brief 
/// @param door_state Door is open or close
/// @param door_type Entrance Door, Parking Door or Outside Door(Yard)
/// @param door_lock lock or Unlock
/// @param power_state Electricite connected or not
/// @param device_name 
/// @param device_message keep device message
door(int door_state, int door_type, bool door_lock, int power_state, std::string device_name, std::string device_message);
~door();

private:
int  door_state;
int  door_type;
bool door_lock;



bool control_device_power(int new_power_state) override;
bool update_device_message(std::string new_message) override;



};





#endif  // DOOR_H