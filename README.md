#FdmRenamePlugin

最近使用FDM(Free Download Manager)，发现UTF中文文件名直接不能识别，文件保存为URL字符串的形式

看了下FDM安装目录下有`Plugins`目录，于是基于`FDM plugins SDK`写了一个UTF中文文件名自动更正的插件

插件比较简陋，目前仅针对UTF编码的中文文件名

如`TeamViewer%20v8.0.20935%E8%BD%BB%E7%8B%82%E7%B2%BE%E7%AE%80%E7%A0%B4%E8%A7%A3%E4%BC%81%E4%B8%9A%E7%89%88.zip`

下载完毕后，文件自动被重命名为`TeamViewer v8.0.20935轻狂精简破解企业版.zip`

## 编译环境

Windows + VC6.0

## 使用方法

将附件的`FdmRenamePlugin.dll`丢到FDM安装目录下的`Plugins`目录即可