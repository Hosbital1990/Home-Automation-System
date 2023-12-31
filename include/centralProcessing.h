#ifndef CENTRAL_PROCESSING_H
#define CENTRAL_PROCESSING_H

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>

 struct DetectedCommand;  //Forward declaration

struct commandStruct
{

std::mutex share_mtx;
std::condition_variable cv;
std::queue<DetectedCommand> command_queue;

};


class CentralProcessing{

public:
CentralProcessing();
~CentralProcessing();


CentralProcessing* systemInitilizer();



private:

};



#endif  // CENTRAL_PROCESSING_H