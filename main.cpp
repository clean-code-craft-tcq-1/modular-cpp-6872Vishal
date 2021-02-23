#include <iostream>
#include "TeleComColorCoder.h"
#include <assert.h>

#define LAST_COLORCODE  25
#define FIRST_COLORCODE 1

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
void Print_PairColorCodes_Manual(void)
{
for(int PairColorCode=FIRST_COLORCODE; PairColorCode <= LAST_COLORCODE ; PairColorCode++)
{

	TeleComColorCoder::ColorPair tmpcolorPair_classobj = TeleComColorCoder::Extract_Color_From_PairNumber(PairColorCode);
	std::cout << PairColorCode << "\t" << tmpcolorPair_classobj.PrintColorPairString() << std::endl;
}
}

int main() {
    testNumberToPair(4, TeleComColorCoder::WHITE, TeleComColorCoder::BROWN);
    testNumberToPair(5, TeleComColorCoder::WHITE, TeleComColorCoder::SLATE);

    testPairToNumber(TeleComColorCoder::BLACK, TeleComColorCoder::ORANGE, 12);
    testPairToNumber(TeleComColorCoder::VIOLET, TeleComColorCoder::SLATE, 25);

    return 0;
}
