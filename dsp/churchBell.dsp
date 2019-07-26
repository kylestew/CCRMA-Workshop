import("stdfaust.lib");

/*
 * BELL: Modal bell model with excitation input
 * strikePosition - 5 strike positions on bell
 * holdLength - t60 decay time
*/
bell = pm.churchBellModel(12,strikePosition,holdLength,1,2.5)*0.5
with {
    strikePosition = nentry("strikePosition", 0,0,4,1);
    holdLength = nentry("holdLength", 40,1,400,0.1);
};


/*
 * WIND INSTRUMENT: ???
 * pressure
 * tubeLength - (in meters) used for note
 * mouthPosition - (0-1)
*/
wind = pm.fluteModel(tubeLength, mouthPosition, pressure)*0.5
with {
    pressure = hslider("pressure", 0, 0, 2, 0.0001);
    tubeLength = hslider("tubeLength", 0, 0, 2, 0.0001);
    mouthPosition = hslider("mouthPosition", 0.5, 0, 1, 0.0001);
};

// OUTPUTS
bellOut = ba.pulse(500000) : bell;
windOut = wind*0.5;

process = windOut+bellOut <: dm.freeverb_demo;
