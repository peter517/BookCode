package classloader;
 
import java.io.File;
import java.io.IOException;
import java.io.InputStream;

public class ClassLoaderTest {

	/**
	 * @param args
	 * @throws ClassNotFoundException
	 * @throws IllegalAccessException
	 * @throws InstantiationException
	 */
	public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException {

		ClassLoader myLoader = new ClassLoader() { 
			// @Override
			
			public Class<?> loadClass(String name) {
//				String fileName = name.substring(name.lastIndexOf(".") + 1) + ".class";
				String fileName = System.getProperty("java.class.path") + File.separator;
				fileName += name.replace('.', File.separatorChar) + ".class";
				InputStream is = getClass().getResourceAsStream(fileName);

				if (is == null) {
					try {
						return super.loadClass(fileName);
					} catch (ClassNotFoundException e) {
						e.printStackTrace();
					}
				}

				byte[] b = null;
				try {
					b = new byte[is.available()];
					is.read(b);

				} catch (IOException e) {
					e.printStackTrace();
				}
				System.out.println(b.length);
				return defineClass(name, b, 0, b.length);

			}

			// public synchronized Class<?> loadClass(String name) throws
			// ClassNotFoundException
			// {
			// Class c = findLoadedClass(name);
			// if (c == null) {
			// try {
			// c = super.loadClass(name, false);
			// } catch (ClassNotFoundException e) {
			// c = findClass(name);
			// }
			// }
			// return c;
			// }
		};

		Object obj = myLoader.loadClass("classloader.ClassLoaderTest").newInstance();
		System.out.println(obj.getClass());
		System.out.println(obj instanceof classloader.ClassLoaderTest);

	}

}
