# sevenseg 

Is a little demonstration project that shows how to use a shift register like the
famous `74HC595` and a darlington array `ULN2803` to drive a 7 segment LED display.

# Requirements

## Software

The software is written in `C++` based on [platformio](https://platformio.org/).
You can also use it directly with the arduino IDE or may even port it to avr gcc.

## Hardware

This section covers the needed components and the circuit diagram

### Components

* Arduino UNO R3 (any other arduino will do)
* `74HC595` shift register to reduce the amount of pins needed from the microcontroller
* `ULN2803` darlington array to drive the led segments. The shift register could 
  not sink enough current.
* Nine 160 Ohm resistors
* One 100nF decoupling capacitor

### Circuit Diagram

![sevseg schematics](https://github.com/crapp/sevseg/raw/master/schematics/sevseg_schematics.png)

# General use

The software itself is just a demo application. It features a simple countdown
from 9 to 0 and you can display multi digest numbers with multiple seven segment
displays with a built in function. The schematics provided here do only show the
simple case with one display. But it is very easy to daisy chain the shift
registers. The needed code is already there.

# License 

Copyright 2018 Christian Rapp

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this 
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, 
   this list of conditions and the following disclaimer in the documentation 
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors 
   may be used to endorse or promote products derived from this software without
   specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
