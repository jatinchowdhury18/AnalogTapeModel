import numpy as np
import matplotlib.pyplot as plt
import scipy.signal as signal

# Constants
N = 100
d = 1e-9 #Spacing between tape and head
g = 2e-6 #Head gap width
delta = 35e-6 #Tape thickness
v = 7.5 * 0.0254

#f = np.linspace (0, 24000, N/2)
f = np.linspace (0, 48000, N)
n = np.linspace (0, N, N)
#n = np.linspace (0, N/2, N/2)

# Calculate H(f)
H = np.zeros (N)
H[0] = 1
waveNum = 2 * np.pi * f[1:int (N/2)] / v
#H[1:int (N/2)] = np.e ** (- abs(waveNum) * d) # Spacing loss
#H[1:int (N/2)] = np.sin (waveNum * g / 2) / (waveNum * g / 2) #gap loss
#H[1:int (N/2)] = (1 - np.exp (-waveNum * delta))/(waveNum * delta) #Thickness loss
H[1:int (N/2)] = (np.e ** (- abs (waveNum) * d)) * (np.sin (waveNum * g / 2) / (waveNum * g / 2)) * ((1 - np.exp (-waveNum * delta)) / (waveNum * delta))
H_flip = np.flip (H[0:int (N/2)], 0)
H[int (N/2):N] = H_flip

# "Roll your own" iDFT
h = np.zeros (N)
for n_k in range (N):
    for k in range (N):
        h[n_k] += H[k] * np.cos (2 * np.pi * k * n_k / N)
    h[n_k] *= (1/N)

#h = np.fft.ifft (H)
H = np.fft.fft (h)
w, H_t = signal.freqz (h)

# Plotting output
#plt.plot(n, h)
#plt.plot (w * 22000 / np.pi, abs (H_t))
plt.semilogx (f[0:int (N/2)], 10 * np.log10 (H[0:int (N/2)]))
plt.axvline (x=15000)
plt.axhline (y=-3)
plt.title ("Tape Loss Effects vs. Frequency")
plt.xlabel ("Frequency [Hz]")
plt.ylabel ("Amplitude [dB]")
plt.show()
