import numpy as np
import matplotlib.pyplot as plt
import soundfile as sf

def toMono (arr):
    list = []
    for samp in arr:
        list.append (samp[0])
    return list

data, fs = sf.read ("RisingSine_NoBias.wav")
mono = toMono (data)

N = 450
start = 5900

t = np.arange (len (mono))

plt.plot (t[start:start+N], mono[start:start+N])
plt.xlabel ("Time [samples]")
plt.ylabel ("Output Amplitude")
plt.title ("\"Deadzone\" Effect")
plt.show()
