# TinyXML2-simple
在TinyXML2库进一步封装，使之更加容易在项目中使用，主要是增加了对XML元素的连贯操作，使得代码更加简短易读。
## 安装说明
与TinyXML2一样，开封即用，仅需要引入tinyxml2文件夹内容
## 使用说明
### 介绍
`TinyXML2-simple`有两个指针，一个指向需要操作的父节点(头指针)，一个指向操作节点(行为指针)。
所有操作行为都是针对行为指针，当行为指针需要归位时，运用`back()`将行为指针归位至头指针。
> 指针操作
+ 头指针的操作方法`next()`
+ 行为指针的操作方法`child()`
> 节点操作
+ 查看节点的内容`text()`
+ 修改节点的内容`text("value")`
+ 查看节点的属性值`attr("name")`
+ 修改节点的属性值`attr("name","value")`
> 文档操作
+ 保存文档`save()`
+ 另存为文档`save("path")`

### 示例 `example.xml` 的解析
```
<?xml version="1.0" encoding="UTF-8" ?>
<users>
    <user>user0</user>
    <user>user1</user>
    <user password="123" yanzhi="100">
        user2
        <gender>male</gender>
        <mobile>2222111</mobile>
        <email>zhangsan@gmail.com</email>
    </user>
    <user>
        user3
        <gender>male</gender>
        <mobile type="tele">3333333333</mobile>
        <email>lisi@gmail.com</email>
    </user>
</users>
```
> 获取user节点的内容，以及更深节点的内容
```
void parseSimple(){
    Simplexml* simplexml=new Simplexml(xmlpath);
    cout<<simplexml->child("user")->text()<<endl;//默认为第一个元素
    cout<<simplexml->child("user",1)->text()<<endl;
    cout<<simplexml->child("user",2)->child("email")->text()<<endl;
    cout<<simplexml->child("user",3)->child("email")->text()<<endl;
    delete simplexml;
}
```
> 获取第二个user节点的属性值，以及更深节点的属性值
```
void parseSimple(){
    Simplexml* simplexml=new Simplexml(xmlpath);
    cout<<simplexml->child("user",2)->attr("yanzhi")<<endl;
    cout<<simplexml->child("user",3)->child("mobile")->attr("type")<<endl;
    delete simplexml;
}
```