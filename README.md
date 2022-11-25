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
