import numpy as np
import matplotlib.pyplot as plt
import audio_dspy as adsp

FS = 48000

worN = np.logspace(1, 2, 500)

# 12 dB/Oct filters
freq = [45, 40, 35]
legend = []
for fc in freq:
    b, a = adsp.design_HPF2(fc, 0.7071, FS)
    adsp.plot_magnitude_response(b, a, fs=FS, worN=worN)
    legend.append(f'12 dB Slope, fc={fc}')

# 24 dB/Oct fitler
freq = 35
sos = adsp.design_HPFN(freq, 0.7071, 4, FS)
adsp.plot_magnitude_response_sos(sos, fs=FS, worN=worN)
legend.append(f'24 dB Slope, fc={freq}')

plt.grid(which='both')
plt.ylim([-30, 3])

plt.legend(legend, loc='lower right')
plt.title('DC Blockers Comparison')
plt.show()
