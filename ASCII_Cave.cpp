#include <fstream>
#include <iostream>

int main()
{
    // opening the rooms file
    std::ifstream inputRooms;
    inputRooms.open("rooms.txt");
    if (inputRooms.fail())
    {
        std::cout << "Problems with opening rooms file.";
        return 1;
    }



    std::cout << "Welcome to the ASCII CAVE!\n";
}
