/// \brief header file for device.h

#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string_view>
#include <memory>

// Contents of the header file go here

class Device {

public:

/**
 * \brief Constractor of Device class
 * 
 * \details
 *          "please consider use of move constructor for this and also any pther classes"
*/

/// @brief Defualt constructor
Device(): device_power_state(false), device_message(std::make_unique<std::string>("")) {}; //

/// @brief entire constructor
/// @param device_power_state 
/// @param device_working_level 
/// @param device_address 
/// @param device_name 
/// @param device_message 
Device(bool device_power_state, u_int8_t device_working_level, 
int device_address, std::string_view device_name, std::shared_ptr<std::string> device_message)

: device_power_state(device_power_state),
  device_working_level(device_working_level),
  device_address(device_address), 
  device_name(device_name),
  device_message(std::move(device_message)) {}   // more consider move 



/**
 * 
 * \brief setter and getter functin
 * 
*/
void set_device_power_state(bool device_power_state); /// Setter for device_power_state argument
bool get_device_switch_on(void);     ///getter for device_power_state

void set_device_working_level(u_int8_t device_working_level); /// Setter for device_working_level argument
u_int8_t get_device_working_level(void);     ///getter for device_working_level

void set_device_address(int device_address); 
int get_device_address(void);     

void set_device_name (std::string_view device_name);
std::string_view get_device_name (void);

void set_device_message (std::string* device_message);
std::string* get_device_message (void);

/**
 * 
 * \brief device Class Deconstructor
 * 
*/
~Device(){}

protected:

private:

/**
 * \brief 
 *      Define Private arguments
 * 
*/
    bool device_power_state ; /// Device power flag state

    u_int8_t device_working_level; /// control the level of the device activity, like light brightness 

    int device_address ;        /// to identify in network

    std::string_view device_name ;  /// device given name to recognition

    std::shared_ptr<std::string> device_message;   /// smart pointer feature-> show the message on behalf of device like warning and error
                                                        ///< std::make_unique<std::string_view>("some message")
                                                        //std::unique_ptr<int> ptr = std::make_unique<int>(42);


/***
 * \brief
 *        Define private functions 
 * 
*/

bool device_power_control (bool device_power_state);

bool device_working_level_adjustment (u_int8_t device_working_level) ;

std::string update_device_message (std::string* device_message);

bool device_reset (void) ;
     


};



#endif // DEVICE_H