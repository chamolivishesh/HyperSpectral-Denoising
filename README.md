# HyperSpectral-Denoising
Denoisning a HyperSpectral Signal using the concept of Thresholding

Hyperspectral imaging collects and processes information from across the electromagnetic spectrum. The aim of hyperspectral imaging is to obtain the spectrum for each pixel in the image of a scene, with the purpose of finding objects, identifying materials, or detecting processes.

Here, my attempt with this repository is to take one single signal and denoise it assuming it got noisy during transmission and the noisy part is removed from the output.

# Pre-requisite
1. Qt - Cross-Platform Development Tool with C++
2. Qt MinGW Kit
3. Qt Charts

# How we do it?
1. We have a file that has all the values for the single wave of the signal. We import all the values in an array

2. We then perform the multiscale analysis on the wave to seperate the main wave and the noise part

3. Then, we threshold the noise in the wave

4. Then from the nth scale wave, we reobtain the wave to get a denoised one.

# Note
1. In the main function, there is a string pointer "filename" which has the path to the input file for wave values (I have written <**add your file path**> there). That is the parameter where you have to put the location of the file in your computer.
2. There is a function **InputWave(const char* filename)** the body of which is formatted to input the values according to the format of the file that I have to take the values from. You might have to make changes in that function so that each value is **"push_back"**-ed into the **mainwave** vector.
