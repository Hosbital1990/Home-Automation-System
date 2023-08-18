#include "userCommand.h"
#include  <vector>



UserCommand::UserCommand(double commandCounter)
: commandCounter(commandCounter)
{
std::cout<< "Congras! UserCommand object has been created!\n\n" ;

}


DetectedCommand UserCommand::provide_user_command(void){
///\brief Initial some required variable

std::vector<char> received_raw_packet;

DetectedCommand detected_command ;


received_raw_packet= UserCommand::receive_user_data();

UserCommand::detect_user_command(&received_raw_packet, &detected_command );

    return detected_command;
}

std::vector<char> UserCommand::receive_user_data(void){

//std::string_view* received_raw_packet;
std::vector<char> received_raw_packet;


/** @brief  generate fake raw command packet only 5 byte packet with a vector will be enough for test version
 * @param
 * targetDevice
 * commandType
 * userId
 * platfrom
 * CRC
 * 
*/
received_raw_packet.push_back('1');
received_raw_packet.push_back('2');
received_raw_packet.push_back('3');
received_raw_packet.push_back('4');
received_raw_packet.push_back('5');

return received_raw_packet;

}

void UserCommand::detect_user_command(std::vector<char>* raw_data, DetectedCommand* detected_command)
{
    detected_command->targetDevice = raw_data->at(0);
    detected_command->commandType = raw_data->at(1);
    detected_command->userId = raw_data->at(2);
    detected_command->platfrom = raw_data->at(3);
    detected_command->CRC = raw_data->at(4);
}



    /// @brief UserCommand class destructor
    UserCommand::~UserCommand(){

        delete this->command_packet ;
                std::cout<<"User Command Object Destroied\n";

    }