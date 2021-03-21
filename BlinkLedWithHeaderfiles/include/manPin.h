#define HIGH 1
#define LOW 0

void setPin(int pin, int mode);

void digitalWrite(int pin, int mode);

extern int segment_pin[];

// takes an array with 8 pins
void setSegmentPins(int *pins);

//Sets display to nr
void number(int nr);
