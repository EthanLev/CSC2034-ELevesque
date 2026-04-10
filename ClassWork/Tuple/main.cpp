#include <iostream>
#include <string>

int main(int, char**){
    auto meetInfo = getMeetingInfo();
    
    std::cout << "The meeting is in " << std::get<0>(meetInfo) << " room " << std::get<1>(meetInfo) << " at " << std::get<2>(meetInfo) << std::endl;

    auto [building, room, time] = getMeetingInfo();

    std::cout << "The meeting is in " << building << " room " << room << " at " << time << std::endl;
}

std::tuple<std::string building, std::string room, std::string time> getMeetingInfo() {
    return {"Blanca Peak", "BP112", "12:00 pm"};
}


