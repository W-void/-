## 1
b = a.reshape((m,n))

改变b的值，a的值也会变，需要先用b = a.copy()
## 2
#### 计算对应元素相乘之和时， *比 np.dot 更费时
%timeit np.sum(a * a)
12.7 µs ± 3.86 µs per loop (mean ± std. dev. of 7 runs, 1 loop each)

%timeit np.dot(a.reshape((1,-1)), a.reshape((-1,1)))
2.2 µs ± 23.9 ns per loop (mean ± std. dev. of 7 runs, 100000 loops each)
## 3
Counter函数

import collections

先定义一个数组a，a = np.array([2,2,1,4,5])

Counter(a)会以键值对的形式返回a的概述
Out[170]: Counter({1: 1, 2: 2, 4: 1, 5: 1})

配合max函数求a中元素中出现次数最多的元素(keys)或次数(values)\n
max(Counter(a).values())
