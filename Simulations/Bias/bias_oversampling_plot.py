import matplotlib.pyplot as plt
import numpy as np

freqs = np.zeros(1000)

fs = 44 * 2

plt.plot([0,20], [0.5,0.5], 'b')
plt.plot([20,20], [0,0.5], 'b')

plt.plot([fs,fs], [0,1])

amp = 1.0
harmonic = 1
f_base = 50
f = 0
while f < 1000:
    f = f_base * harmonic

    if f < fs:
        plt.plot([f,f], [0,amp], 'r')
    else:
        plt.plot([fs-(f-fs),fs-(f-fs)], [0,amp], 'r')

    amp *= 0.9
    harmonic += 0.2

plt.xlim((0,fs*1.1))

plt.xlabel("Frequency [kHz]")
plt.ylabel("Amplitude")

plt.title("Audio Signal + Bias (digitized)")

plt.show()
