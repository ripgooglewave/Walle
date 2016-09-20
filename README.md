# Walle

Malmö, Sweden, Sep 20 2016.

Meet Walle. Walle is an Mbot Ranger from Makeblock.
His brain is the Auriga, a chip from Makeblock based on the ATMega2560 Arduino chip.

(see http://www.makeblock.com/robot-kit-series-STEM/mbot-ranger)

Later on, he might extend his brain with things like a Raspberry PI, more Arduinos, control chips and other exciting stuff.
To say the least, Walle´s future is full of opportunities, the sky is the limit. (or is it?)

This project is his mind.

# Goals
This is a very open thing. The goal is to learn and play, build a robot, have fun.
I will probably not use Makeblocks graphical programming language mBlock much, instead do Arduino programming directly with C/C++
or use JavaScript/Java libs, anything that is handy.

The vision is also connecting a micro computer, like Raspberry Pi. 
Maybe connect him to a cloud, like Amazon.

Inspiration from: http://blog.jdriven.com/2016/04/mission-mars/
(Talk at IOT Conference, Lund 2016)

# Short-term goals (currently)
These goals may change very suddenly, but these are the current goals for Walle.

* Make some prototype demos to control leds, sound, motor, sensors etc in C through the Arduino IDE
* Get him running with Johhny five (http://johnny-five.io/), perhabs write a lib 
to map him to the correct ports so you can control his on-board features with it.
* Learn about and improve the PID-regulated motor control for the Flappy Bird (Kind of a side project since this assembly is not intended for Walle in the long run)
* Build him as a Land Raider and implement a SLAM-algorithm (https://en.wikipedia.org/wiki/Simultaneous_localization_and_mapping)
* Get a Raspberry Pi and hook up via Serial to the Auriga, and control features through it. Find a balance on what features should be implemented on the Auriga and what is run on the RPI.

# Prototype demos

I've started by adding some simple tests in the 'Proto' folder. To run these, you need to install the Arduino IDE and the USB drivers on your computer.
You also need to import Makeblocks libraries, because these are used by the prototypes to address the correct ports. 
Follow these instructions to get started:

http://learn.makeblock.com/en/learning-arduino-programming-ranger/

What you need:
* Computer (Mac/Linux or Windows)
* 1 Mbot Ranger from makeblock (http://www.makeblock.com/robot-kit-series-STEM/mbot-ranger)

OR

* 1 Auriga and plug in the components you want (http://www.makeblock.com/electronic-robot-kit-series-STEM/me-auriga)
