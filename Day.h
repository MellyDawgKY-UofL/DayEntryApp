#pragma once
#include <vector>
#include <stdexcept>
#include "Entry.h"
#include <algorithm>

class Date {
    int day, month, year;
public:
    Date(int d = 1, int m = 1, int y = 1583) : day(d), month(m), year(y) {}

    bool operator<(const Date& other) const {
        if (year < other.year) return true;
        if (year == other.year && month < other.month) return true;
        return day < other.day;
    }

    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }
};

class Day {
    Date date;
    std::vector<Entry> entries;
    int maxEntries;
    int currentEntryIndex;

public:
    Day() : date(Date()), maxEntries(48), currentEntryIndex(0) {
        entries.reserve(maxEntries);
    }

    Day(Date date, int numEntries) : date(date), maxEntries(numEntries), currentEntryIndex(0) {
        entries.reserve(maxEntries);
    }

    void InsertEntry(Entry entry) {
        if (entries.size() >= maxEntries) {
            throw std::runtime_error("List is full");
        }
        entries.push_back(entry);
    }

    void DeleteEntry(Entry entry) {
        auto it = std::find_if(entries.begin(), entries.end(), [&](Entry& e) { return e.getName() == entry.getName() && e.getTime() == entry.getTime(); });
        if (it != entries.end()) {
            entries.erase(it);
        }
    }

    bool isFree(Time time) {
        for (const auto& entry : entries) {
            if (entry.getTime() == time) {
                return false;
            }
        }
        return true;
    }

    bool IsPresent(std::string name) {
        for (const auto& entry : entries) {
            if (entry.getName() == name) {
                return true;
            }
        }
        return false;
    }

    Date GetDate() const { return date; }

    int GetNumberOfEntries() const { return entries.size(); }

    void ResetEntries() { currentEntryIndex = 0; }

    Entry GetNextEntry() {
        if (currentEntryIndex < entries.size()) {
            return entries[currentEntryIndex++];
        }
        throw std::runtime_error("No more entries");
    }

    int ComparedTo(const Day& other) const {
        if (date < other.date) return -1;
        if (date == other.date) return 0;
        return 1;
    }
};
