package jvmrunmechanism;

/*
 * 静态分派演示
 */
public class StaticDispatch {
	
	static abstract class Human {

	}
	
	static class Man extends Human {

	}

	static class Woman extends Human {

	}
	
	public void sayHello(Human guy){
		System.out.println("Human");
	}
	
	public void sayHello(Man guy){
		System.out.println("Man");
	}
	
	public void sayHello(Woman guy){
		System.out.println("Woman");
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {

		Human man = new Man();
		Human woman = new Woman();
		
		StaticDispatch sd = new StaticDispatch();
		sd.sayHello(man);
		sd.sayHello(woman);
		
		sd.sayHello((Man)man);
		sd.sayHello((Woman)woman);
		
		System.out.println(2.00f - 1.10f);

	}

}
