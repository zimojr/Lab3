# Laboratory_X
template repo for Labs

Tasks:

->Product of numbers

->Sum of divisors

->Approximating Euler's number

->Approximating π, method I. and method II.


# Floating Point Arithmetic: Addition and Subtraction with Finite Precision

## 1. Why Floating Point?
Computers cannot represent most real numbers exactly.  
Instead, they use a **finite binary approximation** called *floating point representation*.  

Example:
- The decimal number `0.1` **cannot be represented exactly** in binary floating point. (Why? Try to determine its binary representation on paper!)
- What the computer stores is sometimes just a nearby approximation.

---

## 2. Finite Precision
A floating point number has:
- **Sign bit** (positive/negative),
- **Exponent** (scale factor),
- **Mantissa / significand** (precision digits).

Since the mantissa has limited bits (e.g. 23 bits in `float`, 52 in `double`), **only finitely many numbers can be stored**.  
This leads to *rounding errors*.

---

## 3. What Can Happen with Addition/Subtraction?

### 3.1. Rounding Errors
```c
#include <stdio.h>

int main() {
    float x = 0.1f + 0.2f;
    printf("%.10f\n", x);
    return 0;
}

Output might be:

0.3000000119

👉 The result is close to 0.3, but not exact.
3.2. Loss of Significance (Cancellation)

Subtracting nearly equal numbers can cause most significant digits to cancel out, leaving only error.

#include <stdio.h>
#include <math.h>

int main() {
    double a = 1.0000001;
    double b = 1.0000000;
    double diff = a - b;
    printf("Difference: %.20f\n", diff);
    return 0;
}

Expected: 0.0000001
Actual: something like 0.00000010000000000364
(here less bits were used to represent 0.000001, as a lot went to represent a 1.)
👉 The relative error is large, even if the number looks small.
3.3. Adding Numbers of Very Different Magnitudes

When adding a very small number to a very large one, the small one can disappear.-->summations may not converge anymore!

#include <stdio.h>

int main() {
    double big = 1e16;
    double small = 1.0;
    double sum = big + small;
    printf("Sum: %.0f\n", sum);
    return 0;
}

Output:

10000000000000000

👉 The +1 is lost due to limited precision.
//Joke: in petrol station: -How much is a drop of petrol? -Oh, it's free -Drop it full for me please!

4. How to Work with Floating Point Safely

    Never compare floats directly (if (x == y) is dangerous).
    Instead, compare with a tolerance:

    if (fabs(x - y) < 1e-9) { /* treat as equal */ }

    Rearrange computations to avoid subtracting nearly equal numbers!

    Use higher precision (double instead of float) if accuracy is important.

    Be aware of rounding: results may differ slightly across compilers or platforms.

5. Key Takeaways

    Floating point numbers are approximations.

    Adding/subtracting can produce rounding errors and loss of significance.

    Always design programs with these limitations in mind.

