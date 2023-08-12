#ifndef DOOR_H
#define DOOR_H

#include "device_control.h"

/**
 * \brief Door will control by GPIO interface
 * 
 * \def Parking door, Enterance door, Outside door
 * 
 */

class Door :public DeviceControl
{

public:
Door(/* args */)= default;

Door (int door_type, bool door_lock_state, bool device_power_state, u_int8_t device_working_level, 
int device_address, std::string_view device_name, std::string device_message);

/// getter and setter function for private member
void set_door_type (int door_type);
int get_door_type (void);

void set_door_lock_state (bool door_lock_state);
bool get_door_lock_state (void);

~Door();

protected:

bool device_power_control (bool device_power_state) const override;
bool device_working_level_adjustment (u_int8_t device_working_level)  override ;
std::string update_device_message (std::string* device_message)  override;
bool device_reset (void) override;

private:
    /* data */

int door_type ;  // parking, enterance, lobby door
bool door_lock_state;  // lock, unlock


bool update_door_color(int door_type, std::string color);
bool update_device_message(std::string_view message);


};


#endif