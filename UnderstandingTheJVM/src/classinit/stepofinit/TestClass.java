package classinit.stepofinit;

public class TestClass {
	
	private int a = 1;
	private int b;
	public static int c = 1;
	public static final int d = 1;
	
	public TestClass(){
		System.out.println("TestClass()");
	}
	
	static {
		System.out.println("执行static语句块");
	}


}
