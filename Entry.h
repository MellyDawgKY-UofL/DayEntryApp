#pragma once
#include <string>

class Time {
    int hour, minute;
public:
    Time(int h = 0, int m = 0) : hour(h), minute(m) {}
    bool operator<(const Time& other) const {
        return (hour < other.hour) || (hour == other.hour && minute < other.minute);
    }
    bool operator==(const Time& other) const {
        return (hour == other.hour && minute == other.minute);
    }
};

class Entry {
    std::string name;
    Time time;
public:
    Entry(std::string name, Time time) : name(name), time(time) {}

    Time getTime() const { return time; }
    std::string getName() const { return name; }

    int comparedTo(const Entry& other) const {
        if (time < other.time) return -1;
        if (time == other.time) return 0;
        return 1;
    }
};
