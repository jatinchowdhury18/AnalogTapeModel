# %%
from audio_dspy.hysteresis import Hysteresis
import numpy as np
import matplotlib.pyplot as plt
import audio_dspy as adsp

FS = 96000

# %%
# drive plot
WIDTH = 1.0
SAT = 0.5

legend = []
for DRIVE in [0.0, 0.25, 1.0]:
    hyst = adsp.Hysteresis(DRIVE, SAT, WIDTH, FS, mode='NR4')
    adsp.plot_dynamic_curve(hyst.process_block, freq=10, fs=FS, gain=3, num=10000)
    legend.append(f'Drive = {DRIVE}')

plt.legend(legend)
plt.grid()
plt.title('Hysteresis Drive')
plt.tight_layout()
plt.savefig('drive.png')
# %%
# saturation plot
WIDTH = 1.0
DRIVE= 1.0

legend = []
for SAT in [0.0, 0.4, 0.8]:
    hyst = adsp.Hysteresis(DRIVE, SAT, WIDTH, FS, mode='NR4')
    adsp.plot_dynamic_curve(hyst.process_block, freq=10, fs=FS, gain=3, num=10000)
    legend.append(f'Sat. = {SAT}')

plt.legend(legend)
plt.grid()
plt.title('Hysteresis Saturation')
plt.tight_layout()
plt.savefig('sat.png')
# %%
# width plot
SAT = 0.9
DRIVE= 1.0

legend = []
for WIDTH in [0.0, 0.67, 1.0]:
    hyst = adsp.Hysteresis(DRIVE, SAT, WIDTH, FS, mode='NR4')
    adsp.plot_dynamic_curve(hyst.process_block, freq=10, fs=FS, gain=1, num=10000)
    legend.append(f'Bias = {1-WIDTH:.2f}')

plt.legend(legend)
plt.grid()
plt.title('Hysteresis Bias')
plt.tight_layout()
plt.savefig('bias.png')
# %%
