Template Class声明

`template <typename T> class ClassA`

template 是关键字，意味着下面要定义一个模板。模板如同函数一样，有自己的类型参数，typename是模板的类型， T是模板的形参。在使用中，可以将T替换为自己需要的类型。

模板的使用

`classA<int> classAInt;`

通过在类型后面添加制定类型，将模板代码中的T替换为期望类型.这个时候，模板还不会影响代码的具体逻辑.

模板类的变量的定义可以分为两步看待，第一步classA模板通过将int绑定到模板类上，让模板变成了一个普通的类型 classA<int> ，第二步通过模板生成的普通类实例化一个变量.普通类型绑定到模板类的过程被叫做模板实例化。

```cpp
template <typename T>
void Vector<T>::clear()
{

}
```

模板类的成员函数如果要定义在模板类外，需要说明该函数的参数列表,不然函数将会找不到类的参数符号。

模板函数

```cpp
template <typename T> T Add(T a, T b)
{
return a + b;
}
```

输入 `Add<int>`可以将函数变为

``` int Add(int a, int b) return a + b;```

 使用时 `Add<int>(a, b)`,自然的将模板函数转化为处理期望类型的函数，在这个例子下，如果a, b都是int类型，还可以直接使用`Add(a,b)`， 模板会智能的识别到变量的类型,同时将该类型绑定到模板函数上.

```cpp
template <typename SrcT, typename DstT> DstT c_style_cast(SrcT v)
{
    return (DstT)(v);
}

int v = 0;
float i = c_style_cast<float>(v);
 ```

模板需要手动指定的参数放前面, 让编译器自动识别的放在后面.同时编译器没有办法使用返回值确定模板的类型.

```cpp
template <int i> class A {};

void foo()
{
    int x = 3;
    A<5> a; // 正确！
    A<x> b; // error C2971: '_1_3::A' : template parameter 'i' : 'x' : a local variable cannot be used as a non-type argument
}
 ```

因为模板匹配是在编译期完成的，所以模板的参数也必须要在编译器确定.同时模板的参数也可以使整形，整形模板参数使模板拥有提供常数的能力.

元（meta）无论在中文还是英文里，都是个很“抽象（abstract）”的词。因为它的本意就是“抽象”。元编程，也可以说就是“编程的抽象”。用更好理解的说法，元编程意味着你撰写一段程序A，程序A会运行后生成另外一个程序B，程序B才是真正实现功能的程序。那么这个时候程序A可以称作程序B的元程序，撰写程序A的过程，就称之为“元编程”。

通过模板，我们可以将形形色色的堆栈代码分为两个部分，一个部分是不变的接口，以及近乎相同的实现；另外一部分是元素的类型，它们是需要变化的。因此同函数类似，需要变化的部分，由模板参数来反映；不变的部分，则是模板内的代码。可以看到，使用模板的代码，要比不使用模板的代码简洁许多。

如果元编程中所有变化的量（或者说元编程的参数），都是类型，那么这样的编程，我们有个特定的称呼，叫“泛型”。

但是你会问，模板的发明，仅仅是为了做和宏几乎一样的替换工作吗？可以说是，也可以说不是。一方面，很多时候模板就是为了替换类型，这个时候作用上其实和宏没什么区别。只是宏是基于文本的替换，被替换的文本本身没有任何语义。只有替换完成，编译器才能进行接下来的处理。而模板会在分析模板时以及实例化模板时时候都会进行检查，而且源代码中也能与调试符号一一对应，所以无论是编译时还是运行时，排错都相对简单.

但是模板和宏也有很大的不同，否则此文也就不能成立了。模板最大的不同在于它是“可以运算”的。

模板特化
```cpp
// 我们这个模板的基本形式是什么？
template <typename T> class AddFloatOrMulInt;

// 但是这个类，是给T是Int的时候用的，于是我们写作
class AddFloatOrMulInt<int>;
// 当然，这里编译是通不过的。

// 但是它又不是个普通类，而是类模板的一个特化（特例）。
// 所以前面要加模板关键字template，
// 以及模板参数列表
template </* 这里要填什么？ */> class AddFloatOrMulInt<int>;

// 最后，模板参数列表里面填什么？因为原型的T已经被int取代了。所以这里就不能也不需要放任何额外的参数了。
// 所以这里放空。
template <> class AddFloatOrMulInt<int>
{
    // ... 针对Int的实现 ... 
};
```

模板类型获取
```cpp
template <typename T>
class RemovePointer<T*>
{
public:
    // 如果是传进来的是一个指针，我们就剥夺一层，直到指针形式不存在为止。
    // 例如 RemovePointer<int**>，Result 是 RemovePointer<int*>::Result，
    // 而 RemovePointer<int*>::Result 又是 int，最终就变成了我们想要的 int，其它也是类似。
    typedef typename RemovePointer<T>::Result Result;
};
```