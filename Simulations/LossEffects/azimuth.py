import numpy as np
import audio_dspy as adsp
import matplotlib.pyplot as plt

def inches2meters(inches):
    return inches / 39.370078740157

def deg2rad(deg):
    return deg * np.pi / 180

tape_width = inches2meters(0.25)
tape_speed = inches2meters(15)
azimuth_angle = deg2rad(5)

delay_dist = (tape_width / 2) * np.sin(azimuth_angle)
delay_ms = 1000 * (delay_dist / tape_speed)
print(delay_ms)

FS = 48000
delay_samp = (delay_ms / 1000) * FS
print(delay_samp)

FILT_SAMP = delay_samp / 16
x = np.arange(FILT_SAMP) # np.pi * np.arange(-FILT_SAMP, FILT_SAMP) / FILT_SAMP
p = 1
h = -(6.0 / FILT_SAMP**3) * x * (x - FILT_SAMP)

# plt.plot(h)
adsp.plot_magnitude_response(h, [1], fs=FS)
plt.ylim(-60)
plt.show()
