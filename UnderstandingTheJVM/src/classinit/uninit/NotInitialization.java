package classinit.uninit;

public class NotInitialization {

	/**
	 * 
	 */
	public static void main(String[] args) {
		
		//这种情况不会使得子类初始化
		System.out.println(SubClass.value);

		//这种情况不会使得数组类初始化
		SuperClass[] s = new SuperClass[10];
		
		//这里也不会初始化，这个类只是访问这个常量的一个入口
		System.out.println(ConstClass.HELLOWORD);
	}

}
