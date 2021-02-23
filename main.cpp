#include <iostream>
#include "TeleComColorCoder.h"
#include <assert.h>

void testNumberToPair(int received_pairNumber,
    TeleComColorCoder::MajorColor expectedMajor,
    TeleComColorCoder::MinorColor expectedMinor)
{
    TeleComColorCoder::ColorPair colorPair_classobj =
        TeleComColorCoder::Extract_Color_From_PairNumber(received_pairNumber);
		
    std::cout << "Got pair " << colorPair_classobj.PrintColorPairString() << std::endl;
	
    assert(colorPair_classobj.DeliverMajorColor() == expectedMajor);
    assert(colorPair_classobj.DeliverMinorColor() == expectedMinor);
}

void testPairToNumber(
    TeleComColorCoder::MajorColor received_majorcolor,
    TeleComColorCoder::MinorColor received_minorcolor,
    int expectedPairNumber)
{
    int calculated_pairNumber = TeleComColorCoder::Extract_PairNumber_From_Color(received_majorcolor, received_minorcolor);
	
    std::cout << "Got pair number " << calculated_pairNumber << std::endl;
	
    assert(calculated_pairNumber == expectedPairNumber);
}

int main() {
    testNumberToPair(4, TeleComColorCoder::WHITE, TeleComColorCoder::BROWN);
    testNumberToPair(5, TeleComColorCoder::WHITE, TeleComColorCoder::SLATE);

    testPairToNumber(TeleComColorCoder::BLACK, TeleComColorCoder::ORANGE, 12);
    testPairToNumber(TeleComColorCoder::VIOLET, TeleComColorCoder::SLATE, 25);

    return 0;
}
