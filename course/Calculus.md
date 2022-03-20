## Introduction to Calculus

The velocity is the slope of the distance graph:

$$
slope=\frac{change in distance}{change in time}=\frac{vt}{t}=v
$$

> The slope of the $f$-graph gives the velocity $v$. The area under the
> $v$-graph gives the distance $f$

The number $v(t)$ is the value of the function $v$ at the time $t$. ("$v$ of
$t$") 

$$
v(t)= \begin{cases}
    +V && if & 0<t<3 \\
    ?  && if & t=3 \\
    -V && if & 3<t<6
\end{cases}
$$

$$
f(t)=\begin{cases}
    Vt && if & 0 \leqslant t \leqslant 3 \\
    Vt(6-t) && if & 0 \leqslant t \leqslant 3
\end{cases}
$$

* This would be bad except that they agree: $f(3)=3V$ . v h e distance
  function is "continuous". There is no jump in $f$, even when there is a jump
  in $v$

> The domain of a function is teh set of inputs. The range is the set of outputs.

### SUMMARY: MORE ABOUT FUNCTIONS

* By definition, a function is a "rule" that assigns one member of the range to
  each member of the domain.
* Or, a function is a set of pairs $(t,f(t))$ with no $t$ appearing twice. (These
  are "ordered pairs" because we write $t$ before $f(t)$.) Both of those
  definitions are correct-but somehow they are too passive.

> Calculus is about the ***rate of chage***

## 1.1 Introduction to Calculus

* $f(t)-2$ moves the whole graph *down*
* $f(t-2)$ moves the graph over to teh *right*

Zoom

## 1.2 Calculus Without Limits

> The differences of the $f$'s add up to $(f_{last}-f_{first})$

* piecewise linear
* piecewise constant

The slope of the $f$-graph is

$$
\frac{distance\ up}{distance\ across}=\frac{change\ in\ f}{change\ in\ t}=v
$$

> The total area under the v-graph is $f$'s add up to $(f_{last}-f_{first})$

> The $v$'s are slopes of $f(t)$. The area under the $v$-graph is
> $f(t_{end})-f(t_{start})$

$$Average\ slope\ =\frac{change\ in\ y}{change\ in\ x}=\frac{\Delta y}{\Delta x}$$

The slope of the step function is called a "delta function"

The average velocity is the slope of a straight line

1. To find the slope of the f-graph at a particular time t, you don't have to
   know the whole history.
2. To find the area under the v-graph up to a particular time t, you do have to
   know the whole history.

$$
\frac{\Delta y}{\Delta x}
    =\frac{(x+ \Delta x)^2-x^2}{\Delta x}
    =\frac{x^2+2x \Delta x+ \Delta x^2-x^2}{\Delta x}
$$

$$
\frac{dy}{dx}
    =limit\ of \frac{\Delta y}{\Delta x}
    =2x+\Delta x
    =2x
$$

## 1.4 Circular Motion

## Max and Min and Second Derivative

* Inflection Point: Where the second derevative is zero
* $y\prime\prime$
* Concave and Convex
* Local maximum

## Integrals

$$
y(x)=\int s(x)dx
$$

$$
\sum(\frac{\Delta y}{\Delta x})\Delta x=\int\frac{dy}{dx}dx
    =y_{end}-y_{start}
$$

## Derivative of sin x and cos x

$$
\frac{d}{dx}(\sin x)=\cos x \\
\frac{d}{dx}(\cos x)=-\sin x
$$

$$
\frac{\Delta(\sin x)}{\Delta x}=\frac{\sin(x+\Delta x)-\sin x}{\Delta x}
    =
$$
