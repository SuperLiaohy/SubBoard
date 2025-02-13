# SubBoard

> 本项目既可用keil（使用armclang（第六代编译器）编译）打开，也可用clion打开，用clion打开时，得修改 arm-none-eabi-toolchain.cmake里的armclang（第六代编译器）工具链的位置(默认是笔者电脑的armclang位置，故用户得修改)

robomaster步兵下板代码

## cubemx配置

rs485 $\rightarrow$ USART2 $\rightarrow$ 2000000，9，even，1

rgb $\rightarrow$ spi6

4个瓴控电机 $\rightarrow$ fdcan1 $\rightarrow$ 1000000

4个M3508 $\rightarrow$ fdcan2 $\rightarrow$ 1000000

## 代码架构

> 用户代码如下

- Own
  - App
  - Bsp
  - Cbk
  - Mod
  - Task

其中基本功能已经实现，如果要实现进一步功能，如在下板跑pid，实现检测离线功能，可以把mod(目前mod全注释了，再Own/Mod下有源文件，但未添加到keil里)里的pid和detect用c改写一遍，然后加入到对应的电机结构体里，然后初始化~~~等。
