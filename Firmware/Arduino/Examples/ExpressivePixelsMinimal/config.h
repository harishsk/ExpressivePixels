/***************************************************************************************/
/* This section specifies the LED driver, EG: Neopixel (WS2812), DotStar, Matrix array */
/***************************************************************************************/
// Uncomment the following line for an Adafruit RGB LED Matrix
#define DISPLAYDRIVER_ADAFRUIT_PROTOMATTER

// Uncomment the following line for Adafruit Dotstar
// #define DISPLAYDRIVER_ADAFRUIT_DOTSTAR

// Uncomment the following lines if you're using NeoPixels
// #define DISPLAYDRIVER_ADAFRUIT_NEOPIXEL

#ifdef ADAFRUIT_DOTSTAR
#include "AdafruitDotStar_EPXDriver.h"
#elif defined(ADAFRUIT_NEOPIXEL)
#include <AdafruitNeoPixel_EPXDriver.h>
#elif defined(ADAFRUIT_PROTOMATTER)
#include <AdafruitRGBMatrix_EPXDriver.h>
#endif

/***************************************************************************************/
/* This section specifies the Display Driver's pin connections                         */
/***************************************************************************************/
// Specify the data pin the LED array is connected to 
// #define PIN_STRIP_DATA PIN_A2

// Specify the clock pin the LED array is connected to 
// #define PIN_STRIP_CLOCK PIN_A3


/***************************************************************************************/
/* This section specifies the Display dimensions and topology mapping                  */
/***************************************************************************************/
// Uncomment the following line for the Adafruit Dotstar 8x8
// #define DISPLAY_DOTSTAR8x8

// Uncomment the following line for the Adafruit Featherwing Dotstar
// #define DISPLAY_FEATHERWINGDOTSTAR

// Uncomment the following line for a Flexible 16x16 Matrix
// #define DISPLAY_FLEX16X16

// Uncomment the following line for Sparklet 16x16 Square
// #define DISPLAY_SPARKLETSQUARE16X16

// Uncomment the following line for a 64x32 display
#define DISPLAY_MATRIX64x32

// Uncomment the following line for Sparklet 18x18 Round
// #define DISPLAY_SPARKLETROUND18X18



extern uint8_t bootAnimation[];

#define TOPOLOGYPIXEL_UNASSIGNED	0xFFFF

#ifdef DISPLAY_FEATHERWINGDOTSTAR
    // Specify dimensions of display connect to the device
    #define DISPLAYARRAY_WIDTH		16
    #define DISPLAYARRAY_HEIGHT		16

    // Specify the LED topology on the display
    uint16_t g_displayArrayPixelTopology[DISPLAYARRAY_WIDTH * DISPLAYARRAY_HEIGHT] = 
    { 
        60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 
        48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
        36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
        24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
        12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
        0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11,
    };
#elif defined (DISPLAY_DOTSTAR8x8)
#define DISPLAYARRAY_WIDTH		8
#define DISPLAYARRAY_HEIGHT		8

uint16_t g_displayArrayPixelTopology[DISPLAYARRAY_WIDTH * DISPLAYARRAY_HEIGHT] =
{
  7,  6,  5,  4,  3,  2,  1,  0,
    15, 14, 13, 12, 11, 10, 9,  8,
    23, 22, 21, 20, 19, 18, 17, 16,
    31, 30, 29, 28, 27, 26, 25, 24,
    39, 38, 37, 36, 35, 34, 33, 32,
    47, 46, 45, 44, 43, 42, 41, 40,
    55, 54, 53, 52, 51, 50, 49, 48,
    63, 62, 61, 60, 59, 58, 57, 56
};
#elif defined (DISPLAY_FLEX16X16)
    // Specify dimensions of display connect to the device
    #define DISPLAYARRAY_WIDTH		16
    #define DISPLAYARRAY_HEIGHT		16

    uint16_t g_displayArrayPixelTopology[DISPLAYARRAY_WIDTH * DISPLAYARRAY_HEIGHT] = 
    { 
        0,  31, 32, 63, 64, 95, 96, 127,128,159,160,191,192,223,224,255,
        1,  30, 33, 62, 65, 94, 97, 126,129,158,161,190,193,222,225,254,
        2,  29, 34, 61, 66, 93, 98, 125,130,157,162,189,194,221,226,253,
        3,  28, 35, 60, 67, 92, 99, 124,131,156,163,188,195,220,227,252,
        4,  27, 36, 59, 68, 91,100, 123,132,155,164,187,196,219,228,251,
        5,  26, 37, 58, 69, 90,101, 122,133,154,165,186,197,218,229,250,
        6,  25, 38, 57, 70, 89,102, 121,134,153,166,185,198,217,230,249,
        7,  24, 39, 56, 71, 88,103, 120,135,152,167,184,199,216,231,248,
        8,  23, 40, 55, 72, 87,104, 119,136,151,168,183,200,215,232,247,
        9,  22, 41, 54, 73, 86,105, 118,137,150,169,182,201,214,233,246,
        10, 21, 42, 53, 74, 85,106, 117,138,149,170,181,202,213,234,245,
        11, 20, 43, 52, 75, 84,107, 116,139,148,171,180,203,212,235,244,
        12, 19, 44, 51, 76, 83,108, 115,140,147,172,179,204,211,236,243,
        13, 18, 45, 50, 77, 82,109, 114,141,146,173,178,205,210,237,242,
        14, 17, 46, 51, 78, 81,110, 113,142,145,174,177,206,209,238,241,
        15, 16, 47, 48, 79, 80,111, 112,143,144,175,176,207,208,239,240
    };
#elif defined (DISPLAY_SPARKLETROUND18X18)
    // Specify dimensions of display connect to the device
    #define DISPLAYARRAY_WIDTH		18
    #define DISPLAYARRAY_HEIGHT		18

    uint16_t g_displayArrayPixelTopology[DISPLAYARRAY_WIDTH * DISPLAYARRAY_HEIGHT] = 
    { 
	TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED,	TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED,	TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, 0, 1, 2, 3, 4, 5, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED,	TOPOLOGYPIXEL_UNASSIGNED, 
	TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, 
	TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, 	
	TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, 
	TOPOLOGYPIXEL_UNASSIGNED, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, TOPOLOGYPIXEL_UNASSIGNED, 	
	TOPOLOGYPIXEL_UNASSIGNED, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, TOPOLOGYPIXEL_UNASSIGNED, 
	74,	75,	76, 77,	78,	79,	80,	81,	82,	83,	84,	85,	86,	87,	88,	89,	90,	91,	
	92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
	110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127,
	128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145,
	146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163,
	164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181,
	TOPOLOGYPIXEL_UNASSIGNED, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, TOPOLOGYPIXEL_UNASSIGNED, 	
	TOPOLOGYPIXEL_UNASSIGNED, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, TOPOLOGYPIXEL_UNASSIGNED, 	
	TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED,214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, 	
	TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, 
	TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, 
	TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, 250, 251, 252, 253, 254, 255, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED, TOPOLOGYPIXEL_UNASSIGNED,TOPOLOGYPIXEL_UNASSIGNED
};
#elif defined (DISPLAY_SPARKLETSQUARE16X16)
    // Specify dimensions of display connect to the device
    #define DISPLAYARRAY_WIDTH		16
    #define DISPLAYARRAY_HEIGHT		16

    uint16_t g_displayArrayPixelTopology[DISPLAYARRAY_WIDTH * DISPLAYARRAY_HEIGHT];
#elif defined (DISPLAY_MATRIX64x32)
    #define DISPLAYARRAY_WIDTH		64
    #define DISPLAYARRAY_HEIGHT		32

    uint16_t g_displayArrayPixelTopology[DISPLAYARRAY_WIDTH * DISPLAYARRAY_HEIGHT];
#endif
