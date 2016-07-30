#include <streamFlow.h>
#define mapSz 3
int8_t pcintPins[mapSz][8];

void setup() {
  Serial.begin(115200);
  while (!Serial);
  for(int slot=0;slot<mapSz;slot++) for(int bit=0;bit<8;bit++) pcintPins[slot][bit]=-1;
  for(int pin=0;pin<NUM_DIGITAL_PINS;pin++) {
    volatile uint8_t *pcmask=digitalPinToPCMSK(pin);
    if (!pcmask) continue;//runtime checking if pin has PCINT, i would prefer a compile time check
    uint8_t bit = digitalPinToPCMSKbit(pin);
    uint8_t mask = 1<<bit;
    uint8_t pcicrBit=digitalPinToPCICRbit(pin);
    //Serial<<pin<<": pcmask:"<<*pcmask<<" bit:"<<bit<<" mask:"<<mask<<" pcirBit:"<<pcicrBit<<endl;
    if (pcicrBit<3) pcintPins[pcicrBit][bit]=pin;
  }
  Serial.println("//PCINT map for <put BOARD_NAME here>");
  Serial.print("const uint8_t PROGMEM pcintPinMap[3][8]={");
  for(int slot=0;slot<mapSz;slot++) {
    Serial.print(slot?",":"");
    Serial.print("{");
    for(int bit=0;bit<8;bit++) {
      Serial.print(bit?",":"");
      Serial.print(pcintPins[slot][bit]);
    }
    Serial.print("}");
  }
  Serial.println("};");
  Serial.flush();
}

void loop() {
}
