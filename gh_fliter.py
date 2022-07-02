import matplotlib.pyplot as plt
import numpy as np

#gh滤波算法实现
def g_h_filter (data, x, dx, g, h, dt=1.):
    results = []
    for z in data:
        x_est = x + (dx*dt)
        residual = z - x_est

        dx = dx    + h * (residual / float(dt))
        x  = x_est + g * residual
        #print('gx',dx,)

        results.append(x)


    return results

'''
gh滤波不依赖模型
是一个一阶量x
与一个二阶量dx,dx是x的微分量，代表变化率
例如x是位置，那么dx就是x的变化量为速度
residual为残差
z为测量值
x_est为估计值，是我们需要的
'''


##### 调整图片大小尺寸到合适
plt.figure(figsize=(20, 8))

data_len = 100

data_index = range(0, data_len)
random_data = np.random.rand(data_len) - 0.5
random_data = random_data * 50
measure_data = list(np.add(data_index, random_data))


#g越大越相信测量
g = 0.1
#h越大越相信预测
h = 0.01
#使用gh滤波
fliter_data = g_h_filter(measure_data, 0, 0, g, h, dt=1.)

#画出实际数据
plt.plot([0,data_len], [0,data_len])
#测量数据，测量必然会带有误差
plt.plot(data_index, measure_data)
#gh滤波之后的数据
plt.plot(data_index, fliter_data)

#为了使不出现[<matplotlib.lines.Line2D at 0x294a6536748>]
plt.show()     