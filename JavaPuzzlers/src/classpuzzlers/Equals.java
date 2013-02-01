package classpuzzlers;

class Enigma{
	
	//这里与Object类的equals方法的关系是重载
	public Boolean equals(Enigma other){
		return false;
	}
}
public class Equals {

	public static void main(String[] args) throws InstantiationException, Exception {
		
		Enigma e = new Enigma();
		System.out.println(e.equals(e));//false
		
		Object o = new Enigma();
		System.out.println(o.equals(o));//true
	
	}
}
