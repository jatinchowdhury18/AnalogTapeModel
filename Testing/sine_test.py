import numpy as np
import matplotlib.pyplot as plt
import soundfile as sf

def toMono (arr):
    list = []
    for samp in arr:
        list.append (samp[0])
    return list


d, fs = sf.read ("RisingSine_Dry.wav")

# just use left channel, signal is mono anyway
dry = toMono (-1 * d)

b, fs = sf.read("RisingSine_Bias.wav")
bias = toMono (b)
bias= bias / np.max (np.abs (bias))

n, fs = sf.read("RisingSine_NoBias.wav")
noBias = toMono (n)

c, fs = sf.read("RisingSine_Tape.wav")
tape = toMono (-1*c)
tape = tape / np.max (np.abs (tape))

N = len(dry)
t = np.arange (N)

# print (N)

plt.figure()
plt.plot (dry[0:20000], bias[0:20000])
plt.xlabel ("Input Amplitude")
plt.ylabel ("Output Amplitude")
plt.title ("Real-time System Hysteresis Loop")

plt.figure()
plt.plot (dry[0:20000], tape[0:20000])
plt.xlabel ("Input Amplitude")
plt.ylabel ("Output Amplitude")
plt.title ("Tape Machine Hysteresis Loop")

# plt.figure()
# plt.plot (tape[:20000])
# plt.plot (bias[:20000])
plt.show()
