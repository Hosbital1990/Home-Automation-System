#ifndef DEVICE_CONTROLLER_H
#define DEVICE_CONTROLLER_H

#include "device.h"

struct DetectedCommand;  //Forward declaration -> from userCommand.h
struct commandStruct ; // forward decleration  -> from centralProcessing.h
//enum DooRCommandType; // // forward decleration  -> from door.h

struct DeviceAck
{

    std::string_view deviceName;  
    std::string_view message;
    bool mission ;  /// Complete or failed

};

enum TargetDevice{

    DOOR,
    AIR_CONDITIONER,
    LIGHT,
    PRINTER,
    WATERING

};

enum DoorLockState{

    CLOSE,
    OPEN,

};

enum PowerState{

    POWER_OFF,
    POWER_ON

};
enum WorkingLevel{

    NO_LEVEL_DEFINED=0,

    EXTRA_LOW_LEVEL,
    LOW_LEVEL,
    UPPER_LOW_LEVEL,
    MEDIUM_LEVEL,
    LOWER_HIGH_LEVEL,
    HIGH_LEVEL,
    EXTRA_HIGH_LEVEL

};

class DeviceController{

public:
DeviceController(commandStruct& command_struct);

void apply_user_command ();

~DeviceController();

protected:
commandStruct& command_struct;


};

#endif //DEVICE_CONTROLLER_H