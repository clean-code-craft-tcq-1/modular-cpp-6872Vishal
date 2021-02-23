#include <iostream>
#include "TeleComColorCoder.h"
#include <assert.h>

void testNumberToPair(int pairNumber,
    TeleComColorCoder::MajorColor expectedMajor,
    TeleComColorCoder::MinorColor expectedMinor)
{
    TeleComColorCoder::ColorPair colorPair =
        TeleComColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TeleComColorCoder::MajorColor major,
    TeleComColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TeleComColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

    return 0;
}
