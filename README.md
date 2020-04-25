# cacophony

an experimental MIDI control peripheral

## The core features of the project are as follows:

* The device will receive an input signal from an instrument and record notes played as MIDI while the record button is held.
* The device will read and analyze the input signal for the root frequency of the note/chord being played.
* The device will algorithmically generate the next notes in the sequence based on the current sequence as triggered by the user.
* The device will play the sequence on loop while the user holds the play button.
* The user may modify the tempo of the sequence using the tempo knob.

## Dependencies

* Teensy 4.0
* Teensy 4.0 Audio Shield
* [Boost](https://www.boost.org/) (for unit tests)
