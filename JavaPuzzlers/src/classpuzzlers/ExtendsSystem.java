package classpuzzlers;

class Base {
	  public Base(int i){
		  System.out.println("Base");
	  }
      public  String a = "123";
}

class Test {
	public Test(){
		System.out.println("Test");
	}
}

class Devrived extends Base {
	
	public Test t = new Test();
	public Devrived(int i) {
		super(i);
	}

	private  String a = "321";
}

public class ExtendsSystem {
	
	public static void main(String[] args) {
		new Devrived(1);
	}

}

	