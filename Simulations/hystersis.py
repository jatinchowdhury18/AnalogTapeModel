import numpy as np
import matplotlib.pyplot as plt
from matplotlib import animation

fs = 48000
T = 1/fs # sample interval
M_s = 350000 # Jiles book
a = 2.2e4 #adjustable parameter
alpha = 1.6e-3
k = 27.0e3 #Coercivity
c = 1.7e-1 #1.867e-1
#M_r = 0.5e6 (A/m)
#H_c (coercivity) = 25000 - 30000 A/m (Jiles book)

# Langevin function
def L (x):
    if (abs (x) > 10 ** -4):
        return (1 / np.tanh (x)) - (1/x)
    else:
        return (x / 3)

# Langevin derivative
def L_d (x):
    if (abs(x) > 10 ** -4):
        return (1 / x ** 2) - (1 / np.tanh (x)) ** 2 + 1
    else:
        return (1 / 3)

# trapezoidal rule derivative
def deriv (x_n, x_n1, xDeriv_n1):
    return ((2 / T) * (x_n - x_n1)) - xDeriv_n1

# dM/dt or "non-linear function"
def f (M, H, H_d):
    Q = (H + alpha * M) / a
    M_diff = M_s * L (Q) - M
    delta = 1 if H_d > 0 else -1
    delta_M = 1 if np.sign (delta) == np.sign (M_diff) else 0
    L_prime = L_d (Q)

    denominator = 1 - c * alpha * (M_s / a) * L_prime

    t1_num = (1 - c) * delta_M * M_diff
    t1_den = (1 - c) * delta * k - alpha * M_diff
    t1 = (t1_num / t1_den) * H_d

    t2 = c * (M_s / a) * H_d * L_prime

    return (t1 + t2) / denominator

def M_n (M_n1, k1, k2, k3, k4):
    return M_n1 + (k1 / 6) + (k2 / 3) + (k3 / 3) + (k4 / 6)

#input signal
t = np.linspace (0, 1, fs * 50)
#H_in = (5e5) * np.sin (2 * np.pi * 100 * t)
freq = 2000
H_in = np.concatenate ((5e2 * np.sin (2 * np.pi * freq * t[0:fs*5]), 1e3 * np.sin (2 * np.pi * freq * t[fs*5:fs*10]), \
                        3e3 * np.sin (2 * np.pi * freq * t[fs*10:fs*15]), 5e3 * np.sin (2 * np.pi * freq * t[fs*15:fs*20]), \
                        1e4 * np.sin (2 * np.pi * freq * t[fs*20:fs*25]), 3e4 * np.sin (2 * np.pi * freq * t[fs*25:fs*30]), \
                        5e4 * np.sin (2 * np.pi * freq * t[fs*30:fs*35]), 1e5 * np.sin (2 * np.pi * freq * t[fs*35:fs*40]), \
                        3e5 * np.sin (2 * np.pi * freq * t[fs*40:fs*45]), 5e5 * np.sin (2 * np.pi * freq * t[fs*45:fs*50])))
# plt.plot (t, H_in)
# plt.show()

M_out = np.zeros (fs * 50)
M_n1 = 0
H_n1 = 0
H_d_n1 = 0
H_d2_n1 = 0

n = 0
percent = 0
for H in H_in:
    H_d = deriv (H, H_n1, H_d_n1)
    H_d2 = deriv (H_d, H_d_n1, H_d2_n1)

    k1 = T * f (M_n1, H_n1, H_d_n1)
    k2 = T * f (M_n1 + k1/2, (H + H_n1) / 2, (H_d + H_d_n1) / 2)
    k3 = T * f (M_n1 + k2/2, (H + H_n1) / 2, (H_d + H_d_n1) / 2)
    k4 = T * f (M_n1 + k3, H, H_d)

    M = M_n (M_n1, k1, k2, k3, k4)

    M_n1 = M
    H_n1 = H
    H_d_n1 = H_d
    H_d2_n1 - H_d2

    M_out[n] = M
    n += 1

    curPercent = (int) (n / (fs * 50) * 100)
    if (curPercent > percent + 4):
        percent = curPercent
        print (str (percent) + "% completed")

MH = plt.figure (1)
plt.plot (H_in / 1000, M_out / M_s)
plt.xlabel ("Magnetic Field (A/m)")
plt.ylabel ("Tape Magnetisation (A/m)")
plt.title ("Simulated Ditigal Tape Magnetization Hysteresis Loop")
MH.show()

Mt = plt.figure (2)
plt.plot (t, M_out / M_s)
plt.show()
