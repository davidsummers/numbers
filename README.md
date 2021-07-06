Numbers
=======

Surprisingly, computers don't do very well at computing arithmetic.

They have limited precision and can't decide what the correct result is when
the result falls between the numbers that can be represented by the limited
precision.

In "The End of Error", Dr. John L. Gustafson presents some interesting ways
this can be improved.

One way is to use one bit of the number for an "Uncertain" bit which indicates
that the number is not exactly the number represented but falls in the range
between this number and the next number.

For example:

In Integer arithmetic:

63 / 2 = 31 (false)

With the "Uncertain bit", we can correctly represent this as

63 / 2 = 31... (true)

The "..." says that the number is higher than the printed number but lower than the next representable number.

While we've lost precision, we can say correctly, mathematically, that the
resulting number falls between these numbers.

In this project, I create some C++ classes which begin to attempt to explore
how to improve the normal computer computation.

Lastly, current computers don't correctly compute -X for X = 2^N.

For example, in an 8-bit bit signed number ( Sign + N = 7 ) bits , somehow most
computers think that they can represent that as -128.

However, if you try taking the negative of that number, the result is still -128
which is an incorrect result.

For example, for an 8-bit signed number ( Sign + N = 7 ) bits:
X = -128
Y = -X
Y == 128 (false) (it still equals -128)

Another way of thinking of this is:

How can a computer represent a number that is outside the +/- 2^N bits for that
number?  It can't.

So, let's make this special number the INF (Infinity) value instead.

So for example, a 2-bit signed number would have these possible values.

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
Y == INF (true)

