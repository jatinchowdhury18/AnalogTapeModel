---
author: Jatin Chowdhury
title: Continuous Time Equations for Analog Tape Modeling
date: 2/1/2019
---

## Hysteresis

The magnetostatic field recorded to magnetic tape can be described using a hysteresis loop. A circuit simulation of a hysteresis loop by Martin Holters and Udo Zolzer, using the Jiles-Atherton magnetisation model can be found at http://dafx16.vutbr.cz/dafxpapers/08-DAFx-16_paper_10-PN.pdf. They use the following differential equation to describe magnetisation 'M' as a function of magnetic field 'H':

$$ \frac{dM}{dH} = \frac{(1-c) \delta_M (M_{an} - M)}{(1-c) \delta k - \alpha (M_{an} - M)} + c \frac{dM_{an}}{dH} $$

where $M_{an}$ is the anisotropic magnetisation given by:

$$ M_{an} = M_s L \Big( \frac{H + \alpha M}{a} \Big) $$

where $M_s$ is the magnetisation saturation, and $L$ is the Langevin function:

$$ L(x) = \coth (x) - \frac{1}{x} $$
$$ L'(x) = \frac{1}{x^2} - \coth^2(x) + 1 $$
$$ L''(x) = 2 \coth(x) \cdot (\coth^2(x) - 1) - \frac{2}{x^3} $$

Let $Q(t) = \frac{H + \alpha M}{a}$

Differentiating, we get:

$$ \frac{dM}{dt} = \frac{(1-c) \delta_M (M_sL(Q) - M)}{(1-c) \delta k - \alpha (M_sL(Q) - M)} \frac{dH}{dt} + c \frac{M_s}{a} \Big(\frac{dH}{dt} + \alpha \frac{dM}{dt} \Big) L'(Q) $$

(wrong see paper)
$$
\frac{d^2 M}{dt^2} = \frac{(1-c) \delta_M (M_sL(Q) - M)}{(1-c) \delta k - \alpha (M_sL(Q) - M)} \frac{d^2H}{dt^2} +
\frac{(1-c) \delta_M (M_sL'(Q) - \dot{M})}{(1-c) \delta k - \alpha (M_sL(Q) - M)} \frac{dH}{dt} + 
\frac{(1-c) \delta_M (M_sL(Q) - M)(-\alpha (M_sL'(Q) - \dot{M}))}{((1-c) \delta k - \alpha (M_sL(Q) - M))^2} \frac{dH}{dt} + 
c \frac{M_s}{a} \Big(\frac{dH}{dt} c \frac{M_s}{a} (\frac{dH}{dt} + \alpha \frac{dM}{dt}) L''(Q) + \frac{d^2H}{dt^2} L'(Q) + \alpha \frac{dM}{dt} c \frac{M_s}{a} (\frac{dH}{dt} + \alpha \frac{dM}{dt}) L''(Q) + \alpha \frac{d^2M}{dt^2} L'(Q) \Big) 
$$

Simplified (wrong see paper):
$$ \frac{d^2 M}{dt^2} = \frac{
\frac{(1-c) \delta_M (M_sL(Q) - M)}{(1-c) \delta k - \alpha (M_sL(Q) - M)} \frac{d^2H}{dt^2} + 
\frac{(1-c) \delta_M (M_sL'(Q) - \dot{M})}{(1-c) \delta k - \alpha (M_sL(Q) - M)} \frac{dH}{dt} + 
\frac{(1-c) \delta_M (M_sL(Q) - M)(-\alpha (M_sL'(Q) - \dot{M}))}{((1-c) \delta k - \alpha (M_sL(Q) - M))^2} \frac{dH}{dt} + 
c \frac{M_s}{a} \Big(\frac{d^2H}{dt^2} L'(Q) + c \frac{M_s}{a} L''(Q) (\dot{H} + \alpha \dot{M})^2 \Big)}
{1 - c \alpha \frac{M_s}{a} L'(Q)}
$$


$$ \frac{dM}{dt} = \frac{\frac{(1-c) \delta_M (M_sL(Q) - M)}{(1-c) \delta k - \alpha (M_sL(Q) - M)} \frac{dH}{dt} + c \frac{M_s}{a} \frac{dH}{dt} L'(Q)}{1 - c \alpha \frac{M_s}{a} L'(Q)} = f(t, M, \vec{u})  $$

where $\vec{u} = \begin{bmatrix}
H \\
\dot{H} \\
\ddot{H}
\end{bmatrix}$

Using trapezoidal rule: 

$$ \dot{\hat{H}}(n) = 2 \frac{\hat{H}(n) - \hat{H}(n-1)}{T} - \dot{\hat{H}}(n-1) $$

and similar for $\ddot{\hat{H}}$. Now, using the semi-implicit trapezoidal rule [Yeh]:

$$ \hat{M}(n) = \hat{M}(n-1) + \frac{T}{2} \frac{f[n, \hat{M}(n-1), \vec{u}(n)] + f[n-1, \hat{M}(n-1), \vec{u}(n-1)]}{1 - \frac{T}{2}\ddot{\hat{M}}(n-1)} $$
