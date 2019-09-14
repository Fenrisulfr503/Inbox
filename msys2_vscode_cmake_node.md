Msys2 安装：
    
    pacman 的配置

    编辑 /etc/pacman.d/mirrorlist.mingw32 ，在文件开头添加：

    Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/i686


    编辑 /etc/pacman.d/mirrorlist.mingw64 ，在文件开头添加：

    Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/x86_64


    编辑 /etc/pacman.d/mirrorlist.msys ，在文件开头添加：

    Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/msys/$arch


    然后执行 pacman -Sy 刷新软件包数据即可。

MSYS2 安装工具 ：
    pacman -S mingw-w64-x86_64-gcc
    pacman -S mingw-w64-x86_64-gdb
    pacman -S mingw-w64-x86_64-make
    pacman -S mingw-w64-x86_64-clang

MSYS2 制定exe程序路径：
    vim ~/.bashrc
    在该文件末尾加上 export PATH=yourexeoath:$PATH


VS Code cmake 编译使用使用：
    把路径制定到安装好 gcc / clang 或者gdb 的mingw64路径下。



