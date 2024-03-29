import numpy as np
from scipy import signal
import matplotlib.pyplot as plt

# Code for simulating drift and variance for the wow control
# using an Ornstein-Uhlenbeck process

freq = 0.5
FS = 48000
mag = 1.0
N = int(FS * 20)

rr = np.random.normal(0, 1.0, N)
def oh_process(inp, N, amt, damping, mean):
    y = 0
    out = np.zeros(N)
    sqrtdelta = 1.0 / np.sqrt(FS);
    T = 1.0 / FS

    for i in range(N):
        # y = (y + T * amt * rr[i] + damping * T * mean) / (1.0 + T * damping)
        y += sqrtdelta * rr[i] * amt
        y += 0.001 * damping * (mean - y) * T
        out[i] = y
    return out


x = mag * np.sin(2 * np.pi * freq / FS * np.arange(N))
plt.plot(x, label='sin')

for amt in [1.0]: # [0.0, 0.33, 0.67, 1.0]:
    amt = np.power(amt, 1.15)
    y = x + oh_process(x, N, amt * 0.5, amt * 0.5 + 0.25, 1.0 * amt)
    b, a = signal.butter(2, Wn=10, fs=FS)
    y = signal.lfilter(b, a, y)
    plt.plot(y, label=f'{amt}')

# y = np.power(0.5 * (x + 1), 10.0)
# plt.plot(y)

plt.show()
