import numpy as np
import matplotlib.pyplot as plt

fs = 48000 * 16

t = np.linspace (0, 1, fs)

f = 2000
I_in = np.sin (2 * np.pi * f * t)

f_bias = 50000
A_bias = 5
I_bias = A_bias * np.sin (2 * np.pi * f_bias * t)

I_head = I_in + I_bias

plt.plot (t[0:2000], I_head[0:2000])
plt.title ("2 kHz Sine Wave Biased at 50 kHz")
plt.xlabel ("Time [s]")
plt.ylabel ("Amplitude")
plt.show()
