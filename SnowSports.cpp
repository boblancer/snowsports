#include "SnowSports.hpp"

// SnowSport implementation
SnowSport::SnowSport(const std::string& name, const CourseLocation location)
    : contestantName(name), location(location) {}

 std::string& SnowSport::getName(){
    return contestantName;
}

void SnowSport::setName(const std::string& name) {
    this->contestantName = name;
}

CourseLocation SnowSport::getLocation() const {
    return location;
}

void SnowSport::setLocation(CourseLocation location) {
    this->location = location;
}

// Take argument distance detla from start to now and add it to location metric
void SnowSport::goForward(int distance) {
    Timestamp currentTimestamp = std::chrono::system_clock::now();

    auto& locationMetrics = contestantMetricsMap["location"];

    locationMetrics.getContestantData().push_back(std::make_pair(currentTimestamp, static_cast<double>(distance)));

}

void SnowSport::displayMetrics() {
    std::cout << "Contestant Metrics for " << this->getName() << ":" << std::endl;

    for (const auto& metricEntry : contestantMetricsMap) {
        const std::string& metricKey = metricEntry.first;
        const ContestantMetrics& metrics = metricEntry.second;

        std::cout << "Metric Key: " << metricKey <<std::endl;
        
        // Display all timestamp-value pairs using getContestantData
       metrics.displayContestantMetrics();
    }
}

void ContestantMetrics::addContestantMetrics(Timestamp timestamp, double value) {
    contestantData.push_back(std::make_pair(timestamp, value));
}

// Snowmobiling implementation
Snowmobiling::Snowmobiling(const std::string& name, const CourseLocation location)
    : SnowSport(name, location) {}

void Snowmobiling::turnOnEngine(Timestamp t) {
    Timestamp currentTimestamp = std::chrono::system_clock::now();

    auto& locationMetrics = contestantMetricsMap["engine-on"];

    locationMetrics.getContestantData().push_back(std::make_pair(currentTimestamp, 1));
}

void Snowmobiling::turnOffEngine(Timestamp t) {
    Timestamp currentTimestamp = std::chrono::system_clock::now();

    auto& locationMetrics = contestantMetricsMap["engine-off"];

    locationMetrics.getContestantData().push_back(std::make_pair(currentTimestamp, 1));
}

void Snowmobiling::stop(Timestamp t) {
    Timestamp currentTimestamp = std::chrono::system_clock::now();

    auto& locationMetrics = contestantMetricsMap["stop"];

    locationMetrics.getContestantData().push_back(std::make_pair(currentTimestamp, 1));
}

// Skiing implementation
Skiing::Skiing(const std::string& name, const CourseLocation location)
    : SnowSport(name, location) {}

void Skiing::jump(Timestamp t) {
    Timestamp currentTimestamp = std::chrono::system_clock::now();

    auto& locationMetrics = contestantMetricsMap["jump"];

    locationMetrics.getContestantData().push_back(std::make_pair(currentTimestamp, 10));
}

Snowboarding::Snowboarding(const std::string& name, const CourseLocation location)
    : SnowSport(name, location) {}

void Snowboarding::flip(Timestamp t) {
    Timestamp currentTimestamp = std::chrono::system_clock::now();

    auto& locationMetrics = contestantMetricsMap["flip"];

    locationMetrics.getContestantData().push_back(std::make_pair(currentTimestamp, 1));
}

std::vector<std::pair<Timestamp, double>>& ContestantMetrics::getContestantData() {
    return contestantData;
}

std::string getCurrentTimestamp(const Timestamp& timePoint) {
    std::time_t time = std::chrono::system_clock::to_time_t(timePoint);
    std::tm localTime = *std::localtime(&time);

    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localTime);

    return std::string(buffer);
}

void ContestantMetrics::displayContestantMetrics() const {
    for (const auto& data : contestantData) {
        std::cout << "  Timestamp: " << getCurrentTimestamp(data.first)
                  << ", Value: " << data.second << "\n" <<std::endl;
    }
}