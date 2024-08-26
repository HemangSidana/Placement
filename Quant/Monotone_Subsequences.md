For any subsequence of mn+1 distinct real numbers there is either an increasing subsequence of m+1 numbers or a decreasing subsequence of n+1 numbers.

Let t<sub>i</sub> denote the maximum length of an increasing subsequence starting with a<sub>i</sub>. \
If t<sub>i</sub> > m for some i then, we are done. \
Otherwise, t<sub>i</sub> can take values from 1 to m. \
By Pigeonhole Principle, there are n+1 indices whose t value is same. \
All these numbers must be in decreasing order otherwise we can extend the increasing subsequence.