#ifndef SNOW_SPORTS_HPP
#define SNOW_SPORTS_HPP

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <chrono>

using Timestamp = std::chrono::system_clock::time_point;

class ContestantMetrics {
public:
    void addContestantMetrics( Timestamp timestamp, double value);
    void displayContestantMetrics() const;
    std::vector<std::pair<Timestamp, double>>& getContestantData();


private:
    std::vector<std::pair<Timestamp, double>> contestantData;
};

enum CourseLocation {
    ENCHANTED_GROVE,
    MYSTICAL_SUMMIT,
    DRAGONSPIRE_START,
    CRYSTAL_CREST,
    WIZARDS_FINISH
};

class SnowSport {
public:
    explicit SnowSport(const std::string& contestantName, const CourseLocation location);
    virtual ~SnowSport() = default;

    // Getter and setter functions
    std::string& getName();
    void setName(const std::string& contestantName);

    CourseLocation getLocation() const;
    void setLocation(CourseLocation location);

    void goForward(int distance);

    void displayMetrics();


protected:
    std::string contestantName;
    CourseLocation location;
    std::map<std::string, ContestantMetrics> contestantMetricsMap;

};

class Snowmobiling : public SnowSport {
public:
    explicit Snowmobiling(const std::string& name, const CourseLocation location);
    ~Snowmobiling() = default;

    void turnOnEngine(Timestamp t);
    void turnOffEngine(Timestamp t);
    void stop(Timestamp t);

};

class Skiing : public SnowSport {
public:
    explicit Skiing(const std::string& name, const CourseLocation location);
    ~Skiing() = default;

    void jump(Timestamp t);
};

class Snowboarding : public SnowSport {
public:
    explicit Snowboarding(const std::string& name, const CourseLocation location);
    ~Snowboarding() = default;

    void flip(Timestamp t);
};

#endif