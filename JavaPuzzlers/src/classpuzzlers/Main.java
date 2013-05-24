package classpuzzlers;

//class SubMain extends Main{
//	
//}
public class Main {
	
	public String a;
	
	public Main(String a){
		this.a = a;
	}

	static {
		init();
		System.out.println("执行静态语句块");
	}
	
	private static boolean isInit = false;
	
	private static int num;
//	private static int num = 0; //这是另外一个结果
	
	public static void getNum(){
		init();
	}
	
	private static synchronized void init(){
		if(!isInit){
			num += 10;
			isInit = true;
		}
	}
	
	@Override
	public boolean equals(Object obj) {
		if(!(obj instanceof Main)){
			return false;
		}
		Main m = (Main)obj;
		return a.equals(m.a);
	}

	@Override
	public int hashCode() {
		return 37 * a.hashCode();
	}

	public static void main(String[] args) throws InstantiationException, Exception {
		
		getNum();
	    
	    int x = Integer.MIN_VALUE;
	    int z = 1;
	    
	    System.out.println(x - z);//2147483647
		
	}
}


