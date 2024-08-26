Given a random permutation of N numbers. Find expected length of longest subsequence of type 1,2,...k.

Probability of having subsequence of length atleast x is 1/x! \
Answer= $\Sigma_{k=1}^{N} k(\frac{1}{k!} - \frac{1}{(k+1)!})$ \
For large N, it converges to e-1.