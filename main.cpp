/*
Project 3 - Part 1a-d / 5
Video:  Chapter 2 Part 5
User-Defined Types

Create a branch named Part1

Purpose: The entire purpose of this 5-part project is to get you 
writing C++ code that compiles and to reinforce the syntax habits 
that C++ requires.  
What you create in this project will be used as the basis of 
Project 5 in C++ Language Fundamentals.

************************
Part1 purpose:  Learn to write User-Defined Types (UDTs)

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps, all on the same branch.
    Part 1a: you will learn to think about an object in terms of 
    its sub-objects.
    
    Part 1b: you will write 4 un-related UDTs in plain english.
    
    Part 1c: you will write 1 UDT in plain english that will be 
    made of 5 related sub-objects.
    
    Part 1d: you will write plain-english UDTs for the 5 
    sub-objects that form the UDT defined in Part 1c.
    
    Part 1e: you will convert those 10 plain-english UDTs into code 
    that runs.
************************
*/

/*
Part 1a
1) Look at the picture of the car interior (Part1a pic.jpg).  
    It's in the list of files on the left in Replit.
    Fill in the blanks below which break this car interior down 
    into sub-objects.

Several sub-objects are listed below that make up this car's interior.
    you're going to name several things that you'll find on each 
    subobject.
    you're going to name several things that each subobject can do.
    If you've seen "Family Feud", we are going to do what they do 
    in that show.

    A few blanks are filled in for you already.

Main Object: Car Interior
Sub Object 1: Steering Wheel

 Name 4 things you'll find on the:    Steering Wheel
        1) paddle shifters
        2) 'cruise control' controls
        3) horn pad
        4) airbag
    Name 2 things you can do with the:   Steering Wheel
        1) adjust cruise control settings.
        2) unswer phone call
        3) honk the horn

Sub Object 2: Instrument Cluster
    Name 4 things you'll find on the:   Instrument Cluster
        1) speedometer
        2) fuel gauge
        3) turn signal indicators
        4) tachometer
    Name 3 things you can do with the:   Instrument Cluster
        1) visualise the car's travelling speed 
        2) visualise the engine's rpm
        3) visualize the amount of fuel within the car's tank
    
Sub Object 3: Environment Controls
    Name 3 things you'll find on the:    Environment Controls
        1) air conditioner 
        2) temperature
        3) air circulation       
    Name 3 things you can do with the:   Environment Controls
        1) switch on the air conditioner 
        2) set the internal temperature
        3) choose air circulation modes

Sub Object 4: Infotainment System
    Name 3 things you'll find on the:    Infotainment System
        1) radio
        2) bluetooth
        3) navigator 
    Name 3 things you can do with the:   Infotainment System
        1) selct a radio to listen to
        2) set up a bluetooth device
        3) acess the navigation system

Sub Object 5: Seat 
    Name 3 things you'll find on the:    Seat
        1) reclainer 
        2) legs spacer
        3) warmer 
    Name 2 things you can do with the:   Seat
        1) adujus the reclainer's angle
        2) set the seat's tempurature
*/

/*
Part 1b
Now you have some basic understanding of how to think of an object 
in terms of its sub-objects.

Next, write 4 un-related UDTs in plain english:
*/
/*
 example:  
 
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - the amount of water used per week.
        - amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior

    Notice that I did not use "has a vacuum cleaner" or "Has 
    eco-friendly cleaning supplies" as one of the properties.
    
    Writing 'has a ___" checks whether or not your object **has the 
    ability to do something**.
    Instead, I wrote "number of vacuum cleaners" and "number of 
    eco-friendly cleaning supplies".  
    
    These are specific objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' 
    (has a) as a member variable type.
    Instead, prefer the other primitive types.

    In addition to the usual primitives (covered in Project 2), you 
    can use 'std::string' to represent strings in this project.
 */
/*
Part 1b Assignment:
1)  Fill in the 4 UDTs below with a random UDT in plain english.
    These 4 UDTs do not need to be related.
        a) For each plain-english UDT, write out 5 traits or 
        properties and 3 things it can do.
        b) remember: these properties will eventually become
        primitives.
        c) pick properties that can eventually be represented with 
        'int float double bool char std::string'.
*/

/*
Thing 1:  Midi Controller
    5 properties:
        - number of encorders
        - number of MIDI modes 
        - number of presets
        - MIDI message type
        - MIDI connection type
    3 things it can do:
        - send out Control Changes
        - change between MIDI modes
        - save user custom presets

Thing 2:  Effects Pedal
    5 properties:
        - number of effects modules
        - number of modes for signal processing
        - number of controls
        - number of inputs
        - number of outputs
    3 things it can do:
        - load different effects type per module
        - process signal in-series or parallel 
        - custom assigning effect parameters to UI   

Thing 3:  AI Synth
    5 properties:
        - number of machine learning models
        - ammount of neural nodes
        - number of synthesis parameters
        - number of inputs
        - number of outputs
    3 things it can do:
        - train models via user-inputs
        - store machine learning models data
        - map model-data to the synthesiser parameters 

Thing 4:  Virtual Mic-pre 
    5 properties:
        - number of pre-amp models
        - number of circuit type
        - number of microprones 
        - ammount of storable presets
        - number of color schemes
    3 things it can do:
        - analog-vitrual emulation of mic pre-amps
        - choose between circuit and mic types
        - save user presets       
 */

 /*
Part 1c
You have just finished practicing writing out a UDT that is has 
5 properties and can perform 3 actions.  

Now you will write 1 UDT in plain english. 

This UDT will be different than the previous 4 you wrote: It will 
use UDTs to describe its 5 properties, as opposed to using C++ 
primitives to describe the 5 properties.

You will define these 5 'property' UDTs in Part 1d.
 */

 /*
Part 1c example:
    Cell Phone

    A Cell Phone is built using the following 5 UDTs:
        Display
        Memory
        CPU
        Radio
        Applications

    A Cell Phone has 3 things it can do:
        make a call
        send a text
        run an application.

    Notice that I did not use "has a display" or "Has memory" or 
    "has a cpu" as one of the properties of the CellPhone.
    
    Writing 'has a ___" checks whether or not your object **has 
    the ability to do something**.
    Instead, I wrote "Display" or "CPU".  These are specific 
    objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' 
    (has a) as a member variable type.
    Instead, prefer the other primitive types.

    When you choose your 5 smaller parts, remember that each of 
    these 5 Sub Objects will need to be defined with 5 primitive 
    properties and 3 actions EACH.
*/
/*
Part 1c assignment:
1) Fill in the 10th UDT below.
    Define an object that is made of 5 sub-objects.
    These parts will not be defined using Primitives, but instead 
    will be their own UDTs you'll define in Part 1d.

2) write the name of the primitive type you'll be using after each 
    property in UDTs 1-4:
    pick properties that can be represented with 
    'int float double bool char std::string'.
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            area in cm2 (int)
            brand (std::string)
*/

/*
Thing 10) ModDelay
5 properties:
    1) Dry_Wet ammount (float)
    2) Feedback ammount (flaot)
    3) Filter frequency (double)
    4) Lfo (int)
    5) Combo box (std::string)
3 things it can do:
    1) Modulate the delay time
    2) name and save presets
    3) filter the delay tap
 */

/*
Part 1d
You now know how to define a UDT that is composed of other UDT.
Now you will learn how to break down those sub-object UDTs into 
their 5 properties and 3 actions.

The goal of Part 1d is to get you to think about breaking down an 
object into smaller and smaller objects, until the smallest object 
is made of up only C++ primitives and std::string. 

Revisiting the previous example:  
Cell Phone

A Cell Phone is made up of the following 5 properties/sub-objects 
and 3 actions:
    Display
    Memory
    CPU
    Radio
    Applications
3 actions:
    make a call
    send a text
    run an application.

These 5 properties can be broken down into their own sub-objects 
and properties. 

If we break down the first property 'Display' into its 5 properties 
we get:
    brightness
    amount of power consumed.
    pixels
    width in cm
    height in cm

the Display's brightness can be represented with a Primitive, 
such as a double. 

The amount of power consumed can also be represented with a 
Primitive, such as a float or integer (i.e. 250mWa)

The 'pixels' property must be represented with an array of Pixel 
instances, as the screen has more than 1 row of pixels.
    Arrays have not been discussed and can't be used in this 
    project.
    Instead, we can use an Integer primitive to store the 
    Number of Pixels:

Display:
    Number of Pixels
    Amount of Power consumed (milliwatt-hours)
    Brightness
    width in cm
    height in cm

As you can see, the 'Display' UDT has been broken down to the 
point of being able to describe it with C++ primitives. 
*/

/*
Part 1d assignment:
1) Fill in #5 - #9 below with plain-english UDTs for the 5 
properties you created for UDT #10. 
    example: 
        If #10's first property was 'Engine', then `Thing 5)` 
        will be `Engine`. 
        You will need to provide 5 properties and 3 member 
        functions of that Engine object in plain English.
        Remember to pick properties that can be represented 
        with 'int float double bool char std::string'.

2) write the name of the primitive type you'll be using after 
each property for UDTs 5 - 9.
    You already did this for UDTs 1-4 in Part 1c.
    Pick properties that can be represented with 
    'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            width in cm (int)
            height in cm (int)
*/

/*
Thing 5) Dry_Wet ammount
5 properties:
    1) Mix range (float)
    2) Modulation ammount (int)
    3) MIDI cc range (double)
    4) UI control Type (std::string)
    5) Color scheme (double)
3 things it can do:
    1) process audio signal in parallel 
    2) can be controlled via extrenal MIDI cc
    3) custom UI settings
 */

/*
Thing 6) Combo box 
5 properties:
    1) Save (std::string)
    2) Load (std::string)
    3) Effect Mode (std::string)
    4) Create (std::string)
    5) Compare (int)
3 things it can do:
    1) Save plug-in presets 
    2) Load plug-in presets 
    3) Switch between effects types
 */

/*
Thing 7) Feedback ammount
5 properties:
    1) Feedback range (float)
    2) circuti mode (std::string)
    3) Modulation tagert (bool)
    4) UI control Type (std::string)
    5) Modulation range (int)
3 things it can do:
    1) send feedback ammout into distortion
    2) choose between digital and anolog circuit modes
    3) become a targer for modulation
 */

/*
Thing 8) Filter frequency
5 properties:
    1) High pass (double)
    2) Low pass  (double)
    3) Q (float)
    4) Shelve (int)
    5) Circuit mode (std::string)
3 things it can do:
    1) cut low frequency content 
    2) chage the eq's bandiwth 
    3) switch between analog or digital circuit modelling
 */

/*
Thing 9) Lfo 
5 properties:
    1) Waveforms (std::string)
    2) Range (int)
    3) Destinations (std::string)
    4) Rate (double)
    5) Target (bool)
3 things it can do:
    1) choose between different wave shapes
    2) modulate varius plug-in targets
    3) set the speed of the modulation
 */

/*
You've just defined 10 UDTs!
4 of them are unrelated (UDTs 1-4).
5 of them form the sub-objects that make up the 10th UDT. 

Move them below this block comment and put them in numerical order 
(1 - 10).

The next thing that will happen is that I will review the 
pseudo-code that you have written.
Send me a DM to review your pull request when the project is ready for review.

Thing 1)  Midi Controller
5 properties:
    - number of encorders
    - number of MIDI modes 
    - number of presets
    - MIDI message type
    - MIDI connection type
3 things it can do:
    - send out Control Changes
    - change between MIDI modes
    - save user custom presets

Thing 2)  Effects Pedal
5 properties:
    - number of effects modules
    - number of modes for signal processing
    - number of controls
    - number of inputs
    - number of outputs
3 things it can do:
    - load different effects type per module
    - process signal in-series or parallel 
    - custom assigning effect parameters to UI   

Thing 3)  AI Synth
5 properties:
    - number of machine learning models
    - ammount of neural nodes
    - number of synthesis parameters
    - number of inputs
    - number of outputs
3 things it can do:
     - train models via user-inputs
     - store machine learning models data
     - map model-data to the synthesiser parameters 

Thing 4:  Virtual Mic-pre 
5 properties:
     - number of pre-amp models
     - number of circuit type
     - number of microprones 
     - ammount of storable presets
     - number of color schemes
3 things it can do:
    - analog-vitrual emulation of mic pre-amps
     - choose between circuit and mic types
     - save user presets   

Thing 5) ModDelay
5 properties:
    1) Dry_Wet ammount (float)
    2) Feedback ammount (flaot)
    3) Filter frequency (double)
    4) Lfo (int)
    5) Combo box (std::string)
3 things it can do:
    1) Modulate the delay time
    2) name and save presets
    3) filter the delay tap

Thing 6) Dry_Wet ammount
5 properties:
    1) Mix range (float)
    2) Modulation ammount (int)
    3) MIDI cc range (double)
    4) UI control Type (std::string)
    5) Color scheme (double)
3 things it can do:
    1) process audio signal in parallel 
    2) can be controlled via extrenal MIDI cc
    3) custom UI settings

Thing 7) Combo box 
5 properties:
    1) Save (std::string)
    2) Load (std::string)
    3) Effect Mode (std::string)
    4) Create (std::string)
    5) Compare (int)
3 things it can do:
    1) Save plug-in presets 
    2) Load plug-in presets 
    3) Switch between effects types

Thing 8) Feedback ammount
5 properties:
    1) Feedback range (float)
    2) circuti mode (std::string)
    3) Modulation tagert (bool)
    4) UI control Type (std::string)
    5) Modulation range (int)
3 things it can do:
    1) send feedback ammout into distortion
    2) choose between digital and anolog circuit modes
    3) become a targer for modulation

Thing 9) Filter frequency
5 properties:
    1) High pass (double)
    2) Low pass  (double)
    3) Q (float)
    4) Shelve (int)
    5) Circuit mode (std::string)
3 things it can do:
    1) cut low frequency content 
    2) chage the eq's bandiwth 
    3) switch between analog or digital circuit modelling

Thing 10) Lfo 
5 properties:
    1) Waveforms (std::string)
    2) Range (int)
    3) Destinations (std::string)
    4) Rate (double)
    5) Target (bool)
3 things it can do:
    1) choose between different wave shapes
    2) modulate varius plug-in targets
    3) set the speed of the modulation

*/

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
