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
real_last_N = 0
while (n < N):
    signal[n] = magnitude
    real_last_N = n
    n += N_pulse

# print (real_last_N)

signal = np.asarray (signal, dtype=np.float32)

# Read data
#filename = "pulse_train_3.75.wav"
filename = "pulse_train_7.5.wav"
fs, data_7_5 = wavfile.read (filename)
data = data_7_5 / np.amax (data_7_5)

# clean data
#gate_thresh = 0.3
gate_thresh = 0.1
last_N = 0
for n in range (len (data)):
    # gate
    if (abs (data[n]) < gate_thresh):
        data[n] = 0

    # only take first sample over thresh
    if data[n] != 0:
        data[n] = 1
        data[n+1:n+100] = 0
        last_N = n

# print (last_N)

# Align timing
for n in range (len (data)):
    if data[n] == 1:
        data[n] = 0
        data[int (n * real_last_N / last_N)] = -1

data *= -1

# Time plot
# t = np.arange (N) / fs
# n_to_show = 50000
# n_to_start = 250000
# plt.plot (t[n_to_start:n_to_start+n_to_show], data[n_to_start:n_to_start+n_to_show], t[n_to_start:n_to_start+n_to_show], signal[n_to_start:n_to_start+n_to_show])
# plt.title ("Timing Difference at 7.5 ips")
# plt.xlabel ("Time [s]")
# plt.ylabel ("Amplitude")
# plt.show()

# Timing distribution
test_times = []
for n in range (len (data)):
    if data[n] == 1:
        test_times.append (n)

real_times = []
popped = False
for n in range (N):
    if signal[n] != 0:
        real_times.append (n)

    if len (real_times) == 234 and popped == False:
        real_times.pop()
        popped = True

new_N = 900 #min (len (test_times), len (real_times))

diffs = []
for n in range (new_N):
    diff = real_times[n] - test_times[n]
    if abs (diff) < 2000:
        diffs.append (diff)

d_max = np.amax (diffs)
d_min = np.amin (diffs)
avg = (d_max - d_min) / 2
diffs -= avg

diffs_pos = []
for n in range (len (diffs)):
    if diffs[n] >= 0:
        diffs_pos.append (diffs[n])

# polyfit
t = np.arange (len (diffs_pos))
p = np.polyfit (t, diffs_pos, 10)

print (p)
print (len (diffs_pos))

y = np.poly1d (p)

plt.plot (t, diffs_pos, t, y(t))
plt.xlabel("Time [samples]")
plt.ylabel("Delay [samples]")
plt.title("Tape Delay vs Time")
plt.show()
