# PC-Loudspeaker
一个用fmod-low-api开发的电脑扩音器/侦听器

# 使用
打开sample\RecordTest\Debug\RecordTest.exe，即可开启侦听效果，目前延迟20ms左右。

ps：该工具copy自FMOD的sample，本人只是修改了下参数重新编译了下，对其中的原理不是很懂，欢迎高手来一起修改源码来降低延迟。

我就是个SB,目前看到的降低延迟的解决方案就是使用voicemeeter，配合live prefessor来达到低延迟的效果，其实底层应该是应用了虚拟的asio驱动。如果是这样的话，写驱动明显不是我能做的事情，所以这个项目暂时不继续了。
