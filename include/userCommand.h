#ifndef USER_COMMAND_H 
#define USER_COMMAND_H
        
#include <iostream>
#include "door.h"
#include <vector>


struct commandStruct ; // forward decleration

 struct DetectedCommand
{
    /* data */
    int targetDevice ;      /// who is the device
    int commandType;   ///  what is the command type according to the device like open the parking door
    int userId;        ///  who is the user
    int platfrom;
    int CRC;
};

struct DeviceAck
{

    std::string_view deviceName;  
    std::string_view message;
    bool mission ;  /// Complete or failed

};

enum DeviceName{

    DOOR,
    AIR_CONDITIONER,
    LIGHT,
    PRINTER,
    WATERING

};
enum DoorType{

    PARKING_DOOR,
    ENTERANCE_DOOR,
    OUTSIDE_DOOR

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

class UserCommand
{

public:
    UserCommand(double commandCounter, commandStruct& command_struture );
    ~UserCommand();

DetectedCommand provide_user_command () ;
    

private:
    /* data */
double commandCounter ;

std::string_view* command_packet;

commandStruct& command_struture ;

std::vector<char> receive_user_data();

void detect_user_command(std::vector<char>* raw_data, DetectedCommand* detected_command);

};





#endif // USER_COMMAND_H