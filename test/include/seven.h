// #define HIGH 1
// #define LOW 0

//#define DOT 10

// #define Seg_A PD0;
// #define Seg_B PD1;
// #define Seg_C PD2;
// #define Seg_D PD3;
// #define Seg_E PD4;
// #define Seg_F PD5;
// #define Seg_G PD6;
// #define Seg_DP PD7;
// #define DISP1 PB0;
// #define DISP2 PB1;
// #define DISP3 PB2;
// #define DISP4 PB3;
// #define SWITCH PB5;

//extern int segment_pin[];

/*takes an array with 8 pins and connects them to our 7-segment display
Each pin should be an Arduino-pin number from 0 to (and including) 13
and these should be entered as such: {segment-A, segment-B, ... , segment-DP} */
// takes an array with 8 pins
void setSegmentPins(int *pins);

/*Sets all segments so that the display shows numbers from 
0-9. If numbers 10-19 are put in then the display should show
the number -10 so 10 becomes 0, 11 becomes 1 and so on, but the dot should also be lit. 
If any other number than 0-19 is entered the display should be completely turned off. */
void setDisplayNumber(int nr);

//void digitalWrite(int pin, int mode);

//void setPin(int pin, int mode);
