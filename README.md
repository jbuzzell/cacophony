# cacophony

an experimental control pedal in two parts

## The core features of the project are as follows:

●	The device will receive an input signal and output it unchanged.
●	The device will read and analyze the input signal for the root frequency of the note/chord being played.
●	The device will build an equal-tempered melodic scale based on the notes gathered from the input signal.
●	The device will send random notes within that scale via MIDI based on a tempo set by the user.
●	The user may trigger the device such that one MIDI channel plays the last x notes again, where x is the step length (of a range from 1-16) set by the user.

## Stretch goals for the project are as follows:

●	The user may select a MIDI output mode such that MIDI channels A and B play:
○	the same notes in parallel (and can be bypassed independently).
○	different notes in parallel (and can be bypassed independently).
○	the same notes, but only one channel selected by the user plays at a time.
○	the same notes and alternate MIDI output from A to B per step such that output of each channel is mutually exclusive—if one output is playing a note, the other is silent.
●	The user may trigger the device such that both MIDI channels play the last xA or xB notes again, where xA and xB are the step length (of a range from 1-16) set by the user for channels A and B, respectively.
●	The device will play a third melody on a built-in synthesizer circuit.
●	The device will use a sample and hold circuit to influence externally what notes to play and when.
●	The device will output its pitch data in 1 volt per octave-tuned modular synthesizer control voltage.
