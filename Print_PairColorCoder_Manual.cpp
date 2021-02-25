#include <iostream>
#include "TeleComColorCoder.h"
using namespace TeleComColorCoder

#define LAST_COLORCODE  25
#define FIRST_COLORCODE 1

void Print_PairColorCodes_Manual(void)
{

for(int PairColorCode=FIRST_COLORCODE; PairColorCode <= LAST_COLORCODE ; PairColorCode++)
{

	TeleComColorCoder::ColorPair tmpcolorPair_classobj = TeleComColorCoder::Extract_Color_From_PairNumber(PairColorCode);
	std::cout << PairColorCode << "\t" << tmpcolorPair_classobj.DeliverColorPairString() << std::endl;
}

}
