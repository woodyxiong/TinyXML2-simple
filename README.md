# TinyXML2-simple
在TinyXML2库进一步封装，使之更加容易在项目中使用，主要是增加了对XML元素的连贯操作，使得代码更加简短易读。
## 安装说明
与TinyXML2一样，开封即用，仅需要引入tinyxml2文件夹内容
## 使用说明
### 介绍
`TinyXML2-simple`有两个指针，一个指向需要操作的父节点(头指针)，一个指向操作节点(行为指针)。
所有操作行为都是针对行为指针，当行为指针需要归位时，运用`back()`将行为指针归位至头指针。
> 节点操作
+ 查看节点的内容`text()`
+ 修改节点的内容`text("value")`
+ 查看节点的属性值`attr("name")`
+ 修改节点的属性值`attr("name","value")`
+ 查看节点的名称`name()`
+ 修改节点的名称`name("name")`
> 指针操作
+ 头指针的操作方法`next()`和`previous()`
+ 行为指针的操作方法`child()`和`back()`
> 文档操作
+ 保存文档`save()`
+ 另存为文档`save("path")`

### 节点属性操作
#### 示例 `example.xml` 的解析
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
    <user yanzhi="100">
        user4
        <gender>male</gender>
        <mobile>11111111</mobile>
        <email>wangwu@gmail.com</email>
    </user>
</users>
```
> 获取/修改user节点的内容，以及更深节点的内容
```
void parseSimple(){
    Simplexml* simplexml=new Simplexml("example.xml");
    cout<<simplexml->child("user")->text()<<endl;//默认为第一个元素，输出user0
    cout<<simplexml->child("user",1)->text()<<endl;//输出user1
    cout<<simplexml->child("user",2)->child("email")->text()<<endl;//输出zhangsan@gmail.com
    cout<<simplexml->child("user",3)->child("email")->text()<<endl;//输出lisi@gmail.com
    
    simplexml->child("user",4)->child("mobile")->text("22222");//将user4的手机号修改成22222
    simplexml->save();//保存文档
    delete simplexml;
}
```
> 获取/修改第二个user节点的属性值，以及更深节点的属性值
```
void parseSimple(){
    Simplexml* simplexml=new Simplexml("example.xml");
    cout<<simplexml->child("user",2)->attr("yanzhi")<<endl;//输出100
    cout<<simplexml->child("user",3)->child("mobile")->attr("type")<<endl;//输出tele

    simplexml->child("user",4)->attr("yanzhi","100");//将user4的yanzhi属性修改成100
    simplexml->child("user",4)->attr("tele","777");//在user4的节点添加属性
    simplexml->save();//保存文档
    delete simplexml;
}
```
> 获取/修改第一个user节点的名称
```
void parseSimple(){
    Simplexml* simplexml=new Simplexml("example.xml");
    cout<<simplexml->child("user")->name();//输出user
    simplexml->child("user")->name("user100");//将user1节点的name修改成user100
    simplexml->save();//保存文档
    delete simplexml;
}
```
> 增加删除节点
```
void parseSimple(){
    try {
        Simplexml* simplexml;
        simplexml=new Simplexml("example.xml");
        simplexml->addNode("first");//将first节点插入在为第一个
        simplexml->addNode("end",false);//将end节点插入为最后一个
        simplexml->deleteNode("user",1);//将第二个user节点删除
        simplexml->save();//保存文档
        delete simplexml;
    }catch (string e){
        cout<<e<<endl;
    }
}
```
### 节点指向操作
#### 示例`example1.xml`的解析
```
<?xml version="1.0" encoding="utf-8" ?>
<school>
    <class1>
        <student>stu0</student>
        <student>stu1</student>
        <student>stu2</student>
        <student>stu3</student>
        <student>stu4</student>
    </class1>
    <class2>
            <student>stu0</student>
            <student>stu1</student>
            <student>stu2</student>
            <student>stu3</student>
            <student>stu4</student>
    </class2>
</school>
```
如果我们经常需要操作比较深结构的文档，比如在`example1.xml`中，
我们需要经常操作`student`节点的内容，为了减少解析文档的复杂度和代码量，
可以将头指针指向`class`
> 错误示范，如果不使用头指针，会造成复杂度较高的结果，并且代码会比较冗余
```
void parseSimple(){
    try {
        Simplexml* simplexml;
        simplexml=new Simplexml("example1.xml");
        cout<<"class1\n";
        cout<<simplexml->child("class1")->child("student",0)->text()<<endl;
        cout<<simplexml->child("class1")->child("student",1)->text()<<endl;
        cout<<simplexml->child("class1")->child("student",2)->text()<<endl;
        cout<<simplexml->child("class1")->child("student",3)->text()<<endl;
        cout<<simplexml->child("class1")->child("student",4)->text()<<endl;

        cout<<"class2\n";
        cout<<simplexml->child("class2")->child("student",0)->text()<<endl;
        cout<<simplexml->child("class2")->child("student",1)->text()<<endl;
        cout<<simplexml->child("class2")->child("student",2)->text()<<endl;
        cout<<simplexml->child("class2")->child("student",3)->text()<<endl;
        cout<<simplexml->child("class2")->child("student",4)->text()<<endl;
        delete simplexml;
    }catch (string e){
        cout<<e<<endl;
    }
}
```
> 正确使用头指针
```
void parseSimple(){
    try {
        Simplexml* simplexml;
        simplexml=new Simplexml("example1.xml");
        cout<<"class1\n";
        simplexml->next("class1");//将头指针向子节点移动
        cout<<simplexml->child("student",0)->text()<<endl;
        cout<<simplexml->child("student",1)->text()<<endl;
        cout<<simplexml->child("student",2)->text()<<endl;
        cout<<simplexml->child("student",3)->text()<<endl;
        cout<<simplexml->child("student",4)->text()<<endl;

        cout<<"class2\n";
        simplexml->previous();//将头指针向父节点移动
        simplexml->next("class2");//将头指针向子节点移动
        cout<<simplexml->child("student",0)->text()<<endl;
        cout<<simplexml->child("student",1)->text()<<endl;
        cout<<simplexml->child("student",2)->text()<<endl;
        cout<<simplexml->child("student",3)->text()<<endl;
        cout<<simplexml->child("student",4)->text()<<endl;
        delete simplexml;
    }catch (string e){
        cout<<e<<endl;
    }
}
```

## ToDoList
- [ ] 更加灵活的类似foreach函数