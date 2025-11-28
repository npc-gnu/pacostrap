#pragma once
#include <thread>
#include <chrono>
#include <iostream>
#include <atomic>
#include <vector>
void animatel(std::atomic<bool>& running, int delay_ms = 100);
