/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};

/*
Thing 1)  Midi Controller
5 properties:
    - number of encorders (int)
    - number of MIDI modes  (int)
    - number of presets (int)
    - MIDI message type (std::string)
    - MIDI connection type (std::string)
3 things it can do:
    - send out Control Changes
    - change between MIDI modes
    - save user custom presets

Thing 2)  Effects Pedal
5 properties:
    - number of effects modules (int)
    - number of modes for signal processing (int)
    - number of controls (double)
    - number of inputs (int)
    - number of outputs (int)
3 things it can do:
    - load different effects type per module
    - process signal in-series or parallel 
    - custom assigning effect parameters to UI   

Thing 3)  AI Synth
5 properties:
    - type of machine learning models (std::string)
    - ammount of neural nodes (double)
    - number of synthesis parameters (int)
    - number of inputs (int)
    - number of outputs (int)
3 things it can do:
     - train models via user-inputs
     - store machine learning models data
     - map model-data to the synthesiser parameters 

Thing 4:  Virtual Mic-pre 
5 properties:
     - number of pre-amp models (int)
     - number of circuit type (double)
     - number of microprones (int)
     - ammount of storable presets (int)
     - type of color schemes (std::string)
3 things it can do:
    - analog-vitrual emulation of mic pre-amps
     - choose between circuit and mic types
     - save user presets   

Thing 5) ModDelay
5 properties:
    1) Dry_Wet ammount (float)
    2) Feedback ammount (float)
    3) Filter frequency (double)
    4) Lfo (int)
    5) Combo box (std::string)
3 things it can do:
    1) Modulate the delay time
    2) name and save presets
    3) filter the delay tap

Thing 6) Wet/Dry Control Widget 
5 properties:
    1) Dry/Wet ammount(float)
    2) Modulation ammount (int)
    3) MIDI cc range (double)
    4) UI control Type (std::string)
    5) Color scheme (double)
3 things it can do:
    1) process audio signal in parallel 
    2) can be controlled via extrenal MIDI cc
    3) custom UI settings

Thing 7) Control panel 
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

Thing 8) Feedback Control Widget
5 properties:
    1) Feedback ammount (float)
    2) circuti mode (std::string)
    3) Modulation tagert (bool)
    4) UI control Type (std::string)
    5) Modulation range (int)
3 things it can do:
    1) send feedback ammout into distortion
    2) choose between digital and anolog circuit modes
    3) become a targer for modulation

Thing 9) Filter Control Widget
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

Thing 10) Performance Rack 
5 properties:
    1) Control Panel
    2) Midi Controller
    3) AI Synth
    4) Virtual Mic-pre
    5) ModDelay
3 things it can do:
    1) Save and Load presets
    2) Combine instruments and effects chains
    3) Can be controlled via MIDI cc

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
