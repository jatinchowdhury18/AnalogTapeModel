import numpy as np
import matplotlib.pyplot as plt

T = 48000
M_s = 1.6e6
a = 1.1e3
alpha = 1.6e-3
k = 4.0e2
c = 1.7e-1

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

# Langevin 2nd derivative
def L_d2 (x):
    if (abs(x) > 10 ** -3):
        return 2 * (1 / np.tanh (x)) * ((1 / np.tanh (x)) ** 2 - 1) - (2 / x ** 3)
    else:
        return -(2 / 15) * x

# trapezoidal rule derivative
def deriv (x_n, x_n1, xDeriv_n1):
    return (2 / T) * (x_n - x_n1) - xDeriv_n1

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

# d^2M/dt^2
def M_d2 (M, M_d, H, H_d, H_d2):
    Q = (H + alpha * M) / a
    M_diff = M_s * L (Q) - M
    delta = 1 if H_d > 0 else -1
    delta_M = 1 if np.sign (delta) == np.sign (M_diff) else 0
    L_prime = L_d (Q)

    denominator = 1 - c * alpha * (M_s / a) * L_prime

    t1_num = (1 - c) * delta_M * M_diff
    t1_den = (1 - c) * delta * k - alpha * M_diff
    t1 = (t1_num / t1_den) * H_d2

    M_diff2 = c * (M_s / a) * (H_d + alpha * M_d) * L_d (Q) - M_d
    t2_num = (1 - c) * delta_M * M_diff2
    t2 = (t2_num / t1_den) * H_d

    t3_num = (1 - c) * delta_M * M_diff * (-alpha) * M_diff2
    t3 = (t3_num / t1_den**2) * H_d

    L_2prime = L_d2 (Q)
    t4 = c * (M_s / a) * (H_d2 * L_prime + c * (M_s / a) * L_2prime * (H_d + alpha * M_d)**2)

    return (t1 + t2 + t3 + t4) / denominator 

def M_n (M_n1, f_n, f_n1, M_d2_n1):
    return M_n1 + (T / 2) * (f_n + f_n1) / (1 - (T/2) * M_d2_n1)

t = np.linspace (0, 10, T * 50)
H_in = np.concatenate ((1000 * np.sin (2 * np.pi * 2 * t[0:T*5]), 900 * np.sin (2 * np.pi * 2 * t[T*5:T*10]), \
                        800 * np.sin (2 * np.pi * 2 * t[T*10:T*15]), 750 * np.sin (2 * np.pi * 2 * t[T*15:T*20]), \
                        700 * np.sin (2 * np.pi * 2 * t[T*20:T*25]), 650 * np.sin (2 * np.pi * 2 * t[T*25:T*30]), \
                        600 * np.sin (2 * np.pi * 2 * t[T*30:T*35]), 550 * np.sin (2 * np.pi * 2 * t[T*35:T*40]),
                        500 * np.sin (2 * np.pi * 2 * t[T*40:T*45]), 400 * np.sin (2 * np.pi * 2 * t[T*45:T*50])))
# plt.plot (t, H_in)
# plt.show()

M_out = np.zeros (T * 50)
M_n1 = 0
H_n1 = 0
H_d_n1 = 0
H_d2_n1 = 0

n = 0
percent = 0
for H in H_in:
    H_d = deriv (H, H_n1, H_d_n1)
    H_d2 = deriv (H_d, H_d_n1, H_d2_n1)

    f_n = f (M_n1, H, H_d)
    f_n1 = f (M_n1, H_n1, H_d_n1)
    M_d2_n1 = M_d2 (M_n1, f_n1, H_n1, H_d_n1, H_d2_n1)

    M = M_n (M_n1, f_n, f_n1, M_d2_n1)

    M_n1 = M
    H_n1 = H
    H_d_n1 = H_d
    H_d2_n1 - H_d2

    M_out[n] = (M)
    n += 1

    curPercent = (int) (n / (T * 50) * 100)
    if (curPercent > percent):
        percent = curPercent
        print (str (percent) + "% completed")

MH = plt.figure (1)
plt.plot (H_in, M_out)
#MH.show()

Mt = plt.figure (2)
plt.plot (t, M_out)
plt.show()
