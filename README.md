# Simulink-Serial-FOC
Real-time motor control with Simulink and SimpleFOC library. Simulink uses a serial port to communicate with the commander interface of SimpleFOC.

**Note: This Simulink model is currently in the testing phase and may contain errors. If you have expertise in Simulink, a refinement in the model would be appreciated . Thank you!**

**Step 1:**
Upload the SimpleFOC code in Arduino IDE to your microcontroller (MCU) and assign the Commander and monitored variables accordingly.

**Step 2:**
Open the Simulink model and set up the following blocks:
- Serial setup block
- Serial send block
- Serial receive block

Configure these blocks to correspond to the COM port of your MCU.

**Step 3:**
Set the input targets within the desired range (preferably 0-99.999).

**Step 4:**
Run the simulation and observe the monitored variables in the display or scope block.
