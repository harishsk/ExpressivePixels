#include "EPXVariant.h"
#include "EPXGlobal.h"
#include "EPXPlatform_BLE.h"
#include "EPXPlatform_GPIO.h"
#include "CDisplayTopology.h"
#include "EPXPlatform_SPIClass.h"

char g_szDEFAULT_BLE_NAME[BLEMAX_DEVICENAME + 1] = "SI2Sprklt";

#ifdef DISPLAYTYPE_EMOTICONWS2812

EPX_GUID g_displayDesignGUID = { 0x6C, 0xDE, 0x4E, 0xAC, 0x28, 0x0F, 0xE1, 0x4C, 0x8A, 0x69, 0xD2, 0x5E, 0xF9, 0xD3, 0x11, 0xB1 };


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

#elif DISPLAYTYPE_EMOTICONWS2812_16x16

#define DISPLAYARRAY_WIDTH		16
#define DISPLAYARRAY_HEIGHT		16

EPX_GUID g_displayDesignGUID = { 0xDF, 0xF7, 0xA2, 0xBD, 0x46, 0xA5, 0x4C, 0x9A, 0x85, 0x2A, 0xEC, 0xBF, 0x8D, 0xBA, 0x24, 0x9A };

uint16_t g_displayArrayPixelTopology[DISPLAYARRAY_WIDTH * DISPLAYARRAY_HEIGHT];


#elif DISPLAYTYPE_16x16

EPX_GUID g_displayDesignGUID = { 0xDF, 0xF7, 0xA2, 0xBD, 0xFF, 0xA5, 0x4C, 0x9A, 0x85, 0x2A, 0xEC, 0xBF, 0x8D, 0xBA, 0x24, 0x9A };

uint16_t g_displayArrayPixelTopology[DISPLAYARRAY_WIDTH * DISPLAYARRAY_HEIGHT];

#elif DISPLAYTYPE_22x22
EPX_GUID g_displayDesignGUID = { 0xDF, 0xF7, 0xA2, 0xBD, 0xFF, 0xA5, 0x4C, 0x9A, 0x85, 0x2A, 0xAA, 0xBF, 0x8D, 0x00, 0x24, 0x9A };

uint16_t g_displayArrayPixelTopology[DISPLAYARRAY_WIDTH * DISPLAYARRAY_HEIGHT];

#endif


SWITCHACTIVATION_GPIOBUTTON_MAPPING g_switchTriggerGPIOButtonMappings[VARIANT_NUMTRIGGERGPIOS] = { {"D0", GPIO_PIN_D0 }, {"D1", GPIO_PIN_D1 }, {"D2", GPIO_PIN_D2 }, 
																			{"D3", GPIO_PIN_D3 }, {"D4", GPIO_PIN_D4 }, {"D5", GPIO_PIN_D5 }, 
																			{"D6", GPIO_PIN_D6 }, {"A0", GPIO_PIN_A0 }, {"A1", GPIO_PIN_A1 }, 
																			{"A2", GPIO_PIN_A2 }, {"A3", GPIO_PIN_A3 }, {"A4", GPIO_PIN_A4 }, 
																			{"A5", GPIO_PIN_A5 }};

