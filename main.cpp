#include <iostream>
#include <cassert>
#include "Day.h"

void TestEntryComparison() {
    Entry entry1("John Doe", Time(9, 30));
    Entry entry2("Jane Doe", Time(10, 0));

    assert(entry1.comparedTo(entry2) == -1);
    assert(entry2.comparedTo(entry1) == 1);
    assert(entry1.comparedTo(entry1) == 0);

    std::cout << "Entry comparedTo test passed." << std::endl;
}

void TestDayClass() {
    Day day1;
    Date customDate(2, 10, 2024);
    Day day2(customDate, 10);

    // Test InsertEntry
    Entry entry1("John Doe", Time(9, 30));
    day2.InsertEntry(entry1);

    assert(day2.GetNumberOfEntries() == 1);

    // Test isFree
    assert(day2.isFree(Time(10, 0)) == true);
    assert(day2.isFree(Time(9, 30)) == false);

    // Test IsPresent
    assert(day2.IsPresent("John Doe") == true);
    assert(day2.IsPresent("Jane Doe") == false);

    // Test DeleteEntry
    day2.DeleteEntry(entry1);
    assert(day2.GetNumberOfEntries() == 0);

    std::cout << "Day class unit tests passed." << std::endl;
}

int main() {
    TestEntryComparison();
    TestDayClass();

    return 0;
}
