#include "SnowSports.hpp"
#include "SnowSportCollection.hpp"


int main() {
    // Creating instances of Snowmobiling, Skiing, and Snowboarding
    Snowmobiling snowmobiling("John", DRAGONSPIRE_START);
    Skiing skiing("Alice", CRYSTAL_CREST);
    Snowboarding snowboarding("Bob", ENCHANTED_GROVE);

    // Setting names and locations
    snowmobiling.setName("Snowmobiler John");
    skiing.setName("Skier Alice");
    snowboarding.setName("Snowboarder Bob");

    snowmobiling.setLocation(WIZARDS_FINISH);
    skiing.setLocation(DRAGONSPIRE_START);
    snowboarding.setLocation(MYSTICAL_SUMMIT);

    // Performing specific actions for each sport
    snowmobiling.turnOnEngine(std::chrono::system_clock::now());
    snowmobiling.turnOnEngine(std::chrono::system_clock::now());
    snowmobiling.goForward(10);

    skiing.jump(std::chrono::system_clock::now());
    snowboarding.flip(std::chrono::system_clock::now());

    // Creating a SnowSportCollection and adding instances to it
    SnowSportCollection<SnowSport> snowSportCollection;
    snowSportCollection.add(snowmobiling);
    snowSportCollection.add(skiing);
    snowSportCollection.add(snowboarding);

    // Displaying all elements in the SnowSportCollection
    snowSportCollection.printAll();

    return 0;
}

Timestamp addSeconds(const Timestamp& timePoint, std::chrono::seconds secondsToAdd) {
    return timePoint + secondsToAdd;
}