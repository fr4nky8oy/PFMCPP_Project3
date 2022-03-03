/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.



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

void MidiController::saveUserPreset(ControllerType slide, int touchEncoders, bool automationWrite, std::string skinColor)
{
    slide.model = "Push2";
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
    std::string comboBox = "saveUs";

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
    comboBox = labelMePlease + "My ModDelay";
    
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
    std::string savePreset = "Save New";
    std::string loadPreset = "Load Preset";
    std::string effectMode = "Multi Effect";
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
        savePreset = fileExtension + effectMode + createUserType;
    }
    
}

int ControlPanel::loadFromUserFolder(std::string fileCategory, int presetValue)
{
    ++presetValue;
    int compareLastSaved =+ presetValue;
    loadPreset = fileCategory + effectMode;
    
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
    ++feedItBackIn;
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
    float qRange = 1.0f;
    int shelveAvailable = 2;
    std::string britishMode = "NEVE";

    float removeLowFreqContent(std::string filterType = "HighPass", bool secondOrderFilter = true, double rumbleRange = 10.90);
    int changeQBandwidth(int resonanceWidth = 4, bool fullyParametricMode = true);
    void processViaVintageOrModern(std::string harmonicColoration = "Retro", int componentType = 2);
};

float FilterControlWidget::removeLowFreqContent(std::string filterType, bool secondOrderFilter, double rumbleRange)
{
    if(secondOrderFilter == true)
    {
        highPassFilter = rumbleRange;
        britishMode = filterType + "Cut";
    }   
    return 50.0f;
}

int FilterControlWidget::changeQBandwidth(int resonanceWidth, bool fullyParametricMode)
{
    if(fullyParametricMode == true)
    {
        ++qRange;
        resonanceWidth = 1;
    }   
    return 1;
}

void FilterControlWidget::processViaVintageOrModern(std::string harmonicColoration, int componentType)
{
    britishMode = harmonicColoration + "Custom74";
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
    Example::main();
    
    
    std::cout << "good to go!" << std::endl;
}
