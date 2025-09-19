#include "spinner.hpp"
void animatel(std::atomic<bool>& running, int delay_ms) {
    std::vector<char> frames = {'/', '-', '\\', '|'};
    int index = 0;
    while (running) {
        std::cout << "\r" << frames[index] << std::flush;
        index = (index + 1) % frames.size();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }std::cout << "\r "; 
}

