
#include "door.h"

Door::Door(int door_type, bool door_lock_state, bool device_power_state, u_int8_t device_working_level,
 int device_address, std::string_view device_name, std::string device_message)

 : door_type(door_type),
  door_lock_state(door_lock_state),
  DeviceControl(device_power_state,device_working_level,device_address,device_name,device_message)  // to initial base class constructor
{

    std::cout << "Polymorphism obeject of " << device_name << " calss sucessfully created" << std::endl ;
}

bool Door::device_power_control(bool device_power_state) const
{

    return false;
}

bool Door::device_working_level_adjustment (u_int8_t device_working_level)  {

    return false ;
}
std::string Door::update_device_message (std::string* device_message) {

    return std::string();
}
bool Door::device_reset (void) {

    return false;
}

bool Door::update_door_color(int door_type, std::string color){

    return false;
}
bool Door::update_device_message(std::string_view message){

    return false;
}