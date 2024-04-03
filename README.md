# ToF-gesture-recognition
Program to gesture recognition 

This repository contains a ToF (Time-of-Flight) Gesture Recognition application designed for the LPC55S69 microcontroller using the MCUxpresso IDE. The application utilizes the CMSIS-DSP library for Support Vector Machine (SVM) classification with a polynomial kernel to recognize gestures based on ToF sensor data.

## Features:
* ToF Sensor Integration: Utilizes the VL53L5CX ToF sensor for distance measurement.
* Gesture Recognition: Implements machine learning-based gesture recognition using SVM with a polynomial kernel.
* OLED Display Output: Provides real-time gesture recognition results on an OLED display.

Setup Instructions:
1. **Clone the Repository**: Clone this repository to your local machine using the following command:
```bash
git clone https://github.com/Loki727/ToF-gesture-recognition-.git
```
2. **Import Project into MCUxpresso IDE**:
* Open MCUxpresso IDE.
* Go to File > Import.
* Select Existing MCUXpresso IDE Projects and click Next.
* Browse to the cloned repository directory and select it.
* Click Finish to import the project.
3. **Build and Flash**:
* Connect your LPC55S69 development board to your computer.
* Build the project by clicking the hammer icon or selecting Project > Build All.
* Flash the program to your LPC55S69 board by clicking the lightning bolt icon or selecting Run > Debug.


##License:
This project is licensed under the [MIT](https://choosealicense.com/licenses/mit/) License.
