package cnmJava;
/*
 * [ class inheritance ]
 * ===
 * - it turns out Java does NOT support subclass to inherit ctors from Base;
 * ===
 * 
 * */
public class A {
	private int x;
	public A() {
		this.x = 0;
	}
	
	public String toString() {
		return String.format("x = %d", this.x);
	}
}
