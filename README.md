# VariationalCalculus
Variational Calculus using Minimization.
Variational Calculus is to find a function that gives minimal cost functional (function of function).
The following is an example of cost functional of function <img src="https://latex.codecogs.com/gif.latex?y(x)" />
.

<div align="center">
<img src="https://latex.codecogs.com/gif.latex?F(y(x))=\int_{x_1}^{x_n}y(x)^2+\alpha\left(\frac{\mathrm{d}y}{\mathrm{d}x}\right)^2dx" />
</div>

In this library, we will express a function by a long vector <img src="https://latex.codecogs.com/gif.latex?y_1,\cdots,y_n" />, which is the value corresponding to each x, i.e. <img src="https://latex.codecogs.com/gif.latex?x_1,\cdots,x_n" />. The above example functional can be calculated by the below approximation:

<div align="center">
<img src="https://latex.codecogs.com/gif.latex?F(y(x))\simeq\sum_{i=1}^{n}y_i^2+\alpha\sum_{i=1}^{n-1}\left(y_{i+1}-y_i\right)^2" />
</div>

