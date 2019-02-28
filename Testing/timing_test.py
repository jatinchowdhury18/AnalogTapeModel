import numpy as np
import matplotlib.pyplot as plt
import soundfile as sf

def toMono (arr):
    list = []
    for samp in arr:
        list.append (samp[0])
    return list

pulse_in, fs = sf.read ("pulse_train.wav")

pulse_out, fs = sf.read ("PulseTrain_Out.wav")
pulse_out = toMono (pulse_out)

N = len (pulse_in)
t = np.arange (N)
n = 60000
start = 30000

plt.plot (t[start:start+n], pulse_in[start:start+n], t[start:start+n], pulse_out[start:start+n])
plt.xlabel ("Time [samples]")
plt.ylabel ("Amplitude")
plt.title ("Real-time Timing Offset (Flutter)")
plt.show()
