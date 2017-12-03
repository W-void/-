import numpy as np
import matplotlib.pyplot as plt
from scipy import io as spio
from scipy import optimize

def display_data(imgdata):
    #将这100个数放在同一个矩阵中 ，直接画全部数比较方便
    pad = 1  # 图与图直接的界限
    display_array = np.zeros((pad+10*(pad+20), pad+10*(pad+20)))
    
    for i in range(10):
        for j in range(10):
            display_array[pad+i*(pad+20):pad+i*(pad+20)+20, pad+j*(pad+20):pad+j*(pad+20)+20]=\
                imgdata[i*10+j, :].reshape((20,20), order='F')  
                # F表示从第一维到最后一维，这里表示以列为先
    plt.figure()
    plt.imshow(display_array, cmap='gray') #显示灰度图
    plt.axis('off')
    plt.show()
        
def OneVsAll(x, y):
    x = np.hstack((np.ones((x.shape[0],1)), x)) # h -- horizon,水平方向堆叠，即列增加
    all_theta = np.zeros((x.shape[1], 10))  # x.shape=(5000,401),all_theta.shape=(401, 10)
    
    # y需要变成 one-hot 编码，映射为 0/1 的关系
    class_y = np.zeros((x.shape[0], 10))
    for i in range(10):
        '''因为 class_y[:, i].shape=(5000,) 是一维的，
           np.array(y==i).shape=(5000,1) 是二维的，
           所以必须 reshape 成一个行向量'''
        class_y[:, i] = np.array(y==i).reshape((1, -1))  
    
    '''遍历每个分类，计算theta的值'''
    initial_theta = np.zeros((x.shape[1], 1))
    lambd = 0.1    # 正则化项
    for i in range(10):
        result = optimize.fmin_bfgs(CostFunction, initial_theta, fprime=gradient, args=(x, class_y[:,i], lambd))
        all_theta[:, i] = result
    
    return all_theta

def sigmoid(z):
    return 1/(1+np.exp(-z))

def CostFunction(initial_theta, x, y, lambd):
    m = x.shape[0]
    h = sigmoid(np.dot(x, initial_theta))  # h.shape=(5000, 1)
    theta1 = initial_theta.copy()
    theta1[0] = 0   # theta1[0] 为 bias， 正则化不包括 bias
    
    #  在区间（0，1）上，log是负的，所以前面乘 负的1/m，使他变成一个正数
    #  因为一般逻辑回归的代价函数都是 y*log（h），所以h代表的就是 为1的概率，若变成 y*log(1-h), h则代表为0的概率
    J = (-1/m)*(np.dot(y.T, np.log(h)) + np.dot(1-y.T, np.log(1-h))) + 1/(2*m) * (lambd*np.dot(theta1.T, theta1))
    return J

def gradient(initial_theta, x, y, lambd):
    theta1 = initial_theta.copy()
    theta1[0] = 0
    h = sigmoid(np.dot(x, initial_theta))
    m = x.shape[0]
    
    # 梯度应与theta是同规模的
    grad = np.dot(x.T, h-y)/m + lambd*theta1/m
    return grad

def predict_OneVsAll(all_theta, x):
    x = np.hstack((np.ones((x.shape[0], 1)), x))
    
    predict = sigmoid(np.dot(x, all_theta))
    p = np.zeros((x.shape[0],1))
    #predict 目前为 one-hot 码，需要转换后才能和 y 比较
    for i in range(x.shape[0]):
        p[i] = np.array(np.where(predict[i,:]==np.max(predict[i,:])))
        
    return p

def logisticRegression_OneVsAll():
    data = spio.loadmat('data_digits.mat');
    x = data['X']     #每一行是一个样本，每一列是一个特征
    y = data['y']
    m, n = x.shape
    
    rand_index = np.random.randint(0, 5000, size=100)
    display_data(x[rand_index,:])  # 随机显示100个数
    
    all_theta = OneVsAll(x, y)  # (401, 10)
    
    p = predict_OneVsAll(all_theta, x)
    print('预测精确度为: ', 100*np.mean(p==y))
    
if __name__ == "__main__":
    logisticRegression_OneVsAll()
