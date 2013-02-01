package classinit.uninit;

class SubClass extends SuperClass{
	static {
		System.out.println("SubClass init!");
	}
}

public class SuperClass {
	
	static {
		System.out.println("SuperClass init!");
	}
	
	public static int value = 123;

}
