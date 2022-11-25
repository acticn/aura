// aura.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include <shader.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow* window);

int main()
{
    glfwInit();//初始化glfw
    //下面使用glfwWindowHint函数配置glfw
    /*
    * glfwWindowHint(int hint, int value)
    * 第一个参数代表选项的名称，从多个以GLFW_开头的枚举值中选择
    * 第二个参数接受一个整型，用于设置该选项
    */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//指定主版本号
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//指定次版本号
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//指定CORE模式
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    //下面创建一个窗口对象
    /*
    * glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
    * width：窗口宽度 height：窗口高度 title：标题名 
    * 后面两个参数暂时忽略
    */
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);//创建一个800*600的窗口，标题名为“LearnOpenGL”
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);//绑定窗口
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    //下面配置glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }




    Shader ourShader("./src/shaders/3.3.shader.vs", "./src/shaders/3.3.shader.fs");//创建Shader
    //顶点
    float vertices[] = {
        // positions         // colors
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
    };
    //配置VBO
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    //解释顶点坐标
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //解释顶点颜色
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    /*
    * glViewPort(GLint x, GLint y, GLsizei width, GLsizei height)
    * 前两个参数控制左下角的位置
    * 第三个和第四个参数控制渲染窗口的宽度和高度
    */
    ///glViewport(0, 0, 800, 600);

    //设置窗口调整回调函数，从而在窗口大小改变时调整渲染窗口大小
  
    //render loop
    while (!glfwWindowShouldClose(window))//glfwWindowShouldClose用于判断是否退出
    {
        processInput(window);
        
        glClearColor(.2f, .2f, .2f, .2f);//设置清空颜色
        glClear(GL_COLOR_BUFFER_BIT);//执行清空命令

        ourShader.use();//启用program
        glBindVertexArray(VAO);//绑定VAO 每次program进行渲染都需要指定一个VAO
        glDrawArrays(GL_TRIANGLES, 0, 3);//以draw array方式进行渲染


        glfwSwapBuffers(window);//交换前后缓冲区（这种机制可以避免画面撕裂等现象
        glfwPollEvents();//检查有没有触发什么事件（比如键盘输入、鼠标移动等）、更新窗口状态，并调用回调函数（可以通过回调方法手动设置）。
    }

    //释放资源
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();//中止，释放资源

    return 0;
}

//根据窗口大小设置渲染视口大小
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}