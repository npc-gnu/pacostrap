#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
#include "animatel.hpp"
std::atomic<bool> animating(true);
void animatel(char letter, int time_milisecond){
    while(animating){
        std::cout << letter;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(time_milisecond));
    }}
