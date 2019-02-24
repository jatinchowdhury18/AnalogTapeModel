import matplotlib.pyplot as plt
import numpy as np
from scipy.io import wavfile

# Constants
fs = 44100
f_pulse = 10
num_pulses = 1000
N = int ((1 / f_pulse) * num_pulses * fs)
N_pulse = int ((1 / f_pulse) * fs)
magnitude = 0.8

# Create Signal
signal = np.zeros (N)

n = N_pulse
while (n < N):
    signal[n] = magnitude
    n += N_pulse

signal = np.asarray (signal, dtype=np.float32)

# Write to file
filename = "pulse_train.wav"
wavfile.write (filename, fs, signal)

# Plot
t = np.arange (N) / fs
plt.plot (t[0:100000], signal[0:100000])
plt.title ("Pulse Train Input")
plt.xlabel ("Time [s]")
plt.ylabel ("Amplitude")
plt.show()
