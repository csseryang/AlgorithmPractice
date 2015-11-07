import math

from cmath import exp, pi
 
def web_fft(x):
    N = len(x)
    if N <= 1: return x
    even = fft(x[0::2])
    odd =  fft(x[1::2])
    T= [exp(-2j*pi*k/N)*odd[k] for k in xrange(N/2)]
    return [even[k] + T[k] for k in xrange(N/2)] + \
           [even[k] - T[k] for k in xrange(N/2)]
 

                
def fft(a):
    n = len(a)
    if n == 1:
        return a
    y0 = fft(a[::2])
    y1 = fft(a[1::2])
    w, wn, y = 1, math.e **(2j * math.pi / n), []
    for k in range(n //2):
        y += [y0[k] + w*y1[k] ]
        w *= wn
    w = 1
    for k in range(n//2):
        y += [y0[k] - w * y1[k] ]
        w *= wn
    return y

def inverse_fft(a):
    n = len(a)
    if n == 1:
        return a
    y0 = inverse_fft(a[::2])
    y1 = inverse_fft(a[1::2])
    w, wn, y = 1, math.e **(-2j * math.pi / n), []
    for k in range(n //2):
        y += [y0[k] + w*y1[k] ]
        w *= wn
    w = 1
    for k in range(n//2):
        y += [y0[k] - w * y1[k] ]
        w *= wn
    y = [j/2 for j in y]
    return y

def main():
    a = [1, 2 ,4, 8]
    y1 = fft(a)
    b = [1, 2 ,4, 8]
    y2 = inverse_fft(b)
    
    y3 = web_fft(a)
    print y1
    print y2
    print y3

if __name__=="__main__":
    main()



