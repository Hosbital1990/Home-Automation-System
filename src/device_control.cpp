#include <iostream>
#include "memory"
#include "device_control.h"


/**
 * \brief Implementation of class Device constructor
*/
Device_Control::Device_Control(bool device_power_state, u_int8_t device_working_level, 
int device_address, std::string_view device_name, std::string* device_message)

: device_power_state(device_power_state),
  device_working_level(device_working_level),
  device_address(device_address), 
  device_name(device_name),
  device_message(std::move(device_message)) {

    std::cout << "Device object for device " << device_name << " created" << std::endl;

  }   // more consider move 


/**
 * \brief Implementation of setter and getter
*/

    /**
     * @brief Setter for the device's power state.
     * 
     * @param device_power_state The power state to set.
     */
void Device_Control::set_device_power_state(bool device_power_state){

        this->device_power_state = device_power_state ;
}

   /**
     * @brief Getter for the device's power state.
     * 
     * @return The current power state of the device.
     */
bool Device_Control::get_device_power_state(void){

return this->device_power_state;

}

void Device_Control::set_device_working_level(u_int8_t device_working_level){

    this->device_working_level=device_working_level;
} 

u_int8_t Device_Control::get_device_working_level(void){

    return this->device_working_level;
}     

void Device_Control::set_device_address(int device_address){

    this->device_address = device_address;
}
int Device_Control::get_device_address(void){ 

    return this->device_address=device_address;
}     

void Device_Control::set_device_name (std::string_view device_name){

    this->device_name=device_name;
}

std::string_view Device_Control::get_device_name (void){

    return this->device_name;
}

void Device_Control::set_device_message (std::string* device_message){
    this->device_message= std::make_shared<std::string>(*device_message) ;
}
std::string* Device_Control::get_device_message (void){

    return this->device_message.get(); // read more about .get()
}


/**
 * \brief Implement protected function
*/

/// @brief trigger function to switch On or Off according the user deand
/// @param device_power_state 
/// @return state of the device power
 bool Device_Control::device_power_control(bool device_power_state)
{
      /**
       * \build a class of Interface to call its function to control the connected device in HW level
       * */  
    std::cout << "System is: " << [&device_power_state]()-> std::string{

            if (device_power_state==false)
            {
                /* code */
                return "Off" ;
            }
            else {
            return "On" ;
            }

    }() << std::endl ;

    /**
     * @brief If the trigger action was sucessful it return true else return false
    */
    return false;
}

/// @brief 
/// @param device_working_level 
/// @return current working level of system
bool Device_Control::device_working_level_adjustment(u_int8_t device_working_level)
{

        std::cout << "Working level is: " << device_working_level << std::endl ;

    return false;
}

/// @brief 
/// @param device_message 
/// @return 
std::string Device_Control::update_device_message(std::string *device_message)
{
    
        std::cout << "System message is: " << *device_message << std::endl ;

    return *device_message;
}

/// @brief 
/// @param  
/// @return 
bool Device_Control::device_reset(void)
{
        std::cout << "Reseting ..." << std::endl ;

    return false;
}
