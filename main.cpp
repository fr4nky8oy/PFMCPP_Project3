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

struct MidiController 
{
    // number of encorders
    int numEncoders = 10;
    // number of MIDI modes  (int)
    int numMidimodes = 2;
    // number of presets
    int numPresets = 100;
    // MIDI message type
    std::string midiMode = "Note"; 
    // MIDI connection type 
    std::string midiConnect = "USB"; 
    
    struct ControllerType
    {
        //controller model
        std::string model = "MPK10"; 
        //cotroller mode
        bool keyboardMode = false;
        //poly aftertouch mode
        bool afterTouchisPoly = true;
        // number of trigger pads
        int triggerPads = 10;
        // velocity responsivness range
        float velocityRange = 0.1f;

        // the midi controller can be used as a keyboard
        void loadUserKeyboard (bool velocitySensKeys = true, int octRange = 4);
        // set the number of keys in an octave
        int setNumKeysInOctave (int whiteKeys = 7, int blackKeys = 5);
        //set the velocity range for a particular key
        void setVelocityRangeForKeys(float pressureDown = 0.1f, std::string = "noteOn");   
    }; 

    // send out Control Changes
    int txConChange(std::string = "label", bool tranmistMessage = true, int paramValue = 3);
    // change between MIDI modes
    void changeMidieMode(std::string = "play", int channelOut = 10, bool noteSend = true); 
    // save user custom presets
    void saveUserPreset(ControllerType KeysSlide, int touchEncoders = 3, bool automationWrite = true, std::string = "skinColor");

    ControllerType userPerformReady;
};

struct  EffectsPedal
{
    // number of effects modules
    int numEfxModules = 5;
    // number of modes for signal processing
    int numSigProcessMod = 2;
    // number of controls
    double numControls = 5.2;
    // number of inputs
    int inNum = 4;
    // number of outputs
    int outNum = 4;

    // load different effects type per module
    void loadDiffEfxPerModule(bool chainAisActive = true, std::string = "slotA", int efxTypeSingle = 1);
    // process signal in-series or parallel 
    void processInSeriesOrParallel(std::string series, int mixSendAmmount = 100);
    // custom assigning effect parameters to UI
    int assignEfxParamsToUi(int ecordersNumUI = 5, float encoderRangeUI = 1.0f, std::string = "layoutUI");    
};

struct AISynth
{
    // type of machine learning models (std::string)
    std::string miModel = "NearestN";
    // ammount of neural nodes
    double numNNodes = 20.2;
    // number of synthesis parameters (int)
    int synthParamNum = 10;
    // number of inputs
    int inputNumSynth = 2;
    // number of outputs
    int outputNumSynth = 2;

    struct Synthesis
    {
        // synthesis methods
        int typeOfSynthesis = 4;
        // type of waveforms 
        int waveShapes = 4;
        // modulations router 
        std::string modMatrix = "ModPanel";
        // digital controlled via an operating system 
        double osVersion = 2.1;
        // pressure sensor strip
        float touchStrip = 0.9f;

        // using subtractive synthesis for sound design 
        void useSubSynthForSoundDesign(std::string subtractive, int waveTone = 1);
        // fine tuning all the oscillators
        float fineTuningAllOsc(double oscAll = 4.40, bool a4isPressed = true);
        // low pass filtering the signal
        int lowPassFilterSignal(bool filterIsLowPass = true, float cutOffRange = 0.2f);
    };

     // train models via user-inputs
     void trainModel(Synthesis aNewSynth, std::string mlModel, int learnFeatures = 8);    
     // store machine learning models data
     int storeFeatInputs(int features = 10, float xyzValues = 1.0, bool isRecorded = true);
     // map model-data to the synthesiser parameters 
     void mapModelToSynth(bool mapModeisActive = true, bool modelLoaded = true, int targetParams = 10);

    Synthesis SythesisModel;
};

struct  VirtualMicPre
{
     // number of pre-amp models (int)
     int numPreAmpMod = 10;
     // number of circuit type (double)
     double numCircType = 21.0;
     // number of microprones (int)
     int numOfMics = 20;
     // ammount of storable presets (int)
     int numOfUserPresets = 127;
     // type of color schemes (std::string)
     std::string colorMe = "AbbeyClassic";

     // load an analog-vitrual pre-amp
     void loadVirtualAnalogPreAmp(bool latencyZeroMode = true, std::string micModel = "Akg");
     // combine circuit and mic types
     int combineCircuitAndMicType(std::string polarPattern, int phantomPower = 48);
     // save Mic and Pre-amp preset
     void saverMicAndPreAmpPreset(double circuitAndMic = 1.1, std::string vocalSetUp = "VoxLead");
};

struct ModDelay
{
    // Dry_Wet ammount 
    float modDelaydryWet = 0.5f;
    // Feedback ammount 
    float feedBack = 0.9f;
    // Filter frequency
    double filterFreq = 12.20; 
    // lfo
    int lfoRate = 1;
    // Combobox 
    std::string ComboBox = "SaveUs";

    // Modulate the delay time
    float modulateDelayTime(int tapSignals = 2, double delTimeMs = 20.10, std::string lfoShapeWave = "sine");
    // save a ModDealy preset
    int saveModDelayPreset(int paramToSave = 10, std::string labelMePlease = "TapeSpace");
    // filter the delay tap
    void filterDelayTap (bool delayIsStereo = true, std::string filterType = "Notch");
};

struct  WetDryControlWidget 
{
    // Dry/Wet ammount(float)
    float dryWetAmmout = 0.1f;
    // Modulation ammount (int)
    int modAmmount = 1; 
    // MIDI cc range (double)
    double midiCCrange = 12.70;
    // UI control Type (std::string)
    std::string uiControlType = "Vertical Slider"; 
    // Color scheme (double)
    double colorSchemeToAssign = 23.30;

    // process audio signal in parallel 
    void processSignalInParallel(bool isBusInputActive = true, float bus1Ammount = 3.0f);
    // can be controlled via extrenal MIDI cc
    void learnExternalMidi(std::string midiRxPort = "USB", int midiRxCC = 20, bool parameterLearned = true);
    // save custom UI settings
    int saevCustomUISettins(int paramsToInclude = 10, bool includeSliders = false);
};

struct ControlPanel 
{
    // Save (std::string)
    std::string SavePreset = "Save New";
    // Load 
    std::string LoadPreset = "Load Preset";
    // Effect Mode 
    std::string EffectMode = "Multi Effect";
    // Create 
    std::string createUserType = "Mode A";
    // Compare
    int switchPresetToCompare = 2; 

    // Save plug-in presets 
    void saveToUserFolder(std::string fileExtension = "Cpx", bool paramsAreSaved = true);
    // Load plug-in presets 
    int loadFromUserFolder(std::string fileCategory = "Bassline", int presetValue = 10);
    // Switch effects types
    int switchEffectsTypes(int loadA = 0, int loadB = 1);
};

struct FeedbackControlWidget
{
    // Feedback ammount 
    float feedBackAmmount = 1.0;
    // circuti mode 
    std::string circutiModeToUse = "Digital"; 
    // Modulation tagert (
    bool canBeModulated = true;
    // UI control Type (std::string)
    std::string uiControlToUse = "Rotary";
    // Modulation range (int)
    int modRangAvailable = 100;

    // send feedback ammout into distortion
    void sendFeedbackinDistortion(float feedItBackIn = 1.1f, bool isExcedingLimit = true, std::string warningOn = "RockOn");
    // process feedback signal using digital or anolog mode
    int processFeedbackMode(std::string feebackType = "Dub Classic", int loadSoundReference = 3);
    // become a target for modulation
    void becomeModTarget(bool parameterIsVisisble = true, std::string mappingMode = "Bypolar");
};

struct FilterControlWidget
{
    // High pass
    double highPassFilter = 67.00;
    // Low pass 
    double lowPassFilter = 40.20;
    // Q
    float Qrange = 1.0f;
    // Shelve
    int shelveAvailable = 2;
    // Circuit mode 
    std::string BritishMode = "NEVE";

    // remove low frequency content 
    float removeLowFreqContent(std::string filterType = "HighPass", bool secondOrderFilter = true, double rumbleRange = 10.90);
    // change the eq's bandwidth 
    int changeQBandwidth(int resonanceWidth = 4, bool fullyParametricMode = true);
    // process the singnal via a Vintage or Modern circuit modelling
    void processViaVintageOrModern(std::string harmonicColoration = "Retro", int componentType = 2);
};

struct PerformanceRack 
{
    // Control Panel
    int controlPanel = 1;
    // MidiController
    bool MidiCompatible = true;
    // AISynth
    int machineLearningModels = 10;
    // Virtual Mic-pre
    std::string MicAndPreAmps = "Virtual Studio";
    // ModDelay
    int efxCombinations = 8;

    // Save Performance Rack presets
    void savePerformanceRack(std::string userPerformanceRack = "New Rack", bool saveToUserFolder = true);
    // merge instruments and effects into a rack
    int mergeInstrAndEfxInRack(int instrumentsToLoad = 1, int effectsToLoad = 3);
    // control rack parameters via MIDI cc
    void controlRackParamsViaMidiCC(bool isRackVisible = true, int midiChannel = 1);
};

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
