package classinit.uninit;

public class ConstClass {
	
	static {
		System.out.println("ConstClass init!");
	}
	
	public static final String HELLOWORD = "hellword";

}
