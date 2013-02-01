package classpuzzlers;

public class RecursionInit {
	
	//public static int b = 1;
	public static RecursionInit obj = new RecursionInit();
	public static int b = 1;
	public final int a;
	
	public RecursionInit(){
		a = b - 1;
	}
	
	public static void main(String[] args){
		System.out.print(obj.a);
	}
	
}
