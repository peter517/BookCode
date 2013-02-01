package classinit.stepofinit;

import classinit.stepofinit.TestClass;

public class StepOfClassInit {
	
	static {
		System.out.println("初始化主类");
	}
	
	/**
	 * 类加载步骤如下(注：类加载与tomcat的加载不一样，后者不包括初始化这一动作)
	 * 
	 * 1.加载
	 * a.获取.class文件的二进字节流，有多种途径获取
	 * b.把加载类的结构信息保存到方法区
	 * 
	 * 2.连接
	 * a.验证:验证.class字节码的安全
	 * b.准备:初始化类变量的值(一般先初始化为的是系统默认值，带有final修饰符的常量，则直接初始化成设定的值)
	 * c.解析:将符号引用替换成直接引用
	 * 
	 * 3.初始化
	 * (类内部)
	 * a.static语句块
	 * b.static字段 
	 * c.其他字段
	 * d.构造函数
	 * 
	 * (类之间)
	 * a.主类
	 * b.父类
	 * c.自己
	 * 
	 * @throws Exception 
	 * @throws InstantiationException 
	 */
	public static void main(String[] args) throws InstantiationException, Exception {
		
		System.out.println("初始化开始……");
		
		int d = TestClass.d;
		System.out.println("引用常量池数据d的完毕");
		
		System.out.println("c = " + TestClass.c);
		
	}

	
}
