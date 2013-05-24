package classpuzzlers;

public class MutiThread implements Runnable{ 
	
	private volatile int a = 0;
	@Override
	//这里需要对该方法进行同步
	public void run() {
		for (int i = 0; i < 10000; i++){
			a++;
		}
	} 
	
//	public  void increase(){
//		for (int i = 0; i < 1000; i++){
//			a++;
//		}
//	}
	
	public MutiThread() throws Exception { 

		Thread threads[] = new Thread[10];
		for (int i = 0; i < threads.length; i++)
			threads[i] = new Thread(this);
		for (int i = 0; i < threads.length; i++)
			threads[i].start();
		for (int i = 0; i < threads.length; i++)
			threads[i].join();
		
	} 

	public static void main(String[] args) throws Exception {
		//进行十次实验
		for (int i = 0; i < 10; i++){
			MutiThread test = new MutiThread(); 
			System.out.println(test.a); 
		}
		
		
	}

	
	} 


//package classloader;
//
//public class MutiThread extends Thread {
//	public static int n = 0;
//
//	public synchronized void run() {
//		int m = n;
////		super.yield();
//		m++;
//		n = m;
//	}
//
//	public static void main(String[] args) throws Exception {
//		
//		MutiThread myThread = new MutiThread();
//		
//		Thread threads[] = new Thread[10000];
//		for (int i = 0; i < threads.length; i++)
//			threads[i] = new Thread(myThread);
//		for (int i = 0; i < threads.length; i++)
//			threads[i].start();
//		for (int i = 0; i < threads.length; i++)
//			threads[i].join();
//		System.out.println("n = " + MutiThread.n);
//	}
//	
//}
