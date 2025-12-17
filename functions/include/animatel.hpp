#pragma once
#include <atomic>
extern std::atomic<bool> animating;
void animatel(char letter, int time_milisecond);
