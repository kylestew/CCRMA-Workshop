import("stdfaust.lib");

/*
 * BELL: Modal bell model with excitation input
 * strikePosition - 5 strike positions on bell
 * holdLength - t60 decay time
*/
bell = _*gainIn : fi.lowpass(3, 800) : pm.churchBellModel(12,strikePosition,holdLength,1,2.5)*0.5
with {
    gainIn = nentry("gainIn", 0.2, 0, 1, 0.001);
    strikePosition = nentry("strikePosition", 0,0,4,1);
    holdLength = nentry("holdLength", 40,1,400,0.1);
};


/*
 * WIND INSTRUMENT: Clarinet
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
bellOut = bell;
windOut = wind*0.4;

process = windOut+bellOut;
