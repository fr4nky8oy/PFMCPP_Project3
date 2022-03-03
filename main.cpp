 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person
{
    int age;
    int height;
    float hairLenght;
    float GPA;
    unsigned int SATScore; 
    int distanceTraveled;

    struct Foot
    {
        int acceleration = 5;
        int stepLength = 1;
        int numOfSteps = 0;
        
        void stepForward();
        int stepSize();
        
    };

    Foot leftFoot;
    Foot rightFoot;

    void run(int howFast, bool startWithLeftFoot);
}; 

void Person::Foot::stepForward()
{
    ++acceleration;
    ++numOfSteps;
}

int Person::Foot::stepSize()
{
    return stepLength;
}


void Person::run(int howFast, bool startWithLeftFoot) 
{ 
    if( startWithLeftFoot)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }

    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
    howFast = leftFoot.numOfSteps + rightFoot.numOfSteps + distanceTraveled;
}    
 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */
struct MidiController 
{
    int numEncoders = 10;
    int numMidimodes = 2;
    int numPresets = 100;
    std::string midiMode = "Note"; 
    std::string midiConnect = "USB"; 
    
    struct ControllerType
    {
        std::string model = "MPK10"; 
        bool keyboardMode = false;
        bool afterTouchisPoly = true;
        int triggerPads = 10;
        float velocityRange = 0.1f;

        void loadUserKeyboard(bool velocitySensKeys = true, int octRange = 4);
        void setNumKeysInOctave (int whiteKeys = 7, int blackKeys = 5);
        void setVelocityRangeForKeys(float pressureDown = 0.1f, std::string = "noteOn"); 
        
    }; 

    int txConChange(std::string midiMode = "label", bool tranmistMessage = true, int paramValue = 3);
    void changeMidiMode(std::string = "play", int channelOut = 10, bool noteSend = true); 
    void saveUserPreset(ControllerType KeysSlide, int touchEncoders = 3, bool automationWrite = true, std::string = "skinColor");

    ControllerType userPerformReady;
};

void MidiController::ControllerType::setNumKeysInOctave(int whiteKeys, int blackKeys)
{
    triggerPads = whiteKeys + blackKeys;
}

void MidiController::ControllerType::loadUserKeyboard(bool velocitySensKeys, int octRange)
{
    if(velocitySensKeys)
    {
        afterTouchisPoly = true;
        octRange = velocitySensKeys * octRange;
    }
    else
    {
        afterTouchisPoly = false; 
    }        
}

void MidiController::ControllerType::setVelocityRangeForKeys(float pressureDown, std::string miniKeys)
{
    pressureDown = velocityRange;
    model = miniKeys; 
}

int MidiController::txConChange(std::string filter, bool tranmistMessage, int paramValue)
{
    midiMode = filter;
    if(tranmistMessage == true)
    {   
        paramValue = 14;  
    }
   
    return numPresets;
}

void MidiController::changeMidiMode(std::string play, int channelOut, bool noteSend)
{
    if(noteSend == true)
    {
        midiMode = play; 
        channelOut = 1;  
    }
    else
    {
        midiMode = "noPlay"; 
        channelOut = 1;
    }  
}

void MidiController::saveUserPreset(ControllerType Slide, int touchEncoders, bool automationWrite, std::string skinColor)
{
    Slide.model = "Push2";
    if(automationWrite == true)
    {
        touchEncoders = 1;
        skinColor = "red";
    }
    else
    {
        touchEncoders = 1;
        skinColor = "green";  
    }      
}

struct  EffectsPedal
{
    int numEfxModules = 5;
    int numSigProcessMod = 2;
    double numControls = 5.2;
    int inNum = 4;
    int outNum = 4;

    void loadDiffEfxPerModule(bool chainAisActive = true, std::string = "slotA", int efxTypeSingle = 1);
    void processInSeriesOrParallel(std::string series, int mixSendAmmount = 100);
    int assignEfxParamsToUi(int ecordersNumUI = 5, float encoderRangeUI = 1.0f, std::string = "layoutUI");    
};

void EffectsPedal::loadDiffEfxPerModule(bool chainAisActive, std::string slotA, int efxTypeSingle)
{
    if(chainAisActive == true)
    { 
        slotA = "Bus1";
        efxTypeSingle = 1;         
    }
    else 
    {
        slotA = "Empty";   
    }    
}

void EffectsPedal::processInSeriesOrParallel(std::string series, int mixSendAmmount)
{
    if (mixSendAmmount > 99)
    {
        numSigProcessMod = 2;
        series = "In Parallel Mode";
    }
    else
    {
        numSigProcessMod = 1;
        series = "In Series Mode";
    }         
}

int EffectsPedal::assignEfxParamsToUi(int ecordersNumUI, float encoderRangeUI, std::string layoutUI)
{
    layoutUI = "User Type" + layoutUI;
    numControls = ecordersNumUI + numEfxModules; 
    outNum = inNum *= encoderRangeUI; 

    return numEfxModules;
}

struct AISynth
{
    std::string miModel = "NearestN";
    double numNNodes = 20.2;
    int synthParamNum = 10;
    int inputNumSynth = 2;
    int outputNumSynth = 2;

    struct Synthesis
    {
        int typeOfSynthesis = 4;
        int waveShapes = 4;
        std::string modMatrix = "ModPanel";
        std::string tuning = "Concert Pitch";
        float touchStrip = 0.9f;

        void useSubSynthForSoundDesign(std::string subtractive, int waveTone = 1);
        std::string fineTuningAllOsc(double oscAll = 4.40, bool a4isPressed = true);
        void lowPassFilterSignal(bool filterIsLowPass = true, float cutOffRange = 0.2f);
    };

    void trainModel(Synthesis aNewSynth, std::string mlModel, int learnFeatures = 8);    
    int storeFeatInputs(int features = 10, float xyzValues = 1.0, bool isRecorded = true);
    void mapModelToSynth(bool mapModeisActive = true, bool modelLoaded = true, int targetParams = 10);

    Synthesis SythesisModel;
};

void AISynth::Synthesis::useSubSynthForSoundDesign(std::string subtractive, int waveTone)
{ 
    modMatrix = "Sources and Tagerts" + subtractive;
    typeOfSynthesis += waveShapes + waveTone; 
}

std::string AISynth::Synthesis::fineTuningAllOsc(double oscAll, bool a4isPressed)
{
    if(a4isPressed == true)
    {
        oscAll = 440.0; 
    }
    else 
    {
        touchStrip = 440.0;
    }    
    return "Concert Pitch";
}

void AISynth::Synthesis::lowPassFilterSignal(bool filterIsLowPass, float cutOffRange)
{
   if(filterIsLowPass == true)
    {
        cutOffRange = 90.0f; 
    } 
}

void AISynth::trainModel(Synthesis aNewSynth, std::string mlModel, int learnFeatures)
{
    aNewSynth.typeOfSynthesis = inputNumSynth + learnFeatures;
    mlModel = "NearestN";  
}

int AISynth::storeFeatInputs(int features, float xyzValues, bool isRecorded)
{
    if(isRecorded == true)
    {
        synthParamNum += features / xyzValues;
    }
    return outputNumSynth;
}

void AISynth::mapModelToSynth(bool mapModeisActive, bool modelLoaded, int targetParams)
{
    if(mapModeisActive && modelLoaded == true)
    {
        targetParams = synthParamNum;
    }
}

struct  VirtualMicPre
{
     int numPreAmpMod = 10;
     double numCircType = 21.0;
     int numOfMics = 20;
     int numOfUserPresets = 127;
     std::string colorMe = "AbbeyClassic";

     void loadVirtualAnalogPreAmp(bool latencyZeroMode = true, std::string micModel = "Akg");
     int combineCircuitAndMicType(std::string polarPattern, int phantomPower = 48);
     void saverMicAndPreAmpPreset(double circuitAndMic = 1.1, std::string vocalSetUp = "VoxLead");
};

struct ModDelay
{
    float modDelaydryWet = 0.5f;
    float feedBack = 0.9f;
    double filterFreq = 12.20; 
    int lfoRate = 1;
    std::string ComboBox = "SaveUs";

    float modulateDelayTime(int tapSignals = 2, float delTimeMs = 20.0f, std::string lfoShapeWave = "sine");
    int saveModDelayPreset(int paramToSave = 10, std::string labelMePlease = "TapeSpace");
    void filterDelayTap (bool delayIsStereo = true, std::string filterType = "Notch");
};

float ModDelay::modulateDelayTime(int tapSignals, float delTimeMs, std::string lfoShapeWave)
{
    lfoShapeWave = "sine";
    tapSignals = 2;
    modDelaydryWet = delTimeMs + feedBack;
    
    return modDelaydryWet; 
}

int ModDelay::saveModDelayPreset(int paramToSave, std::string labelMePlease)
{
    int userPresetModDelNum = paramToSave;
    ComboBox = labelMePlease + "My ModDelay";
    
    return userPresetModDelNum;
}

void ModDelay::filterDelayTap(bool delayIsStereo, std::string filterType)
{
    if(delayIsStereo == true)
    {
        filterType = "M/S";
        filterFreq = 110.300;
    }
}

struct  WetDryControlWidget 
{
    float dryWetAmmout = 0.1f;
    int modAmmount = 1; 
    double midiCCrange = 12.70;
    std::string uiControlType = "Vertical Slider"; 
    double colorSchemeToAssign = 23.30;

    void processSignalInParallel(bool isBusInputActive = true, float bus1Ammount = 3.0f);
    void learnExternalMidi(std::string midiRxPort = "USB", int midiRxCC = 20, bool parameterLearned = true);
    int saevCustomUISettins(int paramsToInclude = 10, bool includeSliders = false);
};

void WetDryControlWidget::processSignalInParallel(bool isBusInputActive, float bus1Ammount)
{
    if(isBusInputActive == true)
    {
        bus1Ammount += dryWetAmmout;
    }
    
}

void WetDryControlWidget::learnExternalMidi(std::string midiRxPort, int midiRxCC, bool parameterLearned)
{
    if(parameterLearned == true)
    {
        midiRxPort = "Reciving";
        midiRxCC += midiCCrange;
    }
    
}

int WetDryControlWidget::saevCustomUISettins(int paramsToInclude, bool includeSliders)
{
    int totParamsToInclude = ++paramsToInclude;
    includeSliders = true;

    return totParamsToInclude;
}

struct ControlPanel 
{
    std::string SavePreset = "Save New";
    std::string LoadPreset = "Load Preset";
    std::string EffectMode = "Multi Effect";
    std::string createUserType = "Mode A";
    int switchPresetToCompare = 1; 

    void saveToUserFolder(std::string fileExtension = "Cpx", bool paramsAreSaved = true);
    int loadFromUserFolder(std::string fileCategory = "Bassline", int presetValue = 10);
    int switchEffectsTypes(int loadA = 0, int loadB = 1);
};


void ControlPanel::saveToUserFolder(std::string fileExtension, bool paramsAreSaved)
{
    if(paramsAreSaved == true)
    {
        SavePreset = fileExtension + EffectMode + createUserType;
    }
    
}

int ControlPanel::loadFromUserFolder(std::string fileCategory, int presetValue)
{
    ++presetValue;
    int compareLastSaved =+ presetValue;
    LoadPreset = fileCategory + EffectMode;
    
    return compareLastSaved;
}

int ControlPanel::switchEffectsTypes(int loadA, int loadB)
{
    if(loadA > 0)
    {
        switchPresetToCompare = loadB;
    } 
    
    return 1;
}

struct FeedbackControlWidget
{
    float feedBackAmmount = 1.0;
    std::string circutiModeToUse = "Digital"; 
    bool canBeModulated = true;
    std::string uiControlToUse = "Rotary";
    int modRangAvailable = 100;

    void sendFeedbackinDistortion(float feedItBackIn = 1.1f, bool isExcedingLimit = true, std::string warningOn = "RockOn");
    int processFeedbackMode(std::string feebackType = "Dub Classic", int loadSoundReference = 3);
    void becomeModTarget(bool parameterIsVisisble = true, std::string mappingMode = "Bypolar");
};

void FeedbackControlWidget::sendFeedbackinDistortion(float feedItBackIn, bool isExcedingLimit, std::string warningOn)
{
    feedItBackIn = ++feedItBackIn;
    if(isExcedingLimit == true)
    {
        warningOn = "Clipping";   
    }    
}

int FeedbackControlWidget::processFeedbackMode(std::string feebackType, int loadSoundReference)
{
    circutiModeToUse = feebackType + uiControlToUse;
    loadSoundReference = modRangAvailable += loadSoundReference;
    
    return loadSoundReference;
}

void FeedbackControlWidget::becomeModTarget(bool parameterIsVisisble, std::string mappingMode)
{
    if(parameterIsVisisble == true)
    {
        uiControlToUse = circutiModeToUse + mappingMode;
    }
}

struct FilterControlWidget
{
    double highPassFilter = 67.00;
    double lowPassFilter = 40.20;
    float Qrange = 1.0f;
    int shelveAvailable = 2;
    std::string BritishMode = "NEVE";

    float removeLowFreqContent(std::string filterType = "HighPass", bool secondOrderFilter = true, double rumbleRange = 10.90);
    int changeQBandwidth(int resonanceWidth = 4, bool fullyParametricMode = true);
    void processViaVintageOrModern(std::string harmonicColoration = "Retro", int componentType = 2);
};

float FilterControlWidget::removeLowFreqContent(std::string filterType, bool secondOrderFilter, double rumbleRange)
{
    if(secondOrderFilter == true)
    {
        highPassFilter = rumbleRange;
        BritishMode = filterType + "Cut";
    }   
    return 50.0f;
}

int FilterControlWidget::changeQBandwidth(int resonanceWidth, bool fullyParametricMode)
{
    if(fullyParametricMode == true)
    {
        ++Qrange;
        resonanceWidth = 1;
    }   
    return 1;
}

void FilterControlWidget::processViaVintageOrModern(std::string harmonicColoration, int componentType)
{
    BritishMode = harmonicColoration + "Custom74";
    shelveAvailable += componentType;
}

struct PerformanceRack 
{
    ModDelay modDelay;
    WetDryControlWidget wetdryControlWidget;
    ControlPanel controlOPanel;
    FeedbackControlWidget feedbackControlWidget;
    FilterControlWidget filterControlWidget;

    void savePerformanceRack(ModDelay modDelayA, bool saveToUserFolder = true);
    int mergeInstrAndEfxInRack(ControlPanel instrumentsToLoad, int effectsToLoad = 3);
    void controlRackParamsViaMidiCC(FilterControlWidget orizSlider, FeedbackControlWidget vertSlider);
};

void PerformanceRack::savePerformanceRack(ModDelay modDelayA, bool saveToUserFolder)
{
    if(saveToUserFolder == true)
    {  
        modDelayA.saveModDelayPreset();
    }    
}

int PerformanceRack::mergeInstrAndEfxInRack(ControlPanel instrumentsToLoad, int effectsToLoad)
{
    return instrumentsToLoad.loadFromUserFolder() + effectsToLoad;   
}

void controlRackParamsViaMidiCC(FilterControlWidget orizSlider, FeedbackControlWidget vertSlider)
{
    orizSlider.removeLowFreqContent();
    vertSlider.sendFeedbackinDistortion();
}
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
