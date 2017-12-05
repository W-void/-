## 1
b = a.reshape((m,n))
改变b的值，a的值也会变，需要先用b = a.copy()
## 2
#### 计算对应元素相乘之和时， *比 np.dot 更费时
%timeit np.sum(a * a)
12.7 µs ± 3.86 µs per loop (mean ± std. dev. of 7 runs, 1 loop each)

%timeit np.dot(a.reshape((1,-1)), a.reshape((-1,1)))
2.2 µs ± 23.9 ns per loop (mean ± std. dev. of 7 runs, 100000 loops each)
