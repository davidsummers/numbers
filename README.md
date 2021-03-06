Numbers
=======

Surprisingly, computers don't do very well at computing arithmetic.

They have limited precision and can't give a correct mathematical answer when
the result falls between the numbers that can be represented by the limited
precision.

In "The End of Error", Dr. John L. Gustafson presents some interesting ways
this can be improved.

This project intends to explore his solutions.

One way is to use one bit (the least significant bit) of the number for an
"Uncertain" bit which indicates that the number is not exactly the number
represented but falls in the range between this exactly representable number
and the next exactly representable number.

An integer example
==================

In integer arithmetic:

63 / 2 = 31 (false)

With the "Uncertain" bit, we can correctly represent this as

63 / 2 = 31... (true)

The "..." says that the number is higher than the printed number but lower than the next representable number.

This is represented by the least significant bit being set to 1.
If this bit is 1 then the number is "uncertain" but somewhere between the two
exactly representable numbers.

While we've lost a bit of precision (pun intended), we can say correctly,
mathematically, that the resulting number falls between these numbers.

In this project, I create some C++ classes which begin to attempt to explore
how to improve the normal computer computation and see if it is worth doing.

Representation
==============

S N U

0 0 0 = 0     exactly 0

0 0 1 = 0...  between 0 and 1

0 1 0 = 1     exactly 1

0 1 1 = 1...  between 1 and infinity
 
1 0 0 = INF   infinity (plus or minus)

1 0 1 = -1... between -1 and negative infinity

1 1 0 = -1    exactly -1

1 1 1 = -0... between -1 and 0



Incorrect math at the edge
==========================

Lastly, current computers don't correctly compute -X for X = -2^N.

For example, in an 8-bit bit signed number ( Sign + N = 7 ) bits, somehow most
computers think that they can represent the number -128.

However, if you try taking the negative of that number, the result is still -128
which is an incorrect mathematical result.

For example, for an 8-bit signed number ( Sign + N = 7 ) bits:

X = -128

Y = -X

Y == 128 (false) (it still equals -128)

Another way of thinking of this is:

How can a computer represent a number that is outside the +/- 2^N bits for that
number?  It can't.

 2^7 = max of  127

-2^7 = min of -127

So, let's make this special number the INF (Infinity) value instead.

So for example, a 2-bit signed number would have these possible values.

Representation
==============

S N

0 0 = 0

0 1 = 1

1 0 = INF

1 1 = -1

This is easily expandable to any number of bits.

The number with the Sign bit turned on but the rest of the bits N = 0 is the
INF (Infinity) value.

Or you could think of it as NAN (Not a Number).

Now when we have:

X = INF

Y = -X

Y == INF (true, although we can't represent +/- INF, just INF)

A future possibility would be to make this number NAN and
then 2^N - 1 = +INF and -2^N + 1 = -INF.

Code
====

IntX_t types
============

The IntX_t types (Int8_t, Int16_t, Int32_t, Int64_t) implement normal
integers but with the INF value.

Note: They use modulo arithmetic just like normal int and will wrap around.

IntXu_t types
=============

The IntXu_t types (Int8u_t, Int16u_t, Int32u_t, Int64u_t) implement types
that have the "Uncertain" bit as the least significant bit of the number.

Note: They *don't* do modulo arithmetic but will max out at number higher than
the highest number but lower than infinity or lower than the lowest number but
higher than negative infinity.

For instance (Int16u_t):

3 * 16000 = 16383... (higher than the maximum possible representation of 16383
but less than Infinity)

At the moment, the code only supports integers, but in the future I will be
expanding it to support floating point as well.

I intend to take Dr. Gustafson's "posit" floating point type and add the
"Uncertain" bit to the end of it.

(I don't understand why he dropped it in going from his Type I UNUMs to 
Type III (posit) UNUMs.)


Summary
=======

While these changes reduce the number of representable numbers, they basically
extend the existing C++ types in to better types that give more "mathematically"
correct results than the normal C++ types.

