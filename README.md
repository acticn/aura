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


