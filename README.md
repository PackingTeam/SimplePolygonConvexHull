# 简单多边形的线性时间凸包算法项目

> 本项目为清华大学计算几何课程作业。
>
> 小组成员： @spwlyzx, @zyeric, @xskxzr
>
> 由邓俊辉老师指导。

### 文件列表

- Form Files ----- 界面布局
  - SimplePolygonConvexHull.ui
- Generated Files ----- 由Qt生成的中间文件
- Header Files ----- 头文件集合
  - SimplePolygonConvexHull.h ----- 界面主类内部元素定义
  - DataStruc.h ----- 所需的主要数据结构
  - Commands.h ----- 为方便演示，将算法中的每一个步骤抽象为命令
  - Algorithm.h ----- 为方便方法之间的切换，提取出各个算法的公用类，并具体实现为各个子类
  - Algorithms Header ----- 包含继承自Algorithm类的各个子类的头文件
- Resource Files ----- 界面所使用到的资源文件
- Source Files ----- cpp文件集合
  - main.cpp ----- 程序入口
  - SimplePolygonConvexHull.cpp ----- 主要包含界面响应以及与后端程序交互
  - DataStruc.cpp ----- 对应头文件的实现
  - Commands.cpp ----- 对应命令的实现
  - Algorithms Impl ----- 包含对应header中的算法实现文件

### 公共知识

- 具体一次操作流程为：
  - 选择方法，并点击计算按钮后，系统根据选择的方法新建对应的算法子类
  - 调用该算法的getConvexHull(SimplePolygon & sp, Commands & result)方法，其中sp为传入的简单多边形数据，result为返回的结果
  - result中包含了计算过程中的显示步骤对应的命令，例如：标记点为正在处理，使用直线将平面划分*，将被划分后的平面区域染色，标记点为采用或放弃或待定，等等。
  - 前端系统接收到返回值后，按顺序对result中的命令进行处理，并可以方便的进行undo、redo操作
- 在使用直线划分平面时，考虑默认的界面中，已经限定了各个点坐标的界，即实际上被划分的平面可以认为是一个正方形。即每一次画的仍然是线段。