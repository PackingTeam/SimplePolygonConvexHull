- # 简单多边形的线性时间凸包算法项目

  > 本项目为清华大学计算几何课程作业。
  >
  > 小组成员： @spwlyzx, @zyeric, @xskxzr
  >
  > 由邓俊辉老师指导。
  >
  > 基于以下网址提到的算法：[A History of Linear-time Convex Hull Algorithms for Simple Polygons](http://cgm.cs.mcgill.ca/~athens/cs601/)

  ### 操作流程

  - 具体一次操作流程为：
    - 鼠标左击依次输入点，右击结束输入。
      - 点击clear()可以消除之前所有的输入，重新进行多边形输入。
    - 选择方法，选择显示结果(result)还是演示(displays)，并点击计算按钮后，系统根据选择的方法自动计算。
    - displays状态下，点击计算后，有三种操作演示进度的方式。
      - 点击start，将根据在Setting->Interval Time中设置的值，自动进行演示。演示中随时可以点击Pause暂停，并使用其他两种方式继续演示。
      - 点击Pre和Start来单步演示。
      - 使用滚动条来快速定位演示进度。
    - 演示途中切换方法会立即清除当前的演示，但保留当前的简单多边形。
    - 点击Setting->Generate可以通过输入点的数量，来生成随机的简单多边形。


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
  - lib ----- 依赖的外部源码，即随机生成简单多边形的算法
