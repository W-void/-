import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
import scipy.io as scio
from sklearn.datasets import load_iris


def sigmoid(z):
    return 1.0 / (1.0 + np.exp(-z))


def de_sigmoid(y):
    return y * (1-y)


def LR(x, y, alpha=0.001, iterate=1000, lamda=0.01, batch=1000):
    m, n = x.shape
    x = np.hstack((x, np.ones((m, 1))))
    y = y.reshape((-1, 1))
    np.random.seed(5)
    w = np.random.rand(n + 1, 1)

    for _ in range(iterate):
        i = 0
        while i < m:
            end = min(m, i + batch)
            x_batch, y_batch = x[i:end], y[i:end]
            f = sigmoid(np.dot(x_batch, w))

            delta_w = np.sum(((f - y_batch) * x_batch), 0).reshape((-1, 1)) / (end-i) + lamda * w

            w = w - alpha * delta_w
            i = i + batch

        f = sigmoid(np.dot(x, w)).flatten()
        if _ % 100 == 0:
            cost = -np.sum(y * np.log2(f + 1e-10) + (1-y) * np.log2(1-f + 1e-10)) / len(y) + lamda* np.dot(w.T, w)
            print(cost)
    print(w)
    return w


def predict(x, w):
    m = x.shape[0]
    x = np.hstack((x, np.ones((m, 1))))
    y = np.dot(x, w)
    return y > 0.5


def cal_ACC(y, y_p):
    return sum(y == y_p) / len(y)


if __name__ == '__main__':
    #Data = pd.read_csv('creditcard.csv').values
    iris = load_iris()
    Data = iris.data
    x, y = Data[:, :-1], Data[:, -1]
    y = (y > 1)

    x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.5, random_state=0)

    w = LR(x_train, y_train)
    y_p = predict(x_test, w).flatten()
    acc = cal_ACC(y_test, y_p)

    #print(y_test, y_p)
    print(len(y_test), sum(y_test), sum(y_p))
    print('acc:', acc)