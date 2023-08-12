#include <iostream>
#include "device.h"

Device::Device(int power_state, std::string device_name, std::string device_message)
:
power_state(power_state),
device_name(device_name),
device_message(device_message)
{

    std::cout << " Object of Device " << device_name << " has been created \n\n" ;
}

void Device::set_device_name(std::string device_name){

this->device_name = device_name;
}

std::string Device::get_device_name(void)
{
return this->device_name;
}

/**
 * Implement Private functions
*/



Device::~Device(){};


