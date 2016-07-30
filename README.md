# PCINT

Yet another Arduino PCINT library

Allows handlers to be called with a predefined cargo (void*) for user data.

If your board is not supported please see mkPCIntMap example.

## Example

```c++
PCattachInterrupt(pinA, mixHandler((void(*)(void*))quadEncoderUpdateA,this), CHANGE);
PCattachInterrupt(pinB, mixHandler((void(*)(void*))quadEncoderUpdateB,this), CHANGE);
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

```c++
void PCdetachInterrupt(uint8_t pin);
```

stop monitoring pin change on given pin.

- pin - your board pin number

(Jul 2016) added skectch to print PCINT maps, please pull or send me new maps.
This allows you to add support for your board pinout definition.

(Nov.2014) using arduino PCINT macros for wider compatibility
