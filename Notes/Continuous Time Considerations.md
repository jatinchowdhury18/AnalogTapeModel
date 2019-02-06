---
author: Jatin Chowdhury
title: Continuous Time Equations for Analog Tape Modeling
date: 2/1/2019
---

# Record head

For an instantaneous current I, the magnetic field output of the record head is given as a function of distance along the tape 'x', and depth into the tape 'y' (Karlqvist medium field approximation) [Bertram, page 60]:

$$ H_x(x,y) = \frac{1}{\pi} H_0 \Big(\tan^{-1} \Big(\frac{(g/2) + x}{y} \Big) + \tan^{-1} \Big(\frac{(g/2) - x}{y} \Big) \Big) $$
$$ H_y(x,y) = \frac{1}{2 \pi} H_0 \ln \Big(\frac{((g/2) - x)^2 + y^2}{((g/2) + x)^2 + y^2} \Big) $$

where $g$ = head gap, and $H_0$ = deep gap field, given by:

$$ H_0 = \frac{NIE}{g} $$

where $N$ = number of turns coils of wire around the head, and $E$ = head efficiency given by:

$$ E = \frac{1}{1 + \frac{l  A_g}{\mu_r g} \int_{core} \frac {d \vec{l}}{A(l)}} $$

where $A_g$ is the gap area, $\mu_r$ is the core permeability relative to free space ($\mu_0$), $g$ if the gap width, and $A(l)$ is the cross-sectional area of the core as a function of length.

# Tape Magnetisation

## Deadzone

For low current, the field is insufficient to create a change in magnetisation. For high current the field saturates. The effective field magnetising the tape $H_h$ can be described as follows:

$$ H_h = \begin{cases} 0 & H \le S^* H_c \\
                       H & H > S^* H_c
\end{cases} $$

where $S^*$ = hysteresis loop squareness, and $H_c$ = coercivity.

## Hysteresis

The magnetostatic field recorded to magnetic tape can be described using a hysteresis loop. A circuit simulation of a hysteresis loop by Martin Holters and Udo Zolzer, using the Jiles-Atherton magnetisation model can be found at http://dafx16.vutbr.cz/dafxpapers/08-DAFx-16_paper_10-PN.pdf. They use the following differential equation to describe magnetisation 'M' as a function of magnetic field 'H':

$$ \frac{dM}{dH} = \frac{(1-c) \delta_M (M_{an} - M)}{(1-c) \delta k - \alpha (M_{an} - M)} + c \frac{dM_{an}}{dH} $$

where $M_{an}$ is the anisotropic magnetisation given by:

$$ M_{an} = M_s L \Big( \frac{H + \alpha M}{a} \Big) $$

where $M_s$ is the magnetisation saturation, and $L$ is the Langevin function.

# Playback head

## Ideal playback voltage

The ideal playback voltage as a function of tape magnetisation is given by [Bertram, page 121]:

$$ V(x) =  NWEv \mu_0 \int_{-\infty}^{\infty} dx' \int_{-\delta/2}^{\delta/2} dy' \vec{h}(x' + x, y') \cdot \frac{\vec{M}(x', y')}{dx} $$

where $N$ = number of turns of wire, $W$ = with of the playhead, $E$ = playhead efficiency, $v$ = tape speed. Note that $V(x) = V(vt)$ for constant $v$. $\vec{h}(x, y)$ is defined as:

$$ \vec{h} (x, y) \equiv \frac{\vec{H} (x, y)}{NIE} $$

where $\vec{H} (x, y)$ is the same as for the record head.

## Loss effects

There are several frequency-dependent loss effects associated with playback, described as follows [Kadis, page 126]:

$$ V(x) = V_0(x) [e^{-kd}] \Big[\frac{1 - e^{-k \delta}}{k \delta} \Big] \Big[\frac{\sin (kg /2)}{kg/2} \Big] $$

where $k$ = wave number.

### Spacing Loss

$$ g_s = e^{-kd} $$

where $d$ is the distance between the tape and the playhead.

### Gap Loss

$$ g_g = \frac{\sin (kg /2)}{kg/2} $$

where $g$ is the gap with of the play head.

### Thickness Loss

$$ g_t = \frac{1 - e^{-k \delta}}{k \delta} $$

where $\delta$ is the thickness of the tape.

# Conclusion
If each of these components is digitized, a digital physical model of the analog tape machine can be constructed.
