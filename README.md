# 简单多边形的线性时间凸包算法项目

> 本项目为清华大学计算几何课程作业。
>
> 小组成员： @spwlyzx, @zyeric, @xskxzr
>
> 由邓俊辉老师指导。
>
> 基于以下网址提到的算法：http://cgm.cs.mcgill.ca/~athens/cs601/

### 文件列表

- Form Files ----- 界面布局
  - SimplePolygonConvexHull.ui
- Generated Files ----- 由Qt生成的中间文件
- Header Files ----- 头文件集合
  - SimplePolygonConvexHull.h ----- 界面主类内部元素定义
  - DataStruc.h ----- 所需的主要数据结构
  - GraphicsScene.h ----- 界面显示必要文件，演示和其他显示功能都在其中实现
  - Algorithm.h ----- 为方便方法之间的切换，提取出各个算法的公用类，并具体实现为各个子类
  - AlgorithmFactory.h ----- 用于根据id生成统一的Algorithm类，方便方法调用
  - Algorithms Header ----- 包含继承自Algorithm类的各个子类的头文件
- Resource Files ----- 界面所使用到的资源文件
- Source Files ----- cpp文件集合
  - main.cpp ----- 程序入口
  - SimplePolygonConvexHull.cpp ----- 主要包含界面响应以及与后端程序交互
  - DataStruc.cpp ----- 对应头文件的实现
  - GraphicsScene.cpp ----- 界面显示必要文件，演示和其他显示功能都在其中实现
  - AlgorithmFactory.cpp ----- 对应头文件的实现
  - Algorithms Impl ----- 包含对应header中的算法实现文件

### 公共知识

- 具体一次操作流程为：
  - 鼠标左击依次输入点，右击结束输入。
    - 点击clear()可以消除之前所有的输入，重新进行多边形输入。
  - 选择方法，并点击计算按钮后，系统根据选择的方法新建对应的算法子类
  - 调用该算法的getConvexHull(SimplePolygon & sp, Displays & displays)方法，其中sp为传入的简单多边形数据，displays为返回的演示过程
  - displays中包含了每一步演示中，所需要显示的点、线、区域内容。
  - 前端系统接收到返回值后，按顺序对displays中的命令进行处理。并可以在任意步骤之间跳转而不需要额外的时间。
- 在使用直线划分平面时，考虑默认的界面中，已经限定了各个点坐标的界，即实际上被划分的平面可以认为是一个正方形。即每一次画的仍然是线段。
- 颜色的使用最好一致，符合DataStruc中的内容。
- 目前前端的x坐标水平向右，y坐标轴垂直向下，因此输入的多边形按照顺时针顺序，实际上坐标为逆时针顺序。后续将会实现DataStruc中SimplePolygon的方法normalize()方法，从而确保多边形的点按照逆时针顺序输入，同时第一个点为最左最下点。
