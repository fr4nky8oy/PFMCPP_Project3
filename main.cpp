/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable that IS NOT initialized in-class
    float b { 2.f }; //a member variable that IS initialized in-class
    UDT() : a(0) { } // 'constructor-initializer-list' initializing the member that wasn't initialized in-class.
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //2) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()


struct MidiController 
{
    int numEncoders = 10;
    int numMidimodes = 2;
    int numPresets = 100;
    std::string midiMode = "Note"; 
    std::string midiConnect = "USB";
    MidiController(); 

    struct ControllerType
    {
        std::string model = "MPK10"; 
        bool keyboardMode = false;
        bool afterTouchisPoly = false;
        int triggerPads = 10;
        float velocityRange = 0.1f;
        ControllerType();

        void loadUserKeyboard(bool velocitySensKeys = true, int octRange = 4);
        void setNumKeysInOctave (int whiteKeys = 7, int blackKeys = 5);
        void setVelocityRangeForKeys(float pressureDown = 0.1f, std::string = "noteOn"); 
        
    }; 

    int txConChange(std::string midiMode = "label", bool tranmistMessage = true, int paramValue = 3);
    void changeMidiMode(std::string = "play", int channelOut = 10, bool noteSend = true); 
    void saveUserPreset(std::string = "KeysSlide", int touchEncoders = 3, bool automationWrite = true, std::string = "skinColor");

    ControllerType userPerformReady;
};

MidiController::MidiController()
{
    std::cout << "MidiController being constructed!" << std::endl;
}    

MidiController::ControllerType::ControllerType()
{
    std::cout << "ControllerType::ControllerType being constructed!" << std::endl;
} 

void MidiController::ControllerType::setNumKeysInOctave(int whiteKeys, int blackKeys)
{
    triggerPads = whiteKeys + blackKeys;
    std::cout << "MidiController::ControllerType::setNumKeysInOctave(): " << triggerPads << std::endl;
}

void MidiController::ControllerType::loadUserKeyboard(bool velocitySensKeys, int octRange)
{
    if(velocitySensKeys)
    {
        afterTouchisPoly = true;
        octRange = 4;
    }
    else
    {
        afterTouchisPoly = false;      
    }    
    std::cout << "MidiController::ControllerType::loadUserKeyboarde() After Touch is Active ?: " << (afterTouchisPoly == 0 ? "Yes" : "No") << std::endl;
}

void MidiController::ControllerType::setVelocityRangeForKeys(float pressureDown, std::string miniKeys)
{
    velocityRange /= pressureDown * 1000.0f;
    model = miniKeys; 
    std::cout << "MidiController::ControllerType::setVelocityRangeForKeys(): " << pressureDown << " , " << miniKeys << std::endl;
}

int MidiController::txConChange(std::string filter, bool tranmistMessage, int paramValue)
{
    midiMode = filter;
    if(tranmistMessage == true)
    {   
        paramValue = 14;
        
    }
    std::cout << "MidiController::txConChange() tranmistMessage : " << midiMode << " , " << paramValue << std::endl;
    
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
    std::cout << "MidiController::changeMidiMode() What's the current Midi Mode and Channel?: " << (noteSend == 1 ? "Play" : "noPlay") << " , " << channelOut << std::endl;
}

void MidiController::saveUserPreset(std::string KeysSlide, int touchEncoders, bool automationWrite, std::string skinColor)
{
    KeysSlide = "Push2";
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
    std::cout << "MidiController::saveUserPreset() Encoder Automation Status: " << (automationWrite == true ? "red" : "green") << " , " << touchEncoders << " , " << KeysSlide <<  std::endl;   
}

struct  EffectsPedal
{
    int numEfxModules = 5;
    int numSigProcessMod = 2;
    double numControls = 5.2;
    int inNum = 4;
    int outNum = 4;
    EffectsPedal();

    void loadDiffEfxPerModule(bool chainAisActive = true, std::string = "slotA", int efxTypeSingle = 1);
    void processInSeriesOrParallel(std::string series, int mixSendAmmount = 100);
    int assignEfxParamsToUi(int ecordersNumUI = 5, float encoderRangeUI = 1.0f, std::string = "layoutUI");    
};      

EffectsPedal::EffectsPedal()
{
    std::cout << "EffectsPedal being constructed!" << std::endl;
} 

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
    std::cout << "EffectsPedal::loadDiffEfxPerModule() Load number of Efx : " << (chainAisActive == true ? "1" : "0") <<  std::endl; 
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
    std::cout << "EffectsPedal::processInSeriesOrParallel() Type of Signal Processing : " << (mixSendAmmount > 99 ? "In Parallel Mode" : "In Series Mode") <<  std::endl;
}

int EffectsPedal::assignEfxParamsToUi(int ecordersNumUI, float encoderRangeUI, std::string layoutUI)
{
    layoutUI = "User Type" + layoutUI;
    numControls = ecordersNumUI + numEfxModules; 
    outNum = inNum *= encoderRangeUI;   
    std::cout << "EffectsPedal::assignEfxParamsToUi() Pedal Controls : " << numControls << " , " << layoutUI << std::endl;
    
    return numEfxModules;
}

struct AISynth
{
    std::string miModel = "NearestN";
    double numNNodes = 20.2;
    int synthParamNum = 10;
    int inputNumSynth = 2;
    int outputNumSynth = 2;
    AISynth();

    struct Synthesis
    {
        int typeOfSynthesis = 4;
        int waveShapes = 4;
        std::string modMatrix = "ModPanel";
        std::string tuning = "Concert Pitch";
        float touchStrip = 0.9f;
        Synthesis();

        void useSubSynthForSoundDesign(std::string subtractive, int waveTone = 1);
        std::string fineTuningAllOsc(double oscAll = 4.40, bool a4isPressed = true);
        void lowPassFilterSignal(bool filterIsLowPass = true, float cutOffRange = 0.2f);
    };

    void trainModel(int aNewSynth = 1, std::string = "mlModel", int learnFeatures = 8);    
    int storeFeatInputs(int features = 10, float xyzValues = 1.0, bool isRecorded = true);
    void mapModelToSynth(bool mapModeisActive = true, bool modelLoaded = true, int targetParams = 10);

    Synthesis aCustomNewSynth;  
};

AISynth::AISynth()
{
    std::cout << "AISynth being constructed!" << std::endl;
} 

AISynth::Synthesis::Synthesis()
{
    std::cout << "Synthesis being constructed!" << std::endl;
}

void AISynth::Synthesis::useSubSynthForSoundDesign(std::string subtractive, int waveTone)
{ 
    modMatrix = "Sources and Tagerts" + subtractive;
    typeOfSynthesis += waveShapes + waveTone; 
    std::cout << "AISynth::Synthesis::useSubSynthForSoundDesign() : " << modMatrix << " , " << typeOfSynthesis <<  std::endl;
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
    std::cout << "AISynth::Synthesis::fineTuningAllOsc() Instrument is tuned : " << (a4isPressed == true ? "Concert Pitch = 440Hz " : "Not Tuned to Ccncert Pitch") <<  std::endl;
    
    return "Concert Pitch";    
}

void AISynth::Synthesis::lowPassFilterSignal(bool filterIsLowPass, float cutOffRange)
{
   if(filterIsLowPass == true)
    {
        cutOffRange = 90.0f; 
    } 
     std::cout << "AISynth::Synthesis::lowPassFilterSignal: " << (filterIsLowPass == true ? "Low Pass Mode On " : "Filter Not Active") <<  std::endl;
}
   
void AISynth::trainModel(int aNewSynth, std::string mlModel, int learnFeatures)
{
    aNewSynth = inputNumSynth + learnFeatures;
    mlModel = "NearestN"; 
    std::cout << "AISynth::trainModel: " << mlModel <<  std::endl;
}

int AISynth::storeFeatInputs(int features, float xyzValues, bool isRecorded)
{
    if(isRecorded == true)
    {
        synthParamNum += features / xyzValues;
    }
    std::cout << "AISynth::storeFeatInputs: " << (isRecorded == true ? "Parameters That Have Been Stored : " : "No Data") << synthParamNum << std::endl;
    
    return outputNumSynth;
}

void AISynth::mapModelToSynth(bool mapModeisActive, bool modelLoaded, int targetParams)
{
    if(mapModeisActive && modelLoaded == true)
    {
        targetParams = synthParamNum;
    }
    std::cout << "AISynth::mapModelToSynth: " << (mapModeisActive && modelLoaded == true ? "Parameters are Ready To be sent: " : "No Mapping is Available") << targetParams << std::endl;
}

struct  VirtualMicPre
{
    int numPreAmpMod = 10;
    double numCircType = 21.0;
    int numOfMics = 20;
    int numOfUserPresets = 127;
    std::string colorMe = "AbbeyClassic";
    VirtualMicPre();

    void loadVirtualAnalogPreAmp(bool latencyZeroMode = true, std::string micModel = "Akg");
    int combineCircuitAndMicType(std::string polarPattern, int phantomPower = 48);
    void saverMicAndPreAmpPreset(double circuitAndMic = 1.1, std::string vocalSetUp = "VoxLead");
};

VirtualMicPre::VirtualMicPre()
{
    std::cout << "VirtualMicPre being constructed!" << std::endl;
}

void VirtualMicPre::loadVirtualAnalogPreAmp(bool latencyZeroMode, std::string micModel)
{
    if (latencyZeroMode == true)
    {
        micModel = " UAD Emulation ";
    }
    std::cout << "VirtualMicPre::loadVirtualAnalogPreAmp() : " << (latencyZeroMode == true ? "Latenct Zero mode is On : " : "Latenct Zero mode is Off") << micModel << std::endl;
}

int VirtualMicPre::combineCircuitAndMicType(std::string polarPattern, int phantomPower)
{
    int phantomPoweredMics = 10;
    phantomPower = phantomPoweredMics - numOfMics; 
    polarPattern = "Cardiord"; 
    std::cout << "VirtualMicPre::combineCircuitAndMicType() : " << polarPattern << std::endl;
    
    return 4;
}

void VirtualMicPre::saverMicAndPreAmpPreset(double circuitAndMic, std::string vocalSetUp)
{
    circuitAndMic = 2;
    vocalSetUp = "Soul";
    std::cout << "VirtualMicPre::saverMicAndPreAmpPreset() : " << vocalSetUp << " Template " << circuitAndMic << std::endl;
}

struct ModDelay
{
    float modDelaydryWet = 0.5f;
    float feedBack = 0.9f;
    double filterFreq = 12.20; 
    int lfoRate = 1;
    std::string comboBox = "saveUs";
    ModDelay();

    float modulateDelayTime(int tapSignals = 2, float delTimeMs = 20.0f, std::string lfoShapeWave = "sine");
    int saveModDelayPreset(int paramToSave = 10, std::string labelMePlease = "Space Echo");
    void filterDelayTap (bool delayIsStereo = true, std::string filterType = "Notch");
};

ModDelay::ModDelay()
{
    std::cout << "ModDelay being constructed!" << std::endl;
}

float ModDelay::modulateDelayTime(int tapSignals, float delTimeMs, std::string lfoShapeWave)
{
    lfoShapeWave = "sine";
    tapSignals = 2;
    modDelaydryWet = delTimeMs + feedBack;
    std::cout << "ModDelay::modulateDelayTime():" << modDelaydryWet << std::endl;
    
    return modDelaydryWet; 
}

int ModDelay::saveModDelayPreset(int paramToSave, std::string labelMePlease)
{
    int userPresetModDelNum = paramToSave;
    comboBox = " Roland " + labelMePlease;
    std::cout << "ModDelay::saveModDelayPreset" << userPresetModDelNum << std::endl;
    
    return userPresetModDelNum;
}

void ModDelay::filterDelayTap(bool delayIsStereo, std::string filterType)
{
    if(delayIsStereo == true)
    {
        filterType = "M/S";
        filterFreq = 110.300;
    }
    std::cout << "ModDelay::filterDelayTap(): " << (delayIsStereo == true ? "Parameters are Ready To be sent: " : "No Mapping is Available") << filterType << " , " << filterFreq << std::endl;   
}

struct  WetDryControlWidget 
{
    float dryWetAmmout = 0.1f;
    int modAmmount = 1; 
    double midiCCrange = 12.70;
    std::string uiControlType = "Vertical Slider"; 
    double colorSchemeToAssign = 23.30;
    WetDryControlWidget();

    void processSignalInParallel(bool isBusInputActive = true, float bus1Ammount = 3.0f);
    void learnExternalMidi(std::string midiRxPort = "USB", int midiRxCC = 20, bool parameterLearned = true);
    int saveCustomUISettins(int paramsToInclude = 10, bool includeSliders = false);
};

WetDryControlWidget::WetDryControlWidget()
{
    std::cout << "WetDryControlWidget being constructed!" << std::endl;
}

void WetDryControlWidget::processSignalInParallel(bool isBusInputActive, float bus1Ammount)
{
    float sendAmmount = 0.f;
    if(isBusInputActive == true)
    {
        sendAmmount = bus1Ammount += dryWetAmmout;
    }
    std::cout << "WetDryControlWidget::processSignalInParallel(): " << (isBusInputActive == true ? " Process Signal is in Parallel : " : "Process Signal is in Series") << sendAmmount << std::endl;
}

void WetDryControlWidget::learnExternalMidi(std::string midiRxPort, int midiRxCC, bool parameterLearned)
{
    if(parameterLearned == true)
    {
        midiRxPort = "Reciving";
        modAmmount = midiRxCC += midiCCrange;
    }
    std::cout << "WetDryControlWidget::learnExternalMidi(): " << (parameterLearned == true ? " Reciving " : " Not Reciving" ) << " , " << modAmmount << std::endl;
}

int WetDryControlWidget::saveCustomUISettins(int paramsToInclude, bool includeSliders)
{
    int totParamsToInclude = ++paramsToInclude;
    includeSliders = true;
    std::cout << "WetDryControlWidget::saevCustomUISettins() : " << totParamsToInclude << includeSliders << std::endl; 
    
    return totParamsToInclude;
}

struct ControlPanel 
{
    std::string savePreset = "Save New";
    std::string loadPreset = "Load Preset";
    std::string effectMode = " Multi Effect ";
    std::string createUserType = "Mode A";
    int switchPresetToCompare = 1;
    ControlPanel();

    void saveToUserFolder(std::string fileExtension = "Cpx", bool paramsAreSaved = true);
    int loadFromUserFolder(std::string fileCategory = " Bassline ", int presetValue = 10);
    int switchEffectsTypes(int loadA = 0, int loadB = 1);
};

ControlPanel::ControlPanel()
{
    std::cout << "ControlPanel being constructed!" << std::endl;
}    

void ControlPanel::saveToUserFolder(std::string fileExtension, bool paramsAreSaved)
{
    if(paramsAreSaved == true)
    {
        savePreset = fileExtension + effectMode + createUserType;
    }
    std::cout << "ControlPanel::saveToUserFolder(): " << (paramsAreSaved == true ? " Yes " : " No" ) << " , " << savePreset << std::endl;
}

int ControlPanel::loadFromUserFolder(std::string fileCategory, int presetValue)
{
    ++presetValue;
    int compareLastSaved =+ presetValue;
    loadPreset = fileCategory + effectMode;
    std::cout << "ControlPanel::loadFromUserFolder(): " << compareLastSaved << " , " << loadPreset << std::endl;
    
    return compareLastSaved;
}

int ControlPanel::switchEffectsTypes(int loadA, int loadB)
{
    if(loadA > 0)
    {
        switchPresetToCompare = loadB;
    } 
    std::cout << "ControlPanel::saveToUserFolder(): " << (loadA > 0 ? " Preset B " : " Preset A" ) << std::endl;
    
    return 1;
}

struct FeedbackControlWidget
{
    float feedBackAmmount = 1.0;
    std::string circutiModeToUse = "Digital"; 
    bool canBeModulated = true;
    std::string uiControlToUse = "Rotary";
    int modRangAvailable = 100;
    FeedbackControlWidget();

    void sendFeedbackinDistortion(float feedItBackIn = 1.1f, bool isExcedingLimit = true, std::string warningOn = "RockOn");
    int processFeedbackMode(std::string feebackType = " Dub Classic ", int loadSoundReference = 3);
    void becomeModTarget(bool parameterIsVisisble = true, std::string mappingMode = "Bypolar");
};

FeedbackControlWidget::FeedbackControlWidget()
{
    std::cout << "FeedbackControlWidget being constructed!" << std::endl;
}    

void FeedbackControlWidget::sendFeedbackinDistortion(float feedItBackIn, bool isExcedingLimit, std::string warningOn)
{
    ++feedItBackIn;
    if(isExcedingLimit == true)
    {
        warningOn = "Clipping";   
    }   
    std::cout << "FeedbackControlWidget::sendFeedbackinDistortion() : " << (isExcedingLimit == true ? " Clipping " : " Clear" ) << std::endl;
}

int FeedbackControlWidget::processFeedbackMode(std::string feebackType, int loadSoundReference)
{
    circutiModeToUse = feebackType + uiControlToUse;
    loadSoundReference = modRangAvailable += loadSoundReference;
    std::cout << "FeedbackControlWidget::processFeedbackMode() : " << circutiModeToUse << " , " << loadSoundReference << std::endl;
    
    return loadSoundReference;
}

void FeedbackControlWidget::becomeModTarget(bool parameterIsVisisble, std::string mappingMode)
{
    if(parameterIsVisisble == true)
    {
        uiControlToUse = circutiModeToUse + mappingMode;
    }
    std::cout << "FeedbackControlWidget::becomeModTarget() : " << (parameterIsVisisble == true ? " Yes " : " No" ) << std::endl;
}

struct FilterControlWidget
{
    double highPassFilter = 67.00;
    double lowPassFilter = 40.20;
    float qRange = 1.0f;
    int shelveAvailable = 2;
    std::string britishMode = " NEVE ";
    FilterControlWidget();

    float removeLowFreqContent(std::string filterType = " HighPass ", bool secondOrderFilter = true, double rumbleRange = 10.90);
    int changeQBandwidth(int resonanceWidth = 4, bool fullyParametricMode = true);
    void processViaVintageOrModern(std::string harmonicColoration = " Retro ", int componentType = 2);
};

FilterControlWidget::FilterControlWidget()
{
    std::cout << "FilterControlWidget being constructed!" << std::endl;
}

float FilterControlWidget::removeLowFreqContent(std::string filterType, bool secondOrderFilter, double rumbleRange)
{
    if(secondOrderFilter == true)
    {
        highPassFilter = rumbleRange;
        britishMode = filterType + " Cut ";
    }   
    std::cout << "FilterControlWidget::removeLowFreqContent() : " << (secondOrderFilter == true ? " Oder Selected " : "Oder Not Selected") << " , " << britishMode << " , " << highPassFilter <<  std::endl;
    
    return 50.0f;
}

int FilterControlWidget::changeQBandwidth(int resonanceWidth, bool fullyParametricMode)
{
    if(fullyParametricMode == true)
    {
        ++qRange;
        resonanceWidth = 1;
    }
    std::cout << "FilterControlWidget::changeQBandwidth() : " << (fullyParametricMode == true ? "Parametric Mode on" : " Parametric Mode off ") << " , " << qRange << " , " << resonanceWidth <<  std::endl;
    
    return 1;
}

void FilterControlWidget::processViaVintageOrModern(std::string harmonicColoration, int componentType)
{
    britishMode = harmonicColoration + " Custom74 ";
    componentType = shelveAvailable += componentType;
    std::cout << "FilterControlWidget::processViaVintageOrModern() : " << britishMode << std::endl;
}

struct PerformanceRack 
{
    ModDelay modDelay;
    WetDryControlWidget wetdryControlWidget;
    ControlPanel controlOPanel;
    FeedbackControlWidget feedbackControlWidget;
    FilterControlWidget filterControlWidget;
    PerformanceRack();

    void savePerformanceRack(std::string modDelayMultiEffect, bool saveToUserFolder = true);
    int mergeInstrAndEfxInRack(std::string instrumentsToLoad, int effectsToLoad = 3);
    void controlRackParamsViaMidiCC(std::string orizSlider = " Mixer", std::string vertSlider = "Sequencer");
};

PerformanceRack::PerformanceRack()
{
    std::cout << "PerformanceRack being constructed!" << std::endl;
}    

void PerformanceRack::savePerformanceRack(std::string modDelayMultiEffect, bool saveToUserFolder)
{
    if(saveToUserFolder == true)
    {  
        modDelayMultiEffect = "Multi Mode Effect";
    }
    std::cout << "PerformanceRack::savePerformanceRack() : " << (saveToUserFolder == true ? " User Directory " : " Main Directory ") << " , " << modDelayMultiEffect <<  std::endl;
}

int PerformanceRack::mergeInstrAndEfxInRack(std::string instrumentsToLoad, int effectsToLoad)
{
    ++effectsToLoad;
    instrumentsToLoad = " Sampler ";
    std::cout << "PerformanceRack::mergeInstrAndEfxInRack() : " << effectsToLoad << " , " << instrumentsToLoad <<  std::endl;
    
    return effectsToLoad;   
}

void PerformanceRack::controlRackParamsViaMidiCC(std::string orizSlider, std::string vertSlider)
{
    orizSlider = " Liner Mode ";
    vertSlider = " Exponential Mode ";
    std::cout << "PerformanceRack::controlRackParamsViaMidiCC() : " << orizSlider << " , " << vertSlider <<  std::endl;
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
    std::cout << "-------------------" << std::endl;
    
    MidiController aNewMidiController;
    MidiController::ControllerType aTypeOfController;
    aTypeOfController.setNumKeysInOctave(1, 1);   
    aTypeOfController.loadUserKeyboard();
    aTypeOfController.setVelocityRangeForKeys(127.0f, "Akay MPC");
    
    aNewMidiController.txConChange("filter", 14);
    aNewMidiController.changeMidiMode();
    aNewMidiController.saveUserPreset();
    std::cout << "Studio Set Up" << " connected via " <<aNewMidiController.midiConnect << " , " << " Ready " <<std::endl; 
    std::cout << "-------------------" << std::endl;

    EffectsPedal multiEffectPedal;
    multiEffectPedal.loadDiffEfxPerModule();
    multiEffectPedal.processInSeriesOrParallel("serie", 100);
    multiEffectPedal.assignEfxParamsToUi(0, 1.0f, " : RebelPedal");
    std::cout << "Availble Inputs :  " << multiEffectPedal.inNum << " , " << " Availble Outputs : " << multiEffectPedal.outNum <<std::endl; 
    std::cout << "-------------------" << std::endl;
    
    AISynth brainSynth;
    AISynth::Synthesis synthesisModel;
    synthesisModel.useSubSynthForSoundDesign(" : Lfo, Envelops, Filters, Oscillators", 1);
    synthesisModel.fineTuningAllOsc(440.0, true);
    synthesisModel.lowPassFilterSignal();

    brainSynth.trainModel();
    brainSynth.storeFeatInputs();
    brainSynth.mapModelToSynth();
    std::cout << "New AI Synth Model :  " << brainSynth.miModel << " , " << " Data points : " << brainSynth.numNNodes <<std::endl; 
    std::cout << "-------------------" << std::endl;

    VirtualMicPre vocalSession;
    vocalSession.loadVirtualAnalogPreAmp();
    vocalSession.combineCircuitAndMicType("label", 48);
    vocalSession.saverMicAndPreAmpPreset();
    std::cout << "Channel Strip To Load : " << vocalSession.colorMe <<std::endl; 
    std::cout << "-------------------" << std::endl;

    ModDelay lfoBasedDel;
    lfoBasedDel.modulateDelayTime();
    lfoBasedDel.saveModDelayPreset();
    lfoBasedDel.filterDelayTap();
    std::cout << "Save ModDelay Preset : " << lfoBasedDel.comboBox << " / Type / " << "Haas Effect" <<std::endl; 
    std::cout << "-------------------" << std::endl;

    WetDryControlWidget channelStrip;
    channelStrip.processSignalInParallel();
    channelStrip.learnExternalMidi();
    channelStrip.saveCustomUISettins();
    std::cout << "WetDryControlWidget : " << channelStrip.uiControlType <<std::endl; 
    std::cout << "-------------------" << std::endl;

    ControlPanel effectControlPanel;
    effectControlPanel.saveToUserFolder();
    effectControlPanel.loadFromUserFolder();
    effectControlPanel.switchEffectsTypes();
    std::cout << "ControlPanel : " << effectControlPanel.effectMode << std::endl; 
    std::cout << "-------------------" << std::endl;
    
    FeedbackControlWidget delayControlWidget;
    delayControlWidget.sendFeedbackinDistortion();
    delayControlWidget.processFeedbackMode();
    delayControlWidget.becomeModTarget(true);    
    std::cout << "FeedbackControlWidget: " << delayControlWidget.circutiModeToUse << " Delay  " << std::endl; 
    std::cout << "-------------------" << std::endl;

    FilterControlWidget filterControlWidget;
    filterControlWidget.removeLowFreqContent();
    filterControlWidget.changeQBandwidth();
    filterControlWidget.processViaVintageOrModern();    
    std::cout << "FilterControlWidget: " << filterControlWidget.britishMode << std::endl; 
    std::cout << "-------------------" << std::endl;

    PerformanceRack myGigSetUp;
    myGigSetUp.savePerformanceRack("ModDelay Multi Effect", true);
    myGigSetUp.mergeInstrAndEfxInRack(" Test ", 2);
    myGigSetUp.controlRackParamsViaMidiCC( "Mixer", "Sequencer");
    std::cout << "-------------------" << std::endl;

    std::cout << "good to go!" << std::endl; 
    
}
