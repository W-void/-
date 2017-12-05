# -*- coding: utf-8 -*-
"""
Created on Mon Dec  4 11:23:18 2017

"""

import numpy as np
import matplotlib.pyplot as plt
import scipy.io as spio
from scipy import optimize
import time

def sigmoid(z):
    return 1/(1+np.exp(-z))

def sigmoidGradient(z):
    return sigmoid(z)*(1-sigmoid(z))

def plot_data(data):
    pad = 1
    display_array = -np.ones((pad+10*(pad+20), pad+10*(pad+20)))
    for i in range(10):
        for j in range(10):
            display_array[pad+i*(pad+20):pad+i*(pad+20)+20, pad+j*(pad+20):pad+j*(pad+20)+20]=\
                data[i*10+j, :].reshape((20,20), order='F')
    plt.figure()
    plt.imshow(display_array)
    plt.axis('off')
    plt.show()

def nnCostFunction(nn_params, x, y, hidden_layer_size):    
    theta1 = nn_params[:hidden_layer_size*401].reshape((401, hidden_layer_size))
    theta2 = nn_params[hidden_layer_size*401:].reshape((hidden_layer_size+1, 10))
    
    '''映射y'''
    class_y = np.zeros((x.shape[0], 10))
    for i in range(10):
        class_y[:,i] = np.array(y==i).reshape((1, -1))  # class_y[:,i]是一维的，所以必须reshape才能赋值
    
    '''正向传播'''
    a1 = np.hstack((np.ones((x.shape[0], 1)), x))  #shape[0]代表样本数，表示每个样本都加上一个bias
    z2 = np.dot(a1, theta1)
    a2 = sigmoid(z2)
    a2 = np.hstack((np.ones((a2.shape[0], 1)), a2))  #shape[0]代表样本数，表示每个样本都加上一个bias
    z3 = np.dot(a2, theta2)
    h = sigmoid(z3)
    
    '''正则化项'''
    theta1_ = theta1.copy()
    theta1_[0, :] = 0
    theta2_ = theta2.copy()
    theta2_[0, :] = 0
    # temp 是一个实数，在这里只需要保证对应项相乘即可，不需要考虑shape，
    # np.dot()太麻烦，array的 *号表示点乘
    lambd = 1
    temp = lambd * (np.sum(theta1_ * theta1_) + np.sum(theta2_ * theta2_))
    
    ''' 代价 '''
    m = x.shape[0]  # m 表示样本数
    J = -np.sum(class_y*np.log(h) + (1-class_y)*np.log(1-h))/m + temp/(m*2)
    return J

def nnGradient(nn_params, x, y, hidden_layer_size):
    theta1 = nn_params[:hidden_layer_size*401].reshape((401, hidden_layer_size))
    theta2 = nn_params[hidden_layer_size*401:].reshape((hidden_layer_size+1, 10))
    
    '''映射y'''
    class_y = np.zeros((x.shape[0], 10))
    for i in range(10):
        class_y[:,i] = np.array(y==i).reshape((1, -1))  # class_y[:,i]是一维的，所以必须reshape才能赋值
    
    '''正向传播'''
    a1 = np.hstack((np.ones((x.shape[0], 1)), x))  #shape[0]代表样本数，表示每个样本都加上一个bias
    z2 = np.dot(a1, theta1)
    a2 = sigmoid(z2)         
    a2 = np.hstack((np.ones((a2.shape[0], 1)), a2))  #shape[0]代表样本数，表示每个样本都加上一个bias
    z3 = np.dot(a2, theta2)         # a2.shape= (m, hidden_layer_size+1)
    h = sigmoid(z3)  # (m, 10)
    
    '''反向传播'''
    '''x--w--y
    weight像个管道，x y 是两端，链式求导就像要更新管道，必须知道管道从哪里来到哪里去
    x--w--y-x--w--y-x--w--y
    要更新每一层的w就需要知道每一层的x和y，我们不是求完一层的xy再求下一层的xy，
    我们是正向传播求出所有的x，再反向传播求出所有的y（y也可以求出一层算一层的w）
    就可以求出所有层的w了
    '''
    m = x.shape[0]
    delta3 = np.zeros((m, 10))
    delta2 = np.zeros((m, hidden_layer_size))
    theta1_grad = np.zeros((theta1.shape))   # (401, hidden_layer_size)
    theta2_grad = np.zeros((theta2.shape))   # (hidden_layer_size+1, 10)
    
    delta3 = h - class_y
    theta2_grad = np.dot(a2.T, delta3)
    delta2 = np.dot(delta3, theta2[1:,:].T)*sigmoidGradient(z2)
    theta1_grad = np.dot(a1.T, delta2)
    '''
    for i in range(m):   # m 表示样本数
        delta3[i,:] = h[i,:] - class_y[i,:] # 就像逻辑回归的梯度为（y-h)*x/m
        # delta3[i,:].shape=(10,), a2[i,:].shape=(hidden_layer_size+1,)
        theta2_grad = theta2_grad +  np.dot(a2[i,:].reshape((-1,1)), delta3[i,:].reshape((1,-1)))
        #  x * w = y ==> x = y * w.T
        # (1,10) * (10, hidden_layer_size)
        delta2[i,:] = np.dot(delta3[i,:].reshape((1,-1)), theta2[1:,:].T)*sigmoidGradient(z2[i,:])
        theta1_grad = theta1_grad +  np.dot(a1[i,:].reshape((-1,1)), delta2[i,:].reshape((1,-1)))
    '''
    
    '''正则化项'''
    theta1_ = theta1.copy()
    theta1_[0, :] = 0
    theta2_ = theta2.copy()
    theta2_[0, :] = 0
    lambd = 1
    
    '''梯度'''
    grad = 1/m * (np.hstack((theta1_grad.reshape((1,-1)), theta2_grad.reshape((1,-1)))) + lambd * np.hstack((theta1_.reshape((1,-1)), theta2_.reshape((1,-1)))))
    return np.ravel(grad)

def predict(result, x, hidden_layer_size):
    theta1 = result[:hidden_layer_size*401].reshape((401, hidden_layer_size))
    theta2 = result[hidden_layer_size*401:].reshape((hidden_layer_size+1, 10))
    
    '''正向传播一边'''
    m = x.shape[0]
    x = np.hstack((np.ones((m,1)), x))
    h1 = sigmoid(np.dot(x, theta1))
    h1 = np.hstack((np.ones((m,1)), h1))
    h2 = sigmoid(np.dot(h1, theta2))
    
    p = np.zeros((m, 1))
    for i in range(m):
        p[i] = np.where(h2[i,:]==np.max(h2[i,:]))
    return p
    
def neuralNetwork(hidden_layer_size):
    data = spio.loadmat('data_digits.mat')
    x = data['X']
    y = data['y']
    
    rand_index = np.random.randint(0, 5000, size=100)
    plot_data(x[rand_index,:])
    
    initial_theta1 = np.random.randn(400+1, hidden_layer_size)  #每一列代表一个神经元，每一列有400个weight，1个bias
    initial_theta2 = np.random.randn(hidden_layer_size+1, 10)   # 10个神经元
    initial_nnParams = np.vstack((initial_theta1.reshape(-1,1), initial_theta2.reshape(-1,1)))
    start = time.time()
    result = optimize.fmin_cg(nnCostFunction, initial_nnParams, fprime=nnGradient, args=(x, y, hidden_layer_size))
    print('运行时间：', time.time()-start)
    
    p = predict(result, x, hidden_layer_size)
    print('ACC：', np.mean(p==y)*100)
    
if __name__ == "__main__":
    neuralNetwork(20) #神经网络输入层有400个神经元，输出层有10个
    plt.figure()
    x = np.arange(-5, 5, 0.01)
    plt.plot(x, sigmoid(x))
    plt.plot(x, sigmoidGradient(x))
    
