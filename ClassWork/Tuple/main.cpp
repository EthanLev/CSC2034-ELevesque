#include <iostream>
#include <string>
#include <tuple>

std::tuple<std::string, std::string, std::string> getMeetingInfo()

int main(int, char**){
    auto meetInfo = getMeetingInfo();
    
    std::cout << "The meeting is in " 
              << std::get<0>(meetInfo) << " room " << std::get<1>(meetInfo) << " at " << std::get<2>(meetInfo) << std::endl;

    auto [building, room, time] = getMeetingInfo();

    std::cout << "The meeting is in " << building << " room " << room << " at " << time << std::endl;
}

std::tuple<std::string, std::string, std::string> getMeetingInfo() {
    return {"Blanca Peak", "BP112", "12:00 pm"};
}


