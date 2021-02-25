
namespace TeleComColorCoder
{
    enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
    enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

    const char* MajorColorNames[] = {
        "White", "Red", "Black", "Yellow", "Violet"
    };
    int numberOfMajorColors =
        sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    const char* MinorColorNames[] = {
	    "Blue", "Orange", "Green", "Brown", "Slate"
    };
    int numberOfMinorColors =
        sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

    class ColorPair {
        private:
            MajorColor majorColor_pvt;
            MinorColor minorColor_pvt;
        public:
            ColorPair(MajorColor assign_majorcolor, MinorColor assign_minorcolor):
                majorColor_pvt(assign_majorcolor), minorColor_pvt(assign_minorcolor)
            {}
            MajorColor DeliverMajorColor() 
	    {
                return majorColor_pvt;
            }
            MinorColor DeliverMinorColor()
	    {
                return minorColor_pvt;
            }
            std::string DeliverColorPairString()
	    {
                std::string colorPairStr = MajorColorNames[majorColor_pvt];
                colorPairStr += " ";
                colorPairStr += MinorColorNames[minorColor_pvt];
                return colorPairStr;
            }
    };

    ColorPair Extract_Color_From_PairNumber(int pairNumber) 
    {
        int zeroBasedPairNumber = pairNumber - 1;
	    
        MajorColor Fetch_majorColor = 
            		(MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor Fetch_minorColor =
           		 (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
	    
        return ColorPair(Fetch_majorColor, Fetch_minorColor);
    }
	
    int Extract_PairNumber_From_Color(MajorColor major, MinorColor minor) 
    {
        return major * numberOfMinorColors + minor + 1;
    }
}
