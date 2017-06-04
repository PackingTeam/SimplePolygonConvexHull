- # 简单多边形的线性时间凸包算法项目

  > 本项目为清华大学计算几何课程作业。
  >
  > 小组成员： @spwlyzx, @zyeric, @xskxzr
  >
  > 由邓俊辉老师指导。
  >
  > 基于以下网址提到的算法：[A History of Linear-time Convex Hull Algorithms for Simple Polygons](http://cgm.cs.mcgill.ca/~athens/cs601/)
  >
  > 环境配置：vs2015+Qt5.8+win10

### 操作流程

1. 输入简单多边形
     - 鼠标左击依次输入简单多边形上的点
       - 右击结束输入
       - 在第一个点附近点击鼠标左键，自动封闭简单多边形
       - 点击clear()可以消除之前所有的输入，重新进行多边形输入
     - 点击File->Open选择一个数据文件进行读取
     - 点击Advance->Generate可以通过输入点的数量，来生成随机的简单多边形
       - 为了确保演示中进度条随意调整时的流畅性，尽量将点数保持在2000以内
       - 在只计算凸包时，可以使用20000以内的数量的点
2. 选择方法
     - 点击Method下拉框，选择进行计算的算法
       - 在演示过程中切换方法会清空当前的演示内容，但保留当前简单多边形
3. 选择计算模式
     - result：只显示最后的凸包计算结果
     - display：显示整个演示过程
4. 点击Calculate
     - 如果选择了display模式，Pre,Start,Next以及进度条会变更为可以操作的状态
5. 演示
     - 点击start，自动进行演示。演示中随时可以点击Pause暂停，并使用其他两种方式来继续演示。
       - 演示中每一步之间的实际将根据在Advance->Interval Time中设置的值进行变化
     - 点击Pre和Start来单步演示。
     - 使用滚动条来快速定位演示进度。
### 其他功能

  - 保存用例
    - 点击File->Save，可以将当前绘制的用例保存
  - 帮助
    - 点击File->Help，可以跳转到项目的GitHub页面，可以在Issue中提出bug
  - 反例
    - 在选择错误方法时，点击Advance->Counter Example可以查看该错误方法的失效情况


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
