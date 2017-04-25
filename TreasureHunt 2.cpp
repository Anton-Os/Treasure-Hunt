#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <utility>
#include <windows.h>

/* float computeDistance(){
    unsigned time = std::rand() % 55 + 6;
    unsigned mode = std::rand() % 5 + 1;
    char* modeDescript;
    float howLong;
    time = std::rand() % 55 + 6;
    std::cout << "Travel " << time << " minutes";
    mode = std::rand() % 5 + 1;
    if(mode == 1){
        modeDescript = " walking ";
        howLong = (time * 3) / 60.0f;
    } else if(mode == 2){
        modeDescript = " running ";
        howLong = (time * 8) / 60.0f;
    } else if(mode == 3){
        modeDescript = " biking ";
        howLong = (time * 15) / 60.0f;
    } else if(mode == 4){
        modeDescript = " driving ";
        howLong = (time * 40) / 60.0f;
    } else {
        modeDescript = " flying ";
        howLong = (time * 150) / 60.0f;
    }
    std::cout << modeDescript;
    return howLong;
} */

float computeDistance(){
    float time = std::rand() % 55 + 6;
    unsigned mode = std::rand() % 5 + 1;
    char* modeDescript;
    float howLong;
    time = std::rand() % 55 + 6;
    std::cout << "Travel " << time << " minutes";
    mode = std::rand() % 5 + 1;
    if(mode == 1){
        modeDescript = " walking ";
        howLong = (time / 60.0f) * 3;
    } else if(mode == 2){
        modeDescript = " running ";
        howLong = (time / 60.0f) * 8;
    } else if(mode == 3){
        modeDescript = " biking ";
        howLong = (time / 60.0f) * 15;
    } else if(mode == 4){
        modeDescript = " driving ";
        howLong = (time / 60.0f) * 40;
    } else {
        modeDescript = " flying ";
        howLong = (time / 60.0f) * 150;
    }
    std::cout << modeDescript;
    return howLong;
}

unsigned whichWay(){
    unsigned compass = std::rand() % 8 + 1;
    compass = std::rand() % 8 + 1;
    if(compass == 1){
        return 0;
    } else if(compass == 2){
        return 1;
    } else if(compass == 3){
        return 2;
    } else if(compass == 4){
        return 3;
    } else if(compass == 5){
        return 4;
    } else if(compass == 6){
        return 5;
    } else if(compass == 7){
        return 6;
    } else {
        return 7;
    }
}

std::pair<float, float> generateInstructions(unsigned total, unsigned minimum){

    /* List of all speeds */

    std::cout << "Walking speed is 3 miles per hour" << std::endl
            << "Running speed is 8 miles per hour" << std::endl
            << "Biking speed is 15 miles per hour" << std::endl
            << "Driving speed is 40 miles per hour" << std::endl
            << "Flying speed is 150 miles per hour \n" << std::endl;

    /* Main Logic */

    std::srand(std::time(0));
    unsigned numOfInstruct = std::rand() % total + minimum;
    float treasureX = 0;
    float treasureY = 0;
    float travelDistance;
    unsigned travelDirection, counter;
    numOfInstruct = std::rand() % total + minimum;
    for(counter = 0; counter < numOfInstruct; counter++){
        travelDistance = computeDistance();
        travelDirection = whichWay();
        if(travelDirection == 0){
            std::cout << "N" << std::endl;
            treasureY += travelDistance;
        } else if(travelDirection == 1){
            std::cout << "S" << std::endl;
            treasureY -= travelDistance;
        } else if(travelDirection == 2){
            std::cout << "E" << std::endl;
            treasureX += travelDistance;
        } else if(travelDirection == 3){
            std::cout << "W" << std::endl;
            treasureX -= travelDistance;
        } else if(travelDirection == 4){
            std::cout << "NE" << std::endl;
            treasureX += std::sqrt(std::pow(travelDistance, 2) / 2.0f);
            treasureY += std::sqrt(std::pow(travelDistance, 2) / 2.0f);
        } else if(travelDirection == 5){
            std::cout << "NW" << std::endl;
            treasureX -= std::sqrt(std::pow(travelDistance, 2) / 2.0f);
            treasureY += std::sqrt(std::pow(travelDistance, 2) / 2.0f);
        } else if(travelDirection == 6){
            std::cout << "SE" << std::endl;
            treasureX += std::sqrt(std::pow(travelDistance, 2) / 2.0f);
            treasureY -= std::sqrt(std::pow(travelDistance, 2) / 2.0f);
        } else {
            std::cout << "SW" << std::endl;
            treasureX -= std::sqrt(std::pow(travelDistance, 2) / 2.0f);
            treasureY -= std::sqrt(std::pow(travelDistance, 2) / 2.0f);
        }
    }
    std::pair<float, float> treasureXY = {treasureX, treasureY};
    std::cout << counter << " Instructions generated" << std::endl;
    return treasureXY;
}

void findPath(float treasureX, float treasureY){
    float absoluteX = treasureX - (treasureX * 2);
    float absoluteY = treasureY - (treasureY * 2);
    if(treasureX == 0 || treasureY == 0){ // Testing whether its directly North, South, East or West, or if you are at already there
        if(treasureX == 0) {
            if(treasureY > 0){
                std::cout << "Go North " << treasureY << " miles to reach the treasure" << std::endl;
                return;
            } else if(treasureY < 0) {
                std::cout << "Go South " << absoluteY << " miles to reach the treasure" << std::endl;
                return;
            } else {
                std::cout << "You already have the treasure, idiot " << std::endl;
                return;
            }
        } else {
            if(treasureX > 0){
                std::cout << "Go East " << treasureX << " miles to reach the treasure" << std::endl;
                return;
            } else {
                std::cout << "Go West " << absoluteX << " miles to reach the treasure" << std::endl;
                return;
            }
        }
    } else if(treasureX - treasureY == 0 || treasureX + treasureY == 0){ // Testing whether to head Northeast, Northwest, Southeast, or Southwest
        if(treasureX > 0 && treasureY > 0){
            std::cout << "Go Northeast " << treasureX * std::sqrt(2.0f) << " miles to reach the treasure" << std::endl;
            return;
        } else if(treasureX > 0 && treasureY < 0){
            std::cout << "Go Southeast " << treasureX * std::sqrt(2.0f) << " miles to reach the treasure" << std::endl;
            return;
        } else if(treasureX < 0 && treasureY > 0){
            std::cout << "Go Northwest " << treasureY * std::sqrt(2.0f) << " miles to reach the treasure" << std::endl;
            return;
        } else {
            std::cout << "Go Southwest " << absoluteY * std::sqrt(2.0f) << " miles to reach the treasure" << std::endl;
            return;
        }
    } else {
        if(treasureX > 0 && treasureY > 0){ // A 2 step process first going North/South then East/West, the most commonly used
            std::cout << "Go North " << treasureY << " miles, then go ";
            std::cout << "East " << treasureX << " miles to reach the treasure" << std::endl;
            return;
        } else if(treasureX > 0 && treasureY < 0){
            std::cout << "Go South " << absoluteY << " miles, then go ";
            std::cout << "East " << treasureX << " miles to reach the treasure" << std::endl;
            return;
        } else if(treasureX < 0 && treasureY > 0){
            std::cout << "Go North " << treasureY << " miles, then go ";
            std::cout << "West " << absoluteX << " miles to reach the treasure" << std::endl;
            return;
        } else {
            std::cout << "Go South " << absoluteY << " miles, then go ";
            std::cout << "West " << absoluteX << " miles to reach the treasure" << std::endl;
            return;
        }
    }
}

int main(){
    unsigned instructionsYN, totalInstructions, exitType;
    std::pair<float, float> finalXY;
    std::cout << "Welcome to Treasure Hunt" << std::endl;
    std::cout << "Are your directions provided manually (1) or automatically (2)? ";
    std::cin >> instructionsYN;
    std::cout << std::endl; // newline
    if(instructionsYN == 1){
        std::cout << "How many total instructions? ";
        std::cin >> totalInstructions;
        std::cout << std::endl; // newline
        finalXY = generateInstructions(1, totalInstructions);
    } else if(instructionsYN == 2){
        finalXY = generateInstructions(80, 20);
    } else {
        std::cout << "Please enter a valid input" << std::endl;
        main();
    }
    float finalX = std::get<0>(finalXY);
    // std::cout << finalX << std::endl;
    float finalY = std::get<1>(finalXY);
    // std::cout << finalY << std::endl;
    std::cout << std::endl;
    findPath(finalX, finalY);
    std::cout << "Type any number to exit ";
    std::cin >> exitType;
    if(exitType != NULL){
        return 0;

    }
}

