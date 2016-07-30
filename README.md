# PCINT

Yet another Arduino PCINT library

Allows handlers to be called with a predefined cargo (void*) for user data.

If your board is not supported please see mkPCIntMap example.

## Example

```c++
#include <pcint.h>

#define led 13
#define btn 12

void setled() {
  digitalWrite(led,digitalRead(btn));
}

void setup() {
  pinMode(led,OUTPUT);
  pinMode(btn,INPUT);
  digitalWrite(btn,1);//pullup
  PCattachInterrupt(btn,setled,CHANGE);
  setled();//initial led status
}

void loop() {}
```

## API

### PCattachInterrupt

```c++
void PCattachInterrupt(uint8_t pin, class mixHandler userFunc, uint8_t mode);
```
monitor pin and call user funtion on change.

- pin - your board pin number
- userFunc - function to be called on pin change
- mode - when to call the function, can be CHANGE | RISING | FALLING

### PCdetachInterrupt

```c++
void PCdetachInterrupt(uint8_t pin);
```

stop monitoring pin change on given pin.

- pin - your board pin number

## History

(Jul 2016) added skectch to print PCINT maps, please pull or send me new maps.
This allows you to add support for your board pinout definition.

(Nov.2014) using arduino PCINT macros for wider compatibility
