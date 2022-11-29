# aura.cpp结构

## 1. glfw初始化
## 2. 设置窗口
## 3. glad初始化
## 4. OpenGL配置
## 5. Render Loop


## 处理输入
void processInput(GLFWwindow* window);  
在render loop中加入该函数，从而在每次循环时处理按键响应。


# shader类
## Shader(const char* vertexPath, const char* fragmentPath)
构造函数  
1. 根据参数指定的文件地址获取对应vertex shader和fragment shader，加载到cstr中。
2. 对shader进行编译，创建program链接。
## use()
启用program

## setXXX()  
设置uniform值




# C++输入输出  
 ![图片](./DocumenHelp/images/C%2B%2Bio.jpg)  
 C++库中流类的继承关系  
 
 图 1 中这些流类各自的功能分别为：
+ istream：常用于接收从键盘输入的数据；  
+ ostream：常用于将数据输出到屏幕上；  
+ ifstream：用于读取文件中的数据；  
+ ofstream：用于向文件中写入数据；  
+ iostream：继承自 istream 和 ostream 类，因为该类的功能兼两者于一身，既能用于输入，也能用于输出；  
+ fstream：兼 ifstream 和 ofstream 类功能于一身，既能读取文件中的数据，又能向文件中写入数据。  


# camera.h  
属性:  
相机属性: 
position, front, up, right  
世界坐标系下向上方向:WorldUp  
欧拉角:Yaw, Pitch  
其他相机选项:MovementSpeed, MouseSensitivity, Zoom  
构造函数:
+ 向量构造函数
+ 标量构造函数 

成员函数:  
+ 键盘响应(方向, 时间)
+ 鼠标相应(水平位移, 竖直位移, 是否限制)
+ 滚动响应(位移):调整fov角度
+ 执行update



# 欧拉角转front向量  
欧拉角(Euler Angle)是可以表示3D空间中任何旋转的3个值，由莱昂哈德·欧拉(Leonhard Euler)在18世纪提出。一共有3种欧拉角：俯仰角(Pitch)、偏航角(Yaw)和滚转角(Roll)，下面的图片展示了它们的含义：  

![欧拉角示意图](./DocumenHelp/images/camera_pitch_yaw_roll.png)  
即以front朝向z负方向,up朝向y正方向,right朝向x正方向为起始.  
![](./DocumenHelp/images/camera_triangle.png)  
![](./DocumenHelp/images/camera_pitch.png)  

获得:  
direction.y = sin(glm::radians(pitch));   
direction.x = cos(glm::radians(pitch));  
direction.z = cos(glm::radians(pitch));  

# mesh.h
属性: vertex数组,indices数组,texture数组  
构造函数: 初始化  
setupMesh: 设置VAO,VBO,EBO等缓存  
Draw: 纹理绑定, VAO绑定, 绘图.