/// \brief header file for device.h

#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string_view>
#include <memory>


#define MAX_NUMBER_CONNECTED_DEVICE     10


class Device
{

public:
    /// @brief Constructor
    /// @param power_state 
    /// @param device_name 
    /// @param device_message 
    Device(int power_state, std::string device_name, std::string device_message);

    ///\brief Setter and Getter
    void set_device_name(std::string device_name);
    std::string get_device_name(void);


    virtual int update_device_message(std::string new_message)=0;
    virtual bool control_device_power(int new_power_state, int door_type) =0;
                
    /// @brief desructor
    ~Device();
    protected:
    /// @brief Private functions


    int power_state;
    std::string device_message;


    private:
    /// @brief Private variables

    std::string device_name;

    

};


#endif // DEVICE_H