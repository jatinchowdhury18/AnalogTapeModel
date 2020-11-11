# %%
import numpy as np
import matplotlib.pyplot as plt
from scipy import signal

# %%
FREQS = np.logspace(1.3, 4.3, 50)
N = 128
FS = 48000.0
f = np.linspace (0, FS, N)
n = range(N)

def ips_to_mps(speed):
    return speed * 0.0254

def freq_to_k(tape_speed_ips, freq):
    wavelength = ips_to_mps(tape_speed_ips) / freq
    return 2 * np.pi / wavelength

def gain_to_db(x):
    return 20 * np.log10(x)

def plot_test(speed, H_func = lambda k: 1):
    bin_width = FS / N
    H = np.zeros(N)
    H[0] = 1
    for k in range(N // 2):
        freq = k * bin_width
        wave_num = 2 * np.pi * max(freq, 20) / (speed * 0.0254)
        H[k] = H_func(wave_num)
        H[N - k - 1] = H[k]

    # plt.semilogx(f[:N//2], gain_to_db(H[:N//2]), '--')

    h = np.zeros(N)
    for n in range(N // 2):
        idx = N//2 + n
        for k in range(N):
            h[idx] += H[k] * np.cos(2 * np.pi * k * n / N)
        h[idx] /= N
        h[N//2 - n] = h[idx]

    # h = np.concatenate([h[N//2:], h[:N//2]]) # np.concatenate((h[N//2:])) #, H[:N//2]))

    w, h_z = signal.freqz(h, fs=FS, worN=FREQS)
    plt.semilogx(w, gain_to_db(h_z), '--')

# %%
def spacing_loss(tape_speed_ips, dist_meter, freqs):
    K = freq_to_k(tape_speed_ips, freqs)
    return np.exp(-1 * K * dist_meter)

# SPEED = 7.5 # ips
# dist = 5.0e-6 # meters

for dist in [1.0e-6, 5e-6, 10e-6]:
    for SPEED in [7.5]: #, 15, 30]:
        space_loss = spacing_loss(SPEED, dist, FREQS)
        plt.semilogx(FREQS, gain_to_db(space_loss), label=f'{SPEED}, {dist}')
        plot_test(SPEED, lambda k : np.exp(-k * dist))

# plt.ylim(-6, 0)
# plt.ylim(0, 3.5)
plt.legend()
plt.title('Spacing Loss')

# %%
def thickness_loss(tape_speed_ips, thick_meter):
    K = freq_to_k(tape_speed_ips, FREQS)
    return (1 - np.exp(-1 * K * thick_meter)) / (K * thick_meter)

for thick in [1.0e-6, 10.e-6]:
    for SPEED in [7.5, 15, 30]:
        loss = thickness_loss(SPEED, thick)
        plt.semilogx(FREQS, gain_to_db(loss), label=f'{SPEED}, {thick}')

plt.ylim(-6, 1)
plt.legend()
plt.title('Thickness Loss')
# %%
def gap_loss(tape_speed_ips, gap_meter):
    K = freq_to_k(tape_speed_ips, FREQS)
    return np.sin(K * gap_meter / 2.0) / (K * gap_meter / 2.0)

for gap in [1.0e-6, 10.0e-6, 20.e-6]:
    for SPEED in [7.5]: #, 15, 30]:
        loss = gap_loss(SPEED, gap)
        plt.semilogx(FREQS, gain_to_db(loss), label=f'{SPEED}, {gap}')

plt.ylim(-6, 0)
plt.legend()
plt.title('Gap Loss')

# %%
def head_bump(tape_speed_ips, gap_meter):
    bump_freq = tape_speed_ips * 0.0254 / (gap_meter * 5e2)
    print(bump_freq)
    width = bump_freq * 0.4
    gain = 1.5 * (2e3 - abs(bump_freq - 100)) / 2e3
    A = -(gain - 1) / (width/ 2)**2
    H = np.zeros_like(FREQS)
    for i, f in enumerate(FREQS):
        if abs(f - bump_freq) > width / 2:
            H[i] = 1.0
        else:         
            H[i] = max(A * (f - bump_freq)**2 + gain, 1)
    return H

for gap in [5.0e-6, 10.0e-6, 20.e-6]:
    for SPEED in [7.5, 15, 30]:
        loss = head_bump(SPEED, gap)
        plt.semilogx(FREQS, gain_to_db(loss), label=f'{SPEED}, {gap}')

# plt.ylim(-6, 0)
plt.legend()
plt.title('Head Bump')

# %%
