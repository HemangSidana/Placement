N persons are sitting in a circle. Starting with person 1, each person will kill the next person to their left until only one person is left. Find the last person remaining.

f(2k)= 2f(k)-1 \
f(2k+1)= 2f(k)+1 \
So, f(2<sup>x</sup>)=1 \
Begin with f(1)= 1 and try to form binary representation of N using above operations. \
For adding a bit, we need to add 2 and for each left shift it will be multiplied by 2 afterwards.\
So, bits except most significant bit will increase answer by twice their value.\
f(N)= 1+2(N-2<sup>log<sub>2</sub>N</sup>)